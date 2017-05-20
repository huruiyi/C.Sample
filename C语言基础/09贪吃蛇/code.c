#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>

int BeeBody[5][5] =
{
    { ' ',' ','^',' ',' ' },
    { ' ','^','^','^',' ' },
    { '^','^','^','^','^' },
    { ' ','^','^','^',' ' },
    { '^','^','^','^','^' }
};
COORD Coord;
COORD BeePos;
void KbHitDemo()
{
    while (1)
    {
        while (_kbhit())
        {
            char x = _getch();
            printf("∞¥¡À£∫%c\n", x);
        }
    }

    system("pause");
}

void InitBee()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            Coord.X = BeePos.X + j;
            Coord.Y = BeePos.Y + i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coord);
            putchar(BeeBody[i][j]);
        }
    }
}

static TCHAR buffer_temp[10];

TCHAR * int2ptchar(unsigned int i)
{
    wsprintf(buffer_temp, TEXT("%d"), i);
    return buffer_temp;
}
void Test()
{
    TCHAR * s = int2ptchar(71);

    char carr[] = { '*',' ' ,' ' , ' ' ,' ' ,' ' ,' ' ,'*', '\n',
    '*',' ' ,' ' , ' ' ,' ' ,' ' ,' ' ,'*', '\n',
    '*',' ' ,' ' , ' ' ,' ' ,' ' ,' ' ,'*', '\n',
    '*',' ' ,' ' , ' ' ,' ' ,' ' ,' ' ,'*', '\n','\0' };
    printf("%s", carr);
}