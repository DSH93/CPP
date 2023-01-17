//
// Created by Dor Shukrun on 21/12/2022.
//

#include <sstream>
#include <fstream>
#include <valarray>
#include "GenerationsRace.h"

GenerationsRace::GenerationsRace(char *argv[], int size) {
    this->virusSize = size;
    this->generations = 1000000; // 10^6 max
    this->pm = 0;
    this->argv = argv;
    this->targetVirus = new int[virusSize];
    for (int i = 0; i < virusSize; ++i) {
        targetVirus[i] = 0;
    }

}

void GenerationsRace::start() {
    ReadInputs();
    for (int i = 0; i < generations; i++) {
//        if (pm == 0) {
//            theFirst.updatePopu();
//            continue;
//        }

        if (theFirst.isMissionCompleted()) {
            break;
        }

        theFirst.sort(); // sort the array of viruses
        theFirst.add(); // groupUpdate
        theFirst.updatePopu(); // private UpDate for all The Viruses
        theFirst.theBestUpdate();


    }
    theFirst.sort();
    theFirst.theBestUpdate();
    cout << theFirst << endl;
    cout << *theFirst.getTheBest();
    delete theFirst.getFamilyArray();
    delete theFirst.getVArray();


}

string GenerationsRace::split(string &line) {
    istringstream ss(line);
    string del;
    getline(ss, del, ' ');
    return del;

}

void GenerationsRace::ReadInputs() {
    string configFile = argv[1];
    string firstGenFile = argv[2];
    int number;
    std::cin >> number;
    this->generations = number;
    ifstream file;
    file.open(configFile);
    if (file.fail()) {
        cerr << "Invalid input." << endl;
        exit(-1);
    }
    int counter = 0;
    string ss;

    while (getline(file, ss)) {
        if (counter == 0) {
            virusSize = stoi(ss);
            counter++;
            continue;
        }
        if (counter == 1) {
            this->pm = stoi(ss);
            counter++;
            continue;

        }
        if (counter == 2) {
            targetVirus = new int[virusSize];
            stringstream stream(ss);
            for (int j = 0; j < virusSize; j++) {
                int n;
                stream >> n;
                targetVirus[j] = n;
            }
            counter++;
            continue;
        }
        if (counter > 2) break;

    }
    file.close();
    ifstream fileGen;
    fileGen.open(firstGenFile);
    if (fileGen.fail()) {
        cerr << "Invalid input." << endl;
        exit(-1);
    }

    getline(fileGen, ss);
    dim = stoi(ss);
    VirusPopu v = *new VirusPopu(virusSize, dim);
    int index = 0;
    while (getline(fileGen, ss)) {
        string name;
        name = split(ss);
        auto *virus = new Virus(name, 0, pm, targetVirus, virusSize, index, v.getFamilyArray());
        int sizeName;
        sizeName = (int) name.size();
        string virusArrayInString;
        virusArrayInString = ss.substr(sizeName + 1);

        if(virusArrayInString.size() != virusSize*2){
            cerr << "Invalid input." << endl;
            exit(-1);
        }


        stringstream stream(virusArrayInString);


        int indexCounter = 0;
        for (; indexCounter < virusSize;) {
            int n;
            stream >> n;
            virus->setVirus(indexCounter, n);
            indexCounter++;
        }
        v.setPopVirus(virus, index);
        index++;
    }

    this->theFirst = v;
    fileGen.close();
}

