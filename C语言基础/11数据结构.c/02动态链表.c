#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char * name;
    int scoure;
    struct node * next;
} linknode;

int main021(void)
{
    linknode * node1 = (linknode *)malloc(sizeof(linknode));
    node1->name = (char *)malloc(sizeof(char) * 21);
    strcpy(node1->name, "Ա��A");
    node1->scoure = 100;

    linknode * node2 = (linknode *)malloc(sizeof(linknode));
    node2->name = (char *)malloc(sizeof(char) * 21);
    strcpy(node2->name, "Ա��B");
    node2->scoure = 101;

    linknode * node3 = (linknode *)malloc(sizeof(linknode));
    node3->name = (char *)malloc(sizeof(char) * 21);
    strcpy(node3->name, "Ա��C");
    node3->scoure = 102;

    linknode * node4 = (linknode *)malloc(sizeof(linknode));
    node4->name = (char *)malloc(sizeof(char) * 21);
    strcpy(node4->name, "Ա��D");
    node4->scoure = 103;

    linknode * node5 = (linknode *)malloc(sizeof(linknode));
    node5->name = (char *)malloc(sizeof(char) * 21);
    strcpy(node5->name, "Ա��E");
    node5->scoure = 104;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    linknode* node = node1;
    while (node)
    {
        printf("������%s[%p],������%d[%p]\n", node->name, node->name, node->scoure, &node->scoure);
        node = node->next;
    }

    node = node1;
    while (node)
    {
        free(node->name);
        node = node->next;
    }

    node = node1;
    while (node)
    {
        linknode* xnode = node->next;
        printf("%d���ͷ�\n", node->scoure);
        free(node);
        node = xnode;
    }

    system("pause");
}