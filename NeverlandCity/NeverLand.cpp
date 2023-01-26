//
// Created by Dor Shukrun on 21/01/2023.
//

#include <fstream>
#include <sstream>
#include "NeverLand.h"

NeverLand::NeverLand() {
    // legend is initialized as an empty map
    // legendByKey is initialized as an empty map
    // Traffic is initialized as an empty Graph
    this->counter = 0;
    this->outputFileName = "output.dat"; // default name

}

//The function receives the name of a file and reads from it the source,
// destination and weight of each edge and adds it to the graph
bool NeverLand::readInput(const string &fileName) {
    int count, weightNumber, currentWeight;

    ifstream file(fileName);
    string fileData;
    if (file.is_open()) getline(file, fileData);
    else return false;
    file.close();


    std::istringstream iss(fileData);
    string source;
    string dist;
    string weight;
    count = 0;

    for (std::string s; iss >> s;) {
        if (s == "exit") {
            std::cerr << "Data - source / dist / weight = 'exit' " << std::endl;
            exit(-1);
        }
        if (s == "[-o]") {
            this->outputFileName = fileName;
            return false;
        }
        if (count == 0)source = s;
        if (count == 1) dist = s;
        if (count == 2) weight = s;
        count++;
    }

    weightNumber = stoi(weight);
    if (weightNumber < 0) throw "Invalid Weight Value";
    add(source);
    add(dist);

    int sourceNumber = legend[source];
    int disNumber = legend[dist];

    legendByIntKeys[sourceNumber] = source;
    legendByIntKeys[disNumber] = dist;

    currentWeight = traffic.getWeight(sourceNumber, disNumber);
    if (weightNumber > currentWeight && currentWeight > 0) weightNumber = currentWeight;

    traffic.updateWeight(sourceNumber, disNumber, weightNumber);
    return true;

}

//"The function accepts an input of a string, representing the name of a public transportation station.
// It then seamlessly creates a comprehensive index, which includes both the station's name and number,
// before seamlessly incorporating it into the graphical representation of the station network."
int NeverLand::add(const string &cityName) {
    if (legend.find(cityName) != legend.end()) return -1;
    counter++;
    int result = traffic.addVertex();
    legend[cityName] = result;
    legendByIntKeys[result] = cityName;
    return result;

}

//After receiving and processing the information,
// the user can receive information about public transportation
void NeverLand::getInputFromUser() {
    string sourceUserInput;
    while (true) {
        std::cin >> sourceUserInput;
        if (sourceUserInput == "exit") exit(-1);
        if (legend.find(sourceUserInput) == legend.end()) {
            std::cout << sourceUserInput << " " << "does not exist in the current network\nUSAGE: <node> or ‘exit’ to terminate\n";
            continue;
        }
        int source;
        source = legend[sourceUserInput];

        int howManyOptions = traffic.getNeighbors(source).size();
        if (howManyOptions == 0) {
            std::cout << sourceUserInput << " : " << "no outbound travel\n";
            continue;
        }

        std::cout << legendByIntKeys[source] << "\t";
        unsigned int count = 1;
        for (int value: traffic.getConnections(source)) {
            std::cout << legendByIntKeys[value];
            if (count != traffic.getConnections(source).size())
                std::cout << "\t";
            count++;
        }
        std::cout << std::endl;

    }
}

//The name of the output file may change, depending on the arguments of the program,
// the function returns the name of the relevant file
string NeverLand::getoutputFileName() {
    return this->outputFileName;
}

std::ostream &operator<<(std::ostream &stream, NeverLand &neverLand) {
    for (int i = 0; i < neverLand.counter; i++) {
        stream << neverLand.legendByIntKeys[i] << ":\t";
        unsigned int count = 1;
        for (int value: neverLand.traffic.getConnections(i)) {
            stream << neverLand.legendByIntKeys[value];
            if (count != neverLand.traffic.getConnections(i).size())
                stream << ", ";
            count++;
        }
        stream << std::endl;
    }
    return stream;

}