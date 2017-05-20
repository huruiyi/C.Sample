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
    strcpy_s(p, 100, "变量作用域测试MemoryTest0");//此处报错，GetMemory0分配的内存在此处无法使用
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
    strcpy_s(p, 100, "变量作用域测试MemoryTest1"); //此处正确
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
    strcpy_s(p, 100, "变量作用域测试MemoryTest2"); //此处正确
    printf("%s\n", p);
}