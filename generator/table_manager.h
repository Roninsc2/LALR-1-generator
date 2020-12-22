#pragma once
#include <QString>
#include <QVector>
#include <QSet>
#include <QMap>

class Grammar;

struct Node;
typedef QMap<QString, QMap<QString, QVector<QString>>> MapRules;

class TableManager {
public:
    TableManager();
    void ReadRules(QString f_name, QString &axiom,
                   QSet<QString> &terms, MapRules &rules_table,
                   QString &end, QString &e);
    Grammar SetupGrammar(Node *main, const QString &lex_file);
private:
    void CreateAxiom(Node *n);
    void CreateNotTerms(Node *n);
    void CreateTerms(Node *n);
    void CreateRules(Node *n);
    void ParseRule(Node *n);
    void ParseRightRulePart(Node *n,  QVector<QVector<QString>> &rules);
    void ParseTerm(Node *n, QVector<QString> &rules);
private:
    QSet<QString> terms;
    QSet<QString> nterms;
    QString axiom;
    QMap<QString, QVector<QVector<QString>>> rulesArray;
};

