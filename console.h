#ifndef console
#define console

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define _WIN64_WINNT 0x0500
#include <windows.h>
using namespace std;

//HWND WINAPI GetConsoleWindow(void);

inline void settitle(char *title) //dat tieu de chon console
{
    SetConsoleTitle(title);
}

void gotoxy(int x,int y)
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x,y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Cai mau sac cho chu
void SetColor (int k)
{
	HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, k);
}

void TextColor(WORD color) //set text color
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
 
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
 
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

//Chong nhay
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

inline char getcharxy(int x, int y) //lay ky tu tai vi tri chuot
{
    char c;
    HANDLE hOut;
    COORD Where;
    DWORD NumRead;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Where.X = x;
    Where.Y = y;
    ReadConsoleOutputCharacter(hOut,&c,1,Where,&NumRead);
    return c;
}
inline int wherex() //lay vi tri toa do hien tai x cua con tro
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE ),&csbi)) return -1;
  else return csbi.dwCursorPosition.X;
}
int wherey()//lay vi tri toa do hien tai y cua con tro
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE ),&csbi)) return -1;
  else return csbi.dwCursorPosition.Y;
}
#endif

