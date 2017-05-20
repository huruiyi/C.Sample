#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void 猜数字While()
{
    //生成随机数
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100

    int value = 0;
    while (1)
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("你输入的太大了\n");
        }
        else if (value < num)
        {
            printf("你输入的太小了\n");
        }
        else
        {
            printf("恭喜你对了\n");
            break;
        }
    }
}

void 猜数字For()
{
    int value = 0;
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100

    for (int i = 0; ; i++)
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("你输入的太大了\n");
        }
        else if (value < num)
        {
            printf("你输入的太小了\n");
        }
        else
        {
            printf("恭喜你对了\n");
            break;
        }
    }
}

void 猜数字DoWhile()
{
    int value = 0;
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100
    do
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("你输入的太大了\n");
        }
        else if (value < num)
        {
            printf("你输入的太小了\n");
        }
        else
        {
            printf("恭喜你对了\n");
            break;
        }
    } while (value != num);
}