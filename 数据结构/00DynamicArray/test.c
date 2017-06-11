#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "DArray.h"

typedef struct Persion
{
    int id;
    char name;
}Persion;

void myprint(Persion* p)
{
    printf("name = %c, id = %d\n", p->name, p->id);
}

int main()
{
    Persion p[10];
    // 创建管理动态数组的结构体
    DArray* ptr = Init_DArray(5);
    // 插入元素
    for (int i = 0; i <= 20; ++i)
    {
        p[i].id = i;
        p[i].name = 'A' + i;
        Insert_DArray(ptr, i, &p[i]);
    }
    // 遍历
    Traverse_DArray(ptr, myprint);
    printf("===============\n");

    Delete_DArray(ptr, 4);
    Traverse_DArray(ptr, myprint);

    Destroy_DArray(ptr);

    system("pause");
    return 0;
}