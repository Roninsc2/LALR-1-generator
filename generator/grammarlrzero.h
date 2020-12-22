#pragma once
#include <QHash>
#include <QSet>
#include <QPair>
#include "types.h"

class Grammar;
class GrammarSymbol;

class GrammarLRZero
{
public:
	GrammarLRZero();
	GrammarLRZero(Grammar *grammar);
	Automaton GetAutomaton();
	QSet<QPair<int, int>> Kernel(QSet<QPair<int, int>> state);
private:
	void Closure(QSet<QPair<int, int>> item_set,
		     QSet<QPair<int, int>> &res);
	void Goto(QSet<QPair<int, int>> item_set, GrammarSymbol *sym,
		  QSet<QPair<int, int>> &res);
private:
	Grammar *gr;
};
