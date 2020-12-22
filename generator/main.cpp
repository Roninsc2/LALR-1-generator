#include <iostream>
#include <QCoreApplication>
#include <QCommandLineParser>
#include "parser.h"
#include "lex_pars_exeption.h"
#include "table_manager.h"
#include "grammar.h"
#include "grammarlrone.h"

int main(int argc, char *argv[]) {

	QCoreApplication app(argc, argv);
	QStringList arguments;
	QCommandLineParser parser;
	QString input_grammar;
	QString output;
	QString lex_file;
	int i;
	for (i = 0; i < app.arguments().size(); i++) {
		arguments.append(app.arguments().at(i));
	}

	parser.addHelpOption();
	parser.addOptions({
				  {{"l", "lexconf"}, "lex config file", "val"},
				  {{"i", "input"}, "input grammar file", "val"},
				  {{"o", "output"}, "output file", "val"},
			  });
	parser.process(arguments);

	if (parser.value("l").isEmpty() || parser.value("i").isEmpty() ||
			parser.value("o").isEmpty()) {
		std::cerr << "Incorrect input params, use --help\n";
	}

	input_grammar = parser.value("i");
	output = parser.value("o");
	lex_file = parser.value("l");

	try {
		Parser p(input_grammar);;
		TableManager t;
		Grammar gr = t.SetupGrammar(p.GetTree(), lex_file);
		GrammarLROne lr_one(&gr);
		lr_one.Export(output);
	} catch (Exception* e) {
		std::cerr << e->what() << std::endl;
		delete e;
	}
	return 0;
}
