#include "head.h"
void strcat_demo0()
{
    char ch1[] = "hello";
    char ch2[] = "world";
    char ch3[100] = { 0 };
    strcat(ch3, ch1);
    strcat(ch3, " ");
    strcat(ch3, ch2);
    printf("%s\n", ch3);
    getchar();

    //char str[10] = { "456" };
    //char str1[50] = { "abc" };
    //printf("原始值：%s\n", str1);
    //strcat(str1, str);
    //printf("之后值：%s\n", str1);

    char str[20] = "123";
    char *src = "hello world";
    printf("%s\n", strcat(str, src));
}

void strcat_demo1()
{
    //char ch[100] = { 0 };//必须初始化

    char ch[100];
    memset(ch, 0, sizeof(ch));

    char arr1[] = "hello";
    char arr2[] = "world";
    strcat(ch, arr1);
    strcat(ch, " ");
    strcat(ch, arr2);
    strcat(ch, "\0");
    printf("%s\n", ch);
}

void strncat_demo0()
{
    char ch1[100] = "hello";
    char ch2[] = "world";
    strncat(ch1, ch2, 2);
    printf("%s", ch1);
}