#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
/*
    在创建变量的 时候不能超出栈的大小，一般情况下：windows中栈区的大小为1-8M，在Linux中是1-16M

*/
void MallocDemo()
{
    int * p = (int *)malloc(sizeof(int));
    if (p)
    {
        printf("内存分配成功\n");
        printf("%p\n", p);
        *p = 123;
        free(p);
    }
    else
    {
        printf("内存分配失败\n");
    }
}

int Add(int a, int b)
{
    return a + b;
}

void 函数指针()
{
    int(*P) (int, int);
    P = Add;
    int sum = P(12, 13);
    printf("%d\n", sum);
}

void 二级指针与内存分配()
{
    int **p = (int **)malloc(sizeof(int *) * 3);

    for (int i = 0; i < 3; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * 3);
    }
    int s = 0;
    for (int i = 0; i < 3; i++)
    {
        /*for (int j = 0; j < 3; j++)
        {
           p[i][j] = 10 + (++s);
        }*/

        int sum = 0;

        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &p[i][j]);
            //scanf("%d", *(p[i] + j));
            sum += p[i][j];
        }
        printf("%d名学生总成绩为：%d\n", i + 1, sum);
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        free(p[i]);
        p[i] = NULL;
    }

    free(p);
    p = NULL;
}

void MemsetDemo()
{
    int *p = (int *)malloc(sizeof(int) * 10);
}

void MemcpyDemo0()
{
    char * arr = malloc(sizeof(char) * 6);
    //strcpy(arr, "hello", 6);
    memcpy(arr, "hello", 6);
    printf("%s\n", arr);
    free(arr);
}

void MallocDemo2(int **p)
{
    *p = (int *)malloc(sizeof(int) * 10);
    /* 调用
        int *p = NULL;
        MallocDemo2(&p);
        p[0] = 10;
        printf("%d\n",p[0]);
    */
}

int * MallocDemo3(int *p)
{
    p = (int *)malloc(sizeof(int) * 10);
    return p;
    /* 调用
        int *p = NULL;
        p = MallocDemo3(p);
        p[0] = 10;
        printf("%d\n", p[0]);
    */
}

int * MallocDemo4()
{
    int *p = (int *)malloc(sizeof(int) * 10);
    return p;
    /* 调用
        int *p = NULL;
        p = MallocDemo4(p);
        p[0] = 10;
        printf("%d\n", p[0]);
    */
}

void MallocZere()
{
    int *p = (int *)malloc(0);
    if (p)
    {
        printf("%p\n", p);
        *p = 123;
        printf("%d\n", *p);
        printf("Success\n");
    }
    else
    {
        printf("Failed\n");
    }
    free(p); //0释放一定报错
}

void MallocTwo()
{
    int *p = (int*)malloc(malloc(2));
    if (p)
    {
        printf("%p\n", p);
        *p = 123;
        printf("%d\n", *p);
        printf("Success\n");
    }
    else
    {
        printf("Failed\n");
    }
    free(p);
}

void Nizhi(char * s)
{
    char * star = s;
    char * end = s + strlen(s) - 1;

    while (star < end)
    {
        char temp = *star;
        *star++ = *end;
        *end-- = temp;
    }
    /*调用：
        char h[] = "hello";
        printf("%s\n", h);
        Nizhi(h);
        printf("%s\n", h);
    */
}

void Quchong()
{
    /*
        下表是唯一的,可事先做好标记(标记的次数是多次的)
    */
    //dgfsghjfgshdFGDGFGFf247348374836GJHFHGDG

    char *s = (char *)malloc(sizeof(char) * 100);

    memset(s, 0, 100);
    memcpy(s, "dgfsghjfgshdFGDGFGFf247348374836GJHFHGDG", 41);
    int arr[127] = { 0 };

    for (int i = 0; i < strlen(s); i++)
    {
        arr[s[i]] = 1;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (arr[i])
        {
            printf("%c", i);
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (arr[i])
        {
            printf("%c", i);
        }
    }
    printf("\n");
    free(s);
}

void Demo1x()
{
    char * h = "hello";//不可以通过移动++，--移动指向位置来修改
    printf("%p\n", h);

    printf("%s\n", h);
    h = "world";
    printf("%s\n", h);
}

void Demo1Y()
{
    char *p1, *p2, *p3, *p4, ch;

    //A:
    //p1 = &ch;
    //scanf("%c", p1);
    //printf("p1=%s\n", p1);//

    //B:
    //p2 = (char *)malloc(1);
    //scanf("%c", p2);
    //printf("p2=%s\n", p2);

    /*p3=getchar();
    printf("p3=%s\n", p3);*/

    //p4 = &ch;
    //*p4 = getchar();
    //printf("p4=%s\n", p4);
}

void sub1(int s[], int y)
{
    static int t = 3;
    printf("\nt=%d\n", t);
    s[t] = y;
    t--;
    /*
    int a[] = { 1, 2, 3, 4 }, i, x = 0;
    for (int i = 0; i < 4; i++) {
    sub1(a, x);
    printf("%d", a[i]);
    }
    printf("\n");
    */
}

void sub2(int s[], int y)
{
    static int t = 3;
    y = s[t];
    t--;
    /*调用：
    int a[] = { 1, 2, 3, 4 }, i, x = 0;
    for (i = 0; i < 4; i++) {
    sub2(a, x);
    printf("%d", x);
    }
    printf("\n");
    */
}

void CallocDemo0()
{
    int  num;
    scanf_s("%d", &num);
    int *p = (int *)calloc(num, sizeof(int));
    for (int i = 0; i < num; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < num; i++)
    {
        printf("%d\t%p\t%d\t%p\n", p[i], &p[i], *(p + i), p + i);
    }
}

void CallocDemo1()
{
    int *p = calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(p + i));
    }
    *(p + 0) = 1;
    *(p + 1) = 2;
    *(p + 2) = 3;
    *(p + 3) = 4;
    *(p + 4) = 5;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(p + i));
    }
}

void CallocDemo2()
{
    int *p = calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n请输入前五名学生的成绩：");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", p + +i);
    }

    //*(p + 0) = 1;
    //*(p + 1) = 2;
    //*(p + 2) = 3;
    //*(p + 3) = 4;
    //*(p + 4) = 5;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(p + i));
    }

    p = realloc(p, sizeof(int) * 10);
    printf("\n请后入前五名学生的成绩：");

    for (int i = 5; i < 10; i++)
    {
        scanf("%d", p + +i);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", *(p + i));
    }
}

void reallocDemo0()
{
    int * intArr0 = (int *)malloc(sizeof(int) * 6);

    //分配了24个字节，可存6个整数，超过6个会过界的
    memset(intArr0, 0, sizeof(int) * 5);
    intArr0[0] = 0;
    intArr0[1] = 1;
    intArr0[2] = 2;
    intArr0[3] = 3;
    intArr0[4] = 4;
    intArr0[5] = 5;

    printf("%p\n", intArr0);
    printf("%d\n", intArr0[1]);
    printf("%d\n", intArr0[2]);
    printf("%d\n", intArr0[3]);
    printf("%d\n", intArr0[4]);
    printf("%d\n", intArr0[5]);

    int *  intArr1 = (int *)realloc(intArr0, sizeof(int) * 5);
    printf("%p\n", intArr1);
    printf("%d\n", intArr1[1]);
    printf("%d\n", intArr1[2]);
    printf("%d\n", intArr1[3]);
    printf("%d\n", intArr1[4]);
    free(intArr1);
}

void ReallocDemo1()
{
    int * intArr0 = (int *)malloc(sizeof(int) * 6);

    //分配了24个字节，可存6个整数，超过6个会过界的
    memset(intArr0, 0, sizeof(int) * 5);
    intArr0[0] = 0;
    intArr0[1] = 1;
    intArr0[2] = 2;
    intArr0[3] = 3;
    intArr0[4] = 4;
    intArr0[5] = 5;

    printf("%p\n", intArr0);
    printf("%d\n", intArr0[1]);
    printf("%d\n", intArr0[2]);
    printf("%d\n", intArr0[3]);
    printf("%d\n", intArr0[4]);
    printf("%d\n", intArr0[5]);

    intArr0 = (int *)realloc(intArr0, sizeof(int) * 7);
    printf("%p\n", intArr0);
    printf("%d\n", intArr0[1]);
    printf("%d\n", intArr0[2]);
    printf("%d\n", intArr0[3]);
    printf("%d\n", intArr0[4]);
    printf("%d\n", intArr0[5]);
}

void 内存消耗()
{
    while (1)
    {
        malloc(1024);
        Sleep(1000);
    }
}

void main(void)
{
    MemoryTest1();
    system("pause");
}