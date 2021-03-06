#include <iostream>
#include "console.h"

using namespace std;

enum StatusMario {
	ISFALL, ISJUMP, IDLE, LEFT, RIGHT
};

class Mario{
	public:
		int timeJump;
		float x, y;
		float x_afterDie, y_afterDie;
		void move();
		StatusMario statusJump;
		StatusMario statusMove;
		Mario();
		void move(char **map);
		void updateStatus(int key);
		void draw();
		void drawAfterDie();
		void clear();
		void update(int key, char **map);
		bool isDie(char **maps);
};

Mario::Mario(){
	Nocursortype();
	x = 2;
	y = 20;
	
//	HACK GAME :V
//	x = 73;
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
	if(key == 'w' || key == 72){
		if (statusJump == IDLE){
			timeJump = 5;
			statusJump = ISJUMP;
		}
	}
	else if(key == 'a' || key == 75){
		statusMove = LEFT;
	}
	else if(key == 'd' || key == 77){
		statusMove = RIGHT;
	}
	else{
		statusMove = IDLE;
	}
}

void Mario::draw(){
	SetColor(15);
	gotoxy((int)x, (int)y);
	cout << (char) 158;
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
//	gotoxy(0, 0); cout << maps[(int)y+1][(int)x];
	if(maps[(int)y+1][(int)x] == 'a'){
		return true;
	}
	return false;
}

