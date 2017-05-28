#ifndef _SEQSTACK_H
#define _SEQSTACK_H

#define  MAXSIZE 50
// 管理栈的结构体
typedef struct seqstack
{
	void* data[MAXSIZE];
	int top; // 最后一个元素的下标
}SeqStack;

// 初始化空栈
void InitStack(SeqStack *st);
// 清空栈
void ClearStack(SeqStack *st);
// 获取栈顶元素
void* GetTop(SeqStack *st);
// 压栈
void PushStack(SeqStack *st, void* data);
// 出栈
void PopStack(SeqStack *st);
// 栈的大小
int sizeStack(SeqStack *st);



#endif