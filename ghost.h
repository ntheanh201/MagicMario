#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<time.h>
#include "console.h"
using namespace std;

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

void Ghost::move(){
	if(status == RIGHTn){
		x-=0.3;
		if(x <= firstPoint){
			status = LEFTn;
		}
	}
	else {
		x+=0.3;
		if(x >= lastPoint){
			status = RIGHTn;
		}
	}
}


