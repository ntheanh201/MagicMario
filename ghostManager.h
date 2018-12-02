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
	myGhosts.push_back(Ghost(17, 23, 3, 25, RIGHTn));
//	myGhosts.push_back(Ghost(34, 23, 29, 36, LEFTn));
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
