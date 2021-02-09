/*
CSCI 3010 - Spring 2021
HW 1 - Maze Game
Gabriela Tolosa Ramirez
Player Header
*/

#ifndef PLAYER_H
#define PLAYER_H

struct Position {
	int row;
	int col;

	// already implemented for you!
	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
};

class Player {
private:
	std::string name_;
	int points_;
	Position pos_;
	bool is_human_;
public:
	// constructor
	Player(const std::string name, const bool is_human);

	// getter(s) - inline member function(s)
	std::string get_name() const {return name_; }
	int get_points() const {return points_; }
	Position get_position() const {return pos_; }
	bool is_human() const {return is_human_; }

	// setter(s) - inline member function(s)
	void ChangePoints(const int x){points_ = x; }
	void SetPosition(Position pos){pos_ = pos; }
	void SetPoints(int points){points_ = points; }

	// functios inplemented in Player.cpp

	// toRelativePosition - member function
	std::string ToRelativePosition(Position other);

	// PrintBoard - member function
	void PrintPlayerInfo(const Player &p);

	// << oerator overload
	friend std::ostream& operator<<(std::ostream& os, const Player &p);

}; // class Player

#endif  // PLAYER_H
