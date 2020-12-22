#pragma once
#include "grammar.h"
#include "types.h"

class QTextStream;

class GrammarLROne
{
public:
	GrammarLROne();
	GrammarLROne(Grammar *grammar);
	QPair<GrammarAction, int> Action(int state, GrammarSymbol* sym);
	int Goto(int state, GrammarSymbol*sym);
	void Export(const QString &file_name);

private:
	void SetupGrammarTable();
	void CalcCanonicalCollection();
	void Closure(ItemSet item_set, ItemSet &res);
	void CalcGoto(ItemSet item_set, GrammarSymbol *sym,
		  ItemSet &res);
	void DropItemsetLookaheads(ItemSet set, QSet<QPair<int, int>> &res);
	void ExportHeader(const QString &file_name, QMap<GrammarSymbol*, QString> &sym_to_int);
	void ExportSyms(QTextStream &stream, QMap<GrammarSymbol*, QString> &sym_to_int);

private:
	QSet<GrammarSymbol*> terms;
	QSet<GrammarSymbol*> non_terms;
	QSet<GrammarSymbol*> symbols;
	QVector<QMap<QPair<int, int>, LrZeroItem>> table;
	QVector<QMap<GrammarSymbol*, int>> _goto;
	QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action;
	Grammar *gr;
	int n_states;
	CanonicalCollection ccol;
};
