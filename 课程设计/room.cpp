#include"room.h"
void Room::PrintRoom() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < clo; j++) {
			if (at(i,j) == Wall) std::cout << Wallchar;
			if (at(i, j) == Person)std::cout << Personchar;
			if (at(i, j) == Road) std::cout << Roadchar;
			
		}
		std::cout << std::endl;
	}
}
int Room::at(int i, int j) {
	return room[i * row + j];
}
void Room::clearScreen() {
	system("cls");
	
}
void Room::setRoad(int i, int j) {
	
	room[i * row + j] = Road;
}
void Room::setBlock(int i, int j) {
	room[i * row + j] = Wall;

}
void Room::setPerson(int i, int j) {
	room[i * row + j] = Person;
}
bool Room::Win() {
	if (ptr.x > row || ptr.y > clo) {
		return true;
	}
	else {
		return false;
	}

}
bool Room::CanMove(int i,int j) {
	if (at(i, j) == Road&&i<=row&&j<=clo) return true;
	return false;
}
void Room::moveDown() {
	if (CanMove(ptr.y+1, ptr.x)) {
		setRoad(ptr.y, ptr.x);
		ptr.y = ptr.y + 1;
		setPerson(ptr.y, ptr.x);
	}
}
void Room::moveLeft() {
	if (CanMove(ptr.y, ptr.x-1 )) {
		setRoad(ptr.y, ptr.x);
		ptr.x = ptr.x - 1;
		setPerson(ptr.y, ptr.x);
	}
}
void Room::moveUp() {
	if (CanMove(ptr.y-1, ptr.x)) {
		setRoad(ptr.y, ptr.x);
		ptr.y = ptr.y - 1;
		setPerson(ptr.y, ptr.x);
	}
}
void Room::moveRight() {
	if (CanMove(ptr.y, ptr.x+1)) {
		setRoad(ptr.y, ptr.x);
		ptr.x = ptr.x + 1;
		setPerson(ptr.y, ptr.x);
	}
}
void Room::flashRoom(std::string str) {

}
Room::Room()
{
	row = 10;
	clo = 10;
	room = new int[row * clo];
	srand((unsigned)time(NULL));
	int x = 0, y = 0;
	
	for (int i = 0; i < row/2; i++) {
		for (int j = 0; j < clo/2; j++) {
			x = (rand() % (row  ));
			y = (rand() % (clo ));
			setRoad(x, y);
		}
	}
	x = (rand() % (row + 1));
	y = (rand() % (clo + 1));
	setPerson(x, y);
}
Room::Room(int row, int clo) {
	this->row = row;
	this->clo = clo;
	room = new int[this->row * this->clo];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < clo; j++) {
			setBlock(i, j);
		}
	}

	srand((unsigned)time(NULL));
	int x = 0, y = 0;

	for (int i = 0; i < this->row / 2; i++) {
		for (int j = 0; j < this->clo / 2; j++) {
			x = (rand() % (this->row));
			y = (rand() % (this->clo));
			setRoad(x, y);
		}
	}
	x = (rand() % (this->row + 1));
	y = (rand() % (this->clo + 1));
	setPerson(y, x);
	ptr.x = x;
	ptr.y = y;

}
Room::Room(int none) {
	row = 10;
	clo = 10;
	room = new int[row * clo];
	ptr.x = 0;
	ptr.y = 0;

}
Room::~Room()
{
	delete[]room;
}
