//
// Created by Dor Shukrun on 01/12/2022.
//
#include <sstream>
#include "Cell.h"
#include "GameBoard.h"

GameBoard::GameBoard(int size) {
    this->board = new Cell **[size];
    for (int i = 0; i < size; i++) {
        board[i] = new Cell *[size];
        for (int j = 0; j < size; j++) {
            board[i][j] = new Cell(i, j);
        }
    }
    this->availables = size * size;
    this->isGameOver = false;
    this->size = size;
    this->turn = 0;

} //Creates the game board

void GameBoard::printGameBoard() {
    int avi = 0;
    int rscore = 0;
    int bscore = 0;
    string outp;
    for (int i = 0; i < size; i++) {
        outp += "\n";
        for (int j = 0; j < size; j++) {
            if (board[i][j]->getIsAvailable()) avi++;
            if (board[i][j]->getCurrState() == 4) rscore++;
            if (board[i][j]->getCurrState() == 5) bscore++;
            outp += "   " + board[i][j]->toString();
        }
    }
    this->redScore = rscore;
    this->blueScore = bscore;
    this->availables = avi;
    if (avi == 0) return;
    outp += "\n";
    cout << "Red count: " << this->redScore << "    Blue count: " << this->blueScore;
    cout << outp;

} // Prints the game board

Cell *GameBoard::getCellByRowAndCol(int row, int col) const {
    return board[row - 1][col - 1];
}
// The function returns a pointer to a cell type object by row and column

int *GameBoard::getNeighbors(int index) const {
    int row = getCellByIndex(index)->getRow() + 1;
    int col = getCellByIndex(index)->getCol() + 1;
    int *array = new int[9];


    if (col - 1 < 1 && row - 1 < 1) { // leftUpCorner
        array[0] = 4;
        array[1] = getSquareIndexByRowAndCol(row + 1, col);
        array[2] = getSquareIndexByRowAndCol(row, col + 1);
        array[3] = getSquareIndexByRowAndCol(row + 1, col + 1);
        return array;

    }
    if (col - 1 < 1 && row + 1 > size) { // leftDownCorner
        array[0] = 4;
        array[1] = getSquareIndexByRowAndCol(row - 1, col);
        array[2] = getSquareIndexByRowAndCol(row, col + 1);
        array[3] = getSquareIndexByRowAndCol(row - 1, col + 1);
        return array;

    }
    if (row + 1 < size && row - 1 > 1 && col - 1 < 1) { // onlyLeftSide
        array[0] = 6;
        array[1] = getSquareIndexByRowAndCol(row - 1, col);
        array[2] = getSquareIndexByRowAndCol(row - 1, col + 1);
        array[3] = getSquareIndexByRowAndCol(row, col + 1);
        array[4] = getSquareIndexByRowAndCol(row + 1, col + 1);
        array[5] = getSquareIndexByRowAndCol(row + 1, col);
        return array;

    }

    if (row - 1 < 1) {  // upSide Block
        array[0] = 6;
        array[1] = getSquareIndexByRowAndCol(row, col - 1);
        array[2] = getSquareIndexByRowAndCol(row + 1, col - 1);
        array[3] = getSquareIndexByRowAndCol(row + 1, col);
        array[4] = getSquareIndexByRowAndCol(row + 1, col + 1);
        array[5] = getSquareIndexByRowAndCol(row, col + 1);
        return array;

    } // upSide

    if (row - 1 < 1 && col + 1 > size) {    // rightUpCorner
        array[0] = 4;
        array[1] = getSquareIndexByRowAndCol(row + 1, col);
        array[2] = getSquareIndexByRowAndCol(row, col - 1);
        array[3] = getSquareIndexByRowAndCol(row + 1, col - 1);
        return array;

    }

    if (row + 1 > size && col + 1 > size) {// rightDownCorner
        array[0] = 4;
        array[1] = getSquareIndexByRowAndCol(row - 1, col);
        array[2] = getSquareIndexByRowAndCol(row, col - 1);
        array[3] = getSquareIndexByRowAndCol(row - 1, col - 1);
        return array;

    }
    if (row + 1 < size && row - 1 > 1 && col + 1 > size) { // onlyRightSide
        array[0] = 6;
        array[1] = getSquareIndexByRowAndCol(row - 1, col);
        array[2] = getSquareIndexByRowAndCol(row - 1, col - 1);
        array[3] = getSquareIndexByRowAndCol(row, col - 1);
        array[4] = getSquareIndexByRowAndCol(row + 1, col - 1);
        array[5] = getSquareIndexByRowAndCol(row + 1, col);
        return array;


    } // rightSide


    if (row + 1 > size) { // downSide Block
        array[0] = 6;
        array[1] = getSquareIndexByRowAndCol(row, col - 1);
        array[2] = getSquareIndexByRowAndCol(row - 1, col - 1);
        array[3] = getSquareIndexByRowAndCol(row - 1, col);
        array[4] = getSquareIndexByRowAndCol(row - 1, col + 1);
        array[5] = getSquareIndexByRowAndCol(row, col + 1);
        return array;

    } // downSide

    if (row - 1 > 1 && col + 1 < size && row + 1 < size && col - 1 > 1) {
        array[0] = 9;
        array[1] = getSquareIndexByRowAndCol(row - 1, col - 1);
        array[2] = getSquareIndexByRowAndCol(row - 1, col);
        array[3] = getSquareIndexByRowAndCol(row - 1, col + 1);
        array[4] = getSquareIndexByRowAndCol(row, col - 1);
        array[5] = getSquareIndexByRowAndCol(row, col + 1);
        array[6] = getSquareIndexByRowAndCol(row + 1, col - 1);
        array[7] = getSquareIndexByRowAndCol(row + 1, col);
        array[8] = getSquareIndexByRowAndCol(row + 1, col + 1);
        return array;

    }

    return array;
}
//The function returns a pointer to an array of integers where each number represents a cell

int GameBoard::getSquareIndexByRowAndCol(int row, int col) const {
    if (row == 0) row = 1;
    if (col == 0) col = 1;
    int result = size * row;
    result = result - (size - col);
    return result;
}
//The function returns the numerical representation of a cell by column and row

Cell *GameBoard::getCellByIndex(int index) const {
    int row = 0;
    int col = 0;
    for (int i = 0; i < size; i++) {
        if ((index + i) % size == 0) {
            row = (index + i) / size;
            col = size - i;
        }
    }
    return getCellByRowAndCol(row, col);
}
//The function returns a pointer to a cell type object according to its numeric representation

int GameBoard::whosPlaying() const {
    int playing;
    if (((this->turn - 1) % 2) == 0) playing = 2;
    else playing = 3;
    return playing;

}
//The function returns the currently playing player

string GameBoard::whosTurn() {
    int p = this->turn % 2;
    this->turn += 1;
    if (p == 0) return "R:";
    return "B:";

}
//The function returns who's turn to play now

void GameBoard::updateCells(int array[]) const {
//  ESquare = O, BSquare = X, RPotion = R, B = BPotion, r = RCrystal, b = BCrystal
//  O = 0, X = 1, R = 2, r = 3, B = 4, b = 5
    int sizeArray = array[0]; // the first value is the size of the array.
    int play = whosPlaying(); // return int, 2 or 3, its up witch players is plays.

    for (int i = 1; i < sizeArray; i++) { // runs on the neighbors
        Cell *theCell = getCellByIndex(array[i]);
        if (play == 2) {
            theCell->setRed();
        }
        if (play == 3) {
            theCell->setBlue();
        }
    }

    for (int i = 1; i < sizeArray; i++) { // runs on the neighbors
        Cell *theCell = getCellByIndex(array[i]);
        int red = theCell->getRed();
        int blue = theCell->getBlue();
        if (blue > 1 || red > 1) theCell->setValue(1);

        if (blue == 1 && red == 1 && play == 2) {
            theCell->setValue(4);       // Blue Crystal = b = 5
            // Red Crystal = r = 4
        }
        if (red == 1 && blue == 1 && play == 3) {
            theCell->setValue(5);
        }


    }
}
// The function receives an array of integers, which represent the numerical value of the cells it needs to update

void GameBoard::upDateCellByIndex(int index) const {
    getCellByIndex(index)->setValue(whosPlaying());
}
//The function updates the cells according to their numerical value

int GameBoard::inputVal() {
    int row, col;
    while (true) {
        cout << whosTurn() << std::endl;
        string input;
        getline(std::cin, input);
        stringstream ss(input);
        string n;
        if (!(ss >> n)) {
            this->turn -= 1;
            cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        row = std::stoi(n);
        if (!(ss >> n)) {
            this->turn -= 1;
            cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;

        }
        col = std::stoi(n);
        if (col > size || col < 1 || row < 1 || row > size) {
            this->turn -= 1;
            std::cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        if (!getCellByRowAndCol(row, col)->getIsAvailable()) {
            this->turn -= 1;
            std::cerr << "Invalid row/col index or non free cell" << std::endl;
            continue;
        }
        return getSquareIndexByRowAndCol(row, col);
    }

} // collect the inputs values

int GameBoard::getRedScore() const {
    return this->redScore;
} // get the red score

int GameBoard::getBlueScore() const {
    return this->blueScore;
} // get thr blue score

void GameBoard::letsPlay() {
    while (!isGameOver) {
        printGameBoard();
        if (availables == 0) {
            isGameOver = true;
            break;
        }
        int index = inputVal();
        upDateCellByIndex(index);
        updateCells(getNeighbors(index));


    }
    if (getBlueScore() > getRedScore()) cout << "Blue won\n";
    if (getBlueScore() < getRedScore()) cout << "Red won\n";
    if (getBlueScore() == getRedScore()) cout << "The game ended with a tie\n";
    CellsDestroy();


} // the gameLoop

void GameBoard::CellsDestroy() {
    if (board == nullptr) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}
