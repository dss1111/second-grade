#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
/*
2014112037 Yoon jae moon
Omok program
2015-09-22
*/
void draw_check01(int colum, int row);	
void gotoxy(int x, int y);
void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void game_control();
void display_stone(int matrix[][20][20]);
int judgement(int matrix[][20][20],int other);
int main()
{
	game_control();
	return 0;
}
void draw_check01(int c, int r)
{
	/*
	function that show check on console window
	*/
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];
	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[8]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r - 1; i++)
	{
		printf("%c%c", a, b[7]);
		for (j = 0; j < c - 1; j++)
			printf("%c%c", a, b[11]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < c - 1; i++)
		printf("%c%c", a, b[10]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	/*
	function that get key by keyboard
	*/
	switch (key)
	{
	case 72:
		*y1 = *y1 - 1;
		if (*y1 < 1) *y1 = 1;
			break;
	case 75:
		*x1 = *x1 - 2;
		if (*x1 < 1) *x1 = 1;
			break;
	case 77:
		*x1 = *x1 + 2;
		if (*x1>x_b) *x1 = x_b;
			break;
	case 80:
		*y1 = *y1 + 1;
		if (*y1 > y_b) *y1 = y_b;
			break;
	default:
		return;
	}
}
void gotoxy(int x, int y)	//function that set position of console window
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void game_control()
{
	int x = 1, y = 1, matrix[2][20][20] = { 0, };
	int turn = 1;
	struct recordInfo	//structure to store the location of the stone
	{
		int x;
		int y;
	};
	recordInfo matrixRecord[400] = { 0, };	//matrixRecord[turn]   every turn, store structure that store the location of the stone 
	int other = 0;
	char key;
	char *stone[2] = { "○", "●" };
	do
	{
		gotoxy(1, 1);
		draw_check01(18, 18);
		gotoxy(x, y);
		printf("%s",stone[other]);
		display_stone(matrix);
		gotoxy(1, 20);
		printf("방향키로 움직이고");
		printf("스페이스 키를누르시오.");
		gotoxy(1, 21);
		printf("돌을 놓았으면 상대방 차례입니다.\n");
		printf("백스페이스를 누르면 수를 무를수있습니다.\n");
		printf("%d번째턴",turn);
		key = getch();
		if (key == 27)
			exit(0);
		else if (key == 8)	//key input == backspace
		{
			if (turn > 1)
			{
				other = 1 - other;
				turn--;
				matrix[other][matrixRecord[turn].x][matrixRecord[turn].y] = 0;	//It means delete data of last turn and turn back
			}
		}
		else if (key == 32)	//key input == space bar
		{
			if (matrix[0][(x + 1) / 2][y]!= 1 && matrix[1][(x + 1) / 2][y] != 1) //conditional that prevent stone duplication
			{
				matrix[other][(x + 1) / 2][y] = 1;
				matrixRecord[turn].x = (x + 1) / 2;
				matrixRecord[turn].y = y;
				turn++;
				other = 1 - other;
			}
		}
		else if (key >= 72)
			move_arrow_key(key, &x, &y, 37, 19);
	} while (judgement(matrix, 1-other));
}
void display_stone(int matrix[][20][20])
{
	int i,x, y;
	char *stone[2] = { "○", "●" };
	for (i = 0; i < 2;i++)
		for (x = 1; x < 20; x++)
			for (y = 1; y < 20; y++)
			{
				if (matrix[i][x][y] == 1)
				{
					gotoxy(x * 2 - 1, y);
					printf("%s",stone[i]);
				}
			}
}
int judgement(int matrix[][20][20], int other)
{
	/*
	This function check that whether 5 stone laied on in a row;
	*/
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (matrix[other][i][j] == 1 && matrix[other][i - 1][j + 1] == 1 && matrix[other][i - 2][j + 2] == 1 && matrix[other][i - 3][j + 3] == 1 && matrix[other][i - 4][j + 4] == 1)
				return 0;
			else if (matrix[other][i][j] == 1 && matrix[other][i + 1][j + 1] == 1 && matrix[other][i + 2][j + 2] == 1 && matrix[other][i + 3][j + 3] == 1 && matrix[other][i + 4][j + 4] == 1)
				return 0;
			else if (matrix[other][i][j] == 1 && matrix[other][i][j + 1] == 1 && matrix[other][i][j + 2] == 1 && matrix[other][i][j + 3] == 1 && matrix[other][i][j + 4] == 1)
				return 0;
			else if (matrix[other][i][j] == 1 && matrix[other][i + 1][j] == 1 && matrix[other][i + 2][j] == 1 && matrix[other][i + 3][j] == 1 && matrix[other][i + 4][j] == 1)
				return 0;
		}
	}
		return 1;
}