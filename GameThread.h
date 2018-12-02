#include<iostream>
#include<fstream>
#include "mario.h"
#include "ghostManager.h"
using namespace std;

class GameThread{
	public:
		int score;
		void run();
		void init();
		Mario *ma;
		GhostManager *gama;
		char **maps;
		void draw();
		bool check();
		bool isWin();
};

void GameThread::init(){
	ifstream ifs("maps.txt");
	
	int rowMaps = 25;
	int colMaps = 80;
	
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
    
}

void GameThread::draw(){
	
	int rowMaps = 25;
	int colMaps = 80;
	
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
			else if(maps[i][j] == '&'){
				SetColor(19);
				gotoxy(j, i);
				cout << (char)254;
			}
			else if(maps[i][j] == '^'){
				SetColor(25);
				gotoxy(j, i);
				cout << (char)6;
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
			else if(maps[i][j] == '>'){
				SetColor(12);
				gotoxy(j, i);
				cout << ">";
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
}

void GameThread::run(){
	init();
	draw();
	while(1){
		ma->draw();
		gama -> draw();
		Sleep(100);
		ma->clear();
		gama->clear();
		int key;
		if(kbhit()){
			key = getch();
		}
		else key = '\0';
		gotoxy(0, 0);
		cout << (char) key;
		ma->update(key, maps);
		gama -> move();
		if(ma->isDie(maps) || check()){
			init();
			draw();
		}
		if(isWin()){
			break;
		}
	}
	SetColor(15);
	gotoxy(4, 10);
	cout << "Tinh nang dang duoc phat trien. Moi cac ban don cho phien ban tiep theo :v" << endl;
}

bool GameThread::check(){
	for(int i = 0; i < 15; i++){
		if((int)ma->x == (int)gama->myGhosts[i].x && (int)ma->y == (int)gama->myGhosts[i].y){
			return true;
		}
	}
	return false;
}

bool GameThread::isWin(){
	if((int)ma->x == 75 && (int)ma->y == 6){
		return true;
	}
	return false;
}
