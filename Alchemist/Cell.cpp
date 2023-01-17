//
// Created by Dor Shukrun on 01/12/2022.
//

#include "Cell.h"

Cell::Cell(int row, int col) {
    this->row = row;
    this->col = col;
    this->currentStringState = 'O'; // ESquare = O, BSquare = X, RPotion = R = 2 , B = BPotion = 3, r = RCrystal = 4, b = BCrystal = 5
    this->currentIntegerState = 0; //{ O = 0, X = 1, R = 2, B = 3, r = 4, b = 5 }
    this->isAvailable = true;
    this->canChange = true;
    this->red = 0;
    this->blue = 0;

}

void Cell::setValue(int value) { // Updates with a returned value, and updates the fields accordingly
    switch (value) {
        case 0:
            this->currentStringState = 'O'; // Empty Square = O = 0
            this->currentIntegerState = 0;
            this->canChange = true;
            this->isAvailable = true;
            break;

        case 1:
            if (this->isHeCanChange()) {
                this->currentStringState = 'X'; // Black Square = X = 1
                this->currentIntegerState = 1;
                this->isAvailable = false;
                this->canChange = false;
            }
            break;

        case 2:
            if (this->isAvailable && this->isHeCanChange()) {
                this->currentStringState = 'R'; // Red Potion = R = 2
                this->currentIntegerState = 2;
                this->isAvailable = false;
                this->canChange = false;
            }
            break;

        case 3:
            if (this->isAvailable && this->isHeCanChange()) {
                this->currentStringState = 'B'; // Blue Potion = B = 3
                this->currentIntegerState = 3;
                this->isAvailable = false;
                this->canChange = false;
            }
            break;


        case 4:
            if (this->isHeCanChange()) {
                this->currentStringState = 'r'; // Red Crystal = r = 4
                this->currentIntegerState = 4;// Blue Crystal = b = 5
                this->isAvailable = false;
                this->canChange = true;
            }
            break;

        case 5:
            if (this->isHeCanChange()) {
                this->currentStringState = 'b'; // Blue Crystal = b = 5
                this->currentIntegerState = 5;
                this->isAvailable = false;
                this->canChange = true;
            }
            break;

        default:
            cout << "incomplete value";
            break;
    }

}


string Cell::toString() {
    return this->currentStringState;
}

int Cell::getRow() const {
    return this->row;
}

int Cell::getCol() const {
    return this->col;
}

bool Cell::getIsAvailable() const {
    if (this->isAvailable) return true;
    return false;
}

bool Cell::isHeCanChange() const {
    if (this->canChange) return true;
    return false;

}

int Cell::getCurrState() const {
    return this->currentIntegerState;
}

int Cell::getBlue() const {
    return this->blue;
}

int Cell::getRed() const {
    return this->red;
}

void Cell::setBlue() {
    this->blue += 1;
}

void Cell::setRed() {
    this->red += 1;
}
