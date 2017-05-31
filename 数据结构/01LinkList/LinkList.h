#ifndef _LINK_LIST_H
#define _LINK_LIST_H

// 链表的节点结构
typedef struct Node
{
	void* data;	// 存储地址
	struct Node* next;
}Node;

// 管理链表的结构体
typedef struct LinkList
{
	// 链表头结点
	Node header;
	int size;
}LinkList;

// 函数接口声明
// 初始化
LinkList* Init_LinkList();
// 插入
void Insert_LinkList(LinkList* list, int pos, void* data);
// 删除 - 删除指定位置的节点
void Delete_LinkList(LinkList* list, int pos);
// 删除 - 根据值删除节点, 作业, 自己实现
//void Del_Data_LinkList(LinkList* list, void* data){};
// 遍历
void Foreach_LinkList(LinkList* list, void(*print)(void*));
// 逆序遍历 -- 作业, 自己实现
// --	 回调, 递归
// 查找 - 回调
// -- 比较data和各个元素是否相等 
// compare 用户编写 的比较规则
// 返回值为1, 匹配成功, 0: 没有匹配到
void* Search_LinkList(LinkList* list, void* data, int(*compare)(void*, void*));
// 销毁
void Destroy_LinkList(LinkList* list);


#endif // _LINK_LIST_H