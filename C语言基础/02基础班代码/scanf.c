#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void ScanfDemo01()
{
    float a = 0;
    int b = 0;
    double c = 0;
    scanf("a=%f,b=%d,c=%lf", &a, &b, &c); //a=2.2,b=3,c=12.12
    printf("%f\n", a);
    printf("%d\n", b);
}

void ScanfDemo02()
{
    int a;
    int b;
    int num = scanf("%d%d", &a, &b);
    printf("输入的个数：%d\n", num);//scanf的返回值成功的抓到多少个数据
    printf("%d\n", a);
    printf("%d\n", b);
    system("pause");
}

void ScanfDemo03()
{
    char str[500] = "131610	陈小姐	女	40	165	高中	未婚	朝阳	双子座	在校学生	普通话	北京	面议元/天	有过几次	学生伴游	清纯漂亮 自信可爱的我独在北京上学.在这浪漫的季节偶尔来到这里寻找我的有缘人.愿我们的相聚能留下人生中最美好的回忆!	10:00—23:00		2264938779@qq.com		226493870779";
    int age;
    int tall;
    sscanf(str, "%*d %*s %*s %d %d ", &age, &tall);//挖掘
    printf("age=%d,tall=%d\n", age, tall);

    //	(age >= 海华中意的年龄) && (tall <= 海华中意的身高) ? printf("海华买单") : printf("换下一个");

    system("pause");
}

void  ScanfDemo04()
{
    //%s ,
    char str[500] = "420111197203024016,13600477059,nixiaodong@vip.sina.com";
    //字符串不会吧逗号当作一个结束

    long long selfid;
    long long mobile;
    char email[100] = { 0 };
    //，%  # 不能作为字符串结束符，需要替换

    sscanf(str, "%lld,%lld,%s", &selfid, &mobile, email);//从字符串挖掘，
    printf("%lld,%lld,%s", selfid, mobile, email);

    system("pause");
}

void  ScanfDemo05()
{
    char str[500] = "刘海华,420111197203024016,13600477059,nixiaodong@vip.sina.com";
    for (int i = 0; i < 500; i++)
    {
        if (str[i] == ',')
        {
            str[i] = ' ';
        }
    }

    char name[100] = { 0 };
    long long selfid;
    long long mobile;
    char email[100] = { 0 };

    sscanf(str, "%s %lld %lld %s", name, &selfid, &mobile, email);

    printf("%s     \n    %lld     \n %lld    \n  %s", name, selfid, mobile, email);

    system("pause");
}

void  ScanfDemo06()
{
    char str[150] = "530981645----13707700754aini";
    long long QQ;
    char password[100] = { 0 };
    sscanf(str, "%lld----%s", &QQ, password);
    printf("QQ =%lld,password=%s", QQ, password);

    system("pause");
}

void ScanfDemo07()
{
    int a, b, c, d, e;
    scanf("%3d%3d%3d%3d%3d", &a, &b, &c, &d, &e);//3按照长度3来截取
    printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);

    system("pause");
}

void  ScanfDemo08()
{
    char str1[100] = { 0 };
    char str2[100] = { 0 };
    scanf("%*3s%5s", str1, str2);//固定长度截取,*忽略
    printf("%s,%s", str1, str2);
    system("pause");
}

void  ScanfDemo09()
{
    float fl = 0;
    scanf("%7f", &fl);//实数不可以指定精度
    printf("fl=%f", fl);

    system("pause");
}

void  ScanfDemo10()
{
    int num = 0;
    scanf("%d", &num);//不写地址符，会把整数的值当作地址

    system("pause");
}

void ScanfDemo11()
{
    int num = 0;
    scanf("#num=%d", &num);//精确匹配，不可以遗漏
    printf("%d", num);
    system("pause");
}

void  ScanfDemo12()
{
    char ch1, ch2, ch3;
    scanf("%c%c%c", &ch1, &ch2, &ch3);
    printf("[%c][%c][%c]", ch1, ch2, ch3);//回车会被当作一个输入
    system("pause");
}

void  ScanfDemo13()
{
    int num1;
    int num2;
    int num3;
    char str[100];
    scanf("%s%d%d%d", str, &num1, &num2, &num3);
    printf("%s,%d,%d,%d", str, num1, num2, num3);//字符串必须空格或者回车

    system("pause");
}

void  ScanfDemo14()
{
    int num1;
    int num2;
    int num3;
    //%%scanf代表一个实际的%
    scanf("%d%%%d%d", &num1, &num2, &num3);
    printf("%d,%d,%d", num1, num2, num3);//

    system("pause");
}

void  ScanfDemo15()
{
    int num1;
    int num2;
    int num3;
    char str[100];
    int n;
    scanf("%s%n%d%d%d", str, &n, &num1, &num2, &num3);//统计字符数量
    printf("\n%s,%d,%d,%d", str, num1, num2, num3);//字符串必须空格或者回车
    printf("\nn=%d", n);

    system("pause");
}

void  ScanfDemo16()
{
    char str[100];
    //scanf("%s", str);
    //scanf("%[^\n]", str);//只有\n当作结束

    scanf("%n[A-Z]", str);//只有\n当作结束
    printf("%s", str);

    system("pause");
}

void ScanfDemo17()
{
    int num = 0;
    //printf("%p", &num);

    scanf("num=%d", &num);//根据地址对变量赋值初始化

    printf("num=%d", num);

    system("pause");
}

void ScanfDemo18()
{
    int a, b = 0, c;
    scanf("a=%d,b=%*d,c=%d", &a, &c);

    a = a + 1;
    //b = b + 10;
    printf("a=%d,b=%d,c=%d readall", a, b, c);
}

void ScanfDemo19()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    printf("a=%d,b=%d,c=%d readall", a, b, c);

    system("pause");
}

void ScanfDemo20()
{
    int num;
    char str[100] = { 0 };
    scanf("%d  %s", &num, str);
    printf("num=%d,str=%s", num, str);
    system("pause");
}

void ScanfDemo21()
{
    char str[100] = { 0 };
    //scanf("%s", str);//空格当作结束
    //scanf("%[^\n]", str);//处理空格
    //	scanf("%[^,]", str);
    scanf("%[^,]", str);//,#  =作为结束符

    printf("str=%s", str);
    system("pause");
}

void ScanfDemo22()
{
    char str[100] = { 0 };
    //scanf("%[1]", str);遇到第一个不是1 的字符结束，
    //scanf("%[A-Z]", str);//遇到第一个不是 A-Z的字符结束，
    //scanf("%[^A-Z]", str);//遇到第一个是 A-Z的字符结束，
    //scanf("%[a-zA-Z]", str);
    scanf("%[0-9a-zA-Z]", str);
    printf("str=%s", str);//电话只有数字，
    system("pause");
}