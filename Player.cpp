/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Player Implementations
*/

#include <iostream>

#include "Player.h"

/*
    Parameterized constructor - Create a new player
    @param name (string) - name of player
    @param is_human (bool) - state of being
*/
Player::Player(const std::string name, const bool is_human){
    name_ = name;
    is_human_ = is_human;

    points_ = pos_.row = pos_.col = 0;
}

/*
    translate positions into directions relative to the player
    @param other (Position) - other position
    return posRelative (string) - position relative to player
*/
std::string Player::ToRelativePosition(Position other){
    std::string posRelative = "";

    if((other.row < 0) && (other.col < 0)){ // used to make sure it's still on board
        posRelative = "UNAVAILABLE";
    }
    else{
        if((other.row == pos_.row) && (other.col < pos_.col)){
            posRelative = "LEFT";
        }
        else if((other.row == pos_.row) && (other.col > pos_.col)){
            posRelative = "RIGHT";
        }
        else if((other.col == pos_.col) && (other.row < pos_.row)){
            posRelative = "UP";
        }
        else if((other.col == pos_.col) && (other.row > pos_.row)){
            posRelative = "DOWN";
        }
        else{
            posRelative = "UNAVAILABLE";
        }
    }
    return posRelative;
}

/*
    prints the player info
    @param &p (Player) - player being printed
*/
void Player::PrintPlayerInfo(const Player &p){
    std::cout << std::endl << p;
}

/*
    operator << override
    utilized to print the player information on which the user is playing on
*/
std::ostream& operator<<(std::ostream& os, const Player &p){
    os << "Player: " << p.name_ << std::endl;
    os << "Positon: (" << p.pos_.row << "," << p.pos_.col << ")" << std::endl;
    os << "Points: " << p.points_ << " pts";
    return os;
}
