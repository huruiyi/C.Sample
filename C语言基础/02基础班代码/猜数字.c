#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void ������While()
{
    //���������
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100

    int value = 0;
    while (1)
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("�������̫����\n");
        }
        else if (value < num)
        {
            printf("�������̫С��\n");
        }
        else
        {
            printf("��ϲ�����\n");
            break;
        }
    }
}

void ������For()
{
    int value = 0;
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100

    for (int i = 0; ; i++)
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("�������̫����\n");
        }
        else if (value < num)
        {
            printf("�������̫С��\n");
        }
        else
        {
            printf("��ϲ�����\n");
            break;
        }
    }
}

void ������DoWhile()
{
    int value = 0;
    srand((unsigned int)time(NULL));
    int num = rand() % 100 + 1; //0-99 //1-100
    do
    {
        scanf("%d", &value);
        if (value > num)
        {
            printf("�������̫����\n");
        }
        else if (value < num)
        {
            printf("�������̫С��\n");
        }
        else
        {
            printf("��ϲ�����\n");
            break;
        }
    } while (value != num);
}