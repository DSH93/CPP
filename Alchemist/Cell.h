//
// Created by Dor Shukrun on 01/12/2022.
//

#ifndef ALCHEMIST_CELL_H
#define ALCHEMIST_CELL_H

#include <iostream>
#include <string>

using namespace std;


class Cell {
    int row, col;
    bool isAvailable;
    bool canChange;
    string currentStringState; //{ESquare = O, BSquare = X, RPotion = R, B = BPotion, r = RCrystal, b = BCrystal , halfBlack}
    int currentIntegerState; // { O = 0, X = 1, R = 2, r = 3, B = 4, b = 5 }

    int red;
    int blue;

//todo Produce more situations where a cell can be, half red and half blue


public:
    Cell(int row, int col);

    void setValue(int value); // Updates with a returned value, and updates the fields accordingly
    string toString();

    int getRow() const;

    int getCol() const;

    bool getIsAvailable() const;

    bool isHeCanChange() const;

    int getCurrState() const;

    int getBlue() const;

    int getRed() const;

    void setBlue();

    void setRed();
};


#endif //ALCHEMIST_CELL_H
