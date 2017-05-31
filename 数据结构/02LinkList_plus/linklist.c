#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linklist.h"

// ��ʼ��LinkList
LinkList* InitLinkList()
{
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->header.next = NULL;
	list->size = 0;

	return list;
}
// ����
void InsertLinkList(LinkList* list, int pos, Node *node)
{
	// �ڵ������, ��������ڵ�malloc�ڴ�
	if (list == NULL || node == NULL)
	{
		return;
	}
	// �������
	Node* pcur = &list->header;
	// �ҵ���pos-1λ�õĽڵ�
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	node->next = pcur->next;
	pcur->next = node;

	list->size++;
}

// ɾ��
void DeleteLinkList(LinkList* list, int pos)
{
	Node* pcur = &list->header;
	// �ҵ���pos-1λ�õĽڵ�
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	Node* pdel = pcur->next;
	pcur->next = pdel->next;
	list->size--;
}

// ����
void Foreacher(LinkList* list, void(*print)(void*))
{
	Node* pcur = list->header.next;
	// pcur ������ڵ�ĵ�ַ
	while (pcur)
	{
		print(pcur);
		pcur = pcur->next;
	}
}

// ����
void DestroyLinkList(LinkList* list)
{
	free(list);
}