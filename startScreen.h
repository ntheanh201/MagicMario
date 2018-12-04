#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "console.h"
#include "GameThread.h"
#include "author.h"
using namespace std;

void MenuManager();

void loadingScreen(){ //loading screen
	SetColor(10);
	for(int i = 1; i < 100; i+=5){
		system("cls");
		gotoxy(34, 10);
		cout << "Loading: "<< i << "% \n";
		Sleep(50);
	}
	Sleep(200);
	system("cls");
}

void menuBorder(){ //border of menu
	SetColor(12);
	int rowMaps = 26;
	int colMaps = 82;
	
	for(int i = 0; i < colMaps; i++){
		gotoxy(i, 0); printf("%c", 177);
	}
    for(int i = 0; i < colMaps; i++){
		gotoxy(i, rowMaps); printf("%c", 177);
	}
	for(int j = 0; j <= rowMaps; j++){
		gotoxy(0, j); printf("%c", 177);
	}
	for(int j = 0; j <= rowMaps; j++){
		gotoxy(colMaps, j); printf("%c", 177);
	}
	
    gotoxy(34, 0); SetColor(15); printf(" MAGIC MARIO ");
	SetColor(15);
	
	for(int i = 0; i < colMaps - 36; i++){
		gotoxy(18+i, rowMaps - 6); printf("%c", 205);
	}
		for(int i = 0; i < colMaps - 36; i++){
		gotoxy(18+i, rowMaps - 2); printf("%c", 205);
	}
	SetColor(10);
	gotoxy(24, rowMaps - 4); cout << "https://www.facebook.com/theanhh20";
//	SetColor(15);
}

void selectPlay(){
//	Levels of game. This feature will be appeared at next version.

//	menuBorder();
//	gotoxy(32, 10); printf(" SELECT LEVEL:");
//	SetColor(15);
//	gotoxy(32, 11); printf("%c    EASY     ", 175);
//	SetColor(10);
//	gotoxy(32, 12); printf("    NORMAL    ");
//	gotoxy(32, 13); printf("     HARD.    ");
//	
//	int coor = 11;
//	int selected = 0;
//	do {
//		char a = getch();
//		if(a == 80 || a == 's'||a == 'S' || a == '2') selected = 1;
//		else if(a == 72 || a == 'w' ||a == 'W'|| a == '8') selected = 2;
//		else if(a == 13 || a == '5') selected = 3;
//		else selected = 0;
//		if(selected == 1 && coor < 14) coor++;
//		else if(selected == 2 && coor > 11) coor--;
//		if(coor == 11){
//			gotoxy(32, 11); printf("%c    EASY     ", 175);
//			SetColor(10);
//			gotoxy(32, 12); printf("     NORMAL    ");
//			gotoxy(32, 13); printf("     HARD.    ");
//		}
//		if(coor == 12){
//			gotoxy(32, 11); printf("     EASY     ");
//			SetColor(15);
//			gotoxy(32, 12); printf("%c   NORMAL   ", 175);
//			SetColor(10);
//			gotoxy(32, 13); printf("     HARD.    ");
//		}
//		if(coor == 13){
//			gotoxy(32, 11); printf("     EASY     ");
//			gotoxy(32, 12); printf("     NORMAL    ");
//			SetColor(15);
//			gotoxy(32, 13); printf("%c    HARD.    ", 175);
//			SetColor(10);
//		}
//	} while(selected != 3);
//	
//	if(coor == 11){
//		system("cls");
//		//size of playing window
//		MoveWindow(console2, r.left, r.top, 1000, 512, TRUE);
//		author();
//		GameThread game;
//		game.run(1);
//	}
//	
//	if(coor == 12){
//		system("cls");
//		//size of playing window
//		MoveWindow(console2, r.left, r.top, 1000, 512, TRUE);
//		author();
//		GameThread game;
//		game.run(2);
//	}
//	
//	if(coor == 13){
//		system("cls");
//		//size of playing window
//		MoveWindow(console2, r.left, r.top, 1000, 512, TRUE);
//		author();
//		GameThread game;
//		game.run(3);
//	}
	
	system("cls");
	//size of playing window
	
	HWND console2 = GetConsoleWindow();
	RECT r;
	GetWindowRect(console2, &r); //stores the console's current dimensions
	
	MoveWindow(console2, r.left, r.top, 1000, 512, TRUE);
	author();
	GameThread game;
	game.run();
	
	system("pause > nul");
}

void selectAbout(){
	system("cls");
	int i = 2;
	while(1){
		srand(time(NULL));
		SetColor(rand()%16+2);
		gotoxy(32, i);    cout << "PPPPPPPPPPPROPTIT";
		gotoxy(32, i+1);  cout << "P::::::::::::::::P";
		gotoxy(32, i+2);  cout << "P::::::PPPPPP:::::P";
		gotoxy(32, i+3);  cout << "PP:::::P     P:::::P";
		gotoxy(32, i+4);  cout << "  P::::P     P:::::P";
		gotoxy(32, i+5);  cout << "  P::::P     P:::::P";
		gotoxy(32, i+6);  cout << "  P::::PPPPPP:::::P";
		gotoxy(32, i+7);  cout << "  P:::::::::::::PP";
		gotoxy(32, i+8);  cout << "  P::::PPPPPPPP";
		gotoxy(32, i+9);  cout << "  P::::P";
		gotoxy(32, i+10); cout << "  P::::P";
		gotoxy(32, i+11); cout << "  P::::P";
		gotoxy(32, i+12); cout << "  P::::P";
		gotoxy(32, i+13); cout << "  PPPPPP";
	
		SetColor(15);
		gotoxy(32, i+15); printf("ABOUT THE AUTHOR:");
		gotoxy(23, i+16); printf("Nguyen The Anh - PROPTIT'S MEMBER");
		SetColor(4);
		gotoxy(26, i+17); printf("Press X to return main screen");
		
		if(kbhit()){
			char key = getch();
			if(key == 'x'){
				system("cls");
				MenuManager();
			}
		}
		//Footer
		SetColor(15);
		for(int i = 0; i < colMaps - 36; i++){
			gotoxy(18+i, rowMaps - 6); printf("%c", 205);
		}
			for(int i = 0; i < colMaps - 36; i++){
			gotoxy(18+i, rowMaps - 2); printf("%c", 205);
		}
		SetColor(10);
		gotoxy(24, rowMaps - 4); cout << "https://www.facebook.com/theanhh20";	
	}
	system("pause > nul");
}

void selectExit(){ //if player select exit
	return;
}

void menuSelection(){ //menu selection
	gotoxy(32, 10); printf("MENU SELECTION");
	SetColor(15);
	gotoxy(32, 11); printf("%c    PLAY     ", 175);
	SetColor(10);
	gotoxy(32, 12); printf("     ABOUT    ");
	gotoxy(32, 13); printf("     EXIT.    ");
	int coor = 11;
	int selected = 0;
	do {
		char a = getch();
		if(a == 80 || a == 's'||a == 'S' || a == '2') selected = 1;
		else if(a == 72 || a == 'w' ||a == 'W'|| a == '8') selected = 2;
		else if(a == 13 || a == '5') selected = 3;
		else selected = 0;
		if(selected == 1 && coor < 13) coor++;
		else if(selected == 2 && coor > 11) coor--;
		if(coor == 11){
			SetColor(15);
			gotoxy(32, 11); printf("%c    PLAY     ", 175);
			SetColor(10);
			gotoxy(32, 12); printf("     ABOUT    ");
			gotoxy(32, 13); printf("     EXIT.    ");
		}
		if(coor == 12){
			gotoxy(32, 11); printf("     PLAY     ");
			SetColor(15);
			gotoxy(32, 12); printf("%c    ABOUT    ", 175);
			SetColor(10);
			gotoxy(32, 13); printf("     EXIT.    ");
		}
		if(coor == 13){
			gotoxy(32, 11); printf("     PLAY     ");
			gotoxy(32, 12); printf("     ABOUT    ");
			SetColor(15);
			gotoxy(32, 13); printf("%c    EXIT.    ", 175);
			SetColor(10);
		}
	} while(selected != 3);
	
	if(coor == 11){
		selectPlay();
	}
	
	if(coor == 12){
		selectAbout();
	}
	
	if(coor == 13){
		exit(1);
	}
	system("cls");
}

void MenuManager(){
	Nocursortype();
	loadingScreen();
	menuBorder();
	menuSelection();
}
