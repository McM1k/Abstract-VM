
#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

# include <iostream>
# include <fstream>
# include <list>

# include "Parser.hpp"

class FileHandler{
public:
    FileHandler(void);
    FileHandler(FileHandler const &src);
    virtual ~FileHandler(void);
    FileHandler &operator=(FileHandler const &rhs); //equals

    void stockLines(std::ifstream& ifs);
    void readStdIn();

private:
    Parser                  _parser;


};

#endif