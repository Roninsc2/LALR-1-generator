#pragma once
#include <QString>
#include <QVector>
#include <QMap>
#include <memory>

enum SymbolType {
	SYMBOL_TERMINAL,
	SYMBOL_NON_TERMINAL,
	SYMBOL_START,
	SYMBOL_END,
	SYMBOL_EPS,
	SYMBOL_FREE
};

static const QMap<SymbolType, QString> type_to_str = {
	{SYMBOL_TERMINAL, "SYMBOL_TERMINAL"},
	{SYMBOL_NON_TERMINAL, "SYMBOL_NON_TERMINAL"},
	{SYMBOL_START, "SYMBOL_START"},
	{SYMBOL_END, "SYMBOL_END"},
};

class GrammarSymbol
{
public:
	GrammarSymbol();
	GrammarSymbol(const QString &sym, SymbolType type);
	GrammarSymbol(const QString &sym, const QString &re, SymbolType type);
	GrammarSymbol(const QString &sym, QVector<QVector<GrammarSymbol*>> production, SymbolType type);
	~GrammarSymbol();
	void AddProduction(QVector<GrammarSymbol*> prod);
	QVector<QVector<GrammarSymbol*>> *GetProd();
	void SetRegExp(QString re);
	bool Eq(const QString &sym);
	QRegularExpression *GetRegExp();
	QString GetRegExpSym();
	SymbolType GetType() const;
	QString GetSymbol() const;
private:
	QString symbol;
	QVector<QVector<GrammarSymbol*>> production;
	SymbolType sym_type;
	std::shared_ptr<QRegularExpression> reg_exp;
};
