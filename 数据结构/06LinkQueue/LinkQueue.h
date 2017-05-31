#pragma once

// ����ڵ�Ľṹ��
typedef struct Node
{
	struct Node* next;
}Node;

// ������еĽṹ��
// - �ڵ�ĸ���
// - ָ���һ���ڵ��ָ��
// - ָ�����һ���ڵ��ָ��

typedef struct LinkQueue
{
	int size;
	Node* front;	
	Node* tail;
}LinkQueue;

// ��ʼ��
void InitSeqQueue(LinkQueue* q);
// ���
void ClearQ(LinkQueue* q);
// ������
void PushQ(LinkQueue* q, void* data);
// ������
void PopQ(LinkQueue* q);
// ��С
int SizeQ(LinkQueue* q);
// ��ȡ��ͷԪ��ֵ
void* GetHead(LinkQueue* q);
