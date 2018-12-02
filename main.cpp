#include <iostream>
#include<windows.h>
#include "GameThread.h"
#include "author.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Nocursortype();
	settitle("Magic Mario - Kinn");
	author();
	GameThread game;
	game.run();
	system("pause > nul");
}
