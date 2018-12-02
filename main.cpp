#include <iostream>
#include "GameThread.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Nocursortype();
	GameThread game;
	game.run();
	system("pause");
}
