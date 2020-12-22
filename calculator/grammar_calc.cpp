#include "grammar_calc.h"

GrammarSymbol s1("$END", SYMBOL_END);
GrammarSymbol s7("\"(\"", "\\(", SYMBOL_TERMINAL);
GrammarSymbol s9("\"*\"", "\\*", SYMBOL_TERMINAL);
GrammarSymbol s8("\")\"", "\\)", SYMBOL_TERMINAL);
GrammarSymbol s6("\"NUM\"", "[0-9]+", SYMBOL_TERMINAL);
GrammarSymbol s4("\"+\"", "\\+", SYMBOL_TERMINAL);
GrammarSymbol s2("E", SYMBOL_NON_TERMINAL);
GrammarSymbol s5("F", SYMBOL_NON_TERMINAL);
GrammarSymbol s3("T", SYMBOL_NON_TERMINAL);
GrammarSymbol s0("$ACCEPT", SYMBOL_START);

QSet<GrammarSymbol*> terms = {
	&s7, &s9, &s8, &s6, &s4, 
};
QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods = {
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s0, {
		&s2, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s2, {
		&s3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s2, {
		&s2, &s4, &s2, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s5, {
		&s6, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s5, {
		&s7, &s2, &s8, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s3, {
		&s5, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s3, {
		&s3, &s9, &s3, 
	}),
};

QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action = {
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&s4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&s4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_ACCEPT, 0)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_SHIFT, 7)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 9)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_SHIFT, 7)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&s4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&s4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_SHIFT, 7)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s4, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
	},
};

QVector<QMap<GrammarSymbol*, int>> _goto = {
	{
		{&s2, 3},
		{&s5, 4},
		{&s3, 5},
	},
	{
		{&s2, 6},
		{&s5, 4},
		{&s3, 5},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, 10},
		{&s5, 4},
		{&s3, 5},
	},
	{
		{&s2, -1},
		{&s5, 4},
		{&s3, 11},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
	{
		{&s2, -1},
		{&s5, -1},
		{&s3, -1},
	},
};

