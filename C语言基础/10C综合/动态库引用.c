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
    HANDLE hDll; //����һ��dllʵ���ļ����
    hDll = LoadLibrary("./encrypt/encryption.dll"); //���붯̬���ӿ�

    Func   fun; //��������ָ��
    fun = (Func)GetProcAddress(hDll, "InEncry"); //��ȡ���뺯���ĺ���ָ��

    char *data = "#pragma comment(lib,\".\encrypt\encryption.lib\")";
    void *edata = fun(data, strlen(data));
    printf("%s\n", edata);
}