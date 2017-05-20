#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Change1(int a, int b)
{
    printf("Change1  a=%d	\t	pa=%p	\n", a, &a);
    printf("Change1  b=%d	\t	pb=%p	\n", b, &b);
    int temp = a;
    a = b;
    b = temp;
    printf("Change1  a=%d	\t	pa=%p	\n", a, &a);
    printf("Change1  b=%d	\t	pb=%p	\n", b, &b);
}
void ChangeDemo1()
{
    int a = 1;
    int b = 2;
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
    Change1(a, b);
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
}

void Change2(int *a, int *b)
{
    printf("Change2  a=%d	\t	pa=%p	\n", *a, a);
    printf("Change2  b=%d	\t	pb=%p	\n", *b, b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Change2  a=%d	\t	pa=%p	\n", *a, a);
    printf("Change2  b=%d	\t	pb=%p	\n", *b, b);
}
void ChangeDemo2()
{
    int a = 1;
    int b = 2;
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
    Change2(&a, &b);
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
}

void Change3(int *a, int *b)
{
    printf("Change3  a=%d	pa=%p	\n", *a, a);
    printf("Change3  b=%d	pb=%p	\n", *b, b);
    int *temp = a;
    a = b;
    b = temp;
    printf("Change3  a=%d	pa=%p	\n", *a, a);
    printf("Change3  b=%d	pb=%p	\n", *b, b);
}
void ChangeDemo3()
{
    int a = 1;
    int b = 2;
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
    Change3(&a, &b);
    printf("a=%d	\t	pa=%p	\n", a, &a);
    printf("b=%d	\t	pb=%p	\n", b, &b);
}

void ChageDemo()
{
    ChangeDemo1();
    printf("*****************************************************************************\n");

    ChangeDemo2();
    printf("*****************************************************************************\n");

    ChangeDemo3();
    printf("*****************************************************************************\n");
}