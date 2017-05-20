#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>

void 极值相关()
{
    //typedef int  FALSE=0,TRUE=1
    BOOL bool = FALSE;//0

                      //unsigned short
    WORD word = 123;

    //unsigned char
    BYTE byte = 123;

    //unsigned long
    DWORD dword = 123;

    //unsigned int
    DWORD32 dword32 = 123;

    //unsigned __int64
    DWORD64 dword64 = 123;

    //unsigned long
    ULONG ulong = 123;

    //unsigned int
    ULONG32 ulong32 = 123;

    //unsigned __int64
    ULONG64 ulong64 = 0;

    //unsigned __int64
    ULONGLONG ulonglong = 123;

    //INT_MAX十进制：2147483647
    //INT_MAX二进制：0000 0000 0000 0000 0000 0000 0000 0000 0111 1111 1111 1111 1111 1111 1111 1111

    //INT_MAX+1=    -2147483648
    //二进制：1111 1111 1111 1111 1111 1111 1111 1111 1000 0000 0000 0000 0000 0000 0000 0000
    printf("CHAR_MAX=%d", CHAR_MAX);
    printf("CHAR_MIN=%d", CHAR_MIN);

    printf("        int Max=%d\n", INT_MAX);
    printf("	    int Min=%d\n", INT_MIN);
    printf("unsigned int Max=%u\n", UINT_MAX);

    printf("LONG_MIN=%ld \n", LONG_MIN);
    printf("LONG_MAX=%ld \n", LONG_MAX);

    printf("LLONG_MIN=%lld \n", LLONG_MIN);
    printf("LLONG_MAX=%lld \n", LLONG_MAX);

    printf("%d\n", INT_MIN - 2);

    unsigned short usMax = USHRT_MAX;
    printf("%d\n", usMax);
    //char c = "\n";
    printf("%d\n", SHRT_MAX);
    printf("%d\n", SHRT_MIN);

    int x1 = 1;
    int x2 = 012;
    int x3 = 0x15;
    printf("%d\n", INT_MAX + 1);
    printf("x1=%d,x2=%d,x2=%d\n", x1, x2, x3);
    int a = 11;
    printf("%p", &a);
}