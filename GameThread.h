#include<iostream>
#include<fstream>
#include "mario.h"
#include "ghostManager.h"
#include "giftManager.h"
#include "ghost2Manager.h"

using namespace std;

	int rowMaps = 26;
	int colMaps = 82;

class GameThread{
	public:
		int score;
		void run();
		void init();
		Mario *ma;
		GhostManager *gama;
		Ghost2Manager *ghost2;
		GiftManager *gifts;
		char **maps;
		void draw();
		bool check(); //check with ghosts
		bool isWin();
		void increaseScore(char **maps);
};

void GameThread::init(){
	ifstream ifs("maps.txt");
	
	maps = new char *[rowMaps];
	for(int i = 0; i < rowMaps; i++){
		maps[i] = new char [colMaps];
	}
	for(int i = 0; i < rowMaps; i++){
		for(int j = 0; j < colMaps; j++){
			ifs >> maps[i][j];
		}
	}
    ifs.close();
    score = 0;
    ma = new Mario;
    gama = new GhostManager;
    ghost2 = new Ghost2Manager;
    gifts = new GiftManager;
}

void GameThread::draw(){
	
	for(int i = 0; i < rowMaps; i++){
		for(int j = 0; j < colMaps; j++){
			if(maps[i][j] == '.'){
				SetColor(0);
				gotoxy(j, i);
				cout << " ";
			}
			else if(maps[i][j] == '#'){
				SetColor(12);
				gotoxy(j, i);
				cout << (char) 177;
			}
			else if(maps[i][j] == '@'){
				SetColor(15);
				gotoxy(j, i);
				cout << (char)178;
			}
			else if(maps[i][j] == 'a'){
				SetColor(0);
				gotoxy(j, i);
				cout << " ";
			}
			else if(maps[i][j] == 'p'){
				SetColor(10);
				gotoxy(j, i);
				cout << (char)178;
			}
			else if(maps[i][j] == '0'){
				SetColor(9);
				gotoxy(j, i);
				cout << (char) 4;
			}
			else if(maps[i][j] == '?'){
				SetColor(230);
				gotoxy(j, i);
				cout << "?";
			}
			else if(maps[i][j] == '!'){
				SetColor(36);
				gotoxy(j, i);
				cout << "?";
			}
			else if(maps[i][j] == '|'){
				SetColor(25);
				gotoxy(j, i);
				cout << (char)222;
			}
			else if(maps[i][j] == '*'){
				SetColor(12);
				gotoxy(j, i);
				cout << "*";
			}
			else if(maps[i][j] == '['){
				SetColor(12);
				gotoxy(j, i);
				cout << "[";
			}
			else if(maps[i][j] == ']'){
				SetColor(12);
				gotoxy(j, i);
				cout << "]";
			}
			else {
				SetColor(0);
				gotoxy(j, i);
				cout << " ";
			}
			SetColor(0);
		}
		cout << endl;
	}
	SetColor(15); gotoxy(1, 0); cout << "Score: ";
	gotoxy(27, 25);
	cout << "NGUYEN THE ANH";
}

void GameThread::run(){
	init();
	draw();
	while(1){
		increaseScore(maps);
		ma->draw();
		gama -> draw();
		ghost2 -> draw();
		Sleep(100);
		ma->clear();
		gama->clear();
		ghost2->clear();
		int key;
		if(kbhit()){
			key = getch();
		}
		else key = '\0';
		SetColor(15);
		gotoxy(8, 0);
		cout << score;
		ma->update(key, maps);
		gama -> move();
		ghost2 -> move();
		if(ma->isDie(maps) || check()){
			init();
			draw();
		}
		if(isWin()){
			break;
		}
	}
	SetColor(15);
	gotoxy(10, 9); cout << "Chuc mung ban da giai cuu duoc Cong chua. Diem cua ban la: " << score;
	gotoxy(10, 10);
	cout << "Tuy nhien, khong lau sau do cong chua lai bi bat di   ";
	gotoxy(10, 11);
	cout << "boi mot ga ten la Kinn. Nhung thu thach nao dang cho";
	gotoxy(10, 12);
	cout << "don ban o phia truoc. Hay cho doi phien ban tiep theo";
	gotoxy(10, 13);
	cout << "                                                                     ";
}

bool GameThread::check(){
	for(int i = 0; i < gama->myGhosts.size(); i++){
		if((int)ma->x == (int)gama->myGhosts[i].x && (int)ma->y == (int)gama->myGhosts[i].y || ((int)ma->x == (int)ghost2->myGhosts2[i].x && (int)ma->y == (int)ghost2->myGhosts2[i].y)){
			return true;
		}
	}
	return false;
}

bool GameThread::isWin(){
	if((int)ma->x == 74 && (int)ma->y == 6){
		return true;
	}
	return false;
}

void GameThread::increaseScore(char **maps){
	if(maps[(int)ma->y][(int)ma->x] == '?'){
		score += 10;
		maps[(int)ma->y][(int)ma->x] = '.';
	}
	if(maps[(int)ma->y][(int)ma->x] == '!'){
		score += 20;
		maps[(int)ma->y][(int)ma->x] = '.';
	}
	if(maps[(int)ma->y][(int)ma->x] == '0'){
		score += 30;
		maps[(int)ma->y][(int)ma->x] = '.';
	}
}


