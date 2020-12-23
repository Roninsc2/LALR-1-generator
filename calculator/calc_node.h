#pragma once
#include <QString>

class CalcNode {
public:
	CalcNode(QString t, QString v = "") {
		type = t;
		value = v;
	}

	QString GetValue() {
		return value.isNull() ? type : value;
	}

	QString GetType() {
		return type;
	}

	void AddChild(CalcNode *n) {
		children.push_front(n);
	}

	int GetChildrenSize() const {
		return children.size();
	}

	CalcNode* GetChild(const int i) {
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
	QString value;
	QString type;
	QVector<CalcNode*> children;
	QString number, action;
};
