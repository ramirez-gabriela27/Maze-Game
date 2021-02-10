/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Board Implementations
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include "Board.h"

/*
    return a string representation of a given SquareType
    @param sq (SquareType) - given square
    return st (string) - string conversion of sq
*/
std::string SquareTypeStringify(SquareType sq){
	std::string strType;
	if(sq == SquareType::Wall) { strType = "🥒";}
	else if(sq == SquareType::Exit) { strType = "✨";}
	else if(sq == SquareType::Empty) { strType = "🐾";}
	else if(sq == SquareType::Human) { strType = "🐱";}
	else if(sq == SquareType::Enemy) { strType = "👹";}
	else if(sq == SquareType::Treasure) { strType = "🧶";}
	else{ strType = "ERROR";}
	return strType;
}

/*
    Default constructor - Generte a board
*/
Board::Board(){
    rows_ = 4;
    cols_ = 4;

    //initially fill the board with empty spaces
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            arr_[i][j] = SquareType::Empty;
        }
    }

    //always start at the top left, end at bottom right
    arr_[0][0] = SquareType::Human;
    arr_[3][3] = SquareType::Exit;

    //generate random number of walls
    srand (time(NULL));
    int x = rand() % 3 + 2;
    //generate these in random locations
    int i = 0;
    while(i < x){
        //srand (time(NULL));
        int newRow = rand() % 3;
        int newCol = rand() % 3;

        if(arr_[newRow][newCol] == SquareType::Empty){
            arr_[newRow][newCol] = SquareType::Wall;
            i++;
        }else{
            continue;
        }
    }
}

/*
    returns the SquareType value of the position passed
    @param pos (Position) - position you need to know the value to
    return arr_[pos.row][pos.col]
*/
SquareType Board::get_square_value(Position pos) const{
    return arr_[pos.row][pos.col];
}

/*
    test if position accounts for valid move
    @param there (Position) - position player is trying to get to
    return bool - based on availability
*/
bool Board::testPosition(Position there){
    if(there.row<0 || there.col<0 ){
        return false;
    }else if(there.row > 3 || there.col > 3){
        return false;
    }else{
        if(get_square_value(there) != SquareType::Enemy && get_square_value(there) != SquareType::Wall){
            //can only move into an epty space, or a treasure space
            //enemies can move to human spaces and eat them
            return true;
        }else{
            return false;
        }
    }
    return false;
}

/*
    find available moves
    @param p (Player) - the player
    return moves (vector) - vector of positions
*/
std::vector<Position> Board::GetMoves(Player *p){
    std::vector<Position> moves;

    //position above player
    Position *tUp = new Position;
    tUp->row = p->get_position().row + 1;
    tUp->col = p->get_position().col;
    //check if it's available, then append if necessary
    if(testPosition(*tUp)){
        moves.push_back(*tUp);
    }

    //position right of player
    Position *tRight = new Position;
    tRight->row = p->get_position().row;
    tRight->col = p->get_position().col + 1;
    //check if it's available, then append if necessary
    if(testPosition(*tRight)){
        moves.push_back(*tRight);
    }

    //position under player
    Position *tDown = new Position;
    tDown->row = p->get_position().row - 1;
    tDown->col = p->get_position().col;
    //check if it's available, then append if necessary
    if(testPosition(*tDown)){
        moves.push_back(*tDown);
    }

    //position left of player
    Position *tLeft = new Position;
    tLeft->row = p->get_position().row;
    tLeft->col = p->get_position().col - 1;
    //check if it's available, then append if necessary
    if(testPosition(*tLeft)){
        moves.push_back(*tLeft);
    }

    return moves;
}

/*
    move a player to a new position on the board
    @param p (Player) - player moving
    @param pos (Position) - position player is trying to get to
    return bool - true if player moved successfully, false otherwisety
*/
bool Board::MovePlayer(Player *p, Position pos){
    if(!testPosition(pos)){
        return false;
    }else{
        SetSquareValue(p->get_position(), SquareType::Empty);
        p->SetPosition(pos);
        if(p->is_human()){
            SetSquareValue(pos, SquareType::Human);
        }else{
            SetSquareValue(pos, SquareType::Enemy);
        }
        return true;
    }
}

/*
    prints the board
    @param &b (Board) - board being printed
*/
void Board::PrintBoard(const Board &b){
    std::cout << std::endl << b;
}

/*
    operator << override
    utilized to print the board on which the user is playing on
*/
std::ostream& operator<<(std::ostream& os, const Board &b){
    for (int i = 0; i < b.rows_; ++i)
    {
        for (int j = 0; j < b.cols_; ++j)
        {
            os << SquareTypeStringify(b.get_square_value(Position{i,j})) << ' ';
        }
        os << std::endl << std::endl;
    }
    return os;
}
