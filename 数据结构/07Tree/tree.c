#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  tree 2
// ���ڵ�
typedef struct treeNode
{
    char data;
    struct treeNode *left;
    struct treeNode* right;
}TreeNode;

// �������
void PreOrder(TreeNode* root)
{
    // �ݹ����������
    if (root == NULL)
    {
        return;
    }
    // ����
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// ����
void InOrder(TreeNode* root)
{
    // �ݹ����������
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    // ����
    printf("%c ", root->data);
    InOrder(root->right);
}

// ����
void HouOrder(TreeNode* root)
{
    // �ݹ����������
    if (root == NULL)
    {
        return;
    }
    HouOrder(root->left);
    HouOrder(root->right);
    // ����
    printf("%c ", root->data);
}

// ��Ҷ�ӽڵ���
int leafCount(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int num = 0;
    // ��������Ҷ����
    num += leafCount(root->left);
    // ��������Ҷ����
    num += leafCount(root->right);
    // �����Ҷ��
    if (root->left == NULL && root->right == NULL)
    {
        num++;
    }
    return num;
}

// �����ĸ߶�
int depthTree(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    // �������߶�
    int left = depthTree(root->left);
    // �������߶�
    int right = depthTree(root->right);
    // �ж�
    int max = left > right ? left : right;
    return max + 1;
}

// ����������
TreeNode* copyTree(TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // ����������
    TreeNode* left = copyTree(root->left);
    // ����������
    TreeNode* right = copyTree(root->right);
    // �����ڵ㲢��ʼ��
    TreeNode* pNew = (TreeNode*)malloc(sizeof(TreeNode));
    pNew->data = root->data;
    pNew->left = left;
    pNew->right = right;

    return pNew;
}

void TestTree(TreeNode * a)
{
    printf("����: \n");
    PreOrder(a);
    printf("\n");

    printf("����: \n");
    InOrder(a);
    printf("\n");

    printf("����: \n");
    HouOrder(a);
    printf("\n");

    int count = leafCount(a);
    printf(" tree leaf count: %d\n", count);

    int hight = depthTree(a);
    printf(" tree height : %d\n", hight);

    printf(" ======== copy tree ========\n");
    TreeNode* root = copyTree(a);
    printf("����: \n");
    PreOrder(root);
    printf("\n");

    printf("����: \n");
    InOrder(root);
    printf("\n");

    printf("����: \n");
    HouOrder(root);
    printf("\n");
}

void Test1()
{
    TreeNode a, b, c, d, e, f, g, h;
    memset(&a, 0, sizeof(TreeNode));
    memset(&b, 0, sizeof(TreeNode));
    memset(&c, 0, sizeof(TreeNode));
    memset(&d, 0, sizeof(TreeNode));
    memset(&e, 0, sizeof(TreeNode));
    memset(&f, 0, sizeof(TreeNode));
    memset(&g, 0, sizeof(TreeNode));
    memset(&h, 0, sizeof(TreeNode));

    a.data = 'a';
    b.data = 'b';
    c.data = 'c';
    d.data = 'd';
    e.data = 'e';
    f.data = 'f';
    g.data = 'g';
    h.data = 'h';

    a.left = &b;
    a.right = &c;

    b.left = &d;

    c.right = &e;

    d.right = &f;

    e.left = &g;

    f.right = &h;

    TestTree(&a);

    system("pause");
}

void Test2()
{
    TreeNode a, b, c, d, e, f, g, h;
    memset(&a, 0, sizeof(TreeNode));
    memset(&b, 0, sizeof(TreeNode));
    memset(&c, 0, sizeof(TreeNode));
    memset(&d, 0, sizeof(TreeNode));
    memset(&e, 0, sizeof(TreeNode));
    memset(&f, 0, sizeof(TreeNode));
    memset(&g, 0, sizeof(TreeNode));
    memset(&h, 0, sizeof(TreeNode));

    a.data = 'a';
    b.data = 'b';
    c.data = 'c';
    d.data = 'd';
    e.data = 'e';
    f.data = 'f';
    g.data = 'g';
    h.data = 'h';

    a.left = &b;
    a.right = &f;

    b.right = &c;

    c.left = &d;
    c.right = &e;

    f.right = &g;

    g.left = &h;

    TestTree(&a);

    system("pause");
}

void main()
{
    // ����һ����
    TreeNode a, b, c, d, e, f, g;
    memset(&a, 0, sizeof(TreeNode));
    memset(&b, 0, sizeof(TreeNode));
    memset(&c, 0, sizeof(TreeNode));
    memset(&d, 0, sizeof(TreeNode));
    memset(&e, 0, sizeof(TreeNode));
    memset(&f, 0, sizeof(TreeNode));
    memset(&g, 0, sizeof(TreeNode));

    a.data = 'a';
    a.left = &b;
    a.right = &c;

    b.data = 'b';
    b.left = &d;
    b.right = &e;

    c.data = 'c';
    c.left = &f;
    c.right = &g;

    d.data = 'd';
    e.data = 'e';
    f.data = 'f';
    g.data = 'g';

#if 1
    printf("����: \n");
    PreOrder(&a);
    printf("\n");

    printf("����: \n");
    InOrder(&a);
    printf("\n");

    printf("����: \n");
    HouOrder(&a);
    printf("\n");

    int count = leafCount(&a);
    printf(" tree leaf count: %d\n", count);

    int hight = depthTree(&a);
    printf(" tree height : %d\n", hight);

    printf(" ======== copy tree ========\n");
    TreeNode* root = copyTree(&a);
    printf("����: \n");
    PreOrder(root);
    printf("\n");

    printf("����: \n");
    InOrder(root);
    printf("\n");

    printf("����: \n");
    HouOrder(root);
    printf("\n");
#endif // 0

    system("pause");
    return 0;
}