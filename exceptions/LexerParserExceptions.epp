#ifndef LEXERPARSEREXCEPTIONS_EPP
# define LEXERPARSEREXCEPTIONS_EPP
# include <exception>

class UnknownCommandException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Unknown instruction";
    }
};

class UnknownTypeException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Unknown type";
    }
};

class BadValueException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Bad value";
    }
};

class SyntaxErrorException : public std::exception {//
public:
    virtual const char *what() const throw(){
        return "Syntax Error";
    }
};

class MissingExitException : public std::exception {//
public:
    virtual const char *what() const throw(){
        return "No exit at the end of the program";
    }
};

class CommandAfterExitException : public std::exception {//
public:
    virtual const char *what() const throw(){
        return "Exit must be the last command";
    }
};
#endif