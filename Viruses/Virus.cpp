//
// Created by Dor Shukrun on 21/12/2022.
//

#include "Virus.h"

// Default constructor
Virus::Virus(string &name, int genSize, int pm, int target[], int virusSize, int familyIndex, int *familyArray) {
    this->virusSize = virusSize;
    this->virusTargetArray = target;
    this->virusArray = new int[virusSize];
    this->errorTarget = 1;
    this->name = name;
    this->genSize = genSize;
    this->pm = pm;
    for (int i = 0; i < virusSize; i++) {
        virusArray[i] = 0;
    }
    this->familyArray = familyArray;
    this->indexF = familyIndex;
    this->familySize = familyArray[indexF];


}

// Copy constructor
Virus::Virus(const Virus &other) {
    this->virusSize = other.virusSize;
    this->virusTargetArray = other.virusTargetArray;
    this->virusArray = other.virusArray;
    this->errorTarget = other.errorTarget;
    this->name = other.name;
    this->genSize = other.genSize;
    this->pm = other.pm;
    this->indexF = other.indexF;
    this->familySize = other.familySize;
    this->familyArray = other.familyArray;

    for (int i = 0; i < virusSize; i++) {
        this->virusArray[i] = other.virusArray[i];
    }

}


// Copy assignment operator
Virus &Virus::operator=(const Virus &other) {
    if (&other != this) {
        for (int i = 0; i < virusSize; i++) {
            this->virusArray[i] = other.virusArray[i];
        }
        this->indexF = other.indexF;
        this->familyArray = other.familyArray;
        this->genSize = familyArray[indexF] + 1;
        this->familyArray[indexF]++;

        this->name = other.name;
        this->pm = other.pm;
    }
    return *this;
}

// Move constructor
Virus::Virus(Virus &&other) noexcept {
    if (&other != this) {
        this->virusSize = other.virusSize;
        this->virusArray = other.virusArray;
        this->genSize = other.genSize;
        this->pm = other.pm;
        this->errorTarget = other.errorTarget;
        this->name = other.name;
        this->indexF = other.indexF;
        this->familySize = other.familySize;
        this->virusTargetArray = other.virusTargetArray;
        this->familyArray = other.familyArray;


        other.virusArray = nullptr;
        other.virusTargetArray = nullptr;
        other.familyArray = nullptr;

    }
}

// Destructor
Virus::~Virus() {}

Virus::Virus() {
    this->virusArray = nullptr;
    this->genSize = -1;
    this->name = "";
    this->pm = -1;
    this->virusTargetArray = nullptr;
    this->errorTarget = 1;
    this->virusSize = 0;
    this->familyArray = nullptr;
    this->familySize = 0;
    this->indexF = 0;

}

double Virus::getErrorTarget() {
    double counter = 0.0;
    for (int i = 0; i < this->virusSize; i++) {
        if (this->virusArray[i] != this->virusTargetArray[i]) counter++;
    }
    this->errorTarget = (counter / virusSize);
    return errorTarget;
}

void Virus::updateVirus() {
    int i, j;
    if (pm == 0) return;
    for (int k = 0; k < pm; k++) {
        i = rand() % virusSize;
        j = rand() % virusSize;
        int tmp = getValByIndex(i);
        setVirus(i, getValByIndex(j));
        setVirus(j, tmp);
    }
}

void Virus::setVirus(int index, int elem) {
    this->virusArray[index] = elem;
}

int Virus::getValByIndex(int index) {
    return this->virusArray[index];

}

ostream &operator<<(std::ostream &stream, Virus &v) {
    stream << v.name;
    if (v.genSize != 0) {
        stream << "_" << v.genSize;
    }
    stream << "\t";

    for (int i = 0; i < v.virusSize; i++) {
        stream << v.getValByIndex(i) << " ";
    }
    stream << endl;
    return stream;
}


