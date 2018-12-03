#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<time.h>
#include "console.h"
using namespace std;

float levels = 1;
enum StatusGhost {
	RIGHTn, LEFTn
};

class Ghost{
	public:
		float x, y, firstPoint, lastPoint;
		StatusGhost status;
		void draw();
		void clear();
		void move();
		Ghost(float x, float y, float firstPoint, float lastPoint, StatusGhost status){
			this->x = x;
			this->y = y;
			this->firstPoint = firstPoint;
			this->lastPoint = lastPoint;
			this->status = status;
		}
};

void Ghost::draw(){
	gotoxy((int)x, (int)y);
	srand(time(NULL));
	SetColor(rand()%14+2);
	cout << (char) 2;
}

void Ghost::clear(){
	gotoxy((int)x, (int)y);
	cout << " ";
}

//levels -> speed
void Ghost::move(){
	float speed = 0.3;
	if(levels == 2){
		speed = 0.5;
	}
	else if(levels == 3){
		speed = 0.7;
	}
	if(status == RIGHTn){
		x -= speed;
		if(x <= firstPoint){
			status = LEFTn;
		}
	}
	else {
		x += speed;
		if(x >= lastPoint){
			status = RIGHTn;
		}
	}
}


