#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

// 初始化LinkList
LinkList* InitLinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->header.next = NULL;
	list->size = 0;

	return list;
}
// 插入
void InsertLinkList(LinkList* list, int pos, Node *node)
{
	// 节点的连接, 不给链表节点malloc内存
	if (list == NULL || node == NULL)
	{
		return;
	}
	// 插入操作
	Node* pcur = &list->header;
	// 找到了pos-1位置的节点
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	node->next = pcur->next;
	pcur->next = node;

	list->size++;
}

// 删除
void DeleteLinkList(LinkList* list, int pos)
{
	Node* pcur = &list->header;
	// 找到了pos-1位置的节点
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	Node* pdel = pcur->next;
	pcur->next = pdel->next;
	list->size--;
}

// 遍历
void Foreacher(LinkList* list, void(*print)(void*))
{
	Node* pcur = list->header.next;
	// pcur 是链表节点的地址
	while (pcur)
	{
		print(pcur);
		pcur = pcur->next;
	}
}

// 销毁
void DestroyLinkList(LinkList* list)
{
	free(list);
}