#include "head.h"
char FindChar(const char * ch, char c)
{
    char * pch = strchr(ch, c);
    while (pch != NULL)
    {
        return c;
    }
    return 0;
}

void strchr_demo2()
{
    char arr[] = "hello";//&arr[3]printf("%s",&arr[3]);
    char ch = 'l';
    char *p = strchr(arr, ch);
    if (!p)
    {
        printf("没找到了\n");
    }
    else
    {
        printf("找到了\n%s\n", p);
    }
}

void strchr_demo3()
{
    char str1[] = "This is a sample string";
    char * pch;
    printf("Looking for the 's' character in \"%s\"...\n", str1);
    pch = strchr(str1, 's');
    while (pch != NULL)
    {
        printf("found at %d\n", pch - str1 + 1);
        pch = strchr(pch + 1, 's');
    }
}

void strstr_demo()
{
    char arr1[] = "abcdef";
    char arr2[] = "cd";
    char * p = strstr(arr1, arr2);
    //char * p = strstr(arr1, "cd");
    if (p != NULL)
    {
        printf("结果：%s\n", p);
    }
    else
    {
        printf("未查询到\n");
    }
}