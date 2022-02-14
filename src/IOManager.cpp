#include <iostream>
#include "IOManager.hpp"

void IOManager::print_result(std::string result) {
    std::cout << result << "\n";
}

void IOManager::error(int code) {
    switch (code) {
        case 1:
            std::cerr << "DNA database file not found, "
                << "corrupted, or not a CSV file." << std::endl;
            break;
        case 2:
            std::cerr << "DNA sequence file not found or corrupted." << std::endl;
    }
}

void IOManager::show_usage() {
    std::cerr << "DNA Profiler Tool.\n\nUsage:\n"
        << "  dna_profiler [-d | --database] <database> [-s | --sequence] <sequence>\n"
        << "  dna_profiler -h | --help\n"
        << "\nArguments:\n"
        << "  <database>  The DNA database file, in CSV format.\n"
        << "  <sequence>  The DNA sequence file you wish to identify (find a match for).\n"
        << std::endl;
}
