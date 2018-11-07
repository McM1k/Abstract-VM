
#ifndef FILEHANDLER_HPP
# define FILEHANDLER_HPP

# include <iostream>
# include <list>

class FileHandler{
public:
    FileHandler(void);
    FileHandler(FileHandler const &src);
    virtual ~FileHandler(void);
    FileHandler &operator=(FileHandler const &rhs); //equals



private:
    std::list<std::string> _lines;

};

std::ostream &operator<<(std::ostream &o, FileHandler const &i);


#endif