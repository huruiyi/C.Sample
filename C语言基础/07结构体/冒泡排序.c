#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define  MaxLength 5

typedef struct Student
{
    char * name;
    int * scores;//存储三门成绩 根据总成绩排序
}stu;

void BubbleSort(stu * st, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            //判断 score【0】+score【1】+score【2】
            int sum1 = st[j].scores[0] + st[j].scores[1] + st[j].scores[2];
            int sum2 = st[j + 1].scores[0] + st[j + 1].scores[1] + st[j + 1].scores[2];

            if (sum1 > sum2)
            {
                //交换的是结构体成员中的指针变量
                stu temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }
}

int mainX()
{
    stu st[5];

    for (int i = 0; i < 5; i++)
    {
        st[i].name = (char *)malloc(sizeof(char) * 21);
        st[i].scores = (int *)malloc(sizeof(int) * 3);

        scanf("%s", st[i].name);
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &st[i].scores[j]);
        }
    }

    BubbleSort(st, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("姓名：%s  ", st[i].name);
        for (int j = 0; j < 3; j++)
        {
            printf("成绩：%d  ", st[i].scores[j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        free(st[i].name);
        free(st[i].scores);
    }
    system("pause");
    return EXIT_SUCCESS;
}

typedef struct MStudent
{
    char * name;
    int * scores[3];//存储三门成绩 根据总成绩排序
}mstu;

void main()
{
    int intArr[MaxLength] = { 0 };

    printf("%d\n", MaxLength);

    mstu ms[3];
    ms[0].name = "who";
    ms[0].scores[0] = 12;
    ms[0].scores[1] = 13;
    ms[0].scores[2] = 14;

    printf("姓名：%s\t", ms[0].name);
    printf("成绩：%d\t", ms[0].scores[0]);

    system("pause");
}