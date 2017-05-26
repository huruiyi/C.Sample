#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void PrintfDemo0()
{
    printf("整数：%d\n", 10);
    printf("字符串：%s\n", "Hello World");
    printf("整数：%d,字符串：%s\n", 10, "Hello World");
    printf("字符串：Hello World\n");
}

void PrintDemo1()
{
    char inputStr[100] = { 0 };
    scanf("%s", inputStr);
    char str[100] = { 0 };
    sprintf(str, "color %s", inputStr);//sprintf：字符串拼接
    system(str);
    system("pause");
}

void PrintDemo2()
{
    char des[100] = "abcdefghijklmnopqrstuvwxyz";
    printf("[%s]\n", des);
    printf("[%.5s]\n", des); //截取前五位

    char buf[100] = { 0 };
    sprintf(buf, "[%s]\n", "12");
    //sprintf(buf, "[%6s]\n", "12");//右对齐，默认以空格填充
    //sprintf(buf, "[%-6s]\n", "12");//左对齐，默认以空格填充
    printf("%s", buf);
}

void PrintDemo3()
{
    printf("[%d]\n", 10); //有多宽分配多宽
    printf("[%10d]\n", 10);//宽度为10,
    printf("[%-10d]\n", 10);//宽度为10,默认右边对齐，-代表左边对齐
    printf("[%010d]\n", 10);//宽度为10，空余填充
    printf("[%3d]\n", 12345);//m整数，大于实际宽度，填充0或者空格，否则无效
}

void PrintDemo4()
{
    printf("[%.2f]\n", 1.2345);
    char str[100] = "calc1";
    printf("[%.4s]\n", str);//截取小数点，截取字符串

    long l1 = 12345;
    printf("%d,%ld", l1, l1);//32位 %d,%ld ,int long等价
}

void PrintDemo5()
{
    int num0 = -12345678;
    printf("%d", num0);//有符号十进制
    printf("\n%i", num0);//有符号10进制
    printf("\n%u", num0);//无符号10进制
    printf("\n%o", num0);//无符号8进制
    printf("\n%x\n\n", num0);//无符号16进制

    int num1 = -12345678;
    printf("%d", num1);//有符号十进制
    printf("\n%i", num1);//有符号10进制
    printf("\n%u", num1);//无符号10进制
    printf("\n%o", num1);//无符号8进制
    printf("\n%x\n", num1);//无符号16进制

    unsigned int x = 3;
    unsigned int y = -1;
    unsigned int z = 2;
    printf("%u\n", x);
    printf("%u\n", y);
    if (x > y) {
        if (y < 0)
        {
            z = 0;
        }
        else
        {
            z += 1;
        }
    }

    printf("z=%d\n", z);
}

void PrintDemo6()
{
    char ch = 'A';
    printf("%c\n", ch);//字符
    printf("%d\n", ch);//字符
    printf("%u\n", ch);//字符
    putchar(ch);//输出一个字符

    char str[100] = "calc";
    printf("%s\n", str);//字符串输出
}

void PrintDemo7()
{
    char str[100] = { 0 };
    //%3C ,空格3个
    sprintf(str, "color %c%c", '4', 'f');//格式化，整数，实数，字符串整合到一个字符串
    printf("%s", str);
    system(str);
}

void PrintDemo8()
{
    char str[10] = "task";
    char newstr[10] = "123list123";
    printf("%p", newstr);

    char strall[100] = { 0 };

    //%s%s拼接
    //%.5%s截取，只能从左边截取 //从某一个地址从左向右开始截取
    //10代表宽度
    //-左边对齐,

    sprintf(strall, "%s%.4s", str, newstr + 3);//字符地址的移动实现跳过某一段

    printf("%s", strall);
    system(strall);
}

/*
中文字符Windows下占用两个字符
Linux  下占用三个字符
*/
void PrintDemo9()
{
    //char c = '我';
    //printf("%p", &c);
    char c[10] = "胡睿毅";
    printf("%c%c\n", c[0], c[1]);
    printf("%c%c\n", c[2], c[3]);
    printf("%c%c\n", c[4], c[5]);
}

void PrintDemo10()
{
    // 默认右对齐（+）
    //        左对齐（-）
    double db = 109.123456789123;
    printf("[%.10f]\n", db);//.10小数点保留十位
    printf("[%30.10f]\n", db);
    printf("[%-30.10f]\n", db);//-控制对齐，30宽度
    printf("[%30.10f]\n", db);
}

void PrintDemo11()
{
    double db = 10456700000000;
    double dbs = 0.000000001;
    printf("%e\n", db);//指数输出
    printf("%e\n", dbs);//指数输出
}

void PrintDemo12()
{
    //double db = 10456700000000;
    double db = 1.234567;
    printf("%f\n", db);//g自动选择宽度 %f.%e
    printf("%e\n", db);//g自动选择宽度 %f.%e
    printf("%g\n", db);//g自动选择宽度 %f.%e
}

void PrintDemo13()
{
    //int num;
    //printf("hello %n china", &num);//%n禁用
    //printf("num=%d", num);

    getchar();
}

void PrintDemo14()
{
    int num = printf("a=%d,b=%d", 10, 12);
    printf("\n%d", num);//返回值字符个数
    getchar();
}

void PrintDemo15()
{
    int num = printf("12345");
    printf("\n%d", num);//纯字符串的情况下，返回值字符个数
    getchar();
}

void PrintDemo16()
{
    int num = -1;
    // 0000 0000  0000 0000 0000 0000 0000 0001 +1原码
    // 1000 0000  0000 0000 0000 0000 0000 0001	 -1原码
    // 1111 1111  1111 1111 1111 1111 1111 1110 -1 反码
    // 1111 1111  1111 1111 1111 1111 1111 1111 -1 补码
    unsigned int data = 4294967295u;
    printf("%d\n", num);
    printf("%u\n", num);
    printf("%d\n", data);
    printf("%u\n", data);
    printf("%f\n", 1);
}

void PrintDemo17()
{
    {
        unsigned short int unum1 = 65535;
        short int num1 = 123;
        printf("\n%hu,%hd", unum1, num1);
    }

    {
        unsigned  int unum1 = 65535;
        int num1 = 123;
        printf("\n%u,%d", unum1, num1);
    }
    {
        unsigned long int unum1 = 65535;
        long  int num1 = 123;
        printf("\n%lu,%ld", unum1, num1);
    }

    {
        unsigned long long unum1 = 18611210283;
        long long num1 = 18611210283;
        printf("\n%llu,%lld", unum1, num1);
    }

    //%hd，整数，短整数 16个位的存储  short范围
    //%d,%ld等价  %u %lu等价
    //%lld %llu超长的数据
}

void PrintDemo18()
{
    int num = 0127;
    printf("%o", num);
    printf("\n%#o", num);

    int data = 0x1234;
    printf("\n%x", data);
    printf("\n%#x", data);//一般情况，八进制，十六进制加上#
}

void PrintDemo19()
{
    float fl = 10.8;
    double  db = 10.9;// long double 等价于double

    printf("\n%a", fl);//十六进制的显示方式
    printf("\n%a", db);

    //p 16的底数，e效果一样
}

void PrintDemo20()
{
    printf("%D\n ", 10);//%d不可以大写
    printf("%O\n ", 010);//%o不可以大写
    printf("%U\n ", 010);//%u不可以大写
    printf("%#X\n ", 0x10);//X大小写决定了字母大小写
    printf("%E\n ", 10000000.0);//有字母输出的，可以大小写，没有字母输出一般不可以（%o例外）

    //printf需要精确匹配
    printf("\"123\"\n ");//转义字符
    printf("\'123\'\n ");
    printf("55%%\n ");
}

void PrintDemo21()
{
    printf("\n%d,%d", 1, 2, 3);
    printf("\n%d,%d,%d,%d,%d,%d,%d", 1, 2, 3);
}

void PrintDemo22()
{
    double db = 1.123456789123456789;
    for (int i = 1; i < 20; i++)
    {
        printf("\n%*.*f", i * 2, i, db);//让小数点位置变动的变化
    }
}

void PrintDemo23()
{
    char str[100] = "1234567890qwertretrertert";
    for (int i = 1; i < 20; i++)
    {
        printf("\n%.*s", i, str);//控制宽度，小数点，变元
    }
}