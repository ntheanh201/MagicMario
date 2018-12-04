#include <iostream>
#include "author.h"
#include "startScreen.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	HWND console2 = GetConsoleWindow();
	RECT r;
	GetWindowRect(console2, &r); //stores the console's current dimensions
	
	//setup default values
	Nocursortype();
	settitle("Magic Mario - Kinn");
    
    //size of start screen
	MoveWindow(console2, r.left, r.top, 702, 530, TRUE);
	MenuManager();
	
//	system("pause");
}
