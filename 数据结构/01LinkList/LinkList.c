#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

// 初始化
LinkList* Init_LinkList()
{
	LinkList* ptr = (LinkList*)malloc(sizeof(LinkList));
	// init
	ptr->header.data = NULL;
	ptr->header.next = NULL;
	ptr->size = 0;

	return ptr;
}

// 插入
// data - 外部出进来的地址
// 创建一个新的节点
void Insert_LinkList(LinkList* list, int pos, void* data)
{
	if (NULL == list || NULL == data)
	{
		return;
	}
	if (pos < 0 || pos > list->size)
	{
		return;
	}
	// 创建一个新节点
	Node* pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;

	// 插入节点
	// 需要一个辅助指针
	Node* pcur = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	pnew->next = pcur->next;
	pcur->next = pnew;

	list->size++;
}

// 删除 - 删除指定位置的节点
void Delete_LinkList(LinkList* list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	Node* pcur = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	Node* pdel = pcur->next;	// 没断开
	pcur->next = pdel->next;
	free(pdel);

	list->size--;
}

// 遍历
void Foreach_LinkList(LinkList* list, void(*print)(void*))
{
	if (list == NULL || print == NULL)
	{
		return;
	}
	// 遍历链表
	Node* pcur = list->header.next;	// 第一个数据节点
	while (pcur)
	{
		print(pcur->data);
		pcur = pcur->next;
	}
}

// 查找 - 回调
// -- 比较data和各个元素是否相等 
// compare 用户编写 的比较规则
// 返回值为1, 匹配成功, 0: 没有匹配到
void* Search_LinkList(LinkList* list, void* data, int(*compare)(void*, void*))
{
	if (list == NULL || data == NULL || compare == NULL)
	{
		return NULL;
	}
	// 用链表中的每一个节点, 和data比较
	Node* pcur = list->header.next;
	while (pcur)
	{
		// 比较两个变量是否相等
		if (compare(pcur->data, data))
		{
			break;
		}
		pcur = pcur->next;
	}
	// pcur 指向的地址中的数据和data指向的地址中的数据相等
	if (pcur == NULL)
	{
		return NULL;
	}
	return pcur->data;
}

// 销毁
void Destroy_LinkList(LinkList* list)
{
	if (list == NULL)
	{
		return;
	}
	Node* pcur = list->header.next;
	while (pcur)
	{
		Node* pdel = pcur;
		pcur = pcur->next;
		free(pdel);
	}
	free(list);
	list = NULL;
}