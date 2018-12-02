#include "ghost.h"
#include <vector>
using namespace std;

class GhostManager{
	public:
		vector <Ghost> myGhosts;
		void draw();
		void clear();
		void move();
		GhostManager();
};

GhostManager::GhostManager(){
	myGhosts.push_back(Ghost(17, 23, 4, 25, RIGHTn));
	myGhosts.push_back(Ghost(34, 23, 29, 36, LEFTn));
	myGhosts.push_back(Ghost(42, 23, 41, 47, RIGHTn));
	myGhosts.push_back(Ghost(57, 23, 52, 57, RIGHTn));
	myGhosts.push_back(Ghost(75, 23, 72, 78, RIGHTn));
	myGhosts.push_back(Ghost(67, 15, 25, 72, RIGHTn));
	myGhosts.push_back(Ghost(62, 15, 25, 72, LEFTn));
	myGhosts.push_back(Ghost(60, 15, 25, 72, LEFTn));
	myGhosts.push_back(Ghost(46, 15, 25, 72, RIGHTn));
	myGhosts.push_back(Ghost(12, 15, 10, 22, RIGHTn));
	myGhosts.push_back(Ghost(15, 15, 10, 22, LEFTn));
	myGhosts.push_back(Ghost(11, 6, 9, 12, LEFTn));
	myGhosts.push_back(Ghost(29, 6, 26, 53, RIGHTn));
	myGhosts.push_back(Ghost(35, 6, 26, 53, RIGHTn));
}

void GhostManager::draw(){
	for(int i = 0; i < myGhosts.size(); i++){
		myGhosts[i].draw();
	}
}

void GhostManager::clear(){
	for(int i = 0; i < myGhosts.size(); i++){
		myGhosts[i].clear();
	}
}

void GhostManager::move(){
	for(int i = 0; i < myGhosts.size(); i++){
		myGhosts[i].move();
	}
}
