#include "grammar.h"
#include "grammarsymbol.h"
#include "grammar.h"
#include <QFile>
#include <QDebug>
#include <QPair>
#include <QRegularExpression>

Grammar::Grammar(const QString &file_name)
{
	QFile file(file_name);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}

	ReadTerms(file);
	ReadGrammar(file);
	file.close();
	SetupGrammar();
}

Grammar::Grammar(const QMap<QString, QVector<QVector<QString>>> &rulesArray,
		 const QString &axiom, const QSet<QString> &t,
		 const QSet<QString> &nt, const QString &lex_file)
{
	QMap<QString, QString> reg_exp;
	QFile file(lex_file);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
	    return;
	}
	ReadRegExp(file, reg_exp);
	file.close();

	QVector<GrammarSymbol*> cur_prod;
	GrammarSymbol *sym;
	GrammarSymbol *ax;
	for (auto it = t.begin(); it != t.end(); it++) {
		sym = new GrammarSymbol(*it, SYMBOL_TERMINAL);
		sym->SetRegExp(reg_exp[*it]);
		terms.insert(sym);
	}

	for (auto it = nt.begin(); it != nt.end(); it++) {
		if (*it == axiom) {
			ax = new GrammarSymbol(*it, SYMBOL_NON_TERMINAL);
			non_terms.insert(ax);
		} else {
			non_terms.insert(new GrammarSymbol(*it, SYMBOL_NON_TERMINAL));
		}
	}
	start = new GrammarSymbol(start_sym, SYMBOL_START);
	cur_prod.push_back(ax);
	start->AddProduction(cur_prod);
	non_terms.insert(start);

	for (auto it = rulesArray.begin(); it != rulesArray.end(); it++) {
		GrammarSymbol *from = ContainsInSymbols(it.key());
		for (auto jt = it.value().begin(); jt != it.value().end(); jt++) {
			cur_prod = QVector<GrammarSymbol*>();
			for (auto kt = jt->begin(); kt != jt->end(); kt++) {
				GrammarSymbol *to = ContainsInSymbols(*kt);
				cur_prod.push_back(to);
			}
			from->AddProduction(cur_prod);
		}
	}

	SetupGrammar();
}

Grammar::~Grammar()
{
	for (auto it = terms.begin(); it != terms.end(); it++) {
		delete *it;
	}

	for (auto it = non_terms.begin(); it != non_terms.end(); it++) {
		delete *it;
	}

        delete eps;
	delete end;
	delete free;
}

void Grammar::SetupGrammar()
{
	symbols = terms.values().toVector() + non_terms.values().toVector();

	nonterm_offset[start] = prods.size();
	QVector<QVector<GrammarSymbol*>> *p = start->GetProd();
	for (int i = 0; i < p->size(); i++) {
		prods.push_back(QPair<GrammarSymbol*,
				QVector<GrammarSymbol*>>(start, p->at(i)));
	}

	for (auto it = non_terms.begin(); it != non_terms.end(); it++) {
		if (*it != start) {
			nonterm_offset[*it] = prods.size();
			QVector<QVector<GrammarSymbol*>> *p = (*it)->GetProd();
			for (int i = 0; i < p->size(); i++) {
				prods.push_back(QPair<GrammarSymbol*,
						QVector<GrammarSymbol*>>(*it, p->at(i)));
			}
		}
	}
	BuildFirstSets();
}

void Grammar::ReadRegExp(QFile &file, QMap<QString, QString> &reg_exp)
{
	while (!file.atEnd()) {
	    QString line = QString::fromStdString(file.readLine().toStdString());
	    line.remove(line.size()-1, 1);
	    QString type;
	    QString regExp;
	    SplitLine(line, type, regExp);
	    reg_exp[type] = regExp;
	}
}


void Grammar::ReadTerms(QFile &file) {

	QString line = QString::fromStdString(file.readLine().toStdString());
	while (1) {
		line.remove(line.size()-1, 1);
		if (line.isEmpty()) {
			return;
		}
		QString type;
		QString regExp;
		SplitLine(line, type, regExp);
		GrammarSymbol *sym = new GrammarSymbol(type, SYMBOL_TERMINAL);
		sym->SetRegExp(regExp);
		terms.insert(sym);
		line = QString::fromStdString(file.readLine().toStdString());
	}
}

void Grammar::ReadGrammar(QFile &file)
{
	GrammarSymbol *expr;
	QString line = QString::fromStdString(file.readLine().toStdString());
	QStringList parts;
	line.remove(line.size()-1, 1);
	parts = line.split(QRegularExpression("[ \t]+"), Qt::SkipEmptyParts);
	for (int i = 0; i < parts.size(); i++) {
		if (parts[i] == start_sym) {
			start = new GrammarSymbol(parts[i], SYMBOL_START);
			expr = start;
		} else {
			expr = new GrammarSymbol(parts[i], SYMBOL_NON_TERMINAL);
		}
		non_terms.insert(expr);
	}

	line = QString::fromStdString(file.readLine().toStdString());
	while (1) {
		line.remove(line.size()-1, 1);
		if (line.isEmpty()) {
			return;
		}
		ReadExpr(line);
		line = QString::fromStdString(file.readLine().toStdString());
	}
}

void Grammar::ReadExpr(QString &line)
{
	QStringList parts = line.split(QRegularExpression("[ \t]+"), Qt::SkipEmptyParts);
	QString right = parts[0];
	Expect(parts[1], eq_rule);
	int i = 2;
	GrammarSymbol *expr = ContainsInSymbols(right);
	if (!expr) {
		qDebug() << "RULE NOT FOUND";
		return;;
	}
	QVector<GrammarSymbol*> cur_prod;
	while (1) {
		if (i == parts.size() - 1) {
			expr->AddProduction(cur_prod);
			cur_prod = QVector<GrammarSymbol*>();
			Expect(parts[i], end_rule);
			break;
		}
		if (parts[i] == or_rule) {
			expr->AddProduction(cur_prod);
			cur_prod = QVector<GrammarSymbol*>();
			i++;
			continue;
		}
		GrammarSymbol *left_prod_part = ContainsInSymbols(parts[i]);
		if (!left_prod_part) {
			qDebug() << "RULE NOT FOUND";
			return;
		}
		cur_prod.push_back(left_prod_part);
		i++;
	}
}

void Grammar::SplitLine(QString &line, QString &first, QString &second) {
	int i = 0;
	while (line.at(i) != " ") {
		first += line.at(i);
		i++;
	}
	i++;
	while (i < line.size()) {
		second += line.at(i);
		i++;
	}
}

void Grammar::Expect(const QString &str, const QString val)
{
	if (str != val) {
		qDebug() << "ERR PARSE" << str << val;
	}
}

GrammarSymbol* Grammar::ContainsInSymbols(const QString &sym)
{
	for (auto it = terms.begin(); it != terms.end(); it++) {
		if ((*it)->Eq(sym)) {
			return *it;
		}
	}

	for (auto it = non_terms.begin(); it != non_terms.end(); it++) {
		if ((*it)->Eq(sym)) {
			return *it;
		}
	}

	return nullptr;
}

GrammarSymbol *Grammar::GetNameProdsAt(int i)
{
	return prods.at(i).first;
}

QVector<GrammarSymbol*> Grammar::GetProdProdsAt(int i)
{
	return prods.at(i).second;
}

bool Grammar::ContainsNonTerms(GrammarSymbol *sym)
{
	return non_terms.contains(sym);
}

int Grammar::GetNonTermOffset(GrammarSymbol *sym)
{
	return nonterm_offset[sym];
}

int Grammar::GetProdsSize()
{
	return prods.size();
}

QVector<GrammarSymbol*> *Grammar::GetSymbols()
{
	return &symbols;
}

QSet<GrammarSymbol*> Grammar::GetTerms()
{
	QSet<GrammarSymbol*> t = terms;
	return t;
}

QSet<GrammarSymbol*> Grammar::GetNotTemrs()
{
	QSet<GrammarSymbol*> nt;
	for (auto it = non_terms.begin(); it != non_terms.end(); it++) {
		if ((*it)->GetType() != SYMBOL_START) {
			nt.insert((*it));
		}
	}
	return nt;
}

GrammarSymbol *Grammar::GetEndSym()
{
	return end;
}

GrammarSymbol *Grammar::GetEpsSym()
{
	return eps;
}

GrammarSymbol *Grammar::GetFreeSym()
{
	return free;
}


GrammarSymbol *Grammar::GetStartSym()
{
	return start;
}

void Grammar::FirstSet(QVector<GrammarSymbol*> sym,
		       QSet<GrammarSymbol*> &term)
{
	term.clear();
	if (sym.size() == 1) {
		if (sym[0]->GetType() == SYMBOL_TERMINAL ||
				sym[0]->GetType() == SYMBOL_FREE ||
				sym[0]->GetType() == SYMBOL_END)
		{
			term.insert(sym[0]);
		}
		if (sym[0]->GetType() == SYMBOL_NON_TERMINAL) {
			term = first_set[sym[0]];
		}
	} else {
		int skip_syms = 0;
		QSet<GrammarSymbol*> fs;
		QVector<GrammarSymbol*> new_sym;
		new_sym.resize(1);
		for (auto it = sym.begin(); it != sym.end(); it++) {
			new_sym[0] = (*it);
			FirstSet(new_sym, fs);
			term += fs;
			term.remove(eps);
			if (fs.contains(eps)) {
				skip_syms++;
			} else {
				break;
			}
		}
		if (skip_syms == term.size()) {
			term.insert(eps);
		}
	}
}

void Grammar::BuildFirstSets()
{
	int i;
	int j;
	int cur_fs_size;
	int skippable_symbols;
	bool repeat;

	for (i = 0; i < symbols.size(); i++) {
		if (symbols[i]->GetType() == SYMBOL_TERMINAL) {
			first_set[symbols[i]].insert(symbols[i]);
		} else {
			first_set[symbols[i]] = QSet<GrammarSymbol*>();
			auto prod = symbols[i]->GetProd();
			for (j = 0; j < prod->size(); j++) {
				if (prod->at(j).size() == 1 &&
						prod->at(j).at(0)->GetType() == SYMBOL_EPS)
				{
					first_set[symbols[i]].insert(eps);
				}
			}
		}
	}

	repeat = true;
	while (repeat) {
		repeat = false;
		for (auto it = non_terms.begin();
		     it != non_terms.end(); it++)
		{
			GrammarSymbol* nt = (*it);
			cur_fs_size = first_set[nt].size();
			for (auto jt = nt->GetProd()->begin();
			     jt != nt->GetProd()->end(); jt++)
			{
				QVector<GrammarSymbol*> pt = (*jt);
				skippable_symbols = 0;
				for (auto kt = pt.begin();
				     kt != pt.end(); kt++)
				{
					first_set[nt] += first_set[(*kt)];
					first_set[nt].remove(eps);
					if (first_set[(*kt)].contains(eps)) {
						skippable_symbols++;
					} else {
						break;
					}
				}
				if (skippable_symbols == pt.size()) {
					first_set[nt].insert(eps);
				}
			}
			if (first_set[nt].size() > cur_fs_size) {
				repeat = true;
			}
		}
	}
}
