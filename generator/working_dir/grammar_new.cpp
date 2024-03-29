#include "grammarsymbol.h"
#include <QVector>
#include <QMap>
#include <QSet>
#include <QPair>
#include "types.h"

GrammarSymbol sym_end("$END", SYMBOL_END);
GrammarSymbol sym_14("\"NTERM\"", "[A-Z0-9][A-Z0-9]*", SYMBOL_TERMINAL);
GrammarSymbol sym_18("\"OR\"", "\\|", SYMBOL_TERMINAL);
GrammarSymbol sym_17("\"AXIOM_KW\"", "\\$AXIOM", SYMBOL_TERMINAL);
GrammarSymbol sym_9("\"BREAK\"", ";", SYMBOL_TERMINAL);
GrammarSymbol sym_6("\"TERM\"", "\"[^\"\n\r \t]+\"", SYMBOL_TERMINAL);
GrammarSymbol sym_15("\"EQ\"", "=", SYMBOL_TERMINAL);
GrammarSymbol sym_10("AXIOM", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_16("RIGHTPART", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_4("TERMORNONTERM", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_5("TERMSLIST", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_8("NONTERMSLIST", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_2("PROGRAMM", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_3("RULEPART", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_13("RULE", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_7("NONTERMS", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_11("TERMS", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_12("RULES", SYMBOL_NON_TERMINAL);
GrammarSymbol sym_0("$ACCEPT", SYMBOL_START);

QSet<GrammarSymbol*> terms = {
	&sym_9, &sym_6, &sym_18, &sym_14, &sym_15, &sym_17, 
};
QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods = {
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_0, {
		&sym_2, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_3, {
		&sym_4, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_3, {
		&sym_4, &sym_3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_5, {
		&sym_6, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_5, {
		&sym_6, &sym_5, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_7, {
		&sym_8, &sym_9, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_2, {
		&sym_10, &sym_7, &sym_11, &sym_12, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_13, {
		&sym_14, &sym_15, &sym_16, &sym_9, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_4, {
		&sym_6, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_4, {
		&sym_14, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_10, {
		&sym_17, &sym_14, &sym_9, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_12, {
		&sym_13, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_12, {
		&sym_13, &sym_12, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_16, {
		&sym_3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_16, {
		&sym_3, &sym_18, &sym_16, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_8, {
		&sym_14, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_8, {
		&sym_14, &sym_8, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&sym_11, {
		&sym_5, &sym_9, 
	}),
};

QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action = {
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 4)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_ACCEPT, 0)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 5)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 5)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 15)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 10)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 13)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_REDUCE, 10)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 16)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 10)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 15)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 16)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_REDUCE, 17)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_SHIFT, 19)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 11)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 16)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 12)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_REDUCE, 8)},
		{&sym_18, QPair<GrammarAction, int>(ACT_REDUCE, 8)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 8)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 8)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_REDUCE, 9)},
		{&sym_18, QPair<GrammarAction, int>(ACT_REDUCE, 9)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 9)},
		{&sym_6, QPair<GrammarAction, int>(ACT_REDUCE, 9)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_SHIFT, 26)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 13)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&sym_18, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_SHIFT, 28)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_REDUCE, 7)},
		{&sym_14, QPair<GrammarAction, int>(ACT_REDUCE, 7)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&sym_end, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_14, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_18, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_17, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_9, QPair<GrammarAction, int>(ACT_REDUCE, 14)},
		{&sym_6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&sym_15, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
};

QVector<QMap<GrammarSymbol*, int>> _goto = {
	{
		{&sym_10, 3},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, 2},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, 7},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, 6},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, 9},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, 11},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, 12},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, 14},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, 17},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, 18},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, 17},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, 20},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, 25},
		{&sym_4, 24},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, 23},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, 24},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, 27},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, 29},
		{&sym_4, 24},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, 23},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
	{
		{&sym_10, -1},
		{&sym_16, -1},
		{&sym_4, -1},
		{&sym_5, -1},
		{&sym_8, -1},
		{&sym_2, -1},
		{&sym_3, -1},
		{&sym_13, -1},
		{&sym_7, -1},
		{&sym_11, -1},
		{&sym_12, -1},
	},
};

