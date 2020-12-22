#include "table_manager.h"
#include "node.h"
#include <QFile>
#include "lex_pars_exeption.h"
#include "grammar.h"

TableManager::TableManager() {
}

Grammar TableManager::SetupGrammar(Node *main, const QString &lex_file)
{
	CreateAxiom(main->GetChild(0));
	CreateNotTerms(main->GetChild(1));
	CreateTerms(main->GetChild(2));
	CreateRules(main->GetChild(3));
	Grammar gr(rulesArray, axiom, terms, nterms, lex_file);
	return gr;
}

void TableManager::CreateAxiom(Node *n) {
	axiom = n->GetChild(1)->GetValue();
}

void TableManager::CreateNotTerms(Node *n) {
	n = n->GetChild(0);
	while (n->GetChildrenSize() > 1) {
		nterms.insert(n->GetChild(0)->GetValue());
		n = n->GetChild(1);
	}
	nterms.insert(n->GetChild(0)->GetValue());
	nterms.insert(axiom);
}


void TableManager::CreateTerms(Node *n) {
	n = n->GetChild(0);
	while (n->GetChildrenSize() > 1) {
		terms.insert(n->GetChild(0)->GetValue());
		n = n->GetChild(1);
	}
	terms.insert(n->GetChild(0)->GetValue());
}

void TableManager::CreateRules(Node *n) {
	while (n->GetChildrenSize() > 1) {
		ParseRule(n->GetChild(0));
		n = n->GetChild(1);
	}
	ParseRule(n->GetChild(0));
}

void TableManager::ParseRule(Node *n) {
	QString nterm = n->GetChild(0)->GetValue();
	QVector<QVector<QString>> rules;
	ParseRightRulePart(n->GetChild(2)->GetChild(0), rules);
	if (n->GetChild(2)->GetChildrenSize() == 3) {
		n = n->GetChild(2);
		ParseRightRulePart(n->GetChild(2)->GetChild(0), rules);
	}
	rulesArray[nterm] = rules;
}

void TableManager::ParseRightRulePart(Node *n, QVector<QVector<QString>> &rules) {
	QVector<QString> rule;
	while (n->GetChildrenSize() > 1) {
		ParseTerm(n->GetChild(0), rule);
		n = n->GetChild(1);
	}
	ParseTerm(n->GetChild(0), rule);
	rules.push_back(rule);
}

void TableManager::ParseTerm(Node *n, QVector<QString> &rule) {
	rule.push_back(n->GetChild(0)->GetValue());
}
