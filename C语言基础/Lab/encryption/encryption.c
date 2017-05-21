#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "encryption.h"

__declspec(dllexport)
void * InEncry(char * ch, int len)
{
    short * temp = malloc(sizeof(short)*len + 1);
    memset(temp, 0, sizeof(short)*len + 1);
    for (int i = 0; i < len; i++)
    {
        temp[i] = *ch;
        temp[i] = temp[i] << 2;
        temp[i] = temp[i] | (0x7fff + 1);
        ch++;
    }
    return temp;
}

__declspec(dllexport)
char * OutEncry(void * ch, int len)
{
    char * temp = malloc(sizeof(char)* len + 1);
    memset(temp, 0, sizeof(char)* len + 1);
    short* ch1 = (short*)ch;
    for (int i = 0; i < len; i++)
    {
        ch1[i] = ch1[i] << 1;
        ch1[i] = ch1[i] >> 3;
        temp[i] = ch1[i];
    }
    return temp;
}