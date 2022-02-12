#include <fstream>
#include "Sequence.hpp"

bool Sequence::read_sequence(std::string filename) {

    std::ifstream file {filename};

    if (!file.is_open())
        return false;

    m_sequence = "";
    char c;
    while (file >> std::skipws >> c) {
        if (c != 'A' && c != 'T' && c != 'C' &&  c != 'G')
            return false;
        m_sequence += c;
    }
    return true;
}
