#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//清除首尾空格
void DelEmpty(char * src, char * des)
{
    int i = 0;
    int j = strlen(src) - 1;
    char *start = NULL;
    char *end = NULL;
    while (*(src + i))
    {
        if (*(src + i) != 32)
        {
            start = src + i;
            break;
        }
        i++;
    }

    while (*(src + j))
    {
        if (*(src + j) != 32)
        {
            end = src + j;
            break;
        }
        j--;
    }

    int k = 0;
    for (char* i = start; i <= end; i++, k++)
    {
        des[k] = *(start + k);
    }

    //char src[] = { "   Hello    World    " };
    //char des[256] = { 0 };
    //Del(src, des);
}

//清楚所有空格
void   ClearSpance(char * src, char * des)
{
    int i = 0;
    while (*src++)
    {
        if (*(src - 1) != 32)
        {
            des[i] = *(src - 1);
            i++;
        }
    }

    //char src[] = { "   Hello    World    " };
    //char des[256] = { 0 };
    //ClearSpance(src, des);
    //printf("%s\n", des);
}