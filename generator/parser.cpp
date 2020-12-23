#include "parser.h"
#include "lex_pars_exeption.h"
#include <iostream>
#include "node.h"
#include "token.h"

Parser::Parser()
{
}

Parser::Parser(const QString &code)
	: lex(code)
{
	if (!lex.GetTokensSize()) {
		return;
	}
	Parse();
}

Node *Parser::GetTree()
{
	return nodes_stack.top();
}

Parser::~Parser() {
	FreeNodes(nodes_stack.top());
}


void Parser::FreeNodes(Node *n) {
	if (!n) {
		return;
	}
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		FreeNodes(n->GetChild(i));
	}
	delete n;
}

void Parser::Parse() {
	int it = 0;
	int jt = 0;
	rules_stack.push(0);
	Token current_term = lex.GetToken(it);
	QPair<GrammarAction, int> act;
	GrammarSymbol* pname;
	QVector<GrammarSymbol*> pbody;
	Node* new_node;
	while (it < lex.GetTokensSize()) {
		act = action[rules_stack.top()][current_term.GetType()];
		if (act.first == ACT_SHIFT) {
			nodes_stack.push_back(new Node(current_term));
			lex.Next(it);
			current_term = lex.GetToken(it);
			rules_stack.push(act.second);
		} else if (act.first == ACT_REDUCE) {
			pname = prods[act.second].first;
			pbody = prods[act.second].second;
			new_node = new Node(pname);
			for (jt = 0; jt < pbody.size(); jt++) {
				rules_stack.pop();
				new_node->AddChild(nodes_stack.pop());
			}
			nodes_stack.push(new_node);
			rules_stack.push(_goto[rules_stack.top()][pname]);
		} else if (act.first == ACT_ACCEPT) {
			break;
		} else {
			throw new ParserExceptionErrorRule(current_term.
							   GetType()->GetSymbol().
							   toStdString(),
							   rules_stack.top(),
							   it);
		}
	}
	if (it+1 < lex.GetTokensSize()) {
		throw new ParserExceptionEOP(current_term.
					     GetType()->GetSymbol().
					     toStdString(),
					     it);
	}
}

void Parser::Print() {
	int depth = CalcDepth(nodes_stack.top(), 0);
	for (int i = 0; i < depth; i++) {
		std::cout << "level " << i << " = ";
		PrintLvl(nodes_stack.top(), i, 0);
		std::cout << std::endl;
	}
}

void Parser::PrintLvl(Node *n, int max_depth, int curr_depth) {
	if (curr_depth == max_depth || !n->GetChildrenSize())
	{
		std::cout << n->GetType().toStdString() + " ";
		return;
	}
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		PrintLvl(n->GetChild(i), max_depth, curr_depth + 1);
	}
}

int Parser::CalcDepth(Node *n, const int d) const {
	int depth = d + 1;
	for (int i = 0; i < n->GetChildrenSize(); i++) {
		int tmp = CalcDepth(n->GetChild(i), d + 1);
		depth = (tmp > depth ? tmp : depth);
	}
	return depth;
}
