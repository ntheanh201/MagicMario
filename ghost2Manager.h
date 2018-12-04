#include "ghost2.h"
#include <vector>
using namespace std;

class Ghost2Manager{
	public:
		vector <Ghost2> myGhosts2;
		void draw();
		void clear();
		void move();
		Ghost2Manager();
};

Ghost2Manager::Ghost2Manager(){
	myGhosts2.push_back(Ghost2(65, 4, 3, 6, UPn));
}

void Ghost2Manager::draw(){
	for(int i = 0; i < myGhosts2.size(); i++){
		myGhosts2[i].draw();
	}
}

void Ghost2Manager::clear(){
	for(int i = 0; i < myGhosts2.size(); i++){
		myGhosts2[i].clear();
	}
}

void Ghost2Manager::move(){
	for(int i = 0; i < myGhosts2.size(); i++){
		myGhosts2[i].move();
	}
}
