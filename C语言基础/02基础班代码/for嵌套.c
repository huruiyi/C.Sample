#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void ѭ��Ƕ��()
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
    system("for /l %i in (1,1,5) do calc");//��5�����±���

    system("for /l %i in (1,1,5) do start calc");//ͬʱ��5�����±���
    //%i  ����int����˼��do��������  start  ͬʱ��

    char str[50]; //�ַ����ĳ���
    wsprintf(str, "for /l %i in (1,1,5) do calc");
    system("str");
    //�������д�ӡ ��������ݡ�

    //char str[50]; //�ַ����ĳ���
    //gets_s(str, 50);//  gets_s����������룬���浽str  ��󳤶���50��
    //system(str);// ִ���ַ�����
}

void WsprintfDemo()
{
    int num = 5 + 3;//����һ������
    printf("%d", num);//��ӡ����
    char str[50];//�ַ������ȣ�����50�Ļ�����
    wsprintf(str, "for  /l %i  in (1,1,%d) do start calc", num);

    system(str);
}