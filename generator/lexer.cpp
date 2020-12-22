#include "lexer.h"
#include "lex_pars_exeption.h"
#include <QFile>
#include "types.h"
#include "token.h"
#include "grammar_main.h"
#include <QDebug>

Lexer::Lexer()
{
}

Lexer::Lexer(const QString &codeFile)
{
	new_line = new GrammarSymbol("LINE_TERMINATOR",
				     SYMBOL_TERMINAL);
	new_line->SetRegExp("[\n\r]+");
	space_tab = new GrammarSymbol("SPACE_TAB",
				     SYMBOL_TERMINAL);
	space_tab->SetRegExp("[ \t]+");

	regExpStates = QVector<GrammarSymbol*>(terms.begin(), terms.end());
	regExpStates.push_back(new_line);
	regExpStates.push_back(space_tab);
	ReadCodeFile(codeFile);
	ParseFile();
}

Lexer::~Lexer()
{
	delete new_line;
	delete space_tab;
}

void Lexer::PrintTokens() {
	if (error) {
		qInfo() << "Error at  line, pos : " << line << pos;
		return;
	}
	for (int i = 0; i < tokens.size(); i++) {
		qInfo() << tokens.at(i).GetType() << tokens.at(i).GetPos() + " : " + tokens.at(i).GetValue();
	}
}

void Lexer::Next(int &i) {
	i++;
}

int Lexer::GetTokensSize() const {
	return tokens.size();
}

Token Lexer::GetToken(const int i) const {
	return (i < tokens.size() ? tokens.at(i) : tokens.last());
}

void Lexer::ReadCodeFile(const QString &codeFile) {
	QFile file(codeFile);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		return;
	}
	code = QString::fromStdString(file.readAll().toStdString());
	file.close();
}

void Lexer::ParseFile() {
	error = false;
	line = 1;
	pos = 1;
	filePos = 0;
	while (filePos < code.size()) {
		if (!ParseRegExp()) {
			throw new LexerExceptionIncorrectChar(line, pos);
		}
	}
	tokens.push_back(Token(&s1, QString(), pos, line));
}

bool Lexer::ParseRegExp() {
	QRegularExpressionMatch m;
	GrammarSymbol *r;
	bool correct = false;
	for (int i = 0; i < regExpStates.size(); i++) {
		r = regExpStates.at(i);
		m = r->GetRegExp()->match(code, filePos, QRegularExpression::NormalMatch,
				   QRegularExpression::AnchoredMatchOption);
		if (m.capturedStart() - filePos == 0) {
			int p = pos;
			int l = line;
			UpdatePos(r->GetSymbol(), m.captured().size());
			filePos += m.captured().size();
			correct = !IsIgnore(r->GetSymbol());
			if (correct) {
				tokens.push_back(Token(r, m.captured(), p, l));
				return correct;
			}
			correct = correct || IsIgnore(r->GetSymbol());
		}
	}
	return correct;
}

bool Lexer::IsIgnore(QString type) {
	return (type == "SPACE_TAB" || type == "LINE_TERMINATOR");
}

void Lexer::UpdatePos(QString type, int offset) {
	if (type == "LINE_TERMINATOR") {
		pos = 1;
		line += 1;
		return;
	}
	pos += offset;
}
