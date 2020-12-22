#include "calculator.h"
#include "node.h"
#include <iostream>

Calculator::Calculator()
{
}

int Calculator::CalcDepth(Node *n, const int d) const {
    int depth = d + 1;
    for (int i = 0; i < n->GetChildrenSize(); i++) {
        int tmp = CalcDepth(n->GetChild(i), d + 1);
        depth = (tmp > depth ? tmp : depth);
    }
    return depth;
}

void Calculator::PrintResLvl(Node *n, int max_depth, int curr_depth) {
    if (curr_depth + 1 == max_depth) {
        for (int i = n->GetChildrenSize()-1; i >= 0; i--) {
            if (n->GetChild(i)->GetAct() == "*" || n->GetChild(i)->GetAct() == "+") {
                n->SetAct(n->GetChild(i)->GetAct());
            }
            if (n->GetChild(i)->GetValue() == "*" || n->GetChild(i)->GetValue() == "+") {
                n->SetAct(n->GetChild(i)->GetValue());
            }
            if (!n->GetChild(i)->GetNum().isNull()) {
                if (n->GetNum().isNull()) {
                    n->SetNum(n->GetChild(i)->GetNum());
                } else {
                    if (n->GetAct() == "*") {
                        int mult = n->GetNum().toInt() * n->GetChild(i)->GetNum().toInt();
                        n->SetNum(QString::number(mult));
                    } else {
                        int sum = n->GetNum().toInt() + n->GetChild(i)->GetNum().toInt();
                        n->SetNum(QString::number(sum));
                    }
                    n->SetAct(QString());
                }
            }
	    if (n->GetChild(i)->GetType() == "\"NUM\"") {
                n->SetNum(n->GetChild(i)->GetValue());
            }
        }
    } else {
        for (int i = 0; i < n->GetChildrenSize(); i++) {
            PrintResLvl(n->GetChild(i), max_depth, curr_depth+1);
        }
    }
}
void Calculator::PrintRes(Node *res) {
    int depth = CalcDepth(res, 0);
    for (int i = depth-1; i >= 0; i--) {
        PrintResLvl(res, i, 0);
    }
    std::cout << res->GetNum().toInt() << std::endl;
}
