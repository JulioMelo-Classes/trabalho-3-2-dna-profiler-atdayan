#include <algorithm>
#include <fstream>
#include "Sequence.hpp"

#include <iostream> // teste

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

int count_substring(std::string sequence, std::string str) {
    int width = str.length();

    int counter = 0;

    for (int i = 0; i < sequence.length() - width; i++) {
        int start = i;
        int end = i + width;
        int window_pos = 0;
        bool ok = true;

        for (int j = start; j < end; j++) {
            if (sequence[j] != str[window_pos]) {
                ok = false;
                break;
            }
            ++window_pos;
        }
        if (ok)
            counter++;
    }
    return counter;
}

std::vector<int> Sequence::count_strs(std::vector<std::string> &str_list) {
    std::vector<int> counter_strs;
    counter_strs.reserve(str_list.size());

    for (auto &s : str_list)
        counter_strs.emplace_back(count_substring(m_sequence, s));

    return counter_strs;
}
