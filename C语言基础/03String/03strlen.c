#include "head.h"

void strlen_demo0()
{
    char str1[] = "abcdefg";
    printf("str1 = %d size:%d\n", strlen(str1), sizeof(str1));

    char str2[] = "abc\0defg";
    printf("str2 = %d size:%d\n", strlen(str2), sizeof(str2));
}
void strlen_demo1()
{
    char ch0[] = "hello w\0orld";
    printf("�ַ����鳤�ȣ�%d\n", sizeof(ch0));
    printf("�ַ������ȣ�%d\n", strlen(ch0));

    char ch1[100];
    gets(ch1);
    printf("�ַ����鳤�ȣ�%d\n", sizeof(ch1));
    printf("�ַ������ȣ�%d\n", strlen(ch1));

    char ch2[] = { "���ǲ���" };
    printf("�ַ����鳤�ȣ�%d\n", sizeof(ch2));
    printf("�ַ������ȣ�%d\n", strlen(ch2));
    system("pause");
}