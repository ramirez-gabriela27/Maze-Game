/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Main
*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Board.h"
#include "Maze.h"

int main(int argc, char **argv) {

    std::string name;

    std::cout << "Please enter a name: " << std::endl;
    std::cin >> name;

    ////////////////test to print player//////////////////
    Player *p = new Player(name, true);

    Maze *game = new Maze();
    game->NewGame(p,2); //this prints the map at first

    // while(!game->IsGameOver()){
    //     std::cout << "STILL GOING ON" << std::endl;
    // } loop to keep the game going

    game->TakeTurn(p);
    // print who's turn
    // print the status
    // print the map, prompt user to input, move and print again.

    Player *pE = new Player("enemy1", false);
    game->TakeTurn(pE);

    // std::cout << std::endl << "=====================";
    //
    // ////////////////test to print board//////////////////
    // Board *testBoard = new Board();
    //
    // testBoard->PrintBoard(*testBoard);
    //
    // std::cout << "=====================" << std::endl;
    //
    // ////////////////test to GetMoves /////////////////
    // std::vector<Position> moves = testBoard->GetMoves(p);
    // int mSize = moves.size();
    // for(int i=0; i < mSize; i++){
    //     std::cout << "(" << moves[i].row << "," << moves[i].col << ") ";
    // }
    //
    //
    // std::cout << std::endl << "=====================" << std::endl;
    //
    // ////////////////test set value//////////////////
    // std::cout << "Trying to set exit to enemy:";
    // Position *test = new Position;
    // test->row = 3;
    // test->col = 3;
    //
    // testBoard->SetSquareValue(*test, SquareType::Enemy);
    //
    // testBoard->PrintBoard(*testBoard);
    //
    // std::cout << "=====================" << std::endl;
    //
    // ////////////////test move player//////////////////
    // std::cout << "Trying to move right:";
    // Position *tRight = new Position;
    // tRight->row = p->get_position().row;
    // tRight->col = p->get_position().col + 1;
    // testBoard->MovePlayer(p, *tRight);
    // testBoard->PrintBoard(*testBoard);
    //

    return 0;
}
