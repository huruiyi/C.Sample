#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

void PrintfDemo0()
{
    printf("������%d\n", 10);
    printf("�ַ�����%s\n", "Hello World");
    printf("������%d,�ַ�����%s\n", 10, "Hello World");
    printf("�ַ�����Hello World\n");
}

void PrintDemo1()
{
    char inputStr[100] = { 0 };
    scanf("%s", inputStr);
    char str[100] = { 0 };
    sprintf(str, "color %s", inputStr);//sprintf���ַ���ƴ��
    system(str);
    system("pause");
}

void PrintDemo2()
{
    char des[100] = "abcdefghijklmnopqrstuvwxyz";
    printf("[%s]\n", des);
    printf("[%.5s]\n", des); //��ȡǰ��λ

    char buf[100] = { 0 };
    sprintf(buf, "[%s]\n", "12");
    //sprintf(buf, "[%6s]\n", "12");//�Ҷ��룬Ĭ���Կո����
    //sprintf(buf, "[%-6s]\n", "12");//����룬Ĭ���Կո����
    printf("%s", buf);
}

void PrintDemo3()
{
    printf("[%d]\n", 10); //�ж�������
    printf("[%10d]\n", 10);//���Ϊ10,
    printf("[%-10d]\n", 10);//���Ϊ10,Ĭ���ұ߶��룬-������߶���
    printf("[%010d]\n", 10);//���Ϊ10���������
    printf("[%3d]\n", 12345);//m����������ʵ�ʿ�ȣ����0���߿ո񣬷�����Ч
}

void PrintDemo4()
{
    printf("[%.2f]\n", 1.2345);
    char str[100] = "calc1";
    printf("[%.4s]\n", str);//��ȡС���㣬��ȡ�ַ���

    long l1 = 12345;
    printf("%d,%ld", l1, l1);//32λ %d,%ld ,int long�ȼ�
}

void PrintDemo5()
{
    int num0 = -12345678;
    printf("%d", num0);//�з���ʮ����
    printf("\n%i", num0);//�з���10����
    printf("\n%u", num0);//�޷���10����
    printf("\n%o", num0);//�޷���8����
    printf("\n%x\n\n", num0);//�޷���16����

    int num1 = -12345678;
    printf("%d", num1);//�з���ʮ����
    printf("\n%i", num1);//�з���10����
    printf("\n%u", num1);//�޷���10����
    printf("\n%o", num1);//�޷���8����
    printf("\n%x\n", num1);//�޷���16����

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
    printf("%c\n", ch);//�ַ�
    printf("%d\n", ch);//�ַ�
    printf("%u\n", ch);//�ַ�
    putchar(ch);//���һ���ַ�

    char str[100] = "calc";
    printf("%s\n", str);//�ַ������
}

void PrintDemo7()
{
    char str[100] = { 0 };
    //%3C ,�ո�3��
    sprintf(str, "color %c%c", '4', 'f');//��ʽ����������ʵ�����ַ������ϵ�һ���ַ���
    printf("%s", str);
    system(str);
}

void PrintDemo8()
{
    char str[10] = "task";
    char newstr[10] = "123list123";
    printf("%p", newstr);

    char strall[100] = { 0 };

    //%s%sƴ��
    //%.5%s��ȡ��ֻ�ܴ���߽�ȡ //��ĳһ����ַ�������ҿ�ʼ��ȡ
    //10������
    //-��߶���,

    sprintf(strall, "%s%.4s", str, newstr + 3);//�ַ���ַ���ƶ�ʵ������ĳһ��

    printf("%s", strall);
    system(strall);
}

/*
�����ַ�Windows��ռ�������ַ�
Linux  ��ռ�������ַ�
*/
void PrintDemo9()
{
    //char c = '��';
    //printf("%p", &c);
    char c[10] = "�����";
    printf("%c%c\n", c[0], c[1]);
    printf("%c%c\n", c[2], c[3]);
    printf("%c%c\n", c[4], c[5]);
}

void PrintDemo10()
{
    // Ĭ���Ҷ��루+��
    //        ����루-��
    double db = 109.123456789123;
    printf("[%.10f]\n", db);//.10С���㱣��ʮλ
    printf("[%30.10f]\n", db);
    printf("[%-30.10f]\n", db);//-���ƶ��룬30���
    printf("[%30.10f]\n", db);
}

void PrintDemo11()
{
    double db = 10456700000000;
    double dbs = 0.000000001;
    printf("%e\n", db);//ָ�����
    printf("%e\n", dbs);//ָ�����
}

void PrintDemo12()
{
    //double db = 10456700000000;
    double db = 1.234567;
    printf("%f\n", db);//g�Զ�ѡ���� %f.%e
    printf("%e\n", db);//g�Զ�ѡ���� %f.%e
    printf("%g\n", db);//g�Զ�ѡ���� %f.%e
}

void PrintDemo13()
{
    //int num;
    //printf("hello %n china", &num);//%n����
    //printf("num=%d", num);

    getchar();
}

void PrintDemo14()
{
    int num = printf("a=%d,b=%d", 10, 12);
    printf("\n%d", num);//����ֵ�ַ�����
    getchar();
}

void PrintDemo15()
{
    int num = printf("12345");
    printf("\n%d", num);//���ַ���������£�����ֵ�ַ�����
    getchar();
}

void PrintDemo16()
{
    int num = -1;
    // 0000 0000  0000 0000 0000 0000 0000 0001 +1ԭ��
    // 1000 0000  0000 0000 0000 0000 0000 0001	 -1ԭ��
    // 1111 1111  1111 1111 1111 1111 1111 1110 -1 ����
    // 1111 1111  1111 1111 1111 1111 1111 1111 -1 ����
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

    //%hd�������������� 16��λ�Ĵ洢  short��Χ
    //%d,%ld�ȼ�  %u %lu�ȼ�
    //%lld %llu����������
}

void PrintDemo18()
{
    int num = 0127;
    printf("%o", num);
    printf("\n%#o", num);

    int data = 0x1234;
    printf("\n%x", data);
    printf("\n%#x", data);//һ��������˽��ƣ�ʮ�����Ƽ���#
}

void PrintDemo19()
{
    float fl = 10.8;
    double  db = 10.9;// long double �ȼ���double

    printf("\n%a", fl);//ʮ�����Ƶ���ʾ��ʽ
    printf("\n%a", db);

    //p 16�ĵ�����eЧ��һ��
}

void PrintDemo20()
{
    printf("%D\n ", 10);//%d�����Դ�д
    printf("%O\n ", 010);//%o�����Դ�д
    printf("%U\n ", 010);//%u�����Դ�д
    printf("%#X\n ", 0x10);//X��Сд��������ĸ��Сд
    printf("%E\n ", 10000000.0);//����ĸ����ģ����Դ�Сд��û����ĸ���һ�㲻���ԣ�%o���⣩

    //printf��Ҫ��ȷƥ��
    printf("\"123\"\n ");//ת���ַ�
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
        printf("\n%*.*f", i * 2, i, db);//��С����λ�ñ䶯�ı仯
    }
}

void PrintDemo23()
{
    char str[100] = "1234567890qwertretrertert";
    for (int i = 1; i < 20; i++)
    {
        printf("\n%.*s", i, str);//���ƿ�ȣ�С���㣬��Ԫ
    }
}