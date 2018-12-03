#ifndef ghost
#define ghost
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include "console.h"

void author(){
	int x = 84;
	SetColor(180);
	gotoxy(x, 2);
	cout << (char) 201;
	for(int i = 0; i < 10; i++){
		cout << (char) 205;
	}
	cout << (char) 187;
	cout << endl;
	gotoxy(x, 3);
	cout << (char) 186;
	cout << "  Made by ";
	cout << (char) 186;
	gotoxy(x, 4); cout << (char) 186; cout << "   Kinn   ";
	cout << (char) 186; gotoxy(x, 5);
	cout << (char) 186; cout << " with Luv ";
	cout << (char) 186;
	gotoxy(x, 6);
	cout << (char) 200;
	for(int i = 0; i < 10; i++){
		cout << (char) 205;
	}
	cout << (char) 188;
	
	SetColor(0);
	gotoxy(x, 7);
	SetColor(241);
	gotoxy(x, 8);  cout << "  _  ___              ";            
	gotoxy(x, 9);  cout << " | |/ (_)             ";
	gotoxy(x, 10); cout << " | ' / _ _ __  _ __   ";
	gotoxy(x, 11); cout << " |  < | | '_  | '_  \  ";
	gotoxy(x, 12); cout << " | .  | | | | | | | | ";
	gotoxy(x, 13); cout << " |_|  \_\_|_| |_|_| |_| ";
	gotoxy(x, 14); cout << "                      ";
	
	SetColor(14);
	gotoxy(x, 17);
	cout << "User Manual:";
	gotoxy(x, 18);
	cout << "Use 'W', 'D', 'A'";
	gotoxy(x, 19);cout <<"or UpArrow, LeftArrow, DownArrow";

}

#endif

