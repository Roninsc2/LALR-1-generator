#include "calculator.h"
#include "node.h"
#include "calc_node.h"
#include <iostream>

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
	FreeNode(root);
}

void Calculator::FreeNode(CalcNode *n)
{
	if (!n) {
		return;
	}
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		FreeNode(n->GetChild(i));
	}
	delete n;
}

CalcNode *Calculator::NodeToCalcNode(Node *n)
{
	CalcNode *calc_n = new CalcNode(n->GetType(), n->GetValue());
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		calc_n->AddChild(NodeToCalcNode(n->GetChild(i)));
	}
	return calc_n;
}

int Calculator::CalcDepth(Node *n, const int d) const {
	int depth = d + 1;
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		int tmp = CalcDepth(n->GetChild(i), d + 1);
		depth = (tmp > depth ? tmp : depth);
	}
	return depth;
}

void Calculator::PrintResLvl(CalcNode *n, int max_depth, int curr_depth) {
	if (curr_depth + 1 == max_depth) {
		for (int i = n->GetChildrenSize()-1; i >= 0; i--) {
			CalcNode *child = n->GetChild(i);
			if (child->GetAct() == "*" || child->GetAct() == "+") {
				n->SetAct(child->GetAct());
			}
			if (child->GetValue() == "*" || child->GetValue() == "+") {
				n->SetAct(child->GetValue());
			}
			if (!child->GetNum().isNull()) {
				if (n->GetNum().isNull()) {
					n->SetNum(child->GetNum());
				} else {
					if (n->GetAct() == "*") {
						int mult = n->GetNum().toInt() * child->GetNum().toInt();
						n->SetNum(QString::number(mult));
					} else {
						int sum = n->GetNum().toInt() + child->GetNum().toInt();
						n->SetNum(QString::number(sum));
					}
					n->SetAct(QString());
				}
			}
			if (child->GetType() == "\"NUM\"") {
				n->SetNum(child->GetValue());
			}
		}
	} else {
		for (int i = 0; i < n->GetChildrenSize(); i++) {
			PrintResLvl(n->GetChild(i), max_depth, curr_depth+1);
		}
	}
}
void Calculator::PrintRes(Node *res) {
	int depth = CalcDepth(res);
	root = NodeToCalcNode(res);
	for (int i = depth-1; i >= 0; i--) {
		PrintResLvl(root, i, 0);
	}
	std::cout << root->GetNum().toInt() << std::endl;
}
