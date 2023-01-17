//
// Created by Dor Shukrun on 01/12/2022.
//

#ifndef ALCHEMIST_GAMEBOARD_H
#define ALCHEMIST_GAMEBOARD_H

#include <iostream>
#include <string>
#include "Cell.h"

using namespace std;

class GameBoard {
private:
    Cell ***board;
    bool isGameOver;
    int availables;
    int redScore{};
    int blueScore{};
    int size;
    int turn;

public:
    GameBoard(int size);

    void printGameBoard();

    int *getNeighbors(int index) const ;

    Cell * getCellByRowAndCol(int row, int col) const;

    void updateCells( int array[]) const;

    int getSquareIndexByRowAndCol(int row, int col) const;

    Cell * getCellByIndex(int index) const;

    string whosTurn();

    int inputVal();

    void upDateCellByIndex(int index) const;

    int whosPlaying() const;

    int getRedScore() const;

    int getBlueScore() const;

    void letsPlay();

    void CellsDestroy();
};


#endif //ALCHEMIST_GAMEBOARD_H
