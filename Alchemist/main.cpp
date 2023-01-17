#include <iostream>
#include "GameBoard.h"

using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 2){
        std::cerr << "Invalid run arguments; run the game with board size." << std::endl;
    return 0;
    }
    GameBoard theGame = *new GameBoard(stoi(argv[1]));//
    theGame.letsPlay();
    return 0;
}
