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

    //FOR 5 POINTS MORE
    //Implement a certain amount of moves that the player has to complete this in
        //this will include human and non-human moves
    //I think 20 moves total is a good amount - could be wrong
    int moveCap = 20;

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

    std::cout << std::endl << "YOU MUST COMPLETE THIS GAME IN " << moveCap << " MOVES"  << std::endl;
    int turns = 0;
    while(!gameOver && turns < moveCap){
        //call TakeTurn with game's vector of players in mind
            // each time, print status, map and list of moves
            // take user input to move -- if valid
            // move and update map
            // print updated map

        //loop trought player array
        for(int i=0; i < numPlayers; i++){
            if(gameOver){ break; }

            std::cout << "~~~~~~~~~~~~~~~~~NEXT TURN~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << moveCap - turns << " MOVES LEFT" << std::endl;

            game->TakeTurn(players[i]);
            turns++;

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
        std::cout << std::endl << p->get_name() << " is the winner!" << std::endl;
    }else{
        std::cout << std::endl << "The enemy has won." << std::endl;
    }

    std::cout << std::endl << "FINAL STATS";
    for(int i=0; i < numPlayers; i++){
        std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        players[i]->PrintPlayerInfo(*players[i]);
    }

    return 0;
}
