#pragma once
#include <QString>
#include <QVector>
#include <QRegularExpression>
#include <QFile>
#include <QSet>
#include <QMap>
#include "grammarsymbol.h"

struct Token;

class Lexer {

public:
	Lexer();
	Lexer(const QString &codeFile);
	~Lexer();
	void PrintTokens();
	void Next(int &i);
	Token GetToken(const int i) const;
	int GetTokensSize() const;
private:
	void ReadCodeFile(const QString &codeFile);
	void ParseFile();
	bool IsIgnore(QString type);
	void UpdatePos(QString type, int offset);
	bool ParseRegExp();
private:
	QVector<Token> tokens;
	QString code;
	QVector<GrammarSymbol*> regExpStates;
	GrammarSymbol *new_line;
	GrammarSymbol *space_tab;
	int pos = 0;
	int line = 0;
	int filePos;
	bool error = false;
};
