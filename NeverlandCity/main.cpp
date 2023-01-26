#include <iostream>
#include <fstream>
#include "NeverLand.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Program Argument are Missing" << std::endl;
        exit(-1);
    }
    NeverLand ds;
    try {
        for (int i = 1; i < argc - 1; i++) {
            ds.readInput(argv[i]);
        }

    } catch (const char *e) {
        std::cerr << e << std::endl;
    }
    // Write into the Output File
    std::ofstream outfile;
    outfile.open(ds.getoutputFileName());
    outfile << ds;
    outfile.close();

    ds.getInputFromUser();
    return 0;
}






