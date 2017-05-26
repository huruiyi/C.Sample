#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define  tree 2
// 树节点
typedef struct treeNode
{
    char data;
    struct treeNode *left;
    struct treeNode* right;
}TreeNode;

// 先序遍历
void PreOrder(TreeNode* root)
{
    // 递归结束的条件
    if (root == NULL)
    {
        return;
    }
    // 访问
    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

// 中序
void InOrder(TreeNode* root)
{
    // 递归结束的条件
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    // 访问
    printf("%c ", root->data);
    InOrder(root->right);
}

// 后序
void HouOrder(TreeNode* root)
{
    // 递归结束的条件
    if (root == NULL)
    {
        return;
    }
    HouOrder(root->left);
    HouOrder(root->right);
    // 访问
    printf("%c ", root->data);
}

// 求叶子节点数
int leafCount(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int num = 0;
    // 左子树的叶子数
    num += leafCount(root->left);
    // 右子树的叶子数
    num += leafCount(root->right);
    // 如果是叶子
    if (root->left == NULL && root->right == NULL)
    {
        num++;
    }
    return num;
}

// 求树的高度
int depthTree(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    // 左子树高度
    int left = depthTree(root->left);
    // 右子树高度
    int right = depthTree(root->right);
    // 判断
    int max = left > right ? left : right;
    return max + 1;
}

// 拷贝二叉树
TreeNode* copyTree(TreeNode* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    // 拷贝左子树
    TreeNode* left = copyTree(root->left);
    // 拷贝右子树
    TreeNode* right = copyTree(root->right);
    // 创建节点并初始化
    TreeNode* pNew = (TreeNode*)malloc(sizeof(TreeNode));
    pNew->data = root->data;
    pNew->left = left;
    pNew->right = right;

    return pNew;
}

void TestTree(TreeNode * a)
{
    printf("先序: \n");
    PreOrder(a);
    printf("\n");

    printf("中序: \n");
    InOrder(a);
    printf("\n");

    printf("后序: \n");
    HouOrder(a);
    printf("\n");

    int count = leafCount(a);
    printf(" tree leaf count: %d\n", count);

    int hight = depthTree(a);
    printf(" tree height : %d\n", hight);

    printf(" ======== copy tree ========\n");
    TreeNode* root = copyTree(a);
    printf("先序: \n");
    PreOrder(root);
    printf("\n");

    printf("中序: \n");
    InOrder(root);
    printf("\n");

    printf("后序: \n");
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
    // 创建一棵树
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
    printf("先序: \n");
    PreOrder(&a);
    printf("\n");

    printf("中序: \n");
    InOrder(&a);
    printf("\n");

    printf("后序: \n");
    HouOrder(&a);
    printf("\n");

    int count = leafCount(&a);
    printf(" tree leaf count: %d\n", count);

    int hight = depthTree(&a);
    printf(" tree height : %d\n", hight);

    printf(" ======== copy tree ========\n");
    TreeNode* root = copyTree(&a);
    printf("先序: \n");
    PreOrder(root);
    printf("\n");

    printf("中序: \n");
    InOrder(root);
    printf("\n");

    printf("后序: \n");
    HouOrder(root);
    printf("\n");
#endif // 0

    system("pause");
    return 0;
}