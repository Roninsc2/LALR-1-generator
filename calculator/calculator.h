#pragma once

class Node;
class CalcNode;

class Calculator
{
public:
	Calculator();
	~Calculator();
	void PrintRes(Node *node);
private:
	void FreeNode(CalcNode * n);
	CalcNode *NodeToCalcNode(Node *n);
	int CalcDepth(Node *n, const int d = 0) const;
	void PrintResLvl(CalcNode *n, int max_depth, int curr_depth);
private:
	CalcNode *root;
};
