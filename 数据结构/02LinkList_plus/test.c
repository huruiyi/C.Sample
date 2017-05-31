#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

// 测试文件
typedef struct Persion
{
	// 外部数据包含一个链表节点
	// 链表节点必须放到第一个元素的位置
	Node node;
	int id;
	char name;
}Persion;


void myprint(void* pt)
{
	// pt是node节点的地址
	Persion* p = (Persion*)pt;
	printf("name = %c, id = %d\n", p->name, p->id);
}

int main()
{
	Persion p[10];
#if 0
	p[0].node.next = &p[1];
	p[1].node.next = &p[2];
	p[2].node.next = &p[3];
	p[3].node.next = &p[4];
#endif
	LinkList* list = InitLinkList();
	for (int i = 0; i < 10; ++i)
	{
		p[i].id = i;
		p[i].name = 'a' + i;
		InsertLinkList(list, i, &p[i].node);
		//InsertLinkList(list, i, &p[i]);
	}
	Foreacher(list, myprint);
	system("pause");
	return 0;
}