#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void ��ӡ��ά����(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n");
}
void ��άָ������()
{
    int arr[3][5] = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    ��ӡ��ά����(arr, 15);

    int(*p)[5] = arr;
    for (int i = 0; i < 3; i++)
    {
        printf("%p\t", p + i);
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", *(*(p + i) + j));
        }
        printf("\n");
    }
}
void ��ά�����ӡ()
{
    int arr[3][5] = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    //��ӡ��ά���� (arr);
    int(*p)[5] = arr;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void ��ά��������_ȫ������()
{
    int arr[4][4] = { 0 };
    int *p = arr;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 16; i++)
    {
        *(p + i) = rand() % 100;
    }
    ��ӡ��ά����(p, 16);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16 - 1 - i; j++)
        {
            if (*(p + j) > *(p + j + 1))
            {
                int tmp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = tmp;
            }
        }
    }
    ��ӡ��ά����(p, 16);
}
void ��ά��������_��������()
{
    int arr[4][4] = { 0 };
    int *p = arr;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 16; i++)
    {
        *(p + i) = rand() % 100;
    }
    ��ӡ��ά����(p, 16);
    for (int index = 0; index < 4; index++)
    {
        for (int m = 0; m < 4; m++)
        {
            for (int n = 0; n < 4 - 1 - m; n++)
            {
                if (arr[index][n] > arr[index][n + 1])
                {
                    int tmp = arr[index][n];
                    arr[index][n] = arr[index][n + 1];
                    arr[index][n + 1] = tmp;
                }
            }
        }
    }
    ��ӡ��ά����(p, 16);
}

void �������ָ��(char  **p, int length)
{
    for (int i = 0; i < length; i++)
    {
        //printf("%s\n", *(p + i));
        char *pstr = *(p + i);
        int len = strlen(pstr);
        for (int j = 0; j < len; j++)
        {
            //printf("%c\n", (*(p + i))[j]);
            printf("%c", pstr[j]);
        }
        printf(" \n");
    }
}

void ָ������0()
{
    //ָ��������Ϊ��������ʱ�˻�Ϊ����ָ��
    char *p[3] = { "hello","world","bye" };
    //�������ָ��(p, 3);
    �������ָ��(&p, 3);

    //char *str = { "Hello" };
    //for (int i = 0; i < 5; i++)
    //{
    //	printf("%c\n", str[i]);
    //}
    //for (int i = 0; i < 5; i++)
    //{
    //	printf("%c\n", *(str + i));
    //}
    //for (int i = 0; i < 3; i++)
    //{
    //	printf("%s\n", p[i]);
    //}
}

void ָ������1()
{
    //int(*p0)[5] = { 0 };
    //printf("%d\n", p0);
    //printf("%d\n", p0 + 1);
    //printf("%d\n", p0 + 2);
    //printf("%d\n", p0 + 3);
    //printf("%d\n", p0 + 4);

    //ָ�����飬�洢�����ַ��������ĵ�ַ��������ջ������ֵ�ǲ������޸ĵ�
    char *p[] = { "abcd","1234","mnxy" };
    //p[0][1] = 'A';//�������޸�

    char *p1 = "123";

    /*
    ��ά�����е��׵�ַ
    */
    printf("%p\n", p[0]);
    printf("%p\n", p[1]);
    printf("%p\n", p[2]);

    printf("%c\n", (*p)[0]);
    printf("%c\n", (*p)[1]);
    printf("%c\n", (*p)[2]);

    printf("%c\n", *p[0]);
    printf("%c\n", *p[1]);
    printf("%c\n", *p[2]);
}
void malloc3(char ***p, int length)
{
    *p = (char **)malloc(sizeof(char *) * 3); //*p����
    for (int i = 0; i < 3; i++)
    {
        //1���ҵ�����ָ�� �Զ���ָ������������һ��һ��ָ��  ��*���һ��ָ��
        *(*p + i) = (char *)malloc(sizeof(char) * 20);
        memset(*(*p + i), 0, 20);
        strcpy(*(*p + i), "hello");

        //2���ҵ�����ָ�� �Զ���ָ�뽵�������ڼ��ϲ��� ���һ��ָ���ַ
        //(*p)[i] = (char *)malloc(sizeof(char) * 20);
        //memset((*p)[i], 0, 20);
        //strcpy((*p)[i], "hello");
    }

    ////���Դ洢����
    //for (int i = 0; i < 3; i++)
    //	printf("%s\n", (*p)[i]);

    //�����ͷ�
    for (int i = 0; i < 3; i++)
        free(*(*p + i));
    free(*p);
}
void ����ָ�����()
{
    char **p = NULL;//�ַ���ָ������
    malloc3(&p, 3);
}

void ����ָ��()
{
    //char *p[3] = { "abc","123","!@#" };
    //for (int i = 0; i < 3; i++)
    //{
    //	printf("%s\n", p[i]);
    //}

    char **p = NULL;//�ַ���ָ������
    p = (char **)malloc(sizeof(char *) * 3);
    for (int i = 0; i < 3; i++)
    {
        p[i] = (char *)malloc(sizeof(char) * 20);
        char str[100] = { 0 };
        sprintf(str, "100%d", i);
        strcpy(p[i], str);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s %p\n", p[i], p[i]);
    }
    int x1 = &p[1] - &p[0];//step length :1
    int x2 = &p[2] - &p[1];//step length :1
    int x3 = &p[2] - &p[0];//step length :2
    for (int i = 0; i < 3; i++)
    {
        if (p[i])
        {
            free(p[i]);
            p[i] = NULL;
        }
    }
    if (p)
    {
        free(p);
        p = NULL;
    }
}