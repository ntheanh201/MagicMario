#include<iostream>
#include "console.h"

using namespace std;

enum Status {
	ISFALL, ISJUMP, IDLE, LEFT, RIGHT
};

class Mario{
	public:
		int timeJump;
		float x, y;
		void move();
		Status statusJump;
		Status statusMove;
		Mario();
		void move(char **map);
		void updateStatus(int key);
		void draw();
		void clear();
		void update(int key, char **map);
		bool isDie(char **maps);
};

Mario::Mario(){
	x = 2;
	y = 23;

	//HACK GAME :V
//	x = 76;
//	y = 6;

	statusMove = IDLE;
	statusJump = IDLE;
}

void Mario::move(char **maps){
	
//	gotoxy(0, 0);
//	if(statusMove == RIGHT){
//		cout << "right";
//	}
//	if(statusMove == LEFT) cout << "left";
//	if(statusMove == IDLE) cout << "idle";
	
	if(statusJump == ISJUMP){
		if(maps[(int)y-1][(int)x] == '#' || maps[(int)y-1][(int)x] == '@' || maps[(int)y-1][(int)x] == 'p'){
			statusJump = ISFALL;
		}
		else{
			y-=0.7;
		}
		timeJump--;
		if(timeJump == 0){
			statusJump = ISFALL;
		}
	}
	else if(statusJump != ISJUMP){
		if(maps[(int)y+1][(int)x] != '#' && maps[(int)y+1][(int)x] != '@' && maps[(int)y+1][(int)x] != 'p'){
			y+=0.7;
		}
		else statusJump = IDLE;
	}
	if(statusMove == LEFT){
		if(maps[(int)y][(int)x-1] != '#' && maps[(int)y][(int)x-1] != '@' && maps[(int)y][(int)x-1] != 'p'){
			x--;
		}
	}
	else if(statusMove == RIGHT){
		if(maps[(int)y][(int)x+1] != '#' && maps[(int)y][(int)x+1] != '@' && maps[(int)y][(int)x+1] != 'p'){
			x++;
		}
	}
	statusMove = IDLE;
}

void Mario::updateStatus(int key){
	if(key == 'w'){
		if (statusJump == IDLE){
			timeJump = 6;
			statusJump = ISJUMP;
		}
	}
	else if(key == 'a'){
		statusMove = LEFT;
	}
	else if(key == 'd'){
		statusMove = RIGHT;
	}
	else{
		statusMove = IDLE;
	}
}

void Mario::draw(){
	SetColor(15);
	gotoxy((int)x, (int)y);
	cout << (char) 2;
}

void Mario::clear(){
	SetColor(0);
	gotoxy(x, y);
	cout << " ";
}

void Mario::update(int key, char **map){
	updateStatus(key);
	move(map);
}

bool Mario::isDie(char **maps){
	gotoxy(0, 0); cout << maps[(int)y+1][(int)x];
	if(maps[(int)y+1][(int)x] == 'a'){
		return true;
	}
	return false;
}
