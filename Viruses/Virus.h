//
// Created by Dor Shukrun on 21/12/2022.
//

#ifndef HW3_VIRUS_H
#define HW3_VIRUS_H

#include <iostream>
#include "noProblem/Queue.h"

using namespace std;

class Virus {
private:
    int virusSize;
    int *virusTargetArray;
    int *virusArray; // 4 < size < 101
    double errorTarget;
    string name;
    int genSize;
    int indexF;
    int familySize;
    int *familyArray;
    int pm;


public:
    Virus(string &name, int genSize, int pm, int *target, int virusSize, int familyIndex, int * familyArray);

    Virus(const Virus &other);

    Virus();

    Virus &operator=(const Virus &other);

    Virus(Virus &&other) noexcept;

    virtual ~Virus() = 0;

    double getErrorTarget();

    void updateVirus();

    void setVirus(int index, int elem);

    int getValByIndex(int index);

        friend ostream &operator<<(std::ostream &stream, Virus &virus);


};


#endif //HW3_VIRUS_H
