#include<stdio.h>
#include<stdlib.h>

void ����ת��1()
{
    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void ����ת��2()
{
    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
    //ָ������
    int * p[3] = { NULL };
    p[0] = arr[0];
    p[1] = arr[1];
    p[2] = arr[2];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + j) + i);
            *(*(p + j) + i) = temp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}

void ����ת��3()
{
    int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };

    int(*p)[3] = NULL;
    //p��ָ���������
    p = arr;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + j) + i);
            *(*(p + j) + i) = temp;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
}