#include "heaad.h"

void FputcDemo0()
{
    FILE * fp = fopen("D:\\a.txt", "w");

    char buf[] = "this is a test for fputc";
    int i = 0;
    int n = strlen(buf);
    for (i = 0; i < n; i++)
    {
        //往文件fp写入字符buf[i]
        int ch = fputc(buf[i], fp);
        printf("ch = %c\n", ch);
    }
    fclose(fp);
}

void FgetcDemo2()
{
    FILE * fp = fopen("D:\\a.txt", "r");
    char ch;
    while (!feof(fp)) //文件没有结束，则执行循环
    {
        ch = fgetc(fp);
        printf("%c", ch);
    }
    printf("\n");
}

void FgetcDemo0()
{
    FILE * fp = fopen("D:\\a.txt", "r");
    char ch = ' ';
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
    printf("\n");
    fclose(fp);
    system("pause");
}

void FgetcDemo1()
{
    FILE * fp = fopen("D:\\a.txt", "r");
    char ch = fgetc(fp);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(fp);
    }
    printf("\n");
    fclose(fp);
    system("pause");
}

void fputs_stdout()
{
    printf("hello world\n");
    puts("hello world\n");
    fputs("hello world\n", stdout);
}