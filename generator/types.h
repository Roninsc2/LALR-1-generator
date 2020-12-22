#pragma once
#include <QHash>
#include <QSet>
#include <QVector>
#include <QPair>
#include <QMap>
#include "grammarsymbol.h"

typedef QHash<GrammarSymbol*,
	QSet<GrammarSymbol*>> FirtsMap;

typedef QVector<QSet<QPair<QPair<int, int>,
	GrammarSymbol*>>> CanonicalCollection;
typedef QVector<QSet<QPair<int, int>>> CanonicalCollectionCore;
typedef QSet<QPair<QPair<int, int>, GrammarSymbol*>> ItemSet;
typedef QPair<QPair<int, int>, GrammarSymbol*> ItemElem;

typedef struct {
	QSet<GrammarSymbol*> lookaheads;
	QSet<QPair<int, QPair<int,int>>> propagates_to;
} LrZeroItem;

typedef enum {
	ACT_NONE,
	ACT_SHIFT,
	ACT_ACCEPT,
	ACT_REDUCE
} GrammarAction;

static const QMap<GrammarAction, QString> act_to_str = {
	{ACT_NONE, "ACT_NONE"},
	{ACT_SHIFT, "ACT_SHIFT"},
	{ACT_ACCEPT, "ACT_ACCEPT"},
	{ACT_REDUCE, "ACT_REDUCE"},
};

typedef struct {
	QVector<QSet<QPair<int, int>>> states;
	QHash<QSet<QPair<int, int>>, int> id_from_state;
	QHash<QPair<int, GrammarSymbol*>, int> _goto;
} Automaton;
