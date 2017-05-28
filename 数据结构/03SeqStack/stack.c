#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

// 初始化空栈
void InitStack(SeqStack *st)
{
	if (st == NULL)
	{
		return;
	}
	st->top = -1;	// 无效位置
	memset(st->data, 0, sizeof(st->data));
}

// 清空栈
void ClearStack(SeqStack *st)
{
	InitStack(st);
}

// 获取栈顶元素
void* GetTop(SeqStack *st)
{
	if (st == NULL)
	{
		return NULL;
	}
	// 空栈
	if (st->top == -1)
	{
		return NULL;
	}
	// 数组的最后一个元素
	return st->data[st->top];
}

// 压栈
void PushStack(SeqStack *st, void* data)
{
	if (st == NULL || data == NULL)
	{
		return;
	}
	// 栈已满
	if (st->top == MAXSIZE - 1)
	{
		return;
	}
	st->top++;
	st->data[st->top] = data;
}

// 出栈
void PopStack(SeqStack *st)
{
	if (st == NULL || st->top == -1)
	{
		return;
	}
	st->top--;
}

// 栈的大小
int sizeStack(SeqStack *st)
{
	if (st->top == -1)
	{
		return 0;
	}
	return st->top + 1;
}