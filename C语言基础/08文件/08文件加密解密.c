#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 123456789

void �ļ���ȡ()
{
    FILE * f1 = fopen("Դ�ļ�", "r");
    if (!f1)
    {
        perror("�ļ�����ʧ��\n");
    }
    char ch[1024] = { 0 };
    while (!feof(f1))
    {
        memset(ch, 0, 1024);
        fgets(ch, 1024, f1);
        printf("%s\n", ch);
    }

    fclose(f1);
}

void �ļ�����0()
{
    /*
    int a = 10;
    int b = 20;

    a = a^b;
    b = a^b;
    a = a^b;

    printf("%d\n", a);
    printf("%d\n", b);
    */
    FILE * f1 = fopen("Դ�ļ�", "rb");
    FILE * f2 = fopen("�����ļ�", "wb");
    if (!f1 || !f2)
    {
        perror("�ļ�����ʧ��\n");
    }
    char ch = { 0 };
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch ^ KEY, f2);
    }

    fclose(f1);
    fclose(f2);
}

void �ļ�����0()
{
    FILE * f1 = fopen("�����ļ�", "rb");
    FILE * f2 = fopen("�����ļ�", "wb");
    if (!f1 || !f2)
    {
        perror("�ļ�����ʧ��\n");
    }
    char ch = { 0 };
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch ^ KEY, f2);
    }

    fclose(f1);
    fclose(f2);
}

void �ļ�����1()
{
    FILE * fp0 = fopen("Դ�ļ�", "r");
    FILE * fp1 = fopen("�����ļ�", "w");
    if (!fp0)
    {
        printf("Դ�ļ���ʧ��\n");
        return -1;
    }
    if (!fp1)
    {
        printf("�����ļ���ʧ��\n");
        return -2;
    }

    char ch;
    short pass;
    while ((ch = fgetc(fp0)) != EOF)
    {
        //a -> 97 ->

        pass = (short)ch;
        //0000 0000 0110 0001  << 2
        //0000 0001 1000 0100
        pass = pass << 2;
        //1000 0001 1000 0100
        pass = pass | (0x7fff + 1);
        //0000 0000 0001 0000 |
        //1000 0000 0000 0000 -0
        //1000 0000 0001 0000  &
        //0111 1111 1111 1111 0x7fff
        //0111 1111 1111 1111 0x7fff+1
        //����޸�short���͵����λ

        fprintf(fp1, "%hd", pass);
    }

    fclose(fp0);
    fclose(fp1);
}

void �ļ�����1()
{
    FILE * fp0 = fopen("�����ļ�", "r");
    FILE * fp1 = fopen("�����ļ�", "w");
    if (!fp0 || !fp1)
    {
        printf("�����ļ�ʧ��\n");
        return -1;
    }
    short pass;
    char ch;
    while (!feof(fp0))
    {
        fscanf(fp0, "%hd", &pass);
        //printf("%hd\n", pass);
        ////����һλ
        //pass = pass << 1;
        ////������λ
        //pass = pass >> 3;
        ////ǿ��ת��Ϊchar
        //ch = (char)pass;

        pass = pass & 0x7fff;
        pass = pass >> 2;
        ch = (char)pass;

        fputc(ch, fp1);
    }

    fclose(fp0);
    fclose(fp1);
}