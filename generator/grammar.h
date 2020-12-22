#pragma once
#include <QVector>
#include <QString>
#include <QHash>
#include <QSet>
#include <memory>
#include "grammarsymbol.h"
#include "types.h"

class GrammarSymbol;
class QFile;

class Grammar
{
public:
	Grammar(const QString &file_name);
	Grammar(const QMap<QString, QVector<QVector<QString>>> &rulesArray,
		const QString &axiom, const QSet<QString> &terms,
		const QSet<QString> &nterms, const QString &lex_file);
	~Grammar();
	GrammarSymbol *GetNameProdsAt(int i);
	QVector<GrammarSymbol*> GetProdProdsAt(int i);
	bool ContainsNonTerms(GrammarSymbol *sym);
	int GetNonTermOffset(GrammarSymbol *sym);
	int GetProdsSize();
	QVector<GrammarSymbol*> *GetSymbols();
	QSet<GrammarSymbol*> GetTerms();
	QSet<GrammarSymbol *> GetNotTemrs();
	GrammarSymbol* GetEndSym();
	GrammarSymbol* GetEpsSym();
	GrammarSymbol* GetStartSym();
	GrammarSymbol* GetFreeSym();
	void FirstSet(QVector<GrammarSymbol*> following_symbols,
		      QSet<GrammarSymbol*> &following_terminals);
private:
	void ReadRegExp(QFile &file, QMap<QString, QString> &reg_exp);
	void SetupGrammar();
	void ReadTerms(QFile &file);
	void ReadGrammar(QFile &file);
	void ReadExpr(QString &line);
	void SplitLine(QString &line, QString &first, QString &second);
	void Expect(const QString &str, const QString val);
	void BuildFirstSets();
	GrammarSymbol* ContainsInSymbols(const QString &sym);
private:
	const QString eq_rule = "=";
	const QString or_rule = "|";
	const QString end_rule = ";";
	const QString start_sym = "$ACCEPT";
	const QString eps_sym = "$EPS";
	const QString end_sym = "$END";

	QSet<GrammarSymbol*> terms;
	QSet<GrammarSymbol*> non_terms;
	QVector<GrammarSymbol*> symbols;
	QHash<GrammarSymbol*, int> nonterm_offset;
	QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods;
	GrammarSymbol *eps = new GrammarSymbol(eps_sym, SYMBOL_EPS);
	GrammarSymbol *end = new GrammarSymbol(end_sym, SYMBOL_END);
	GrammarSymbol *free = new GrammarSymbol(QString(), SYMBOL_FREE);
	GrammarSymbol *start;
	FirtsMap first_set;
};
