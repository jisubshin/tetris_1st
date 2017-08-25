#include <iostream>
#include <Windows.h>
#include <conio.h>
//스페이스바 - 회전
using namespace std;

void gotoxy(int x, int y)
{
	COORD Cur = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void spin(char(*block)[4]){
	char tmp[4][4] = { 0 };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			tmp[j][3 - i] = block[i][j];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = tmp[i][j];
}

void keyboard(char(*block)[4]) {
	int key = _getch();
	if (key == 32)
		spin(block);
}

void draw(char(*block)[4]){
	system("cls");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			gotoxy(2*j, i);
			if (block[i][j] == 1)
				printf("■");
			else
				printf("□");
		}
	}
}

void main(){
	char block[4][4] = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	};
	while (1){
		draw(block);
		keyboard(block);
	}
}