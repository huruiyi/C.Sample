#include<Windows.h>
#include<stdlib.h>
#include<stdio.h>
#include "resource.h"

#define Write(x) printf("%s",x);
#define WriteLine(x) printf("%s\n",x);

#define Cheng1(x) (x)*(x);
#define Cheng2(x) x*x;
#define Sum(a,b)(a+b)
#define Yinhao(x) #x;
#define Connect(x,y) x##y;

#define PrintVari(first,...) printf("first=" #first"\t"__VA_ARGS__)

void Ԥ����()
{
    Write("HelloWorld");
    WriteLine("Hello World");

    int x1 = Cheng1(10 + 1);
    printf("%d\n", x1);

    int x2 = Cheng2(10 + 1);
    printf("%d\n", x2);

    char sx[] = Yinhao(abc);
    printf("%s\n", sx);

    char a[] = "abcdefg";

    int b = Connect(1, 30);

    char c1 = 'a';
    char c2 = 'b';

    char c = Connect(6, 5);// ��Ӧ�ַ�A

    printf("%s---%s\n", a, "");

    PrintVari(1, "2:%d\t 3:%d\t 4:%d\t 5:%d\n", 2, 3, 4, 5);

    int arr[3][2] = { { 1,2, },{ 3,4 },{ 5,6 } };
    printf("%d\n", sizeof(arr) / sizeof(int));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }
    printf("%5d", 123);
    system("pause");
}

void Ԥ����1()
{
    int a = 10;
    int b = 20;
#if a>b
    printf("%d\n", a);
#else
    printf("%d\n", b);
#endif
}

void Ԥ����2()
{
#ifdef DEBUG
    printf("Debug");
#else
    printf("Not Debug");
#endif // DEBUG
}

void Ԥ����3()
{
#ifndef DEBUG
    printf("%d\n", 1);
#else
    printf("%d\n", 0);
#endif // !1
}

void Ԥ����4()
{
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
}
void DrawImage()
{
    while (1)
    {
        HWND win = GetDesktopWindow();
        HDC windc = GetWindowDC(win);
        HDC memdc = CreateCompatibleDC(0);

        HBITMAP bit = (HBITMAP)LoadImage(win, IDB_BITMAP1, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
        SelectObject(memdc, bit);
        BitBlt(windc, 0, 0, 400, 300, memdc, 0, 0, SRCCOPY);
    }
}

void TextType()
{
    /*
    0��ȷ��
    1��ȷ����ȡ��
    2����ֹ�����ԣ�����
    3���ǣ���ȡ��
    4���ǣ���
    5�����ԣ�ȡ��
    6��ȡ�������ԣ�����
    */
    //MessageBox(0, TEXT("Welcome to itcast"), TEXT("���Ǳ���1"), 0);//����Ӧ
    //MessageBox(0, L"Welcome to itcast", L"���Ǳ���2", 0);//Unicode
    //MessageBox(0, "Welcome to itcast", "���Ǳ���3", 0); //���ֽ��ַ�����δ����
}