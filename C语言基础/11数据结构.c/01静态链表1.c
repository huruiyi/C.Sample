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

//void ��̬����()
//{
//    linknode * node1 = (linknode *)malloc(sizeof(linknode));
//    node1->name = (char *)malloc(sizeof(char) * 21);
//    strcpy(node1.name, "Ա��A");
//    node1.scoure = 100;
//
//    linknode node2;
//    strcpy(node2.name, "Ա��B");
//    node2.scoure = 101;
//
//    linknode node3;
//    strcpy(node3.name, "Ա��C");
//    node3.scoure = 102;
//
//    linknode node4;
//    strcpy(node4.name, "Ա��D");
//    node4.scoure = 103;
//
//    linknode node5;
//    strcpy(node5.name, "Ա��E");
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
//        printf("������%s,������%d\n", node->name, node->scoure);
//        node = node->next;
//    }
//}
void main01(void)
{
    linknode node1;
    strcpy(node1.name, "Ա��A");
    node1.scoure = 100;

    linknode node2;
    strcpy(node2.name, "Ա��B");
    node2.scoure = 101;

    linknode node3;
    strcpy(node3.name, "Ա��C");
    node3.scoure = 102;

    linknode node4;
    strcpy(node4.name, "Ա��D");
    node4.scoure = 103;

    linknode node5;
    strcpy(node5.name, "Ա��E");
    node5.scoure = 104;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;

    linknode* node = &node1;
    while (node)
    {
        printf("������%s,������%d\n", node->name, node->scoure);
        node = node->next;
    }
    system("pause");
}