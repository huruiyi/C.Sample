#ifndef _LINK_LIST_H
#define _LINK_LIST_H

// ����Ľڵ�ṹ
typedef struct Node
{
	void* data;	// �洢��ַ
	struct Node* next;
}Node;

// ��������Ľṹ��
typedef struct LinkList
{
	// ����ͷ���
	Node header;
	int size;
}LinkList;

// �����ӿ�����
// ��ʼ��
LinkList* Init_LinkList();
// ����
void Insert_LinkList(LinkList* list, int pos, void* data);
// ɾ�� - ɾ��ָ��λ�õĽڵ�
void Delete_LinkList(LinkList* list, int pos);
// ɾ�� - ����ֵɾ���ڵ�, ��ҵ, �Լ�ʵ��
//void Del_Data_LinkList(LinkList* list, void* data){};
// ����
void Foreach_LinkList(LinkList* list, void(*print)(void*));
// ������� -- ��ҵ, �Լ�ʵ��
// --	 �ص�, �ݹ�
// ���� - �ص�
// -- �Ƚ�data�͸���Ԫ���Ƿ���� 
// compare �û���д �ıȽϹ���
// ����ֵΪ1, ƥ��ɹ�, 0: û��ƥ�䵽
void* Search_LinkList(LinkList* list, void* data, int(*compare)(void*, void*));
// ����
void Destroy_LinkList(LinkList* list);


#endif // _LINK_LIST_H