#include "grammarlrone.h"
#include "grammarlrzero.h"
#include <QDebug>
#include <QFile>

GrammarLROne::GrammarLROne()
{
}

GrammarLROne::GrammarLROne(Grammar *grammar)
{

	gr = grammar;
	terms = gr->GetTerms();
	terms.insert(gr->GetEndSym());
	non_terms = gr->GetNotTemrs();
	symbols = terms + non_terms;
	CalcCanonicalCollection();
	SetupGrammarTable();
}

void GrammarLROne::SetupGrammarTable()
{
	QSet<QPair<int, int>> ccol_core_elem;
	CanonicalCollectionCore ccol_core;
	QHash<QSet<QPair<int, int>>, int> id_from_core;
	QVector<QMap<GrammarSymbol*, int>> goto_precalc;
	QMap<GrammarSymbol*, int> goto_elem;
	QMap<GrammarSymbol*, QPair<GrammarAction, int>> action_elem;
	QPair<GrammarAction, int> null_elem;
	null_elem.first = ACT_NONE;
	null_elem.second = -1;
	ItemSet next_state;
	GrammarSymbol *pname;
	GrammarSymbol *terminal;
	GrammarSymbol* next_symbol;
	QVector<GrammarSymbol*> pbody;
	int prod_id;
	int dot;
	int next_state_id;
	int state_id;

	for (auto it = ccol.begin(); it != ccol.end(); it++) {
		DropItemsetLookaheads(*it, ccol_core_elem);
		ccol_core.push_back(ccol_core_elem);
	}

	for (int i = 0; i < n_states; i++) {
		id_from_core[ccol_core[i]] = i;
		for (auto it = non_terms.begin();
		     it != non_terms.end(); it++)
		{
			goto_elem[*it] = -1;
		}
		_goto.push_back(goto_elem);

		for (auto it = terms.begin();
		     it != terms.end(); it++)
		{
			action_elem[*it] = null_elem;
		}
		action.push_back(action_elem);
	}

	goto_precalc.resize(n_states);
	for (auto it = symbols.begin(); it != symbols.end(); it++) {
		for (state_id = 0; state_id < n_states; state_id++) {
			CalcGoto(ccol[state_id], *it, next_state);
			if (!next_state.size()) {
				continue;
			}
			DropItemsetLookaheads(next_state, ccol_core_elem);
			next_state_id = id_from_core[ccol_core_elem];
			goto_precalc[state_id][*it] = next_state_id;
		}
	}

	for (state_id = 0; state_id < n_states; state_id++) {
		for (auto it = ccol[state_id].begin();
		     it != ccol[state_id].end();
		     it++)
		{
			prod_id = it->first.first;
			dot = it->first.second;
			next_symbol = it->second;
			pname = gr->GetNameProdsAt(prod_id);
			pbody = gr->GetProdProdsAt(prod_id);
			if (dot < pbody.size()) {
				terminal = pbody[dot];
				if (terminal->GetType() != SYMBOL_TERMINAL ||
						!goto_precalc[state_id].contains(terminal))
				{
					continue;
				}

				next_state_id = goto_precalc[state_id][terminal];
				action[state_id][terminal] =
						QPair<GrammarAction, int>(
							ACT_SHIFT,
							next_state_id);
			} else {
				if (!prod_id) {
					action[state_id][gr->GetEndSym()] =
							QPair<GrammarAction, int>(
								ACT_ACCEPT, 0);
				} else {
					action[state_id][next_symbol] =
							QPair<GrammarAction, int>(
								ACT_REDUCE, prod_id)
							;
				}
			}
		}

		for (auto nt = non_terms.begin(); nt != non_terms.end(); nt++) {
			if (!goto_precalc[state_id].contains(*nt)) {
				continue;
			}
			next_state_id = goto_precalc[state_id][*nt];
			_goto[state_id][*nt] = next_state_id;
		}
	}
}

void GrammarLROne::CalcCanonicalCollection()
{
	GrammarLRZero lr_zero(gr);
	Automaton dfa = lr_zero.GetAutomaton();
	QVector<QSet<QPair<int, int>>> kstates;
	QVector<GrammarSymbol*> state_symbols;
	ItemSet closure_set;
	ItemSet item_set;
	GrammarSymbol* next_symbol;
	GrammarSymbol *pname;
	QVector<GrammarSymbol*> pbody;
	int j_state_id;
	int prod_id;
	int dot;
	int j_cell_lookaheads_len;
	QPair<int, int> j_item;
	QPair<int, QPair<int,int>> propagate;
	bool repeat;
	QPair<int, int> i_item;
	LrZeroItem *i_cell;
	LrZeroItem *j_cell;

	for (auto it = dfa.states.begin(); it != dfa.states.end(); it++) {
		kstates.push_back(lr_zero.Kernel(*it));
	}
	n_states = kstates.size();
	for (int i = 0; i < n_states; i++) {
		QMap<QPair<int, int>, LrZeroItem> table_elem;
		for (auto it = kstates[i].begin(); it != kstates[i].end(); it++) {
			table_elem[*it] = LrZeroItem();
		}
		table.push_back(table_elem);
	}
	table[0][QPair<int,int>(0,0)].lookaheads.insert(gr->GetEndSym());

	for (int i_state_id = 0; i_state_id < n_states; i_state_id++) {
		state_symbols.clear();
		for (auto it = dfa._goto.begin(); it != dfa._goto.end(); it++) {
			if (it.key().first == i_state_id) {
				state_symbols.push_back(it.key().second);
			}
		}

		for (auto it = kstates[i_state_id].begin();
		     it != kstates[i_state_id].end(); it++)
		{
			item_set.clear();
			item_set.insert(ItemElem((*it), gr->GetFreeSym()));
			Closure(item_set, closure_set);

			for (auto jt = state_symbols.begin();
			     jt != state_symbols.end(); jt++)
			{
				j_state_id = dfa._goto[QPair<int, GrammarSymbol*>(i_state_id, (*jt))];

				for (auto kt = closure_set.begin(); kt != closure_set.end(); kt++) {
					prod_id = kt->first.first;
					dot = kt->first.second;
					next_symbol = kt->second;
					pname = gr->GetNameProdsAt(prod_id);
					pbody = gr->GetProdProdsAt(prod_id);
					if (dot == pbody.size() || pbody[dot] != (*jt)) {
						continue;
					}
					j_item.first = prod_id;
					j_item.second = dot + 1;

					if (next_symbol == gr->GetFreeSym()) {
						propagate.first = j_state_id;
						propagate.second = j_item;
						table[i_state_id][(*it)].
								propagates_to.
								insert(propagate);
					} else {
						table[j_state_id][j_item].
								lookaheads.
								insert(next_symbol);
					}
				}
			}
		}
	}

	repeat = true;
	while (repeat) {
		repeat = false;
		for (int i_state_id = 0;
		     i_state_id < table.size();
		     i_state_id++)
		{
			for (auto it = table[i_state_id].begin();
			     it != table[i_state_id].end();
			     it++)
			{
				i_item = it.key();
				i_cell = &it.value();

				for (auto jt = i_cell->propagates_to.begin();
				     jt != i_cell->propagates_to.end();
				     jt++)
				{
					j_state_id = jt->first;
					j_item = jt->second;
					j_cell = &table[j_state_id][j_item];
					j_cell_lookaheads_len = j_cell->
								lookaheads.
								size();

					j_cell->lookaheads += i_cell->lookaheads;
					if (j_cell->lookaheads.size() > j_cell_lookaheads_len) {
						repeat = true;
					}
				}
			}
		}
	}

	ccol.resize(n_states);
	for (int i_state_id = 0; i_state_id < n_states; i_state_id++) {
		for (auto it = table[i_state_id].begin();
		     it != table[i_state_id].end();
		     it++)
		{
			i_item = it.key();
			i_cell = &it.value();

			for (auto jt = i_cell->lookaheads.begin();
			     jt != i_cell->lookaheads.end();
			     jt++)
			{
				ccol[i_state_id].insert(ItemElem(i_item, (*jt)));
			}
		}
		Closure(ccol[i_state_id], ccol[i_state_id]);
	}
}

void GrammarLROne::Closure(ItemSet item_set, ItemSet &res)
{
	res = item_set;
	int prod_id;
	int dot;
	int nt_offset;
	int idx;
	ItemSet new_elems;
	ItemElem new_item_set;
	GrammarSymbol *pname;
	GrammarSymbol *nt;
	QVector<GrammarSymbol*> pbody;
	QVector<GrammarSymbol*> following_symbols;
	QSet<GrammarSymbol*> following_terminals;
	GrammarSymbol *lookahead;
	while (item_set.size()) {
		new_elems.clear();
		for (auto it = item_set.begin(); it != item_set.end(); it++) {
			prod_id = it->first.first;
			dot = it->first.second;
			lookahead = it->second;
			pname = gr->GetNameProdsAt(prod_id);
			pbody = gr->GetProdProdsAt(prod_id);
			if (dot == pbody.size() || !gr->ContainsNonTerms(pbody[dot])) {
				continue;
			}
			nt = pbody[dot];
			nt_offset = gr->GetNonTermOffset(nt);
			following_symbols = pbody.mid(dot+1);
			following_symbols.push_back(lookahead);
			gr->FirstSet(following_symbols, following_terminals);
			for (idx = 0; idx < nt->GetProd()->size(); idx++) {
				for (auto jt = following_terminals.begin();
				     jt != following_terminals.end(); jt++)
				{
					new_item_set.first = QPair<int,int>(nt_offset + idx, 0);
					new_item_set.second = (*jt);
					if (!res.contains(new_item_set)) {
						new_elems.insert(new_item_set);
						res.insert(new_item_set);
					}
				}
			}
		}
		item_set = new_elems;
	}
}

void GrammarLROne::CalcGoto(ItemSet item_set, GrammarSymbol *sym, ItemSet &res)
{
	res.clear();
	ItemElem new_item;
	GrammarSymbol *pname;
	QVector<GrammarSymbol*> pbody;
	int prod_id;
	int dot;
	for (auto it = item_set.begin(); it != item_set.end(); it++) {
		prod_id = it->first.first;
		dot = it->first.second;
		pname = gr->GetNameProdsAt(prod_id);
		pbody = gr->GetProdProdsAt(prod_id);
		if (dot == pbody.size() || pbody[dot] != sym) {
			continue;
		}

		new_item.first = QPair<int, int>(prod_id, dot + 1);
		new_item.second = it->second;
		res.insert(new_item);
	}

	Closure(res, res);
}

QPair<GrammarAction, int> GrammarLROne::Action(int state, GrammarSymbol *sym)
{
	return action[state][sym];
}

int GrammarLROne::Goto(int state, GrammarSymbol *sym)
{
	return _goto[state][sym];
}

void GrammarLROne::Export(const QString &file_name)
{
	QMap<GrammarSymbol*, QString> sym_to_int;
	sym_to_int.insert(gr->GetStartSym(), QString::number(0));
	sym_to_int.insert(gr->GetEndSym(), "end");
	int num = 2;
	for (int i = 0; i < gr->GetProdsSize(); i++) {
		if (!sym_to_int.contains(gr->GetNameProdsAt(i))) {
			sym_to_int[gr->GetNameProdsAt(i)] = QString::number(num);
			num++;
		}
		for (int j = 0; j < gr->GetProdProdsAt(i).size(); j++) {
			if (!sym_to_int.contains(gr->GetProdProdsAt(i).at(j))) {
				sym_to_int[gr->GetProdProdsAt(i).at(j)] = QString::number(num);
				num++;
			}
		}
	}

	QFile file(file_name + ".cpp");
	if (!file.open(QFile::WriteOnly|QFile::Truncate)){
		return;
	}
	QTextStream stream(&file);
	stream << "#include \"grammarsymbol.h\"\n"
	       << "#include <QVector>\n" << "#include <QMap>\n"
	       << "#include <QSet>\n" << "#include <QPair>\n"
	       << "#include \"types.h\"\n\n";
	ExportSyms(stream, sym_to_int);
	stream << "QVector<QMap<GrammarSymbol*,"
		  " QPair<GrammarAction, int>>> action = {\n";
	for (int i = 0; i < action.size(); i++) {
		stream << "\t{\n";
		for (auto it = action[i].begin(); it != action[i].end(); it++) {
			stream << "\t\t{&sym_" << sym_to_int[it.key()]
			       << ", QPair<GrammarAction, int>("
			       << act_to_str[it.value().first] << ", "
			       << QString::number(it.value().second)
			       << ")},\n";
		}
		stream << "\t},\n";
	}
	stream << "};\n\n";
	stream << "QVector<QMap<GrammarSymbol*, int>> _goto = {\n";
	for (int i = 0; i < _goto.size(); i++) {
		stream << "\t{\n";
		for (auto it = _goto[i].begin(); it != _goto[i].end(); it++) {
			stream << "\t\t{&sym_" << sym_to_int[it.key()]
			       << ", " << QString::number(it.value())
			       << "},\n";
		}
		stream << "\t},\n";
	}
	stream << "};\n\n";
	file.close();
}

void GrammarLROne::DropItemsetLookaheads(ItemSet set,
					 QSet<QPair<int, int> > &res)
{
	res.clear();
	for (auto it = set.begin(); it != set.end(); it++) {
		res.insert(QPair<int,int>(it->first.first, it->first.second));
	}
}

void GrammarLROne::ExportHeader(const QString &file_name,
				QMap<GrammarSymbol *, QString> &sym_to_int)
{
	QFile file(file_name + ".h");
	if (!file.open(QFile::WriteOnly|QFile::Truncate)){
		return;
	}
	QTextStream stream(&file);
	stream << "#pragma once\n#include \"grammarsymbol.h\"\n"
	       << "#include <QVector>\n" << "#include <QMap>\n"
	       << "#include <QSet>\n" << "#include <QPair>\n"
	       << "#include \"types.h\"\n\n";
	QString sym = "extern GrammarSymbol s";
	for (auto it = sym_to_int.begin(); it != sym_to_int.end(); it++) {
		stream << sym + it.value() << ";\n";
	}
	stream << "\nextern QSet<GrammarSymbol*> terms;\n";
	stream << "extern QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods;\n";
	stream << "extern QVector<QMap<GrammarSymbol*,"
		  " QPair<GrammarAction, int>>> action;\n";
	stream << "extern QVector<QMap<GrammarSymbol*, int>> _goto;\n";

}

void GrammarLROne::ExportSyms(QTextStream &stream,
			      QMap<GrammarSymbol*, QString> &sym_to_int)
{
	QString sym = "GrammarSymbol sym_";
	for (auto it = sym_to_int.begin(); it != sym_to_int.end(); it++) {
		stream << sym + it.value();
		if (it.key()->GetType() == SYMBOL_TERMINAL) {
			stream << "(\"" << it.key()->GetSymbol().replace("\"", "\\\"") << "\", "
			       << "\"" << it.key()->GetRegExpSym().
				  replace("\\$", "\\\\$").
				  replace("\\|", "\\\\|").
				  replace("\\)", "\\\\)").
				  replace("\\(", "\\\\(").
				  replace("\\*", "\\\\*").
				  replace("\\+", "\\\\+").
				  replace("\"", "\\\"") << "\", "
			       << type_to_str[it.key()->GetType()] << ");\n";
		} else {
			stream << "(\"" << it.key()->GetSymbol() << "\", "
			       << type_to_str[it.key()->GetType()] << ");\n";
		}
	}
	stream << "\n";

	QSet<GrammarSymbol*> terms = gr->GetTerms();
	stream << "QSet<GrammarSymbol*> terms = {\n\t";
	for (auto it = terms.begin(); it != terms.end(); it++) {
		stream << "&sym_" << sym_to_int[*it] <<", ";
	}
	stream << "\n};\n";
	stream << "QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods = {\n";
	for (int i = 0; i < gr->GetProdsSize(); i++) {
		GrammarSymbol *key = gr->GetNameProdsAt(i);
		stream << "\tQPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_"
		       << sym_to_int[key] << ", {\n\t\t";
		for (int j = 0; j < gr->GetProdProdsAt(i).size(); j++) {
			stream << "&sym_" << sym_to_int[gr->GetProdProdsAt(i).at(j)]
			       << ", ";
		}
		stream << "\n\t}),\n";
	}
	stream << "};\n\n";

}
