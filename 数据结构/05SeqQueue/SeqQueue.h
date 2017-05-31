#pragma  once
#define  MAX 50
// 管理队列的结构体
typedef struct SeqQueue
{
	void* data[MAX];
	int front;
	int tail;
}SeqQueue;

// 初始化
void InitSeqQueue(SeqQueue* q);
// 清空
void ClearQ(SeqQueue* q);
// 进队列
void PushQ(SeqQueue* q, void* data);
// 出队列
void PopQ(SeqQueue* q);
// 大小
int SizeQ(SeqQueue* q);
// 获取队头元素值
void* GetHead(SeqQueue* q);