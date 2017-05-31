#ifndef _LINKLIST_H
#define _LINKLIST_H

// 链表节点结构体
typedef struct Node
{
	struct Node* next;
}Node;

// 管理链表的结构体
typedef struct LinkList
{
	// 链表的头结点
	Node header;
	int size;
}LinkList;

// 初始化LinkList
LinkList* InitLinkList();
// 插入
void InsertLinkList(LinkList* list, int pos, Node *node);
// 删除
void DeleteLinkList(LinkList* list, int pos);
// 遍历
void Foreacher(LinkList* list, void(*print)(void*));
// 销毁
void DestroyLinkList(LinkList* list);

#endif // _LINKLIST_H
