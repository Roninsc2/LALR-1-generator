#include "grammarlrzero.h"
#include "grammar.h"
#include <QDebug>


GrammarLRZero::GrammarLRZero()
{
}

GrammarLRZero::GrammarLRZero(Grammar *grammar)
{
	gr = grammar;
}

Automaton GrammarLRZero::GetAutomaton()
{
	Automaton dfa;
	QSet<QPair<int, int>> item_set;
	QSet<QPair<int, int>> res;
	QVector<QSet<QPair<int, int>>> set_queue;
	QVector<QSet<QPair<int, int>>> new_elems;
	QSet<QSet<QPair<int, int>>> seen;
	QSet<QPair<int, int>> next_item_set;
	QPair<int, GrammarSymbol*> goto_key;
	GrammarSymbol *sym;
	int next_id = 0;
	int item_set_id;
	item_set.insert(QPair<int, int>(0,0));

	Closure(item_set, res);
	dfa.states.push_back(res);

	dfa.id_from_state[dfa.states.last()] = next_id;
	next_id++;

	seen = QSet<QSet<QPair<int, int>>>(dfa.states.begin(),
						dfa.states.end());
	set_queue = dfa.states;
	while (set_queue.size()) {
		new_elems.clear();
		for (auto it = set_queue.begin();
		     it != set_queue.end(); it++)
		{
			item_set = *it;
			item_set_id = dfa.id_from_state[item_set];
			for (auto jt = gr->GetSymbols()->begin();
			     jt != gr->GetSymbols()->end(); jt++)
			{
				sym = *jt;
				Goto(item_set, sym, next_item_set);
				if (!next_item_set.size()) {
					continue;
				}

				if (!seen.contains(next_item_set)) {
					new_elems.push_back(next_item_set);
					seen.insert(next_item_set);

					dfa.states.push_back(next_item_set);
					dfa.id_from_state[dfa.states.last()] = next_id;
					next_id++;
				}
				goto_key.first = item_set_id;
				goto_key.second = sym;
				dfa._goto[goto_key] = dfa.id_from_state[next_item_set];
			}
		}
		set_queue = new_elems;
	}

	return dfa;
}

QSet<QPair<int, int>> GrammarLRZero::Kernel(QSet<QPair<int, int>> state)
{
	QSet<QPair<int, int>> kstate;
	int x;
	int y;
	for (auto it = state.begin(); it != state.end(); it++) {
		x = it->first;
		y = it->second;
		if (x == 0 || y > 0) {
			kstate.insert(QPair<int, int>(x, y));
		}
	}
	return kstate;
}

void GrammarLRZero::Closure(QSet<QPair<int, int>> item_set,
			    QSet<QPair<int, int>> &res)
{
	res = item_set;
	int prod_id;
	int dot;
	int nt_offset;
	int idx;
	QSet<QPair<int, int>> new_elems;
	QPair<int, int> new_item_set;
	GrammarSymbol *pname;
	GrammarSymbol *nt;
	QVector<GrammarSymbol*> pbody;
	while (item_set.size()) {
		new_elems.clear();
		for (auto it = item_set.begin(); it != item_set.end(); it++) {
			prod_id = it->first;
			dot = it->second;
			pname = gr->GetNameProdsAt(prod_id);
			pbody = gr->GetProdProdsAt(prod_id);
			if (dot == pbody.size() || !gr->ContainsNonTerms(pbody[dot])) {
				continue;
			}
			nt = pbody[dot];
			nt_offset = gr->GetNonTermOffset(nt);
			for (idx = 0; idx < nt->GetProd()->size(); idx++) {
				new_item_set.first = nt_offset + idx;
				new_item_set.second = 0;
				if (!res.contains(new_item_set)) {
					new_elems.insert(new_item_set);
					res.insert(new_item_set);
				}
			}
		}
		item_set = new_elems;
	}
}

void GrammarLRZero::Goto(QSet<QPair<int, int> > item_set,
			 GrammarSymbol *sym,
			 QSet<QPair<int, int> > &res)
{
	res.clear();
	int prod_id;
	int dot;
	GrammarSymbol *pname;
	QVector<GrammarSymbol*> pbody;
	for (auto it = item_set.begin(); it != item_set.end(); it++) {
		prod_id = it->first;
		dot = it->second;
		pname = gr->GetNameProdsAt(prod_id);
		pbody = gr->GetProdProdsAt(prod_id);
		if (dot < pbody.size() && pbody[dot] == sym) {
			res.insert(QPair<int, int>(prod_id, dot + 1));
		}
	}
	Closure(res, res);
}
