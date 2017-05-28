#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

// ��ʼ����ջ
void InitStack(LinkStack* st)
{
	if (st == NULL)
	{
		return;
	}
	st->size = 0;
	st->top = NULL;
}
// ���ջ
void ClearStack(LinkStack* st)
{
	if (st == NULL)
	{
		return;
	}
	while (st->size)
	{
		Pop(st);
	}
}
// ��ȡջ��Ԫ��
void* GetTop(LinkStack* st)
{
	if (st->size == 0)
	{
		return NULL;
	}
	return st->top;
}
// ѹջ
void Push(LinkStack* st, Node* node)
{
	if (st == NULL || node == NULL)
	{
		return;
	}
	// ͷ�巨
	node->next = st->top;
	st->top = node;
	st->size++;
}
// ��ջ
void Pop(LinkStack* st)
{
	if (st->size == 0)
	{
		return;
	}
	st->top = st->top->next;
	st->size--;
}
// ջ�Ĵ�С
int Size(LinkStack* st)
{
	if (st == NULL)
	{
		return 0;
	}
	return st->size;
}