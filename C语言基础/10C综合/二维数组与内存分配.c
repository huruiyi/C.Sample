#include<stdio.h>
#include<stdlib.h>

void ��ά�������ݱ���()
{
    /*
        int a[3][4] = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12 };
        a[1][1];  //6
        int x  = *(&a[0]);//����
        int x0 = *(&a[0] + 1);//����
        int x1 = *(&a[0] + 5);//����
        int x2 = *(a[0] + 5);  //6
        int x3 = (*(a + 1)[1]);  //9
        int * x4 = *(a + 5);
    */
    int arr[4][3] =
    {
        { 11,12,13 },
        { 14,15,16 },
        { 17,18,19 } ,
        { 21,22,23 }
    };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%p	%p	%p	%d	%d	%d	%d\n", &arr[i][j], *(arr + i) + j, arr[i] + j, arr[i][j], *(*(arr + i) + j), *(arr[i]) + j, *(arr[i] + j));
        }
        printf("\n");
    }

    printf("��ά�����׵�ַ��%p	%p\n", arr, &arr[0][0]);
    for (int i = 0; i < 4; i++)
    {
        printf("��%d���׵�ַ��%p��ֵ ��%d---%d---%d---\n", (i + 1), arr[i], *arr[i], *(arr[i]) + 1, *(arr[i]) + 2);
    }
    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        printf("��%d���׵�ַ��%p��ֵ��", (i + 1), arr[i]);

        for (int j = 0; j < 3; j++)
        {
            printf(" %d---", *(arr[i]) + j);
        }
        printf("\n");
    }
    printf("\n");

    int *p = arr;
    for (int i = 0; i < 12; i++)
    {
        printf("��%d-%d-%d��", *(*arr + i), *(p + i), *(&arr[0][0] + i));
    }
    printf("\n");
}

void Demo1()
{
    int arr[3][3] = { 1,4,7,2,5,8,3,6,9 };
    //ָ������
    int * p0[3] = { NULL };
    p0[0] = arr[0];
    p0[1] = arr[1];
    p0[2] = arr[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", *(*(p0 + i) + j));
        }
    }
    printf("\n");

    int(*p1)[3] = NULL;
    //p��ָ���������
    p1 = arr;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", *(*(p1 + i) + j));
        }
    }
    printf("\n");

    //����ָ��
    int *p2 = arr;
    for (int i = 0; i < 9; i++)
    {
        printf("%d\t", *(p2 + i));
    }
}

void Demo2()
{
    int arr[2][5] = { 11,12,13,14,15,16,17,18,19,20 };

    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", &arr[0][0]);

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");

    int *p1 = arr;
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", *(p1 + i));
    }
    printf("\n");

    //int *p2[5] = { NULL };
    //p2[0] = arr[0];
    //p2[1] = arr[1];
    //p2[2] = arr[2];
    //p2[3] = arr[3];
    //p2[4] = arr[4];
    int * p2[5] = { arr[0],arr[1],arr[2],arr[3],arr[4] };

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", *(*(p2 + i) + j));
        }
    }
    printf("\n");

    int(*p3)[5] = arr;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", *(*(p3 + i) + j));
        }
    }
    printf("\n");

    int(*p4)[5] = arr;
    for (int i = 0; i < 2; i++)
    {
        int *p4j = *(p4 + i);
        printf("%d\t", *p4j);
        for (int j = 0; j < 5; j++)
        {
            printf("[%d  %d]\t", *p4j + j, *(p4j + j));
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%p\t", p4 + i);
            //printf("%p\t", *(p4 + i));
            printf("%p\t", (*(p4 + i) + j));
            printf("%d\t", *(*(p4 + i) + j));
            printf("\n");
        }
    }
    printf("\n");
}

void �ڴ����1()
{
    int * p1[5][2] = { 0 };
    p1[0][0] = malloc(sizeof(int));;
    p1[1][0] = malloc(sizeof(int));;
    p1[2][0] = malloc(sizeof(int));;
    p1[3][0] = malloc(sizeof(int));;
    p1[4][0] = malloc(sizeof(int));;

    p1[0][1] = malloc(sizeof(int));;
    p1[1][1] = malloc(sizeof(int));;
    p1[2][1] = malloc(sizeof(int));;
    p1[3][1] = malloc(sizeof(int));;
    p1[4][1] = malloc(sizeof(int));;

    *p1[0][0] = 11;
    *p1[1][0] = 12;
    *p1[2][0] = 13;
    *p1[3][0] = 14;
    *p1[4][0] = 15;

    *p1[0][1] = 12;
    *p1[1][1] = 13;
    *p1[2][1] = 14;
    *p1[3][1] = 15;
    *p1[4][1] = 16;
}
void �ڴ����2()
{
    int * p1 = { 0 };
    p1 = (int *)malloc(sizeof(int) * 5);
    for (int i = 0; i < 5; i++)
    {
        *(p1 + i) = i + 10;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", *(p1 + i));
    }
    free(p1);
}
void �ڴ����3()
{
    int *p[3];
    for (int i = 0; i < 3; i++)
    {
        p[i] = (int *)malloc(sizeof(int) * 5);
        for (int j = 0; j < 5; j++)
        {
            //p[i][j] = (i + 1)*(j + 1);
            *(p[i] + j) = (i + 1)*(j + 1);;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
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
}
void �ڴ����4()
{
    int(*p)[5];//�˴�5ָ������
    p = (int *)malloc(sizeof(int) * 35);
    // 5��3��  ��15��Ԫ��
    int val = 0;
    //���п����У��ڲ������
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //p[i][j] = (i + 1)*(j + 1);
            *(p[i] + j) = ++val;
        }
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    free(p);
    p = NULL;
}