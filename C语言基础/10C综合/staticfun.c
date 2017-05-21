#include<stdio.h>
#include<stdlib.h>

typedef int(*PSAdd)(int, int);

/*^_^*\

/*
    static静态函数只在当前文件中可以访问。外部文件不可访问，除非包含当前文件
*/
static int Sadd(int a, int b)
{
    return a + b;
}

void InvorkeSadd(int a, int b)
{
    return Sadd(a, b);
}