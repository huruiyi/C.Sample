#include "head.h"

void sprintf_demo0()
{
    char str5[100] = { 0 };
    sprintf(str5, "title %s���Ͼ�Ҫ������", "C���Ի�����");
    system(str5);
}

void sprintf_demo1()
{
    char ch[100];
    char arr1[] = "hello";
    char arr2[] = "world";

    sprintf(ch, "%s %s", arr1, arr2);//strcat
    printf("%s\n", ch);

    sprintf(ch, "%s %c %c", arr1, arr2[0], arr2[1]);//strncat
    printf("%s\n", ch);

    sprintf(ch, "%s", arr1);
    printf("%s\n", ch);
}

void sprintf_demo2()
{
    char ch[100];
    int a = 1;
    int b = 2;
    sprintf(ch, "%d+%d=%d\n", a, b, a + b);
    printf("%s\n", ch);
}

void sscanf_demo0()
{
    //tabҲ������ֹһ��scnaf������ֵ
    char ch[] = "1	2";
    char arr1[10] = { "hello" };
    char arr2[10] = "world";
    sscanf(ch, "%s	%s", arr1, arr2);
    printf("%s\n", arr1);
    printf("%s\n", arr2);
}

void sscanf_demo1()
{
    //\nҲ������ֹһ��scnaf������ֵ
    char ch[] = "1\n2";
    char arr1[10] = { "hello" };
    char arr2[10] = "world";
    sscanf(ch, "%s%s", arr1, arr2);
    printf("%s\n", arr1);
    printf("%s\n", arr2);
}

void sscanf_demo2()
{
    char ch[] = "1+2=3";
    int a, b, c;
    sscanf(ch, "%d+%d=%d", &a, &b, &c);
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}

void �ַ�����ȡ()
{
    char params[200] = { "userName=����&userSkill=����&minzu=��" };
    //char params[200] = { "userName=����" };
    char un[50] = "";      //userName
    char unValue[50] = ""; //����
    char usk[50] = "";     //userSkill
    char uskValue[50] = "";//����

    char ps[200] = { 0 };
    char *p = strtok(params, "&");
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, "&");
    }

    sscanf(params, "userName=%s&userSkill=%s", &unValue, &uskValue);
    sscanf(params, "%s=%s&%s=%s", &un, &unValue, &usk, &uskValue);
    sscanf(params, "userName=%s&userSkill=%s", &un, &unValue);
    printf("a=%s\n", un);
    printf("b=%s\n", unValue);
    printf("c=%s\n", usk);
    printf("d=%s\n", uskValue);
}