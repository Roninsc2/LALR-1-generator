#include "grammarsymbol.h"
#include <QRegularExpression>

GrammarSymbol::GrammarSymbol() {}

GrammarSymbol::GrammarSymbol(const QString &sym,
			     SymbolType type)
{
	symbol = sym;
	sym_type = type;
}

GrammarSymbol::GrammarSymbol(const QString &sym,
			     const QString &re,
			     SymbolType type)
{
	symbol = sym;
	reg_exp = std::shared_ptr<QRegularExpression>(new QRegularExpression(re));
	sym_type = type;
}

GrammarSymbol::GrammarSymbol(const QString &sym,
			     QVector<QVector<GrammarSymbol *> > pr,
			     SymbolType type)
{
	symbol = sym;
	production = pr;
	sym_type = type;
}

GrammarSymbol::~GrammarSymbol()
{
}

void GrammarSymbol::AddProduction(QVector<GrammarSymbol*> prod)
{
	production.push_back(prod);
}

QVector<QVector<GrammarSymbol*>> *GrammarSymbol::GetProd()
{
	return &production;
}

void GrammarSymbol::SetRegExp(QString re)
{
	reg_exp = std::shared_ptr<QRegularExpression>(new QRegularExpression(re));
}

bool GrammarSymbol::Eq(const QString &sym)
{
	return sym == symbol;
}

QRegularExpression *GrammarSymbol::GetRegExp()
{
	return reg_exp.get();
}

QString GrammarSymbol::GetRegExpSym()
{
	return reg_exp->pattern();
}

SymbolType GrammarSymbol::GetType() const
{
	return sym_type;
}

QString GrammarSymbol::GetSymbol() const
{
	return symbol;
}

