#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define W 50
#define H 16

int   Score;
COORD DirP, coord, foodP;

struct Snake
{
	int Len;
	int Body[W*H];
	COORD SnakeP;
} snake;

void InitSnake()
{
	snake.Len = 1;
	snake.Body[0][0] = W / 2;
	snake.Body[0][1] = H / 2;

	srand((unsigned int)time(NULL));
	foodP.X = rand() % W;
	foodP.Y = rand() % H;

	Score = 0;
}

void ShowUI()
{
	for (int i = 0; i < snake.Len; i++)
	{
		coord.X = snake.Body[i][0];
		coord.Y = snake.Body[i][1];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar(i == 0 ? '@' : '*');
	}
	coord.X = foodP.X;
	coord.Y = foodP.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('*');
}

void StartGame()
{
	char key = 'W';
	while (
		snake.Body[0][0] >= 0 &&
		snake.Body[0][0] <= W &&
		snake.Body[0][1] >= 0 &&
		snake.Body[0][1] <= H)
	{
		ShowUI();
		while (_kbhit())
		{
			key = _getch();
		}
		switch (key)
		{
		case 'A':
			DirP.X = -1;
			DirP.Y = 0;
			break;
		case 'D':
			DirP.X = 1;
			DirP.Y = 0;
			break;
		case 'W':
			DirP.X = 0;
			DirP.Y = -1;
			break;
		case 'S':
			DirP.X = 0;
			DirP.Y = 1;
			break;
		}

		for (int i = 1; i < snake.Len; i++)
		{
			if (snake.Body[0][0] == snake.Body[i][0] && snake.Body[0][1] == snake.Body[i][1])
			{
				return;
			}
		}

		if (snake.Body[0][0] == foodP.X && snake.Body[0][1] == foodP.Y)
		{
			snake.Len++;
			foodP.X = rand() % W;
			foodP.Y = rand() % H;
			Score += 10;
		}

		//更新蛇的位置(不包含蛇头)
		for (int i = snake.Len - 1; i > 0; i--)
		{
			snake.Body[i][0] = snake.Body[i - 1][0];
			snake.Body[i][1] = snake.Body[i - 1][1];
		}

		//更新蛇头坐标
		snake.Body[0][0] += DirP.X;
		snake.Body[0][1] += DirP.Y;

		Sleep(250);
		system("cls");
	}
	return;
}

int main()
{
	InitSnake();
	StartGame();
	//打印分数
	printf("游戏结束：\n分数:%d\n", Score);
	return EXIT_SUCCESS;
}