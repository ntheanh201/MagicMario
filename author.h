#ifndef ghost
#define ghost
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<fstream>
#include "console.h"

void author(){
	SetColor(180);
	gotoxy(82, 2);
	cout << (char) 201;
	for(int i = 0; i < 10; i++){
		cout << (char) 205;
	}
	cout << (char) 187;
	cout << endl;
	gotoxy(82, 3);
	cout << (char) 186;
	cout << "  Made by ";
	cout << (char) 186;
	gotoxy(82, 4); cout << (char) 186; cout << "   Kinn   ";
	cout << (char) 186; gotoxy(82, 5);
	cout << (char) 186; cout << " with Luv ";
	cout << (char) 186;
	gotoxy(82, 6);
	cout << (char) 200;
	for(int i = 0; i < 10; i++){
		cout << (char) 205;
	}
	cout << (char) 188;
	
	SetColor(0);
	gotoxy(82, 7);
	SetColor(241);
	gotoxy(82, 8);  cout << "  _  ___              ";            
	gotoxy(82, 9);  cout << " | |/ (_)             ";
	gotoxy(82, 10); cout << " | ' / _ _ __  _ __   ";
	gotoxy(82, 11); cout << " |  < | | '_  | '_  \  ";
	gotoxy(82, 12); cout << " | .  | | | | | | | | ";
	gotoxy(82, 13); cout << " |_|  \_\_|_| |_|_| |_| ";
	gotoxy(82, 14); cout << "                      ";
	
	SetColor(14);
	gotoxy(82, 17);
	cout << "User Manual:";
	gotoxy(82, 18);
	cout << "Use 'W', 'D', 'A'";
	gotoxy(82, 19);cout <<"or UpArrow, LeftArrow, DownArrow";

}

#endif

