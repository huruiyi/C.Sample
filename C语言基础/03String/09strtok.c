#include "head.h"

void StrtokDemo0()
{
    char arr[] = "www.itcast.cn";

    char arr1[100] = { 0 };
    char * p = strtok(arr, ".");
    while (p != NULL)
    {
        //printf("%s\n", p);
        strcat(arr1, p);
        strcat(arr1, "*");
        p = strtok(NULL, ".");
    }
    //www\0itcast\0cn
    printf("%s\n", arr1);
}

void StrtokDemo1()
{
    char arr[] = "123456@qq.com";

    char *p = strtok(arr, "@");
    printf("%s\n", p);
    p = strtok(NULL, ".");
    printf("%s\n", p);
    p = strtok(NULL, ".");
    printf("%s\n", p);
}

void StrtokDemo2()
{
    char a[100] = "12*34*56*78*90";
    char *s = strtok(a, "*");//将"*"分割的子串取出
    while (s != NULL)
    {
        printf("%s\n", s);
        s = strtok(NULL, "*");
    }
}