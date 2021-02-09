/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Maze Implementations
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Maze.h"
#include "Board.h"

/*
    Default constructor - Create a maze
*/
Maze::Maze(){
    //generating the board will put:
        //human on uper left
        //exit on lower right
        //randomly generated walls
    board_ = new Board();
}

/*
    Initialize a new game
    @param *human (Player) - Player object of human
    @param enemies (int) - number of enemies in game
*/
void Maze::NewGame(Player *human, const int enemies){
    //generate new maze/board
    Maze();

    //update player vector, with player1 being human
    players_.push_back(human);

    //set turn count to 0
    turn_count_ = 0;

    //generate enemies in random locations
    int i = 0;
    srand (time(NULL));
    while(i < enemies){
        Position *enPos = new Position;
        enPos->row = rand() % 3;
        enPos->col = rand() % 3;
        //update player vector with enemy names
        std::string enName = "Enemy";

        if(board_->get_square_value(*enPos) == SquareType::Empty){
            enName = enName+std::to_string(i);
            //initialize and create enemy
            Player *enNew = new Player(enName, false);
            enNew->SetPosition(*enPos);
            //place on board
            board_->SetSquareValue(*enPos, SquareType::Enemy);
            //append to vector of players
            players_.push_back(enNew);
            i++;
        }else{
            continue;
        }
    }

    //lastly, generate treasure
    Position *trsPos = new Position;
    trsPos->row = rand() % 3;
    trsPos->col = rand() % 3;
    bool treasurePlaced = false;
    while(!treasurePlaced){
        if(board_->get_square_value(*trsPos) == SquareType::Empty){
            board_->SetSquareValue(*trsPos, SquareType::Treasure);
            treasurePlaced = true;
        }else{
            trsPos->row = rand() % 3;
            trsPos->col = rand() % 3;
        }
    }
    //and print the board to display before begining game
    board_->PrintBoard(*board_);
}

/*
    Given player p takes turn
    @param *p (Player) - Player taking turn
*/
void Maze::TakeTurn(Player *p){
    std::cout << "It is now " << p->get_name() << "\'s turn." << std::endl;
    std::cout << "=============STATUS=============";
    p->PrintPlayerInfo(*p);
    std::cout << std::endl << "==============MAP==============" << std::endl;
    board_->PrintBoard(*board_);
    std::cout << "=============MOVES=============" << std::endl;
    //collect possible moves
    std::vector<Position> posMoves = board_->GetMoves(p);
    // translate them and print them out
    int mSize = posMoves.size();
    for(int i=0; i < mSize; i++){
        std::cout << p->ToRelativePosition(posMoves[i]) << " ";
    }
    std::cout << std::endl << "Please select a move:" << std::endl;
    std::string choice;
    std::cin >> choice;

    for(int i=0; i < mSize; i++){
        if(choice == p->ToRelativePosition(posMoves[i])){
            if(board_->get_square_value(posMoves[i]) == SquareType::Treasure){
                //assuming all treasures are 100 pts
                p->SetPoints(p->get_points() +100);
            }
            board_->MovePlayer(p, posMoves[i]);
        }
    }

}

//might wanna go into office hours for this one
// // Get the next player in turn order
// Player * GetNextPlayer();

// return true iff the human made it to the exit
// or the enemies ate all the humans
/*
    State of game based on completion
    return state (bool) - true if human made it to exit or enemies won
*/
bool Maze::IsGameOver(){
    bool state = false;
    return state;
}