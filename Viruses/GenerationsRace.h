//
// Created by Dor Shukrun on 21/12/2022.
//

#ifndef HW3_GENERATIONSRACE_H
#define HW3_GENERATIONSRACE_H

#include "Virus.h"
#include "VirusPopu.h"


class GenerationsRace {
private:
    char **argv;
    int dim{};
    int virusSize;
    int generations; // 0 <= generations <= max 10^6 iterations
    int pm;
    VirusPopu theFirst;
    int *targetVirus;

public:
    explicit GenerationsRace(char *argv[], int size);

    void start();

    static string split(string &line);

    void ReadInputs();


};


#endif //HW3_GENERATIONSRACE_H
