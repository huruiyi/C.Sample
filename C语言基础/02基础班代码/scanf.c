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
    printf("����ĸ�����%d\n", num);//scanf�ķ���ֵ�ɹ���ץ�����ٸ�����
    printf("%d\n", a);
    printf("%d\n", b);
    system("pause");
}

void ScanfDemo03()
{
    char str[500] = "131610	��С��	Ů	40	165	����	δ��	����	˫����	��Уѧ��	��ͨ��	����	����Ԫ/��	�й�����	ѧ������	�崿Ư�� ���ſɰ����Ҷ��ڱ�����ѧ.���������ļ���ż����������Ѱ���ҵ���Ե��.Ը���ǵ���������������������õĻ���!	10:00��23:00		2264938779@qq.com		226493870779";
    int age;
    int tall;
    sscanf(str, "%*d %*s %*s %d %d ", &age, &tall);//�ھ�
    printf("age=%d,tall=%d\n", age, tall);

    //	(age >= �������������) && (tall <= ������������) ? printf("������") : printf("����һ��");

    system("pause");
}

void  ScanfDemo04()
{
    //%s ,
    char str[500] = "420111197203024016,13600477059,nixiaodong@vip.sina.com";
    //�ַ�������ɶ��ŵ���һ������

    long long selfid;
    long long mobile;
    char email[100] = { 0 };
    //��%  # ������Ϊ�ַ�������������Ҫ�滻

    sscanf(str, "%lld,%lld,%s", &selfid, &mobile, email);//���ַ����ھ�
    printf("%lld,%lld,%s", selfid, mobile, email);

    system("pause");
}

void  ScanfDemo05()
{
    char str[500] = "������,420111197203024016,13600477059,nixiaodong@vip.sina.com";
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
    scanf("%3d%3d%3d%3d%3d", &a, &b, &c, &d, &e);//3���ճ���3����ȡ
    printf("a=%d,b=%d,c=%d,d=%d,e=%d", a, b, c, d, e);

    system("pause");
}

void  ScanfDemo08()
{
    char str1[100] = { 0 };
    char str2[100] = { 0 };
    scanf("%*3s%5s", str1, str2);//�̶����Ƚ�ȡ,*����
    printf("%s,%s", str1, str2);
    system("pause");
}

void  ScanfDemo09()
{
    float fl = 0;
    scanf("%7f", &fl);//ʵ��������ָ������
    printf("fl=%f", fl);

    system("pause");
}

void  ScanfDemo10()
{
    int num = 0;
    scanf("%d", &num);//��д��ַ�������������ֵ������ַ

    system("pause");
}

void ScanfDemo11()
{
    int num = 0;
    scanf("#num=%d", &num);//��ȷƥ�䣬��������©
    printf("%d", num);
    system("pause");
}

void  ScanfDemo12()
{
    char ch1, ch2, ch3;
    scanf("%c%c%c", &ch1, &ch2, &ch3);
    printf("[%c][%c][%c]", ch1, ch2, ch3);//�س��ᱻ����һ������
    system("pause");
}

void  ScanfDemo13()
{
    int num1;
    int num2;
    int num3;
    char str[100];
    scanf("%s%d%d%d", str, &num1, &num2, &num3);
    printf("%s,%d,%d,%d", str, num1, num2, num3);//�ַ�������ո���߻س�

    system("pause");
}

void  ScanfDemo14()
{
    int num1;
    int num2;
    int num3;
    //%%scanf����һ��ʵ�ʵ�%
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
    scanf("%s%n%d%d%d", str, &n, &num1, &num2, &num3);//ͳ���ַ�����
    printf("\n%s,%d,%d,%d", str, num1, num2, num3);//�ַ�������ո���߻س�
    printf("\nn=%d", n);

    system("pause");
}

void  ScanfDemo16()
{
    char str[100];
    //scanf("%s", str);
    //scanf("%[^\n]", str);//ֻ��\n��������

    scanf("%n[A-Z]", str);//ֻ��\n��������
    printf("%s", str);

    system("pause");
}

void ScanfDemo17()
{
    int num = 0;
    //printf("%p", &num);

    scanf("num=%d", &num);//���ݵ�ַ�Ա�����ֵ��ʼ��

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
    //scanf("%s", str);//�ո�������
    //scanf("%[^\n]", str);//����ո�
    //	scanf("%[^,]", str);
    scanf("%[^,]", str);//,#  =��Ϊ������

    printf("str=%s", str);
    system("pause");
}

void ScanfDemo22()
{
    char str[100] = { 0 };
    //scanf("%[1]", str);������һ������1 ���ַ�������
    //scanf("%[A-Z]", str);//������һ������ A-Z���ַ�������
    //scanf("%[^A-Z]", str);//������һ���� A-Z���ַ�������
    //scanf("%[a-zA-Z]", str);
    scanf("%[0-9a-zA-Z]", str);
    printf("str=%s", str);//�绰ֻ�����֣�
    system("pause");
}