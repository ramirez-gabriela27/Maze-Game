CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: maze

clean:
	rm Player.o Maze.o Board.o maze.exe #change this!!!

maze: Player.o Maze.o Board.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp Player.o Maze.o Board.o -o maze

Player.o: Player.cpp
	$(CXX) $(CXXFLAGS) -c Player.cpp

Maze.o: Maze.cpp
	$(CXX) $(CXXFLAGS) -c Maze.cpp

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c Board.cpp
