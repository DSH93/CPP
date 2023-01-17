//
// Created by Dor Shukrun on 21/12/2022.
//

#ifndef HW3_VIRUSPOPU_H
#define HW3_VIRUSPOPU_H
#include "noProblem/Queue.h"
#include "Virus.h"

class VirusPopu {
private:
    int virusSize;
    Virus **virusArray; // Array of Viruses
    Queue<Virus> virusQueue;
    int *familyArray;
    int dim;
    bool isZero;
    Virus *theBest;


public:
    VirusPopu(int vSize, int dim);

    VirusPopu();

    void sort(); // sort the array of viruses

    void updatePopu(); // groupUpdate

    void add();   // groupUpdate

    void missionCompleted();

    bool isMissionCompleted() const;

    void setPopVirus(Virus *v, int index); // Set Virus in The Virus Array

    friend ostream &operator<<(std::ostream &stream, VirusPopu &vP);

    int *getFamilyArray();

    Virus* getTheBest();

    void theBestUpdate();

    Virus **getVArray();

};


#endif //HW3_VIRUSPOPU_H
