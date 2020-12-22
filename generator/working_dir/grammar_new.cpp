#include "grammar_new.h"

GrammarSymbol s1("$END", SYMBOL_END);
GrammarSymbol s7("\"TERM\"", "\"[^\"\n\r \t]+\"", SYMBOL_TERMINAL);
GrammarSymbol s8("\"NTERM\"", "[A-Z0-9][A-Z0-9]*", SYMBOL_TERMINAL);
GrammarSymbol s16("\"AXIOM_KW\"", "\\$AXIOM", SYMBOL_TERMINAL);
GrammarSymbol s15("\"BREAK\"", ";", SYMBOL_TERMINAL);
GrammarSymbol s6("\"OR\"", "\\|", SYMBOL_TERMINAL);
GrammarSymbol s18("\"EQ\"", "=", SYMBOL_TERMINAL);
GrammarSymbol s17("RULE", SYMBOL_NON_TERMINAL);
GrammarSymbol s13("TERMSLIST", SYMBOL_NON_TERMINAL);
GrammarSymbol s11("TERMS", SYMBOL_NON_TERMINAL);
GrammarSymbol s3("RULEPART", SYMBOL_NON_TERMINAL);
GrammarSymbol s10("NONTERMS", SYMBOL_NON_TERMINAL);
GrammarSymbol s14("NONTERMSLIST", SYMBOL_NON_TERMINAL);
GrammarSymbol s5("RIGHTPART", SYMBOL_NON_TERMINAL);
GrammarSymbol s4("TERMORNONTERM", SYMBOL_NON_TERMINAL);
GrammarSymbol s9("AXIOM", SYMBOL_NON_TERMINAL);
GrammarSymbol s12("RULES", SYMBOL_NON_TERMINAL);
GrammarSymbol s2("PROGRAMM", SYMBOL_NON_TERMINAL);
GrammarSymbol s0("$ACCEPT", SYMBOL_START);

QSet<GrammarSymbol*> terms = {
	&s16, &s6, &s15, &s7, &s8, &s18, 
};
QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods = {
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s0, {
		&s2, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s3, {
		&s4, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s3, {
		&s4, &s3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s5, {
		&s3, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s5, {
		&s3, &s6, &s5, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s4, {
		&s7, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s4, {
		&s8, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s2, {
		&s9, &s10, &s11, &s12, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s13, {
		&s7, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s13, {
		&s7, &s13, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s10, {
		&s14, &s15, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s9, {
		&s16, &s8, &s15, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s11, {
		&s13, &s15, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s14, {
		&s8, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s14, {
		&s8, &s14, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s12, {
		&s17, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s12, {
		&s17, &s12, 
	}),
	QPair<GrammarSymbol*, QVector<GrammarSymbol*>>(&s17, {
		&s8, &s18, &s5, &s15, 
	}),
};

QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action = {
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_SHIFT, 1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 4)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_ACCEPT, 0)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 5)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_SHIFT, 8)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 5)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 13)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 10)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_SHIFT, 13)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 11)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 14)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 10)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 8)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_SHIFT, 15)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 16)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_REDUCE, 10)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 9)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 12)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_SHIFT, 19)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 7)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 15)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 16)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 16)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s6, QPair<GrammarAction, int>(ACT_REDUCE, 5)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s6, QPair<GrammarAction, int>(ACT_REDUCE, 6)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 3)},
		{&s6, QPair<GrammarAction, int>(ACT_SHIFT, 26)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_SHIFT, 27)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&s6, QPair<GrammarAction, int>(ACT_REDUCE, 1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_SHIFT, 21)},
		{&s8, QPair<GrammarAction, int>(ACT_SHIFT, 22)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_REDUCE, 17)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_REDUCE, 17)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&s6, QPair<GrammarAction, int>(ACT_REDUCE, 2)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
	{
		{&s1, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s7, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s8, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s16, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s15, QPair<GrammarAction, int>(ACT_REDUCE, 4)},
		{&s6, QPair<GrammarAction, int>(ACT_NONE, -1)},
		{&s18, QPair<GrammarAction, int>(ACT_NONE, -1)},
	},
};

QVector<QMap<GrammarSymbol*, int>> _goto = {
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, 3},
		{&s12, -1},
		{&s2, 2},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, 6},
		{&s14, 7},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, 9},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, 11},
		{&s11, 12},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, 14},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, 18},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, 17},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, 18},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, 20},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, 23},
		{&s10, -1},
		{&s14, -1},
		{&s5, 24},
		{&s4, 25},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, 28},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, 25},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, 23},
		{&s10, -1},
		{&s14, -1},
		{&s5, 29},
		{&s4, 25},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
	{
		{&s17, -1},
		{&s13, -1},
		{&s11, -1},
		{&s3, -1},
		{&s10, -1},
		{&s14, -1},
		{&s5, -1},
		{&s4, -1},
		{&s9, -1},
		{&s12, -1},
		{&s2, -1},
	},
};

