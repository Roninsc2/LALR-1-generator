#pragma once
#include "node.h"

class Calculator
{
public:
    Calculator();
    void PrintRes(Node *node);
private:
    int CalcDepth(Node *n, const int d) const;
    void PrintResLvl(Node *n, int max_depth, int curr_depth);
};
