#include "head.h"

void ScantfDemo1()
{
    char ch1[10] = "hello";
    char ch2[10] = { 0 };
    char ch3[10] = { 0 };

    //接收换行（\n）和文件结尾标志  （-1）
    //gets(ch);15
    //1、接收有限字符(按照是输入的顺序依次获取)
    //scanf("%1s%2s%3s", ch1, ch2, ch3);
    //printf("%s\n", ch1);
    //printf("%s\n", ch2);
    //printf("%s\n", ch3);

    //2、接收空格（只能输入一个空格，例如：123 456）
    scanf("%[^\n]", ch1);
    printf("%s\n", ch1);
}

void ScanfDemo2()
{
    int a, b, c;
    //3、接收非字母的数字
    //scanf("%*5c%d", &a);//a12
    //printf("%d\n", a);

    //4、接收有限数字
    scanf("%1d%2d%3d", &a, &b, &c);

    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
}

void func(char s1[], char s2[])
{
    int i = 0;
    while (s2[i] != '\0')
        s1[i++] = s2[i++];
    s1[i] = '\0';

    //char s1[100]="123456";;  char s2[] = "def";
    //func(s1, s2);
    //printf("%s\n\n", s1);
    //printf("%s\n\n",s2);
}

void ConvertDemo()
{
    char arr[] = "3.14159265317";
    //int value = atoi(arr);
    //printf("%d\n", value);
    //long value = atol(arr);
    //printf("%d\n", value);
    double value = atof(arr);
    printf("%.15f\n", value);
}

void WipeSpace(char  c[], char newc[100])
{
    int i = 0;
    int j = 0;
    while (c[i] != '\0')
    {
        char ch = c[i];
        if (ch != 32)
        {
            newc[j] = ch;
            j++;
        }
        i++;
    }
}

void CalcDemo()
{
    char str[100];
    gets(str);
    printf("str = %s\n", str);

    char c1 = FindChar(str, '+');
    char c2 = FindChar(str, '-');
    char c3 = FindChar(str, '*');
    char c4 = FindChar(str, '/');

    char ci = c1 | c2 | c3 | c4;
    char cfi[] = { ci };
    char *s = strtok(str, cfi);//将"*"分割的子串取出

    int num[2];
    int i = 0;
    while (s != NULL)
    {
        num[i] = atoi(s);
        s = strtok(NULL, cfi);
        i++;
    }
    int value = 0;
    switch (ci)
    {
    case '+':
        value = num[0] + num[1];
        break;
    case '-':
        value = num[0] - num[1];
        break;
    case '*':
        value = num[0] * num[1];
        break;
    case '/':
        value = num[0] / num[1];
        break;
    }
    printf("%d %c %d = %d\n", num[0], ci, num[1], value);
}

void Demo()
{
    int i, x, y;
    i = x = y = 0;
    do
    {
        ++i;
        if (i % 2 != 0)
        {
            x = x + i;
            i++;
        }
        y = y + i++;
    } while (i <= 7);
    printf("x=%d, y=%d.\n", x, y);
}

void test()
{
    char * p = "hello world";
    printf("%p--%s\n", p, p);
    p = "abcdefg";
    printf("%p--%s\n", p, p);

    char *p4[4];
    p4[0] = "abc";
    p4[1] = "123";
    p4[2] = "def";
    p4[3] = "456";

    char str[] = "I love chia";
    char * chp = "I love chia";
}

void testzifuchuan()
{
    char parr[] = "zifuchuanshuzu";
    char charr[] = { 'z','i','f','u','c','h','u','a','n','s','h','u','z','u','\0' };
    printf("%s\n", charr);
    printf("%s\n", parr);
}
void zero()
{
    char str[50] = "notepad";
    printf("%x", str);
    printf("%c,%d", '\0', '\0'); //空字符，0
    printf("%c,%d", 0, 0); //   编号为0的字符,0,内存的整数0
    printf("%c,%d", '0', '0');//字符0，字符0的编号48
}
void main()
{
    zero();
    //char c[5] = { 'a', 'b', '\0', 'c', '\0' };
    //printf("%s\n", c);

    char * language[] = { "FORTRAN", "BASIC", "PASCAL", "JAVA","C" };
    printf("%s\n", language[2]);

    system("pause");
}