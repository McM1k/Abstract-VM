#ifndef OPERANDEXCEPTIONS_EPP
# define OPERANDEXCEPTIONS_EPP
# include <exception>

class OverFlowException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Overflowing resulting operand";
    }
};

class UnderFlowException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Underflowing resulting operand";
    }
};

class FloatOnIntException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Can't create an Integer operand with a float value";
    }
};

class DivideByZeroException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Dividing by zero";
    }
};

class ModOnFloatException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "Can't obtain a modulo on an non-euclidian division";
    }
};
#endif