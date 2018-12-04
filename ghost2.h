#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<time.h>
#include "console.h"
using namespace std;

enum StatusGhost2 {
	UPn, DOWNn
};

class Ghost2{
	public:
		float x, y, firstPoint, lastPoint;
		StatusGhost2 status;
		void draw();
		void clear();
		void move();
		Ghost2(float x, float y, float firstPoint, float lastPoint, StatusGhost2 status){
			this->x = x;
			this->y = y;
			this->firstPoint = firstPoint;
			this->lastPoint = lastPoint;
			this->status = status;
		}
};

void Ghost2::draw(){
	gotoxy((int)x, (int)y);
	srand(time(NULL));
	SetColor(rand()%14+2);
	cout << (char) 227;
}

void Ghost2::clear(){
	gotoxy((int)x, (int)y);
	cout << " ";
}

//levels -> speed
void Ghost2::move(){
	float speed = 0.3;
	if(levels == 2){
		speed = 0.5;
	}
	else if(levels == 3){
		speed = 0.7;
	}
	if(status == UPn){
		y -= speed;
		if(y <= firstPoint){
			status = DOWNn;
		}
	}
	else {
		y += speed;
		if(y >= lastPoint){
			status = UPn;
		}
	}
}


