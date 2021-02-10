/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Maze Header
*/

#ifndef MAZE_H
#define MAZE_H

#include <vector>
#include "Player.h"
#include "Board.h"

class Maze {
private:
	Board *board_;
	std::vector<Player *> players_;
	int turn_count_;
public:
	// constructor
	Maze();

	//return player array
	std::vector<Player *> GetPlayers(){return players_;}

	// initialize a new game, given one human player and
	// a number of enemies to generate
	void NewGame(Player *human, const int enemies);

	// have the given Player take their turn
	void TakeTurn(Player *p);

	// // Get the next player in turn order
	// Player * GetNextPlayer();

	// return true iff the human made it to the exit
	// or the enemies ate all the humans
	bool IsGameOver();

 // will look at these later
	// // You probably want to implement these functions as well
	// // string info about the game's conditions after it is over
	// std::string GenerateReport();
	// friend std::ostream& operator<<(std::ostream& os, const Maze &m);

};  // class Maze

#endif  // MAZE_H
