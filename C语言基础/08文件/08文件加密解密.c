#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define KEY 123456789

void 文件读取()
{
    FILE * f1 = fopen("源文件", "r");
    if (!f1)
    {
        perror("文件加密失败\n");
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

void 文件加密0()
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
    FILE * f1 = fopen("源文件", "rb");
    FILE * f2 = fopen("加密文件", "wb");
    if (!f1 || !f2)
    {
        perror("文件加密失败\n");
    }
    char ch = { 0 };
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch ^ KEY, f2);
    }

    fclose(f1);
    fclose(f2);
}

void 文件解密0()
{
    FILE * f1 = fopen("加密文件", "rb");
    FILE * f2 = fopen("解密文件", "wb");
    if (!f1 || !f2)
    {
        perror("文件加密失败\n");
    }
    char ch = { 0 };
    while ((ch = fgetc(f1)) != EOF)
    {
        fputc(ch ^ KEY, f2);
    }

    fclose(f1);
    fclose(f2);
}

void 文件加密1()
{
    FILE * fp0 = fopen("源文件", "r");
    FILE * fp1 = fopen("加密文件", "w");
    if (!fp0)
    {
        printf("源文件打开失败\n");
        return -1;
    }
    if (!fp1)
    {
        printf("加密文件打开失败\n");
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
        //如何修改short类型的最高位

        fprintf(fp1, "%hd", pass);
    }

    fclose(fp0);
    fclose(fp1);
}

void 文件解密1()
{
    FILE * fp0 = fopen("加密文件", "r");
    FILE * fp1 = fopen("解密文件", "w");
    if (!fp0 || !fp1)
    {
        printf("操作文件失败\n");
        return -1;
    }
    short pass;
    char ch;
    while (!feof(fp0))
    {
        fscanf(fp0, "%hd", &pass);
        //printf("%hd\n", pass);
        ////左移一位
        //pass = pass << 1;
        ////右移三位
        //pass = pass >> 3;
        ////强制转换为char
        //ch = (char)pass;

        pass = pass & 0x7fff;
        pass = pass >> 2;
        ch = (char)pass;

        fputc(ch, fp1);
    }

    fclose(fp0);
    fclose(fp1);
}