#include "IOManager.hpp"
#include "Database.hpp"
#include "Sequence.hpp"


#include <iostream> // teste

int main(int argc, char *argv[]) {

    IOManager io;
    if (argc != 5) {
        io.show_usage();
        return 1;
    }
    std::string db_filename, seq_filename;
    bool parsed_db = false;
    bool parsed_seq = false;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            io.show_usage();
            return 0;
        } else if ((arg == "-d") || (arg == "--database")) {
            if (i + 1 < argc) {
                db_filename = argv[++i];
                parsed_db = true;
            }
        } else if ((arg == "-s") || (arg == "--sequence")) {
            if (i + 1 < argc) {
                seq_filename = argv[++i];
                parsed_seq = true;
            }
        }
    }
    if (parsed_db && parsed_seq) {
        Database db;
        if (!db.read_database(db_filename)) {
            io.error(1);
            return 1;
        }
        Sequence seq;
        if (!seq.read_sequence(seq_filename)) {
            io.error(2);
            return 1;
        }

        auto qntd_strs = seq.count_strs(db.get_strs());
        io.print_result(db.check_match(qntd_strs));

    } else {
        io.show_usage();
    }

}
