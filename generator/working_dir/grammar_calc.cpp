#include "grammarsymbol.h"
#include <QVector>
#include <QMap>
#include <QSet>
#include <QPair>
#include "types.h"

GrammarSymbol sym_end("$END", SYMBOL_END);
GrammarSymbol sym_6("\")\"", "\\)", SYMBOL_TERMINAL);
GrammarSymbol sym_9("\"+\"", "\\+", SYMBOL_TERMINAL);
GrammarSymbol sym_8("\"*\"", "\\*", SYMBOL_TERMINAL);
GrammarSymbol sym_5("\"(\"", "\\(", SYMBOL_TERMINAL);
GrammarSymbol sym_4("\"NUM\"", "[0-9]+", SYMBOL_TERMINAL);
GrammarSymbol sym_7("T", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_2("E", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_3("F", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_0("$ACCEPT", SYMBOL_START);

QSet<GrammarSymbol*> terms = {
	&sym_9, &sym_4, &sym_8, &sym_6, &sym_5, 
};
QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods = {
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_0, {
		&sym_2, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_3, {
		&sym_4, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_3, {
		&sym_5, &sym_2, &sym_6, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_7, {
		&sym_3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_7, {
		&sym_7, &sym_8, &sym_7, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_2, {
		&sym_7, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_2, {
		&sym_2, &sym_9, &sym_2, 
	}),
};

QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action = {
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&sym_4, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_8, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&sym_4, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&sym_8, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&sym_8, QPair<GrammarAction, int>(ACT_SHIFT, 7)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_ACCEPT, 0)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 9)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&sym_4, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_SHIFT, 2)},
		{&sym_4, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_8, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&sym_8, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&sym_8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_5, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_4, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
};

QVector<QMap<GrammarSymbol*, int>> _goto = {
	{
		{&sym_7, 4},
		{&sym_2, 5},
		{&sym_3, 3},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, 4},
		{&sym_2, 6},
		{&sym_3, 3},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, 10},
		{&sym_2, -1},
		{&sym_3, 3},
	},
	{
		{&sym_7, 4},
		{&sym_2, 11},
		{&sym_3, 3},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
	{
		{&sym_7, -1},
		{&sym_2, -1},
		{&sym_3, -1},
	},
};

