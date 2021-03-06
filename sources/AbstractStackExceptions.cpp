#ifndef ABSTRACTSTACKEXCEPTIONS_EPP
# define ABSTRACTSTACKEXCEPTIONS_EPP
# include <exception>

class EmptyStackException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "The stack is empty";
    }
};

class AssertFailException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "The assertion failed";
    }
};

class StackTooShortException : public std::exception {//
public :
    virtual const char *what() const throw(){
        return "The stack needs two elements to proceed to this operation";
    }
};

class NotPrintableException : public std::exception {//
public :
    virtual const char *what() const throw(){
            return "Not an Int8 : cannot print";
    }
};
#endif