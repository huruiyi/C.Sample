#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
#include<winddi.h>
#include<time.h>
#include<process.h>
#include <string.h>
/*
字符数组与字符串区别
	C语言中没有字符串这种数据类型，可以通过char的数组来替代；
	字符串一定是一个char的数组，但char的数组未必是字符串；
	数字0(和字符‘\0’等价)结尾的char数组就是一个字符串，
但如果char数组没有以数字0结尾，那么就不是一个字符串，只是普通字符数组，所以字符串是一种特殊的char的数组。
*/
void 字符串与字符数组()
{
    char str1[] = "ab\0c";
    char  str2[] = { "abc" };

    printf("str1=%s %d \t %d\n", str1, sizeof(str1), strlen(str1));
    printf("str2=%s %d \t %d\n", str2, sizeof(str2), strlen(str2));

    char c1[] = { 'c', ' ', 'p', 'r', 'o', 'g' }; //普通字符数组
    printf("c1 = %s\n", c1); //乱码，因为没有’\0’结束符

                             //以‘\0’(‘\0’就是数字0)结尾的字符数组是字符串
    char c2[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0' };
    printf("c2 = %s\n", c2);

    //字符串处理以‘\0’(数字0)作为结束符，后面的'h', 'l', 'l', 'e', 'o'不会输出
    char c3[] = { 'c', ' ', 'p', 'r', 'o', 'g', '\0', 'h', 'l', 'l', 'e', 'o', '\0' };
    printf("c3 = %s\n", c3);

    //不指定长度, 没有0结束符，有多少个元素就有多长
    char buf[] = { 'a', 'b', 'c' };
    printf("buf = %s\n", buf);	//乱码

                                //指定长度，后面没有赋值的元素，自动补0
    char buf2[100] = { 'a', 'b', 'c' };
    printf("buf2 = %s\n", buf2);

    //所有元素赋值为0
    char buf3[100] = { 0 };
    //输出之后是一排空

    //char buf4[2] = { '1', '2', '3' };//数组越界

    char buf5[50] = { '1', 'a', 'b', '0', '7' };
    printf("buf5 = %s\n", buf5);

    char buf6[50] = { '1', 'a', 'b', 0, '7' };
    printf("buf6 = %s\n", buf6);

    char buf7[50] = { '1', 'a', 'b', '\0', '7' };
    printf("buf7 = %s\n", buf7);

    //使用字符串初始化，编译器自动在后面补0，常用
    char buf8[] = "agjdslgjlsdjg";
    printf("buf8 = %s\n", buf8);

    //'\0'后面最好不要连着数字，有可能几个数字连起来刚好是一个转义字符
    //'\ddd'八进制字义字符，'\xdd'十六进制转移字符
    // \012相当于\n
    char str[] = "\012abc";
    printf("str == %s\n", str);
}

void SizeOfStrlen()
{
    char ch0[] = { "Hello world" };
    printf("%d\n", sizeof(ch0));
    printf("%d\n", strlen(ch0));
    printf("%s\n", ch0);
    system("pause");

    char ch00[] = "Hello world";
    printf("%d\n", sizeof(ch00));
    printf("%d\n", strlen(ch00));
    printf("%s\n", ch00);
    system("pause");

    char ch1[] = { 'H','e' ,'l','l','o','w','o','r','l','d' };
    printf("%d\n", sizeof(ch1));
    printf("%d\n", strlen(ch1));
    printf("%s\n", ch1);
    system("pause");

    char ch11[10] = { 'H','e' ,'l','l','o','\0','w','o','r','l' };
    printf("%d\n", sizeof(ch11));
    printf("%d\n", strlen(ch11));
    printf("%s\n", ch11);
    system("pause");

    char ch2[11] = { 'H','e' ,'l','l','o','w','o','r','l','d','\0' };
    printf("%d\n", sizeof(ch2));
    printf("%d\n", strlen(ch2));
    printf("%s\n", ch2);
    system("pause");

    char ch3[] = "hello\0 world";
    printf("%d\n", sizeof(ch3));
    printf("%d\n", strlen(ch3));
    system("pause");

    char ch4[12] = "hello\0 world";
    printf("%d\n", sizeof(ch4));
    printf("%d\n", strlen(ch4));
    system("pause");
}

void UniCode()
{
    //char s1[5] = { 'h', 'e', 'l', 'l', 'o' };//错误乱码
    char s1[6] = { 'h', 'e', 'l', 'l', 'o',0 };
    printf("%s\n", s1);

    char s2[10];
    //s2 = "abcd";
    strcpy(s2, "胡睿毅");
    printf("%s\n", s2);

    char s3[18] = "a book!";
    printf("%.4s\n", s3);

    printf("%c\n", "abcd"[1]);

    int a1[] = { "string" };//数字初始化必须要｛｝
    printf("a1=%s\n", a1);
    //int a2[5] = { 0,1,2,3,4 };
    //printf("a2=%s\n", a2);xxxxx
    //char a3 = "string";
    //printf("a3=%s\n", a3);xxxx
    char a4[] = { 0,1,2,3,4,5 };
    printf("a4=%s\n", a4);

    //int b1 = 5, b[n][n];
    int b2[1][2] = { { 1,2 } };
    int b3[][2] = { { 1,2 },{ 3,4 } };
    int b4[3][2] = { { 1,2 },{ 3,4 } };

    int x[10] = { 0,2,4 };
    printf("%d\n", sizeof(x));
    printf("%d\n", strlen(x));

    //int i, a[10];
    //for (i = 9; i >= 0; i--)
    // a[i] = 10 - i;
    //printf("%d%d%d", a[2], a[5], a[8]);

    // char ch1[5] = { "a","b","c","d","e" };
    char ch2[] = { 'a','b' };
    printf("%s", ch2);
    // char ch3[15] = { "welcome to china" };
    char ch4[14] = { "I am a student" };
    printf("%s", ch4);
}

void ZeroOne()
{
    char a1 = '0';
    char a2 = '\0';
    int a3 = 0;
    printf("%c \t %d \t %d \n", a1, a1, sizeof(a1));
    printf("%c \t %d \t %d \n", a2, a2, sizeof(a2));
    printf("%c \t %d \t %d \n", a3, a3, sizeof(a3));

    char o1 = '1';
    int o2 = 1;
    printf("%d\t%d\t%c\n", o1, sizeof(o1), o1);
    printf("%d\t%d\t%c\n", o2, sizeof(o2), o2);
}

void CharArrSizeLen()
{
    printf("%d\t%d\t%d \n", sizeof('A'), sizeof("A"), strlen("A"));
    printf("%d\t%d \n", strlen("传智播客"), sizeof("传智播客"));

    char a = 'A';
    char b[] = "A";

    CHAR c = 'A';
    WCHAR wc = 'A';
    wchar_t wct = L'A';
    printf("%d\t%d\t%d\t%d\t%d\n", sizeof(a), sizeof(b), sizeof(c), sizeof(wc), sizeof(wct));

    char * d1 = "仙剑奇侠传";
    printf("%s\n", d1);
    printf("%d\t%d\n\n", sizeof(d1), strlen(d1));

    char d2[] = "仙剑奇侠传";
    printf("%s\n", d2);
    printf("%d\t%d\n\n", sizeof(d2), strlen(d2));

    char d3[11] = "仙剑奇侠传";
    printf("%s\n", d3);
    printf("%d\t%d\n\n", sizeof(d3), strlen(d3));

    char d4[10] = "仙剑奇侠传";
    printf("%s\n", d4);
    printf("%d\t%d\n\n", sizeof(d4), strlen(d4));
}