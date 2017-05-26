#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void һά����0();
void һά����1();
void һά�����ʼ��(int *arr, int length);
void һά�������ӡ(int *arr, int length);

void һά����0()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d	%p	%d	%p\n", arr[i], &arr[i], *(arr + i), arr + i);
    }

    int *p1 = arr;
    int *p2 = &arr;
    printf("%p	%d	%p	%d\n", p1, *p1, p2, *p2);

    p1 = p1 + 1;
    p2 = p2 + 1;
    printf("%p	%d	%p	%d\n", p1, *p1, p2, *p2);

    int	*p3 = arr + 1;
    int	*p4 = &arr + 1;
    printf("%p	%d	%p	%d\n", p3, *p3, p4, *p4);
}
void һά����1()
{
    int arr[10] = { 0 };
    һά�����ʼ��(arr, 10);
    һά�������ӡ(arr, 10);
}
void һά�����ʼ��(int *arr, int length)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
}
void һά�������ӡ(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void һ��ָ��()
{
    int len = 1024 * 1024 * 10;
    int *p = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        p[i] = 123 + i;
        //*(p + i) = 123 + i;
    }
    /* for (int i = 0; i < len; i++)
     {
         printf("%d\n", p[i]);
     }*/
    free(p);
}
void malloc2(int **p, int length)
{
    *p = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
    {
        (*p)[i] = 123 + i;
        //	*(*p + i) = 123 + i;
    }
}
void һ��ָ�����ѿռ�()
{
    int *p = (int *)malloc(sizeof(int) * 5);
    malloc2(&p, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", p[i]);
    }
    if (p)
    {
        free(p);
        p = NULL;
    }
}