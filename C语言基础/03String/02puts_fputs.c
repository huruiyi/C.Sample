#include "head.h"

void puts_demo()
{
    /*puts输出一行后自动哈换行，printf不会自动换行*/
    printf("hello world");
    puts("hello world");
}

void fputs_demo0()
{
    //fputs()不会自动输出一个'\n'。

    printf("1:hello world\n");
    puts("2:hello world\n");
    fputs("3:hello world\n", stdout);

    char str1[7] = { "1" };
    fputs(str1, stdout);
    putchar('\n');

    char str2[7] = { "2" };
    fputs(str2, stdout);
    putchar('\n');

    char str3[7] = { "12345\n" };
    char str4[7] = { "123456\n" };//第七个字符是\n。没有\0

    printf("\str3.size=%d\n", sizeof(str3));
    printf("\nstr3.length=%d\n", strlen(str3));
    fputs(str3, stdout);

    printf("\str4.size=%d\n", sizeof(str4));
    printf("\str4.length=%d\n", strlen(str4));
    fputs(str4, stdout);

    FILE *fp = fopen("123.txt", " w");
    fputc('a', fp);
    fclose(fp);
}

void fputs_demo1()
{
    //fputs  不会输出换行
    char ch1[10] = "hello";
    fputs(ch1, stdout);
    printf("%s", ch1);
}

/*
    字符串：\0占用一个字节大小
    gets:不安全，缓冲区可能溢出
    不会自动换行
    puts:输出所有字符后会自动输出\n换行(只有在字符串正常结束时，才能输出换行)

    fgets:是安全的,空格占一个字符
    会自动换行
    fputs:不会自动换行
*/
void main()
{
    //puts_demo2();
    fgets_demo2();
    system("pause");
}
gets_demo2()
{
    char buf[5] = { 0 };
    gets(buf);
    printf("[%s]", buf);
}
puts_demo2()
{
    char che[11] = "hello world";//输出会异常，没有\0的位置
    printf("%d\n", sizeof(che));
    printf("%d\n", strlen(che));
    puts(che);

    //char che[12] = "hello world";
    //printf("%d\n", sizeof(che));
    //printf("%d\n", strlen(che));
    //puts(che);

    //puts("hello world");//会直接换行

    puts("1:hello");
    char ch[6] = "hello"; //ok
    //char ch[5] = "hello"; //error ,没有\0的位置，会导致异常
    //char ch[6] = "hello";
    //printf("%s\n", ch);
    //printf("%d\n", sizeof(ch));
    //printf("%d\n", strlen(ch));
    puts(ch);
}
fgets_demo2()
{
    //char str[10];
    //printf("str: ");
    //fgets(str, sizeof(str), stdin);
    //printf("str: %s", str);

    char buf[5];
    //fgets(buf, sizeof(buf), stdin);  //安全的，缓冲区不会溢出
    fgets(buf, 4, stdin);  //不安全
    printf("[%s]", buf);
}
fputs_demo2()
{
    char buf[5] = "1234";
    int a = 123;
    fputs(buf, stdout);
    printf("[%s]", buf);
}