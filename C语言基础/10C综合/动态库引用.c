#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<Windows.h>

#include "math\math.h"
#pragma comment(lib,".\\math\\math.lib")

void TestAdd()
{
    int value1 = Add(1, 2);
    printf("%d\n", value1);
}

#include "encrypt\encryption.h"
#pragma comment(lib,".\\encrypt\\encryption.lib")

void Testencrypt1()
{
    char *data = "#pragma comment(lib,\".\encrypt\encryption.lib\")";
    void *edata = InEncry(data, strlen(data));
    printf("%s\n", edata);

    void *jdata = OutEncry(edata, strlen(data));
    printf("%s\n", jdata);
}

typedef void *( * Func)(char *, int);
void Testencrypt2()
{
    HANDLE hDll; //声明一个dll实例文件句柄
    hDll = LoadLibrary("./encrypt/encryption.dll"); //导入动态链接库

    Func   fun; //创建函数指针
    fun = (Func)GetProcAddress(hDll, "InEncry"); //获取导入函数的函数指针

    char *data = "#pragma comment(lib,\".\encrypt\encryption.lib\")";
    void *edata = fun(data, strlen(data));
    printf("%s\n", edata);
}