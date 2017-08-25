#include <iostream>
#include <Windows.h>
#include <conio.h>
//방향키 - 이동, 스페이스바 - 회전, 엔터 - 모양변경
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

void change_block(char(*block)[4], char shape){
	char blocko[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	char blockI[4][4] = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 }
	};
	char blockT[4][4] = {
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	};
	char blockS[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	char blockZ[4][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	};
	char blockJ[4][4] = {
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	char blockL[4][4] = {
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	};
	switch (shape){
	case 'o':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blocko[i][j];
		break;
	case 'I':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockI[i][j];
		break;
	case 'T':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockT[i][j];
		break;
	case 'S':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockS[i][j];
		break;
	case 'Z':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockZ[i][j];
		break;
	case 'J':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockJ[i][j];
		break;
	case 'L':
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			block[i][j] = blockL[i][j];
		break;
	}
}

void keyboard(char(*block)[4], int *x, int *y, char *block_status) {
	int key = _getch();
	if (key == 0xE0 || key == 0) {
		key = _getch();
		switch (key){
		case 72:
			(*y)--;
			break;
		case 75:
			(*x)--;
			break;
		case 77:
			(*x)++;
			break;
		case 80:
			(*y)++;
			break;
		default:
			break;
		}
		if (*y < 0)
			(*y)++;
		else if (*x < 0)
			(*x)++;
		else if (*y > 20)
			(*y)--;
		else if (*x > 36)
			(*x)--;
	}
	else if (key == 32){
		spin(block);
	}
	else if (key == 13){
		switch (*block_status){
		case 'o':
			*block_status = 'I';
			break;
		case 'I':
			*block_status = 'T';
			break;
		case 'T':
			*block_status = 'S';
			break;
		case 'S':
			*block_status = 'Z';
			break;
		case 'Z':
			*block_status = 'J';
			break;
		case 'J':
			*block_status = 'L';
			break;
		case 'L':
			*block_status = 'o';
			break;
		}
		change_block(block, *block_status);
	}
}

void draw(char(*block)[4], int x, int y){
	system("cls");
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			gotoxy(x + 2 * j, y + i);
			if (block[i][j] == 1)
				printf("■");
			else
				printf("□");
		}
	}
}

void main(){
	int x = 5, y = 5;
	char block_status = 'o';
	char block[4][4] = { 0 };
	change_block(block, block_status);
	while (1){
		draw(block, x, y);
		keyboard(block, &x, &y, &block_status);
	}
}