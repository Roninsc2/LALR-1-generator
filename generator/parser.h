#pragma once
#include <QString>
#include "lexer.h"
#include "node.h"
#include <QMap>
#include <QSet>
#include <QStack>

class Parser {
public:
	Parser();
	Parser(const QString &code);
	~Parser();
	void Print();
	Node* GetTree();
private:
	void Parse();
	void FreeNodes(Node *n);
	void PrintLvl(Node *n, int d, int c);
	int CalcDepth(Node *n, const int d) const;
private:
	int res;
	QStack<Node*> nodes_stack;
	QStack<int> rules_stack;
	QSet<GrammarSymbol*> terms;
	Lexer lex;
};
