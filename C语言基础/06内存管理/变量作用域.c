#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void GetMemory0(char * p)
{
    p = (char *)malloc(100);
}

void MemoryTest0()
{
    char *p = NULL;
    GetMemory0(p);
    strcpy_s(p, 100, "�������������MemoryTest0");//�˴�����GetMemory0������ڴ��ڴ˴��޷�ʹ��
    printf("%s\n", p);
}

char * GetMemory1(char * p)
{
    p = (char *)malloc(100);
    return p;
}

void MemoryTest1()
{
    char *p = NULL;
    p = GetMemory1(p);
    strcpy_s(p, 100, "�������������MemoryTest1"); //�˴���ȷ
    printf("%s\n", p);
}

void GetMemory2(char ** p)
{
    *p = (char *)malloc(100);
}

void MemoryTest2()
{
    char *p = NULL;
    GetMemory2(&p);
    strcpy_s(p, 100, "�������������MemoryTest2"); //�˴���ȷ
    printf("%s\n", p);
}