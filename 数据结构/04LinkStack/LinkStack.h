#ifndef _LINKSTACK_H
#define _LINKSTACK_H

// ����ڵ�Ľṹ��
typedef struct Node
{
    struct Node* next;
}Node;

// ��������Ľṹ��
typedef struct LinkStack
{
    int size;
    Node* top;
}LinkStack;

// api
// ��ʼ����ջ
void InitStack(LinkStack* st);
// ���ջ
void ClearStack(LinkStack* st);
// ��ȡջ��Ԫ��
void* GetTop(LinkStack* st);
// ѹջ
void Push(LinkStack* st, Node* node);
// ��ջ
void Pop(LinkStack* st);
// ջ�Ĵ�С
int Size(LinkStack* st);

#endif