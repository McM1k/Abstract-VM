#include "../includes/FileHandler.hpp"
#include <iostream>


int main (int ac, char ** av){
//    std::ifstream file;
    FileHandler fh;

    try {
        if (ac == 2) {
//            file.open(av[1]);
            fh.stockLines(av[1]);
        } else {
            fh.readStdIn();
        }
    }
    catch (const FileHandler::FailedToOpenException& e) { std::cerr << e.what() << std::endl; }
    catch (const MissingExitException& e)               { std::cerr << e.what() << std::endl; }
    catch (const std::exception& e)                     { std::cerr << e.what() << std::endl; }
    return 0;
}
