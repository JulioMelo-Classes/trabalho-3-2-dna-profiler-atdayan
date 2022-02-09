#include "IOManager.hpp"
#include "Database.hpp"

int main(int argc, char *argv[]) {

    IOManager io;
    if (argc < 2)
        return io.error(0);

    Database db;
    if (!db.read_database(argv[2]))
        return io.error(1);

    //Sequence seq;
    //if (!seq.read_sequence(argv[4]))
    //    return io.error(2);

    io.print_result("Teste IO");
}
