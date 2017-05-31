#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SeqQueue.h"

// 将数组的头部作为了队头
// 数组的尾部作为了队尾
// 初始化
void InitSeqQueue(SeqQueue* q)
{
	q->front = q->tail = -1;
	memset(q->data, 0, sizeof(q->data));
}

// 清空
void ClearQ(SeqQueue* q)
{
	InitSeqQueue(q);
}
// 进队列
void PushQ(SeqQueue* q, void* data)
{
	if (q == NULL || data == NULL)
	{
		return;
	}
	if (q->tail == MAX - 1)
	{
		// 队列已满
		return;
	}
	// 如果是第一次放数据
	if (q->front == -1)
	{
		q->front = 0;
	}
	// 数据放到队尾
	q->tail++;
	q->data[q->tail] = data;
}
// 出队列
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
	// 没有元素了
	if (q->tail == -1)
	{
		q->front = -1;
	}
}
// 大小
int SizeQ(SeqQueue* q)
{
	if (q)
	{
		return q->tail + 1;
	}
	return 0;
}
// 获取队头元素值
void* GetHead(SeqQueue* q)
{
	if (q->front == -1)
	{
		return NULL;
	}
	return q->data[q->front];
}