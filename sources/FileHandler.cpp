
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

/*************************************************************************
 * Other * Other * Other * Other * Other * Other * Other * Other * Other *
 *************************************************************************/
void FileHandler::readStdIn() {
    std::string str;

    while(getline(std::cin, str) && str != ";;") {
        try {
            this->_parser.parseLine(str);
        }
        catch (const BadValueException &e)          { std::cerr << e.what() << std::endl; }
        catch (const UnknownTypeException &e)       { std::cerr << e.what() << std::endl; }
        catch (const UnknownCommandException &e)    { std::cerr << e.what() << std::endl; }
        catch (const SyntaxErrorException& e)       { std::cerr << e.what() << std::endl; }
        catch (const CommandAfterExitException& e)  { std::cerr << e.what() << std::endl; }
        catch (const std::exception& e)             { std::cerr << e.what() << std::endl; }
    }
}

void FileHandler::stockLines(char *fileName) {
    std::ifstream file;
    std::string str;
    std::list<std::string> lines;

    file.open(fileName);
    if (!file.is_open()) { throw(FailedToOpenException()); }

    while(std::getline(file, str)){
        lines.push_back(str);
    }

    while(lines.size() > 0) {
        try {
            this->_parser.parseLine(lines.front());
        }
        catch (const BadValueException &e)          { std::cerr << e.what() << std::endl; }
        catch (const UnknownTypeException &e)       { std::cerr << e.what() << std::endl; }
        catch (const UnknownCommandException &e)    { std::cerr << e.what() << std::endl; }
        catch (const SyntaxErrorException& e)       { std::cerr << e.what() << std::endl; }
        catch (const CommandAfterExitException& e)  { std::cerr << e.what() << std::endl; }
        catch (const std::exception& e)             { std::cerr << e.what() << std::endl; }
        lines.pop_front();
    }
}


/*******************************************************************************
 * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions * Exceptions *
 *******************************************************************************/
 const char* FileHandler::FailedToOpenException::what() const throw(){
     return "Couldn't open file";
 }