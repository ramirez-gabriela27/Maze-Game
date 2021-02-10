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

    std::cout << "Please enter a player name: " << std::endl;
    std::cin >> name;
    std::cout << std::endl << " ******** let the game begin ********"  << std::endl;

    //initialize human player
    Player *p = new Player(name, true);
    //initialize game
    Maze *game = new Maze();
    //we start eith 2 enemies, randomly located
    game->NewGame(p,2); //this prints the map at first

    //if a player is out of moves, it moves on to the next player
    //this will continue until there are no moves, in which case it terminates
    //  --game is neither won or lost

    //to proceed through game, IsGameOver() has to be false
    //  -- i.e. there has to be a huma on board
    //  -- human hasn't reached exit
    //  -- moves are available

    std::vector<Player *> players = game->GetPlayers();

    bool gameOver = false;
    int numPlayers = players.size();
    while(!gameOver){
        //call TakeTurn with game's vector of players in mind
            // each time, print status, map and list of moves
            // take user input to move -- if valid
            // move and update map
            // print updated map

        //loop trought player array
        for(int i=0; i < numPlayers; i++){
            if(gameOver){ break; }

            std::cout << "~~~~~~~~~~~~~~~~~NEXT TURN~~~~~~~~~~~~~~~~~" << std::endl;

            game->TakeTurn(players[i]);

            // after turn is over, move on to the next player and repeat
            // nextPlayer = game->GetNextPlayer();
            gameOver = game->IsGameOver();
        }
        // // after turn is over, move on to the next player and repeat
        // // nextPlayer = game->GetNextPlayer();
        // gameOver = game->IsGameOver();
    }

    std::cout << "The game has ended" << std::endl;

    Position *exitLoc = new Position;
    exitLoc->row = 3;
    exitLoc->col = 3;

    if(p->is_human() && (*exitLoc == p->get_position())){
        std::cout << p->get_name() << " is the winner!" << std::endl;
    }else{
        std::cout << "The enemy has won." << std::endl;
    }

    return 0;
}
