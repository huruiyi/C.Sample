#include<stdio.h>
#include<stdlib.h>
//#include "staticfun.c"

typedef int(*tp1)(int, int);

typedef int(tp2)(int, int);

int Add(int a, int b)
{
    return a + b;
}

int Sub(int a, int b)
{
    return a - b;
}

int Mul(int a, int b)
{
    return a * b;
}

int Div(int a, int b)
{
    return a / b;
}

void FunPoint1()
{
    int(*p)(int a, int b);
    p = Add;
    int a = p(1, 2);
    p = Sub;
    int b = p(5, 1);
    p = Mul;
    int c = p(2, 3);
    p = Div;
    int d = p(12, 2);
    printf("1+2=%d\n", a);
    printf("5-1=%d\n", b);
    printf("2*3=%d\n", c);
    printf("12/2=%d\n", d);
}
void FunPoint2()
{
    int(*p1[])(int, int) = { Add,Sub,Mul,Div };
    printf("%d\n", p1[0](1, 2));
    printf("%d\n", p1[1](1, 2));
    printf("%d\n", p1[2](1, 2));
    printf("%d\n", p1[3](1, 2));
}
void FunPoint3()
{
    tp1 t1 = Add;
    printf("%d\n", t1(1, 2));

    tp2 *t2 = Add;
    printf("%d\n", t1(11, 22));
}
void FunPoint4()
{
    //PSAdd *psd = Sadd ;
    //int staticI1 = Sadd(123, 456);
    //printf("%d\n", staticI1);

    int staticI2 = InvorkeSadd(1, 20);
}