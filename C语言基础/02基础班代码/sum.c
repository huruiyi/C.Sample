#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int GetSum1(int max)
{
    int sum = 0;
    for (int i = 0; i <= max; i++)
    {
        sum += i;
    }
    return sum;
}

int GetSum2(int max)
{
    int i = 0;
    int sum = 0;
    while (i <= max)
    {
        sum += i++;
    }
}