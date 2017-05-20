#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

#define W 50
#define H 15

int   Score;
COORD DirP, coord, foodP;
COORD zhangai[];

struct Snake
{
    int Len;
    int Body[W*H][2];
} snake;

void InitSnake()
{
    snake.Len = 1;
    snake.Body[0][0] = W / 2;
    snake.Body[0][1] = H / 2;

    srand((unsigned int)time(NULL));
    foodP.X = rand() % (W - 1) + 1;
    foodP.Y = rand() % (H - 1) + 1;

    Score = 0;
}

void ShowUI()
{
    for (int i = 0; i < W; i++)
    {
        putchar('+');
    }
    printf("\n");

    for (int i = 1; i < H + 1; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j == 0)
            {
                putchar('+');
            }
            else 	if (j == W - 1)
            {
                putchar('+');
                printf("\n");
            }
            else if (j == 5 && i > 2 && i < 10)
            {//障碍
                putchar('+');
            }
            else
            {
                putchar(' ');
            }
        }
    }

    for (int i = 0; i < W; i++)
    {
        putchar('+');
    }

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
        case 'A':DirP.X = -1;  DirP.Y = 0;	break;
        case 'D':DirP.X = 1;	DirP.Y = 0;	break;
        case 'W':DirP.X = 0;	DirP.Y = -1;	break;
        case 'S':DirP.X = 0;   DirP.Y = 1;	break;
        }

        for (int i = 1; i < snake.Len; i++)
        {
            if (snake.Body[0][0] == snake.Body[i][0] &&
                snake.Body[0][1] == snake.Body[i][1])
            {
                return;
            }
        }

        if (snake.Body[0][0] == foodP.X &&
            snake.Body[0][1] == foodP.Y)
        {
            snake.Len++;
            foodP.X = rand() % (W - 1) + 1;
            foodP.Y = rand() % (H - 1) + 1;
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

        Sleep(400);
        system("cls");
    }
    return;
}

void Begin()
{
    InitSnake();
    StartGame();
    //打印分数
    printf("游戏结束：\n分数:%d\n", Score);
}

int main()
{
    Begin();
    system("pause");
    return EXIT_SUCCESS;
}