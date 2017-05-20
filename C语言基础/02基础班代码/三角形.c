#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void 三角ABC()
{
    int row = 0;
    printf("请输入行数\n");
    scanf("%d", &row);
    int max = 2 * row - 1;
    for (int i = 1; i < row + 1; i++)
    {
        int kong = row - i;

        for (int i = 0; i < kong; i++)
        {
            printf(" ");
        }

        int flag = 0;
        for (int j = 0; j < i * 2 - 1; j++)
        {
            if (kong + j < row)
            {
                printf("%c", 'A' + j);
                flag = 1;
            }
            else
            {
                flag++;
                printf("%c", 'A' + row - flag - (row - i));
            }
        }
        printf("\n");
    }
}

void 正三角()
{
    int row = 0;
    printf("请输入行数\n");
    scanf("%d", &row);
    int max = 2 * row - 1;
    for (int i = 1; i < row + 1; i++)
    {
        int kong = row - i;

        for (int i = 0; i < kong; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < i * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void 菱形()
{
    int row = 0;
    scanf("%d", &row);
    printf("请输入行数\n");
    int max = 2 * row - 1;
    for (int i = 1; i < row + 1; i++)
    {
        int kong = row - i;

        for (int i = 0; i < kong; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < i * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (int i = row - 1; i >= 1; i--)
    {
        int kong = row - i;
        for (int i = 0; i < kong; i++)
        {
            printf(" ");
        }

        for (int j = 0; j < i * 2 - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}