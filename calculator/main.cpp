#include <iostream>
#include <QCoreApplication>
#include <QCommandLineParser>
#include "parser.h"
#include "lex_pars_exeption.h"
#include "calculator.h"

int main(int argc, char *argv[]) {

	QCoreApplication app(argc, argv);
	QStringList arguments;
	QCommandLineParser parser;
	QString input_problem;
	int i;
	for (i = 0; i < app.arguments().size(); i++) {
		arguments.append(app.arguments().at(i));
	}

	parser.addHelpOption();
	parser.addOptions({
				  {{"i", "input"}, "input problem", "val"},
			  });
	parser.process(arguments);

	if (parser.value("i").isEmpty()) {
		std::cerr << "Incorrect input params, use --help\n";
	}

	input_problem = parser.value("i");

	try {
		Parser p(input_problem);
		Calculator c;
		c.PrintRes(p.GetTree());
	} catch (Exception* e) {
		std::cerr << e->what() << std::endl;
		delete e;
	}
	return 0;
}
