#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkQueue.h"

// 链表的头部 - 队头
// .....尾部 -- 队尾
// 初始化
void InitSeqQueue(LinkQueue* q)
{
	// 空链表
	q->size = 0;
	q->front = q->tail = NULL;
}

// 清空
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

// 进队列
void PushQ(LinkQueue* q, void* data)
{
	if (q == NULL || data == NULL)
	{
		return;
	}
	// 队列为空
	if (q->size == 0)
	{
		q->front = q->tail = data;
	}
	else
	{
		// 尾插法
		q->tail->next = data;
		q->tail = data;
	}
	q->size ++;
}

// 出队列
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
	// 如果队列空了
	if (q->size == 0)
	{
		q->tail = NULL;
	}
}

// 大小
int SizeQ(LinkQueue* q)
{
	if (q == NULL)
	{
		return 0;
	}
	return q->size;
}
// 获取队头元素值
void* GetHead(LinkQueue* q)
{
	if (q == NULL)
	{
		return NULL;
	}
	return q->front;
}