#include<stdio.h>
#include<stdlib.h>

typedef int(*PSAdd)(int, int);

/*^_^*\

/*
    static��̬����ֻ�ڵ�ǰ�ļ��п��Է��ʡ��ⲿ�ļ����ɷ��ʣ����ǰ�����ǰ�ļ�
*/
static int Sadd(int a, int b)
{
    return a + b;
}

void InvorkeSadd(int a, int b)
{
    return Sadd(a, b);
}