#include "../includes/FileHandler.hpp"
#include <iostream>


int main (int ac, char ** av){
    std::ifstream file;
    FileHandler fh;

    try {
        if ((ac == 2) & (file.open(av[1]))) {
            fh.stockLines(file);
        } else {
            fh.readStdIn();
        }
    } catch (const MissingExitException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const std::exception& e) {
        e.what();
    }
    return 0;
}
