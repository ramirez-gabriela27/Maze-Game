/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Board Header
*/

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include "Player.h"

// enum - the type of square can be one of these
enum class SquareType { Wall, Exit, Empty, Human, Enemy, Treasure};

class Board {
private:
    SquareType arr_[4][4];
    int rows_;
    int cols_;
public:
	// constructor
	Board();

	// getter(s) - inline member function(s)
	int get_rows() const {return 4; }  // you should be able to change the size of your
	int get_cols() const {return 4; }  // board by changing these numbers and the numbers in the arr_ field
	SquareType GetExitOccupant() {return arr_[rows_-1][cols_-1]; } // Get the square type of the exit square

	// getter(s) - implemented in Board.cpp
	SquareType get_square_value(Position pos) const;
	std::vector<Position> GetMoves(Player *p);

	// setter(s) - implemented in Board.cpp
	void SetSquareValue(Position pos, SquareType value) { arr_[pos.row][pos.col] = value; }

	// other functios inplemented in Board.cpp

	// MovePlayer - member function
	bool MovePlayer(Player *p, Position pos);

	//HELPERS ADDED

	//test if relative position is valid
	bool testPosition(Position there);

	// PrintBoard - member function
	void PrintBoard(const Board &b);

	// << oerator overload
	friend std::ostream& operator<<(std::ostream& os, const Board &b);
};  // class Board

#endif  // BOARD_H
