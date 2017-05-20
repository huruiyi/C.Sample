#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void 打印二维数组(int *p, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", *(p + i));
    }
    printf("\n");
}
void 二维指针数组()
{
    int arr[3][5] = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    打印二维数组(arr, 15);

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
void 二维数组打印()
{
    int arr[3][5] = { 11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
    //打印二维数组 (arr);
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
void 二维数组排序_全部排序()
{
    int arr[4][4] = { 0 };
    int *p = arr;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 16; i++)
    {
        *(p + i) = rand() % 100;
    }
    打印二维数组(p, 16);
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
    打印二维数组(p, 16);
}
void 二维数组排序_单行排序()
{
    int arr[4][4] = { 0 };
    int *p = arr;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 16; i++)
    {
        *(p + i) = rand() % 100;
    }
    打印二维数组(p, 16);
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
    打印二维数组(p, 16);
}

void 输出函数指针(char  **p, int length)
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

void 指针数组0()
{
    //指针数组做为函数参数时退化为二级指针
    char *p[3] = { "hello","world","bye" };
    //输出函数指针(p, 3);
    输出函数指针(&p, 3);

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

void 指针数组1()
{
    //int(*p0)[5] = { 0 };
    //printf("%d\n", p0);
    //printf("%d\n", p0 + 1);
    //printf("%d\n", p0 + 2);
    //printf("%d\n", p0 + 3);
    //printf("%d\n", p0 + 4);

    //指针数组，存储的是字符串常量的地址，存在于栈区，其值是不可以修改的
    char *p[] = { "abcd","1234","mnxy" };
    //p[0][1] = 'A';//不可以修改

    char *p1 = "123";

    /*
    二维数组行的首地址
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
    *p = (char **)malloc(sizeof(char *) * 3); //*p二级
    for (int i = 0; i < 3; i++)
    {
        //1、找到二级指针 对二级指针自增跳过了一个一级指针  在*变成一级指针
        *(*p + i) = (char *)malloc(sizeof(char) * 20);
        memset(*(*p + i), 0, 20);
        strcpy(*(*p + i), "hello");

        //2、找到二级指针 对二级指针降级运算在加上步长 变成一级指针地址
        //(*p)[i] = (char *)malloc(sizeof(char) * 20);
        //memset((*p)[i], 0, 20);
        //strcpy((*p)[i], "hello");
    }

    ////测试存储数据
    //for (int i = 0; i < 3; i++)
    //	printf("%s\n", (*p)[i]);

    //测试释放
    for (int i = 0; i < 3; i++)
        free(*(*p + i));
    free(*p);
}
void 二级指针调用()
{
    char **p = NULL;//字符串指针数组
    malloc3(&p, 3);
}

void 二级指针()
{
    //char *p[3] = { "abc","123","!@#" };
    //for (int i = 0; i < 3; i++)
    //{
    //	printf("%s\n", p[i]);
    //}

    char **p = NULL;//字符串指针数组
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