#pragma once
#include <string>
#include <exception>

class Exception : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Lexer error";
    }
};

class LexerExceptionIncorrectChar : public Exception {
public:
    LexerExceptionIncorrectChar(const int line, const int pos) {
        err_str = "Input incorrect character in line "
                + std::to_string(line) + ", in pos "
                + std::to_string(pos);
    }
    virtual const char* what() const throw()  {
        return err_str.c_str();
    }
public:
    std::string err_str;
};

class ParserExceptionIncorrectTerminal : public Exception {
public:
    ParserExceptionIncorrectTerminal(const std::string tok_type, const int tok_pos) {
        err_str = "Input incorrect token, token type = \"" + tok_type
                + "\" ; tok_pos = " + std::to_string(tok_pos);

    }
    virtual const char* what() const throw() {
        return err_str.c_str();
    }
public:
    std::string err_str;
};

class ParserExceptionErrorRule : public Exception {
public:
    ParserExceptionErrorRule(const std::string tok_type, const int rule, const int tok_pos) {
	err_str = "Error rule, term type = \"" + tok_type + "\" ; state num = \""
		+ std::to_string(rule) + "\" ; term_pos = " + std::to_string(tok_pos);
    }
    virtual const char* what() const throw() {
        return err_str.c_str();
    }
public:
    std::string err_str;

};

class ParserExceptionEOP : public Exception {
public:
    ParserExceptionEOP(const std::string tok_type, const int tok_pos) {
        err_str = "Error term type = \"" + tok_type + "\" ; term_pos = " + std::to_string(tok_pos);
    }
    virtual const char* what() const throw() {
        return err_str.c_str();
    }
public:
    std::string err_str;

};

class TableExceptionAxiom : public Exception {
public:
    TableExceptionAxiom(const std::string str) {
        if (str.size()) {
            err_str = "2 or more axioms error : " + str;
        } else {
            err_str = "None axiom error";
        }
    }
    virtual const char* what() const throw() {
        return err_str.c_str();
    }
public:
    std::string err_str;

};

class TableExceptionNterm : public Exception {
public:
    TableExceptionNterm(const std::string nterm) {
        err_str = "Error : nterm = " + nterm + " not used";
    }
    virtual const char* what() const throw() {
        return err_str.c_str();
    }
public:
    std::string err_str;

};
