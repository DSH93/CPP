//
// Created by Dor Shukrun on 21/01/2023.
//

#ifndef NEVERLANDCITY_NEVERLAND_H
#define NEVERLANDCITY_NEVERLAND_H

#include "Graph.h"

using namespace std;

class NeverLand {
private:
    map<string, int> legend;
    map<int, string> legendByIntKeys;

    string outputFileName;
    Graph traffic;
    int counter;

public:
    NeverLand();

    //The function receives the name of a file and reads from it the source,
    // destination and weight of each edge and adds it to the graph
    bool readInput(const string &fileName);

    //"The function accepts an input of a string, representing the name of a public transportation station.
    // It then seamlessly creates a comprehensive index, which includes both the station's name and number,
    // before seamlessly incorporating it into the graphical representation of the station network."
    int add(const string &cityName);

    //After receiving and processing the information,
    // the user can receive information about public transportation
    void getInputFromUser();

    //The name of the output file may change, depending on the arguments of the program,
    // the function returns the name of the relevant file
    string getoutputFileName();

    friend std::ostream &operator<<(std::ostream &stream, NeverLand &neverLand);

};


#endif //NEVERLANDCITY_NEVERLAND_H
