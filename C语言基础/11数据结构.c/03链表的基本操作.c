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
        printf("请输入数字：");
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
    printf("打印数据\n");

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
            //找到值，插入要插入的值
            current->next = insertNode;
            insertNode->next = next;
            printf("插入成功\n");
            return;
        }
        current = current->next;
        if (current != NULL)
        {
            next = current->next;
            if (next == NULL)
            {
                //没找到值，把值插入到链表结尾
                current->next = insertNode;
                insertNode->next = next;
                printf("插入成功\n");
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
        printf("未找到删除的数据\n");
        return;
    }

    //如果找到数据
    prev->next = current->next;
    //销毁
    free(current);
    printf("删除节点成功\n");
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
    printf("销毁成功\n");
}
void main03()
{
    /*
    1：链表初始化
    2：链表遍历数据
    3：链表插入数据
    4：插标删除数据
    5：链表销毁
    */
    node *nodehead = NULL;
    //1：链表初始化

    nodehead = CreateLinkNode();

    //2：链表遍历数据
    ForeachLinkNode(nodehead);

    //3：链表插入数据
    while (1)
    {
        int insertPlace = 0;
        int insertVal = 0;
        printf("\n请输入要插入的位置：");
        scanf("%d", &insertPlace);
        if (insertPlace == -2)
        {
            break;
        }
        printf("\n请输入要插入的值：");
        scanf("%d", &insertVal);
        InsertNode(nodehead, insertPlace, insertVal);
        //2：链表遍历数据
        ForeachLinkNode(nodehead);
    }

    // 4：插标删除数据
    while (1)
    {
        int deleteVal;
        printf("\n请输入要删除的值：");
        scanf("%d", &deleteVal);
        if (deleteVal == -1)
        {
            break;
        }
        DeleteNode(nodehead, deleteVal);
        //2：链表遍历数据
        ForeachLinkNode(nodehead);
    }

    //5：链表销毁
    FreeSpace(nodehead);
    nodehead = NULL;
    system("pause");
};