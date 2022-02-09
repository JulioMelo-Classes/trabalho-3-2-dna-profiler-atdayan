#include <iostream>
#include "IOManager.hpp"

int IOManager::error(int code) {
    switch (code) {
        case 0:
            std::cerr << "Usage: dna_profiler -d <database_file> -s <dna_sequence_file>\n\t"
                "Where the arguments are:\n\t"
                "<database_file>     The DNA database file, in CSV format.\n"
                "<dna_sequence_file> The DNA sequence file you wish to identify (find a match for).\n";
            break;
        case 1:
            std::cerr << "DNA database file not found, corrupted, or not a CSV file.\n";
            break;
        case 2:
            std::cerr << "DNA sequence file not found or corrupted.\n";
    }
    return EXIT_FAILURE;
}

void IOManager::print_result(std::string result) {
    std::cout << result << "\n";
}
