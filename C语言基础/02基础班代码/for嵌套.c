#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void 循环嵌套()
{
    for (int i = 0; i < 24; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            printf("%2d\t", j);
        }
        printf("\n");
    }
}
// for /l %i in (1,1,5) do notepad

void SystemEx()
{
    system("for /l %i in (1,1,5) do calc");//打开5个记事本；

    system("for /l %i in (1,1,5) do start calc");//同时打开5个记事本；
    //%i  就是int的意思。do就是做。  start  同时；

    char str[50]; //字符串的长度
    wsprintf(str, "for /l %i in (1,1,5) do calc");
    system("str");
    //在命令行打印 后面的内容。

    //char str[50]; //字符串的长度
    //gets_s(str, 50);//  gets_s接受你的输入，保存到str  最大长度是50；
    //system(str);// 执行字符串；
}

void WsprintfDemo()
{
    int num = 5 + 3;//定义一个整数
    printf("%d", num);//打印整数
    char str[50];//字符串长度，设置50的缓冲区
    wsprintf(str, "for  /l %i  in (1,1,%d) do start calc", num);

    system(str);
}