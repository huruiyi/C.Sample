#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "LinkList.h"

// ��ʼ��
LinkList* Init_LinkList()
{
	LinkList* ptr = (LinkList*)malloc(sizeof(LinkList));
	// init
	ptr->header.data = NULL;
	ptr->header.next = NULL;
	ptr->size = 0;

	return ptr;
}

// ����
// data - �ⲿ�������ĵ�ַ
// ����һ���µĽڵ�
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
	// ����һ���½ڵ�
	Node* pnew = (Node*)malloc(sizeof(Node));
	pnew->data = data;
	pnew->next = NULL;

	// ����ڵ�
	// ��Ҫһ������ָ��
	Node* pcur = &list->header;
	for (int i = 0; i < pos; ++i)
	{
		pcur = pcur->next;
	}
	pnew->next = pcur->next;
	pcur->next = pnew;

	list->size++;
}

// ɾ�� - ɾ��ָ��λ�õĽڵ�
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
	Node* pdel = pcur->next;	// û�Ͽ�
	pcur->next = pdel->next;
	free(pdel);

	list->size--;
}

// ����
void Foreach_LinkList(LinkList* list, void(*print)(void*))
{
	if (list == NULL || print == NULL)
	{
		return;
	}
	// ��������
	Node* pcur = list->header.next;	// ��һ�����ݽڵ�
	while (pcur)
	{
		print(pcur->data);
		pcur = pcur->next;
	}
}

// ���� - �ص�
// -- �Ƚ�data�͸���Ԫ���Ƿ���� 
// compare �û���д �ıȽϹ���
// ����ֵΪ1, ƥ��ɹ�, 0: û��ƥ�䵽
void* Search_LinkList(LinkList* list, void* data, int(*compare)(void*, void*))
{
	if (list == NULL || data == NULL || compare == NULL)
	{
		return NULL;
	}
	// �������е�ÿһ���ڵ�, ��data�Ƚ�
	Node* pcur = list->header.next;
	while (pcur)
	{
		// �Ƚ����������Ƿ����
		if (compare(pcur->data, data))
		{
			break;
		}
		pcur = pcur->next;
	}
	// pcur ָ��ĵ�ַ�е����ݺ�dataָ��ĵ�ַ�е��������
	if (pcur == NULL)
	{
		return NULL;
	}
	return pcur->data;
}

// ����
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