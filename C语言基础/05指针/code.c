#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void 指针初步()
{
    int a = 10;
    int * p = &a;
    printf("%d\n", a);
    printf("%p\n", &a);

    *p = 100;
    printf("%d\n", a);
    printf("%p\n", &a);
}

void 空指针()
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int));
    if (p != NULL)
    {
        printf("%p\n", p);
        *p = 123;
        printf("%d\n", *p);
    }
    free(p);
}

void 常量指针1()
{
    //int a = 10;
    //int b = 20;
    //const int *p = &a;
    ////*p = 100;//错误的
    //p = &b;

    //int a = 10;
    //int b = 20;
    //int * const p = &a;
    ////p = &b;//错误的
    //*p = b;

    int a = 10;
    int b = 20;
    const int * const p = &a;// 可以通过二级指针修改

    //p = &b; //错误的
    //*p = 123;//错误的
}

void 二级指针()
{
    int a = 10;
    int b = 20;
    const int * const p = &a;// 可以通过二级指针修改
    int **p2 = &p;
}

void 多级指针1()
{
    int a = 10;
    int *p = &a;
    int **pp = &p;
    int ***ppp = &pp;

    printf("%d\n", a);
    printf("%d\n", *p);
    printf("%d\n", **pp);
    printf("%d\n", ***ppp);

    printf("%p\n", **ppp);
    printf("%p\n", *pp);
    printf("%p\n", p);
    printf("%p\n", &a);

    printf("%p\n", *ppp);
    printf("%p\n", pp);
    printf("%p\n", &p);
}

void 多级指针2()
{
    int a = 12;
    int b = 13;
    int *p1 = &a;
    int **p2 = &p1;

    printf("p1=%x\n", p1);
    printf("p2=%x\n", p2);
    **p2 = 123;
    printf("p2=%x\n", p2);
    printf("a=%d\n", a);
}
void 数组和指针()
{
    int arr[] = { 1,2,3,4,5,6,7 };
    int *p = arr;
    printf("%d\n", p);
    printf("%p\n", &arr);
    printf("%p\n", &arr + 1);
    for (int i = 0; i < 7; i++)
    {
        printf("%d\t %d\t %p\t %p\n", arr[i], *(arr + i), &arr[i], arr + i);
    }
}

void mystrcat(char * dest, char * src)
{
    //while (*dest++ != '\0');
    //dest--;
    //while (*dest++ = *src++);

    //dest指向的地址是\0所在地址  找到字符串中有效字符
    //while (*++dest != '\0');
    //while (*dest++ = *src++);

    while (*++dest);
    while (*dest++ = *src++);

    /*
        char c1[100] = "hello";
        char c2[] = "world";
        mystrcat(c1, c2);
        printf("%s\n", c1);
    */
}
void 指针()
{
    int a = 10;
    int b = 100;
    int *p0 = &a;
    *p0 = b;
    printf("%d\n", a);

    int arr1[] = { 1,2,3,4,5 };
    int arr2[] = { 5,6,7,8,9 };
    printf("%p\n", arr1);
    printf("%p\n", arr2);

    //*(arr1 + 0) = *(arr2 + 0);
    //*(arr1 + 1) = *(arr2 + 1);
    //*(arr1 + 2) = *(arr2 + 2);
    //*(arr1 + 3) = *(arr2 + 3);
    //*(arr1 + 4) = *(arr2 + 4);
    //*(arr1 + 5) = *(arr2 + 5);

    int *p1 = arr1;
    int *p2 = arr2;
    printf("%p\n", p1);
    printf("%p\n", p2);

    for (int i = 0; i < 5; i++)
    {
        printf("%d %d\t", arr1[i], *(arr1 + i));
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", arr2[i]);
    }
}

void 数组指针()
{
    int stu1[] = { 50,60,70 };
    int stu2[] = { 60,70,80 };
    int stu3[] = { 70,70,80 };
    int *p[3] = { stu1,stu2,stu3 };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d-%d \t", *(p[i] + j), p[i][j]);
        }
        printf("\n");
    }
}

void 常量指针()
{
    char* s = "AAA";
    //s[0] = 'B';
    s = &"BBB";
    printf("%s\n", s);
}

int * ReturnPoint1()
{
    int a = 12;
    return &a;
}

int * ReturnPoint2(int a)
{
    return &a;
}

void Reverse(char * src)
{
    int len = strlen(src);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = src[i];
        src[i] = src[len - i - 1];
        src[len - i - 1] = temp;
    }
    //char src[] = { "   Hello    World    " };
    //char des[256] = { 0 };
    //Reverse(src);
    //printf("%s\n", src);
}

void 保留字母去重并排序(char * src, char * des)
{
    int srclen = strlen(src);
    int j = 0;
    for (int i = 0; i < srclen; i++)
    {
        char srcc = *(src + i);
        if ((srcc >= 'A'&&srcc <= 'Z') || (srcc >= 'a'&&srcc <= 'z'))
        {
            if (strchr(des, *(src + i)) == NULL)
            {
                *(des + j) = *(src + i);
                j++;
            }
        }
    }
    *(des + j) = 0;
    int deslen = strlen(des);
    for (int i = 0; i < deslen - 1; i++)
    {
        for (int j = 0; j < deslen - 1 - i; j++)
        {
            if (des[j] > des[j + 1])
            {
                char temp = des[j];
                des[j] = des[j + 1];
                des[j + 1] = temp;
            }
        }
    }
    /* 调用：
        char src[] = { "aAa!<-13cxnjfnefhivdHFJHGFHUJVbdjBJdbvjdBvsrgbviuaAa1->!zZzZ" };
        char des[256] = { 0 };
        保留字母去重并排序(src, des);
        printf("%s", des);
    */
}

void 指针的优先级()
{
    int a[5] = { 1,2,3,4,5 };
    int *p = a;
    printf("%p,%d\n", a, a[0]);
    //*p++; //p++先执行，改变的是p,而不是*p,++的优先级大于*
    ++*p; //++(*p) ,优先级只有与变量连在一起，才有优先级
    printf("%p,%d\n", a, a[0]);
}
void 指针数组()
{
    int intArr[] = { 1,2,3,4,5,6 };
    char *p[4] = { "hello","tree","new","bee" };
    for (int i = 0; i < 4; i++)
    {
        printf("%p \t %s\n", p[i], p[i]);
        printf("\n ");
    }
}
void 字符串指针1()
{
    char *lines[5] = {
        "COSC1283/1284",
        "Programming",
        "Techniques",
        "is",
        "great fun"
    };

    char *str1 = lines[1];
    char *str2 = *(lines + 3);
    char c1 = *(*(lines + 4) + 6);
    char c2 = (*lines + 5)[5];
    char c3 = *lines[0] + 2;

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1);
    printf("  c2 = %c\n", c2);
    printf("  c3 = %c\n", c3);
}
void 字符串指针2()
{
    char *string0 = "COSC1283/1284";
    char *string1 = "Programming";
    char *string2 = "Techniques";
    char *string3 = "is";
    char *string4 = "great fun";

    char *lines[5];
    lines[0] = string0;
    lines[1] = string1;
    lines[2] = string2;
    lines[3] = string3;
    lines[4] = string4;

    char *str1 = lines[1];
    char *str2 = *(lines + 3);
    char c1 = *(*(lines + 4) + 6);
    char c2 = (*lines + 5)[5];
    char c3 = *lines[0] + 2;

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1);
    printf("  c2 = %c\n", c2);
    printf("  c3 = %c\n", c3);
}

void Mprintf1(void * arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", *((int *)arr + i));
    }
}

void 万能指针1()
{
    int   arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    void *  ch = arr;
    Mprintf1(ch, 10);
}

void Mprintf2(void **arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s\n", *((int *)arr + i));
    }
}

void 万能指针2()
{
    void* data0[] = { 111,222,333,444,555,666,777,888,999 };
    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", data0[i]);
    }
    //指针数组
    void* data1[] = { "1","2","3","4","5","6" };
    Mprintf2(data1, 6);
    printf("\n");
    char *p[] = { "abc","123","456","xyz" };
    void **vp = p;
    Mprintf2(vp, 4);
}

void 万能指针3()
{
    void* data[] = { 1,2,3,4,5,6,7,8,9 };
    int a = data[0];
    for (int i = 0; i < 9; i++)
    {
        printf("%d\t", data[i]);
    }

    printf("\n");
    void **datap = data;
    int datap0 = datap[0];
    for (int i = 0; i < 9; i++)
    {
        printf("%d\t", datap[i]);
    }
}
void test()
{
    void *p = (int *)malloc(sizeof(int) * 5);

    //int *p0 = (int *)p + 0;
    //int *p1 = (int *)p + 1;
    //int *p2 = (int *)p + 2;
    //int *p3 = (int *)p + 3;
    //int *p4 = (int *)p + 4;

    //* p0  = 11110 + 1;
    //* p1  = 11111 + 1;
    //* p2  = 11112 + 1;
    //* p3  = 11113 + 1;
    //* p4  = 11114 + 1;

    //printf("%p\n", p);
    //printf("%p\n", p0);
    //printf("%p\n", p1);
    //printf("%p\n", p2);
    //printf("%p\n", p3);
    //printf("%p\n", p4);

    int * pp = p;
    int *pp0 = pp + 0;
    int *pp1 = pp + 1;
    int *pp2 = pp + 2;
    int *pp3 = pp + 3;
    int *pp4 = pp + 4;

    *pp0 = 111;
    *pp1 = 222;
    *pp2 = 333;
    *pp3 = 444;
    *pp4 = 555;
    for (int i = 0; i < 5; i++)
    {
        printf("%d---%d\n", pp + i, *(pp + i));
    }
    if (p)
    {
        free(p);
        printf("释放成功\n");
    }
    //常量 栈区，可以修改
}

void main()
{
    system("pause");
}