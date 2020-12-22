#pragma once
#include <QVector>
#include <QString>
#include "grammarsymbol.h"
#include "types.h"
#include "token.h"

struct Node {

	Node(){}

	Node(GrammarSymbol *t, QString val = "") {
		type = t;
		value = val;
	}

	Node(const Token &tok) {
		type = tok.GetType();
		value = tok.GetValue();
	}

public:

	QString GetValue() {
		return value.isNull() ? type->GetSymbol() : value;
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

	void SetNum(QString num) {
		if (num.at(0) == "\"") {
			num.remove(0,1);
			num.remove(num.size()-1,1);
		}
		number = num;
	}

	void SetAct(QString act) {
		if (act.size() && act.at(0) == "\"") {
			act.remove(0,1);
			act.remove(act.size()-1,1);
		}
		action = act;
	}

	QString GetAct() {
		return action;
	}

	QString GetNum() {
		return number;
	}

private:
	QString number, action;
	QString value;
	GrammarSymbol* type;
	QVector<Node*> children;
};
