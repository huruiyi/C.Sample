#pragma  once
#define  MAX 50
// ������еĽṹ��
typedef struct SeqQueue
{
	void* data[MAX];
	int front;
	int tail;
}SeqQueue;

// ��ʼ��
void InitSeqQueue(SeqQueue* q);
// ���
void ClearQ(SeqQueue* q);
// ������
void PushQ(SeqQueue* q, void* data);
// ������
void PopQ(SeqQueue* q);
// ��С
int SizeQ(SeqQueue* q);
// ��ȡ��ͷԪ��ֵ
void* GetHead(SeqQueue* q);