#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

typedef struct Persion
{
	int id;
	char name;
}Persion;

void myprint(void* p)
{
	Persion* pt = (Persion*)p;
	printf("name = %c, id = %d\n", pt->name, pt->id);
}

int mycompare(Persion* p1, Persion* p2)
{
	if (p1->id == p2->id && p1->name == p2->name)
	{
		return 1;
	}
	return 0;
}

int main()
{
	Persion p[10];
	// 创建管理链表的结构体
	LinkList* list = Init_LinkList();
	// insert
	for (int i = 0; i < sizeof(p)/sizeof(p[0]); ++i)
	{
		p[i].id = i;
		p[i].name = i + 'A';
		Insert_LinkList(list, i, &p[i]);
	}
	// 遍历
	Foreach_LinkList(list, myprint);
	printf("===============\n");
	// 删除
	Delete_LinkList(list, 3);
	Foreach_LinkList(list, myprint);

	// 查找
	Persion* pt = Search_LinkList(list, &p[2], mycompare);
	printf("===============\n");
	printf(" Search == name = %c, id = %d\n", pt->name, pt->id);

	system("pause");
	return 0;
}