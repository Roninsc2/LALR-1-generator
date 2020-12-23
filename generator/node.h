#pragma once
#include <QVector>
#include <QString>
#include "grammarsymbol.h"
#include "types.h"
#include "token.h"

class Node
{
public:
	Node(){}

	Node(GrammarSymbol *t, QString val = "") {
		type = t;
		value = val;
	}

	Node(const Token &tok) {
		type = tok.GetType();
		value = tok.GetValue();
	}

	QString GetValue() {
		return value;
	}

	QString GetType() {
		return type->GetSymbol();
	}

	void AddChild(Node *n) {
		children.push_front(n);
	}

	int GetChildrenSize() const {
		return children.size();
	}

	Node* GetChild(const int i) {
		return children[i];
	}

private:
	QString value;
	GrammarSymbol* type;
	QVector<Node*> children;
};
