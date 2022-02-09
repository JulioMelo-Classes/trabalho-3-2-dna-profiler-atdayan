#include <fstream>
#include "Database.hpp"
#include <iostream>

bool Database::read_database(std::string filename) {
    std::ifstream file {filename};
    int dot_pos = filename.find_last_of(".");
    if (filename.substr(dot_pos+1) != "csv") {
        std::cout << "not a csv file\n";
        return false;
    }

    if (file.is_open()) {
        // getline(file, line, ',')...
        // Não deu pra fazer a tempo pro checkin
        return true;
    }
    return false;
}
