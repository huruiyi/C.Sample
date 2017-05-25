#ifndef _LINKSTACK_H
#define _LINKSTACK_H

// 链表节点的结构体
typedef struct Node
{
    struct Node* next;
}Node;

// 管理链表的结构体
typedef struct LinkStack
{
    int size;
    Node* top;
}LinkStack;

// api
// 初始化空栈
void InitStack(LinkStack* st);
// 清空栈
void ClearStack(LinkStack* st);
// 获取栈顶元素
void* GetTop(LinkStack* st);
// 压栈
void Push(LinkStack* st, Node* node);
// 出栈
void Pop(LinkStack* st);
// 栈的大小
int Size(LinkStack* st);

#endif