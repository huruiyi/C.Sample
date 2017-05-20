#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode
{
    int data;
    struct  LinkNode *next;
} node;
node * CreateLinkNode()
{
    node *nodehead = (node *)malloc(sizeof(node));
    if (nodehead == NULL)
    {
        return NULL;
    }
    nodehead->data = -1;
    nodehead->next;

    node *currentNode = nodehead;
    int inputData = 0;
    while (1)
    {
        printf("���������֣�");
        scanf("%d", &inputData);

        if (inputData == -1)
        {
            break;
        }
        node *newnode = (node *)malloc(sizeof(node));

        newnode->data = inputData;
        newnode->next = NULL;

        currentNode->next = newnode;
        currentNode = newnode;
    }

    return nodehead;
}
void ForeachLinkNode(node *head)
{
    printf("��ӡ����\n");

    node *node = head->next;
    while (node != NULL)
    {
        printf("%d\t", node->data);
        node = node->next;
    }
}
void  InsertNode(node *head, int placeVal, int insertVal)
{
    if (head == NULL)
    {
        return;
    }
    node *current = head;
    node *next = current->next;

    node *insertNode = (node *)malloc(sizeof(node));
    insertNode->data = insertVal;
    insertNode->next = NULL;

    while (current != NULL)
    {
        if (current->data == placeVal)
        {
            //�ҵ�ֵ������Ҫ�����ֵ
            current->next = insertNode;
            insertNode->next = next;
            printf("����ɹ�\n");
            return;
        }
        current = current->next;
        if (current != NULL)
        {
            next = current->next;
            if (next == NULL)
            {
                //û�ҵ�ֵ����ֵ���뵽�����β
                current->next = insertNode;
                insertNode->next = next;
                printf("����ɹ�\n");
                return;
            }
        }
    }
}
void DeleteNode(node *head, int deleteVal)
{
    if (head == NULL)
    {
        return;
    }
    node * prev = head;
    node * current = head->next;
    while (current != NULL)
    {
        if (current->data == deleteVal)
        {
            break;
        }
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        printf("δ�ҵ�ɾ��������\n");
        return;
    }

    //����ҵ�����
    prev->next = current->next;
    //����
    free(current);
    printf("ɾ���ڵ�ɹ�\n");
}
void FreeSpace(node *head)
{
    node * current = head;
    while (current != NULL)
    {
        node * next = current->next;
        free(current);
        current = next;
    }
    if (current != NULL)
    {
        free(current);
        current = NULL;
    }
    printf("���ٳɹ�\n");
}
void main03()
{
    /*
    1�������ʼ��
    2�������������
    3�������������
    4�����ɾ������
    5����������
    */
    node *nodehead = NULL;
    //1�������ʼ��

    nodehead = CreateLinkNode();

    //2�������������
    ForeachLinkNode(nodehead);

    //3�������������
    while (1)
    {
        int insertPlace = 0;
        int insertVal = 0;
        printf("\n������Ҫ�����λ�ã�");
        scanf("%d", &insertPlace);
        if (insertPlace == -2)
        {
            break;
        }
        printf("\n������Ҫ�����ֵ��");
        scanf("%d", &insertVal);
        InsertNode(nodehead, insertPlace, insertVal);
        //2�������������
        ForeachLinkNode(nodehead);
    }

    // 4�����ɾ������
    while (1)
    {
        int deleteVal;
        printf("\n������Ҫɾ����ֵ��");
        scanf("%d", &deleteVal);
        if (deleteVal == -1)
        {
            break;
        }
        DeleteNode(nodehead, deleteVal);
        //2�������������
        ForeachLinkNode(nodehead);
    }

    //5����������
    FreeSpace(nodehead);
    nodehead = NULL;
    system("pause");
};