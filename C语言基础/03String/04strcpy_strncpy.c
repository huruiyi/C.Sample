#include "head.h"

void strcpy_demo()
{
    char str1[] = "Sample string";
    char str2[40];
    char str3[40];
    strcpy(str2, str1);
    strcpy(str3, "copy successful");
    printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
    getchar();

    char ch[] = "hello";//Դ�ַ���
    char dst[10];//Ŀ���ַ���
    if (strcpy(dst, "���") != NULL)
    {
        printf("�����ɹ�\n");
        printf("%s\n", dst);
    }
}

void strncpy_demo()
{
    char dest[20];
    char src[] = "hello world";

    strncpy(dest, src, 5);
    printf("%s\n", dest);

    dest[5] = '\0';
    printf("%s\n", dest);

    getchar();

    char ch[] = "hello";//Դ�ַ���
    char dst[10];//Ŀ���ַ���

    strncpy(dst, ch, 3);//���޿���  ��Դ�ַ����п���n���ַ���dst�ַ����� Ĭ�ϲ����\0
    printf("%s\n\n\n", dst);
    dst[3] = 0;
    printf("%s", dst);
}