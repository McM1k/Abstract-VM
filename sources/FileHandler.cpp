
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
void FileHandler::readStdIn() {
    std::string str;

    while(getline(std::cin, str) && str != ";;") {
        try {
            this->_parser.parseLine(str);
        } catch (const std::exception e) {
            e.what();
        }
    }
}

void FileHandler::stockLines(std::istream is) {
    std::string str;
    std::list<std::string> lines;

    while(getline(is, str)){
        lines.push_back(str);
    }

    while(lines.at(0)) {
        try {
            this->_parser.parseLine(lines.at(0));
        } catch (const std::exception e) {
            e.what();
        }
        lines.pop_front();
    }
}


/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/