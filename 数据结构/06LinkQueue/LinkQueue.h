#pragma once

// 链表节点的结构体
typedef struct Node
{
	struct Node* next;
}Node;

// 管理队列的结构体
// - 节点的个数
// - 指向第一个节点的指针
// - 指向最后一个节点的指针

typedef struct LinkQueue
{
	int size;
	Node* front;	
	Node* tail;
}LinkQueue;

// 初始化
void InitSeqQueue(LinkQueue* q);
// 清空
void ClearQ(LinkQueue* q);
// 进队列
void PushQ(LinkQueue* q, void* data);
// 出队列
void PopQ(LinkQueue* q);
// 大小
int SizeQ(LinkQueue* q);
// 获取队头元素值
void* GetHead(LinkQueue* q);
