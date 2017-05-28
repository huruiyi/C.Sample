#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

// ��ʼ����ջ
void InitStack(SeqStack *st)
{
	if (st == NULL)
	{
		return;
	}
	st->top = -1;	// ��Чλ��
	memset(st->data, 0, sizeof(st->data));
}

// ���ջ
void ClearStack(SeqStack *st)
{
	InitStack(st);
}

// ��ȡջ��Ԫ��
void* GetTop(SeqStack *st)
{
	if (st == NULL)
	{
		return NULL;
	}
	// ��ջ
	if (st->top == -1)
	{
		return NULL;
	}
	// ��������һ��Ԫ��
	return st->data[st->top];
}

// ѹջ
void PushStack(SeqStack *st, void* data)
{
	if (st == NULL || data == NULL)
	{
		return;
	}
	// ջ����
	if (st->top == MAXSIZE - 1)
	{
		return;
	}
	st->top++;
	st->data[st->top] = data;
}

// ��ջ
void PopStack(SeqStack *st)
{
	if (st == NULL || st->top == -1)
	{
		return;
	}
	st->top--;
}

// ջ�Ĵ�С
int sizeStack(SeqStack *st)
{
	if (st->top == -1)
	{
		return 0;
	}
	return st->top + 1;
}