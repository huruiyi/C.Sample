#ifndef _LINKLIST_H
#define _LINKLIST_H

// ����ڵ�ṹ��
typedef struct Node
{
	struct Node* next;
}Node;

// ��������Ľṹ��
typedef struct LinkList
{
	// �����ͷ���
	Node header;
	int size;
}LinkList;

// ��ʼ��LinkList
LinkList* InitLinkList();
// ����
void InsertLinkList(LinkList* list, int pos, Node *node);
// ɾ��
void DeleteLinkList(LinkList* list, int pos);
// ����
void Foreacher(LinkList* list, void(*print)(void*));
// ����
void DestroyLinkList(LinkList* list);

#endif // _LINKLIST_H
