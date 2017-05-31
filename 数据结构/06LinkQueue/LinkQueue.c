#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkQueue.h"

// �����ͷ�� - ��ͷ
// .....β�� -- ��β
// ��ʼ��
void InitSeqQueue(LinkQueue* q)
{
	// ������
	q->size = 0;
	q->front = q->tail = NULL;
}

// ���
void ClearQ(LinkQueue* q)
{
	if (q == NULL)
	{
		return;
	}
	while (q->size)
	{
		PopQ(q);
	}
}

// ������
void PushQ(LinkQueue* q, void* data)
{
	if (q == NULL || data == NULL)
	{
		return;
	}
	// ����Ϊ��
	if (q->size == 0)
	{
		q->front = q->tail = data;
	}
	else
	{
		// β�巨
		q->tail->next = data;
		q->tail = data;
	}
	q->size ++;
}

// ������
void PopQ(LinkQueue* q)
{
	if (q == NULL)
	{
		return;
	}
	if (q->size == 0)
	{
		return;
	}
	q->front = q->front->next;
	q->size--;
	// ������п���
	if (q->size == 0)
	{
		q->tail = NULL;
	}
}

// ��С
int SizeQ(LinkQueue* q)
{
	if (q == NULL)
	{
		return 0;
	}
	return q->size;
}
// ��ȡ��ͷԪ��ֵ
void* GetHead(LinkQueue* q)
{
	if (q == NULL)
	{
		return NULL;
	}
	return q->front;
}