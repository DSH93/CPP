#include <iostream>
#include <fstream>
#include <valarray>
#include "GenerationsRace.h"
#include "noProblem/Queue.h"

int getVrSize(char *argv[]) {
    string configFile = argv[1];
    ifstream file;
    file.open(configFile);
    if (file.fail()) {
        cerr << "Invalid input." << endl;
        exit(-1);
    }
    string ss;
    getline(file, ss);
    int virusSize = stoi(ss);
    file.close();
    return virusSize;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: run the program with <init file name> <location file name>" << std::endl;
        exit(-1);
    }
    int vrs = getVrSize(argv);
    GenerationsRace gs(argv, vrs);
    gs.start();

    return 0;
}

