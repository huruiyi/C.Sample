#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#define  MAXSIZE 50
// ����ջ�Ľṹ��
typedef struct seqstack
{
	void* data[MAXSIZE];
	int top; // ���һ��Ԫ�ص��±�
}SeqStack;

// ��ʼ����ջ
void InitStack(SeqStack *st);
// ���ջ
void ClearStack(SeqStack *st);
// ��ȡջ��Ԫ��
void* GetTop(SeqStack *st);
// ѹջ
void PushStack(SeqStack *st, void* data);
// ��ջ
void PopStack(SeqStack *st);
// ջ�Ĵ�С
int sizeStack(SeqStack *st);



#endif