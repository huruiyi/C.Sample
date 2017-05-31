#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqQueue.h"

// �������ͷ����Ϊ�˶�ͷ
// �����β����Ϊ�˶�β
// ��ʼ��
void InitSeqQueue(SeqQueue* q)
{
	q->front = q->tail = -1;
	memset(q->data, 0, sizeof(q->data));
}

// ���
void ClearQ(SeqQueue* q)
{
	InitSeqQueue(q);
}
// ������
void PushQ(SeqQueue* q, void* data)
{
	if (q == NULL || data == NULL)
	{
		return;
	}
	if (q->tail == MAX - 1)
	{
		// ��������
		return;
	}
	// ����ǵ�һ�η�����
	if (q->front == -1)
	{
		q->front = 0;
	}
	// ���ݷŵ���β
	q->tail++;
	q->data[q->tail] = data;
}
// ������
void PopQ(SeqQueue* q)
{
	if (q->front == -1)
	{
		return;
	}
	for (int i = 1; i <= q->tail; ++i)
	{
		q->data[i - 1] = q->data[i];
	}
	q->tail--;
	// û��Ԫ����
	if (q->tail == -1)
	{
		q->front = -1;
	}
}
// ��С
int SizeQ(SeqQueue* q)
{
	if (q)
	{
		return q->tail + 1;
	}
	return 0;
}
// ��ȡ��ͷԪ��ֵ
void* GetHead(SeqQueue* q)
{
	if (q->front == -1)
	{
		return NULL;
	}
	return q->data[q->front];
}