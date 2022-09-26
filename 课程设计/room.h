#pragma once
#include<vector>
#include<iostream>
#define Wall 0
#define Person 1
#define Road 2
#define Wallchar "#@#"
#define Personchar "<->"
#define Roadchar "   "
typedef struct  {
	int x;
	int y;
}Point;
class Room
{
public:
	Room();
	Room(int row, int clo);
	Room(int none);
	~Room();
	int at(int i, int j);
	void setBlock(int i, int j);
	void setRoad(int i, int j);
	void setPerson(int i, int j);
	void flashRoom(std::string str);
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void PrintRoom();
	void clearScreen();
	bool Win();
	
private:
	bool CanMove(int i,int j);
	int* room;
	int row, clo;
	Point ptr;
};

