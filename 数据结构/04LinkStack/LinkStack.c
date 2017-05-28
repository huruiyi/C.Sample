#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkStack.h"

// 初始化空栈
void InitStack(LinkStack* st)
{
	if (st == NULL)
	{
		return;
	}
	st->size = 0;
	st->top = NULL;
}
// 清空栈
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
// 获取栈顶元素
void* GetTop(LinkStack* st)
{
	if (st->size == 0)
	{
		return NULL;
	}
	return st->top;
}
// 压栈
void Push(LinkStack* st, Node* node)
{
	if (st == NULL || node == NULL)
	{
		return;
	}
	// 头插法
	node->next = st->top;
	st->top = node;
	st->size++;
}
// 出栈
void Pop(LinkStack* st)
{
	if (st->size == 0)
	{
		return;
	}
	st->top = st->top->next;
	st->size--;
}
// 栈的大小
int Size(LinkStack* st)
{
	if (st == NULL)
	{
		return 0;
	}
	return st->size;
}