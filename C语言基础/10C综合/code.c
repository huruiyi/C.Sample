#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef int(xyz)[5];
xyz* a;

void BubbleSort(int *arr, int length)
{
    int flag = 0;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (!flag)
        {
            return;
        }
        flag = 0;
    }
}
void 栈区变量生成方向()
{
    int arr[] = { 1,2,3,4,5,6,7,8 };
    for (int i = 0; i < 8; i++)
    {
        printf("%x\n", &arr[i]);
    }

    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    printf("\n\n");
    printf("%x\n", &a);
    printf("%x\n", &b);
    printf("%x\n", &c);
    printf("%x\n", &d);
    printf("%x\n", &e);
    //栈区数据存储从高地址到低地址
    //b3f660
    //b3f654
    //b3f648
    //b3f63c
    //b3f630
}
void 静态局部变量()
{
    static int a = 3;
    a++;
    printf("%d", a);
    /*
    //for (int i = 0;i < 3;i++)
    //{
    //	静态局部变量();
    //}
    */
}
void 数据存储()
{
    int a[] = { 1,2,3,4,5,6 };
    for (int i = 0; i < 6; i++)
    {
        printf("%p\n", a + i);
    }
    printf("[%d]\n", a + 1 - a);

    printf("\n");
    char  b = 'b';
    printf("%p\n", &b);
    char  c = 'c';
    printf("%p\n", &c);

    char dc[] = { 1,2,3,4,5,6 };
    for (char i = 0; i < 6; i++)
    {
        printf("%p\n", dc + i);
    }
    printf("\n");
    int *xx = dc;
    printf("%d\n", *xx);
}
void 格式化输入0()
{
    char str[] = "123456asd";
    int a = 0;
    char des[100] = { 0 };
    sscanf(str, "%[1-9]s", des);
    printf("%s\n", des); //---》123546
}
void 格式化输入1()
{
    char str[] = "hello@itcast.cn";
    char ch1[20] = { 0 };
    char ch2[20] = { 0 };
    sscanf(str, "%5s@%s", ch1, ch2);
    printf("%s\n", ch1);
    printf("%s\n", ch2);
}
void 字符串指针()
{
    char *a = "常量区";
    char *b = "常量区";
    char *c = "常量区";
    if (a == c)
    {
        printf("相等\n");
    }
    else
    {
        printf("不相等\n");
    }
    //指向的地址一致
    printf("%p\n", a);
    printf("%p\n", b);
    printf("%p\n", c);

    //指向的地址不一致
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);
}
void 浅拷贝()
{
    char *ch = "hello world";
    char *a = malloc(20);
    char *b = malloc(20);
    char *c = malloc(20);

    //浅拷贝 地址
    strcpy(a, ch);
    strcpy(b, ch);
    strcpy(c, ch);
    if (a == c)
    {
        printf("相等\n");
    }
    else
    {
        printf("不相等\n");
    }
    printf("%p %s\n", a, a);
    printf("%p %s\n", b, b);
    printf("%p %s\n", c, c);

    /*
        struct man
        {
        char *name;
        int   count;
        }Man1, Man2;
        Man1.name = (char*)malloc(8);
        Man1.count = 20;
        memcpy(&Man2, &Man1, sizeof(Man1));
    */
}
void 深拷贝()
{
    char *ch = "hello world";
    char *a = malloc(20);
    char *b = malloc(20);
    char *c = malloc(20);
    //深拷贝 内容
    memcpy(a, ch, 12);
    memcpy(b, ch, 12);
    memcpy(c, ch, 12);
    if (a == c)
    {
        printf("相等\n");
    }
    else
    {
        printf("不相等\n");
    }
    printf("%p %s\n", a, a);
    printf("%p %s\n", b, b);
    printf("%p %s\n", c, c);
}
void 字符整形加法运算()
{
    char mm[4][3] = { "12", "34", "56", "78" };
    char *pn[4];
    int k, s = 0;
    for (k = 0; k < 4; k++)
    {
        pn[k] = mm[k];
    }
    for (k = 1; k < 4; k += 2)
    {
        //s = s * 10 + pn[k][1] - '0';

        int x = pn[k][1];
        s = s * 10 + x - '0';

        printf("%d\n", s);
    }

    int sx = 4 * 10 + 8 - '0';
    printf("%d\n", s);
}
void 强制类型转化1()
{
    typedef struct Teacher
    {
        char *name;
        int age;
    } Teacher_t;

    Teacher_t * t = (Teacher_t *)0;
    printf("%p\n", t);
    int	offset = (int)
        &
        (
        ((Teacher_t *)0)->age
            );
    printf("%d\n", offset);//4
}
void 强制类型转化2()
{
#pragma pack(4)
    typedef struct Teacher
    {
        char *name;
        int age;
    } Teacher_t;

    int	offset = (int)&(((Teacher_t *)0)->age) - (int)&(((Teacher_t	*)0)->name);
    printf("%d\n", offset);//4
}
void 强制类型转化3()
{
    typedef struct Teacher
    {
        char name[64];
        int age;
    } Teacher_t;

    int *p = &(((Teacher_t *)0)->age); //0x00000040  ===>十进制 64
    int offset = (int)&(((Teacher_t *)0)->age);
    printf("%d\n", offset);//64
}
void 强制类型转化4()
{
    printf("%d", (int)((int*)0 + 4));
}

void main()
{
    结构体内存分配();
    system("pause");
}