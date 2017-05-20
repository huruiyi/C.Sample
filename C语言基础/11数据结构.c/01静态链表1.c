#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[21];
    int scoure;
    struct node * next;
} linknode;

//void 动态链表()
//{
//    linknode * node1 = (linknode *)malloc(sizeof(linknode));
//    node1->name = (char *)malloc(sizeof(char) * 21);
//    strcpy(node1.name, "员工A");
//    node1.scoure = 100;
//
//    linknode node2;
//    strcpy(node2.name, "员工B");
//    node2.scoure = 101;
//
//    linknode node3;
//    strcpy(node3.name, "员工C");
//    node3.scoure = 102;
//
//    linknode node4;
//    strcpy(node4.name, "员工D");
//    node4.scoure = 103;
//
//    linknode node5;
//    strcpy(node5.name, "员工E");
//    node5.scoure = 104;
//
//    node1.next = &node2;
//    node2.next = &node3;
//    node3.next = &node4;
//    node4.next = &node5;
//    node5.next = NULL;
//
//    linknode* node = &node1;
//    while (node->next)
//    {
//        printf("姓名：%s,分数：%d\n", node->name, node->scoure);
//        node = node->next;
//    }
//}
void main01(void)
{
    linknode node1;
    strcpy(node1.name, "员工A");
    node1.scoure = 100;

    linknode node2;
    strcpy(node2.name, "员工B");
    node2.scoure = 101;

    linknode node3;
    strcpy(node3.name, "员工C");
    node3.scoure = 102;

    linknode node4;
    strcpy(node4.name, "员工D");
    node4.scoure = 103;

    linknode node5;
    strcpy(node5.name, "员工E");
    node5.scoure = 104;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    linknode* node = &node1;
    while (node)
    {
        printf("姓名：%s,分数：%d\n", node->name, node->scoure);
        node = node->next;
    }
    system("pause");
}