#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char * name;
    int * scoure;
    struct node * next;
} linknode;

int  动态链表2(void)
{
    linknode * node1 = (linknode *)malloc(sizeof(linknode));
    node1->name = (char *)malloc(sizeof(char) * 21);
    node1->scoure = (char *)malloc(sizeof(int) * 2);
    strcpy(node1->name, "员工A");
    node1->scoure[0] = 100;
    node1->scoure[1] = 1000;

    linknode * node2 = (linknode *)malloc(sizeof(linknode));
    node2->name = (char *)malloc(sizeof(char) * 21);
    node2->scoure = (char *)malloc(sizeof(int) * 2);
    strcpy(node2->name, "员工B");
    node2->scoure[0] = 101;
    node2->scoure[1] = 1010;

    linknode * node3 = (linknode *)malloc(sizeof(linknode));
    node3->name = (char *)malloc(sizeof(char) * 21);
    node3->scoure = (char *)malloc(sizeof(int) * 2);
    strcpy(node3->name, "员工C");
    node3->scoure[0] = 102;
    node3->scoure[1] = 1020;

    linknode * node4 = (linknode *)malloc(sizeof(linknode));
    node4->name = (char *)malloc(sizeof(char) * 21);
    node4->scoure = (char *)malloc(sizeof(int) * 2);
    strcpy(node4->name, "员工D");
    node4->scoure[0] = 103;
    node4->scoure[1] = 1030;

    linknode * node5 = (linknode *)malloc(sizeof(linknode));
    node5->name = (char *)malloc(sizeof(char) * 21);
    node5->scoure = (char *)malloc(sizeof(int) * 2);
    strcpy(node5->name, "员工E");
    node5->scoure[0] = 104;
    node5->scoure[1] = 1040;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    linknode* node = node1;
    while (node)
    {
        printf("姓名：%s[%p],分数：%d[%p]\n", node->name, node->name, node->scoure, &node->scoure);
        node = node->next;
    }

    node = node1;
    while (node)
    {
        free(node->name);
        free(node->scoure);
        node = node->next;
    }

    node = node1;
    while (node)
    {
        linknode* xnode = node->next;
        free(node);
        printf("释放........00\n");
        node = xnode;
    }

    system("pause");
}