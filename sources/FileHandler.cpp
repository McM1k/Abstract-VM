
#include "../includes/FileHandler.hpp"
#include <iostream>

/****************************************************************************
 * Constructors * Constructors * Constructors * Constructors * Constructors *
 ****************************************************************************/
FileHandler::FileHandler(void) {
    //std::cout << "An instance of FileHandler has been created" << std::endl;
}

FileHandler::FileHandler(FileHandler const &src) {
    //std::cout << "An instance of FileHandler has been created by copy" << std::endl;
    *this = src;
}

/***********************************************************************
 * Destructors * Destructors * Destructors * Destructors * Destructors *
 ***********************************************************************/
FileHandler::~FileHandler(void) {
    //std::cout << "An instance of FileHandler has been destroyed" << std::endl;
}

/***********************************************************************
 * Getters * Getters * Getters * Getters * Getters * Getters * Getters *
 ***********************************************************************/

/***********************************************************************
 * Setters * Setters * Setters * Setters * Setters * Setters * Setters *
 ***********************************************************************/

/*************************************************************************
 * Operators * Operators * Operators * Operators * Operators * Operators *
 *************************************************************************/
FileHandler &FileHandler::operator=(FileHandler const &rhs) {
    if (this != &rhs) {
        //this->XXX = rhs.getXXX();
    }
    return *this;
}

/******************************************************************************
 * ToString * ToString * ToString * ToString * ToString * ToString * ToString *
 ******************************************************************************/
std::ostream &operator<<(std::ostream &o, FileHandler const &i) {
    o << "no attributes" << std::endl;
    return o;
}

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
std::list<std::string> FileHandler::stockLines(file) {
    std::string str;
    std::list<std::string> lines;

    while (getline(file.firstLine, str)){

    }
}

std::list<std::string> FileHandler::splitLines(std::istream is) {
    std::string str;
    std::list<std::string> lines;

    while(getline(is, str)){
        lines.push_back(str);
    }

    lines = this->_lines;
    return lines;
}


/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/