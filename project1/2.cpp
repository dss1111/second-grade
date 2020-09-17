#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
/*
2014112037 Yoon jae moon
traffic light control program
2015-09-22
*/
void crosswalk();
void gotoxy(int x, int y);
void redTimeWork();
void yellowTimeWork();
void greenTimeWork();

int main()
{
	crosswalk();
	return 0;
}

void crosswalk()
{
	int walkTime,greenTime;
	int CurrentTime = 0;
	int runTime;
	printf("보행시간을 입력하세요(5~10) >>");
	scanf("%d", &walkTime);
	printf("녹색불이 지속될시간을 입력하세요(20~30) >>");
	scanf("%d",&greenTime);
	system("cls");
	do
	{
		gotoxy(1, 1);
		printf("%d",CurrentTime++);
		runTime = CurrentTime%(greenTime+walkTime+3);
		if (runTime <= greenTime)
		{
			greenTimeWork();
		}
		else if (runTime<=greenTime + 3)
		{
			yellowTimeWork();
		}
		else if (runTime <= greenTime + walkTime+3)
		{
			redTimeWork();
		}
		Sleep(300);
	} while (!kbhit());
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void greenTimeWork()
{
	/*
	while green light on, this function operated 
	*/
	gotoxy(30, 3);
	printf("Don't Walk\n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 5);
	printf("Ⅰ----Ⅰ GREEN\n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(24, 7);
	printf("GREEN Ⅰ----Ⅰ \n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 9);
	printf("Don't Walk\n");
}
void yellowTimeWork()
{
	/*
	while yellow light on, this function operated
	*/
	gotoxy(30, 3);
	printf("Don't Walk\n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 5);
	printf("Ⅰ----Ⅰ YELLOW\n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(23, 7);
	printf("YELLOW Ⅰ----Ⅰ \n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 9);
	printf("Don't Walk\n");
}
void redTimeWork()
{
	/*
	while red light on, this function operated
	*/
	gotoxy(30, 3);
	printf("  Walk    \n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 5);
	printf("Ⅰ----Ⅰ RED   \n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(23, 7);
	printf("   RED Ⅰ----Ⅰ \n");
	printf("-----------------------------Ⅰ----Ⅰ------------------------\n");
	gotoxy(30, 9);
	printf("  Walk    \n");
}