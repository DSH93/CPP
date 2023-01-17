//
// Created by Dor Shukrun on 21/12/2022.
//
#include "VirusPopu.h"


VirusPopu::VirusPopu(int vSize, int dim) {
    this->virusArray = new Virus *[dim];
    this->virusQueue = *new Queue<Virus>(dim);
    this->dim = dim;
    this->virusSize = vSize;
    this->isZero = false;
    this->familyArray = new int[virusSize];
    for (int i = 0; i < virusSize; ++i) {
        familyArray[i] = 0;
    }
    this->theBest = nullptr;



}

VirusPopu::VirusPopu() {
    this->virusArray = nullptr;
    this->virusQueue = *new Queue<Virus>();
    this->dim = 0;
    this->virusSize = 0;
    this->isZero = false;
    this->familyArray = nullptr;
    this->theBest = nullptr;

}

void VirusPopu::sort() {
    virusQueue.queueSort();

}

void VirusPopu::updatePopu() {
    for (int i = 0; i < dim; i++) {

        this->virusQueue.getValByIndex(i)->updateVirus();
    }
}

void VirusPopu::setPopVirus(Virus *v, int index) {
    this->virusQueue.setValByIndex(*v,index);
}

void VirusPopu::add() {
    sort();
    Virus *v = virusQueue.peak();
    virusQueue.removeAndAddByPriority(papiloma,v);
}

void VirusPopu::missionCompleted() {
    isZero = true;
}

bool VirusPopu::isMissionCompleted() const {
    return isZero;
}

std::ostream &operator<<(std::ostream &stream, VirusPopu &vP) {
    for (int i = 0; i < vP.dim; i++) {
        stream << *(vP.virusArray[i]);
    }
    return stream;
}

int* VirusPopu::getFamilyArray(){
    return familyArray;
}

Virus* VirusPopu::getTheBest(){
    return this->theBest;
}

void VirusPopu::theBestUpdate(){
    if(this->theBest == nullptr) theBest = new Virus(*(virusQueue.getValByIndex(0)));
    if(virusQueue.getValByIndex(0)->getErrorTarget() < theBest->getErrorTarget()){
        theBest = virusQueue.getValByIndex(0);
    }
}

Virus** VirusPopu::getVArray(){
    return this->virusArray;
}







