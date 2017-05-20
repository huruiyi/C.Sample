#include "head.h"

void strcmp_demo()
{
    char ch1[] = "hello";
    char ch2[] = { "hello" };

    //int value = strcmp(ch1, ch2);
    //printf("%d\n", value);

    if (!strcmp(ch1, ch2))
    {
        printf("相同\n");
    }
    else
    {
        printf("不同\n");
    }
}
void strncmp_demo()
{
    //0000 0000 0000 0000 0000 0000 0010 0001
    //0010 0001
    //int a = 65;
    //char b = 'A';

    int a = 127;
    //0000 0000 0000 0000 0000 0000 0111 1111
    short b = 0xf7f;
    //0000 1111 0111 1111

    if (!strncmp(&a, &b, 1))
    {
        printf("相同\n");
    }
    else
    {
        printf("不同\n");
    }
}