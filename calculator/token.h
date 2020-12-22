#pragma once
#include <QString>
#include "grammarsymbol.h"

struct Token {
	Token(){}
	Token(GrammarSymbol *t, QString v, int p, int l) {
		type = t;
		value = v;
		pos = p;
		line = l;
	}
public:
	QString GetValue() const {
		return value;
	}
	GrammarSymbol *GetType() const {
		return type;
	}

	QString GetPos() const {
		return "("+ QString::number(line) + ", " + QString::number(pos) + ")";
	}

private:
	GrammarSymbol *type;
	QString value;
	int pos, line;
};
