#pragma once
#include "grammarsymbol.h"
#include <QVector>
#include <QMap>
#include <QSet>
#include <QPair>
#include "types.h"

extern GrammarSymbol s1;
extern GrammarSymbol s13;
extern GrammarSymbol s10;
extern GrammarSymbol s18;
extern GrammarSymbol s5;
extern GrammarSymbol s2;
extern GrammarSymbol s17;
extern GrammarSymbol s0;
extern GrammarSymbol s8;
extern GrammarSymbol s3;
extern GrammarSymbol s11;
extern GrammarSymbol s6;
extern GrammarSymbol s7;
extern GrammarSymbol s4;
extern GrammarSymbol s14;
extern GrammarSymbol s16;
extern GrammarSymbol s15;
extern GrammarSymbol s12;
extern GrammarSymbol s9;

extern QSet<GrammarSymbol*> terms;
extern QVector<QPair<GrammarSymbol*, QVector<GrammarSymbol*>>> prods;
extern QVector<QMap<GrammarSymbol*, QPair<GrammarAction, int>>> action;
extern QVector<QMap<GrammarSymbol*, int>> _goto;
