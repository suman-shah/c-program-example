#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <limits.h>

// #define COUNT 10
typedef long long int ll;

struct BinaryTree
{
    struct BinaryTree *left;
    struct BinaryTree *right;
    int e;
};

typedef struct BinaryTree bstnode;
typedef struct BinaryTree *Bstnode;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a <= b) ? a : b;
}

Bstnode createNode(int e)
{
    Bstnode temp = (Bstnode)malloc(sizeof(bstnode));
    temp->left = NULL;
    temp->right = NULL;
    temp->e = e;
    return temp;
}

/* ---------- DEQUE IMPLEMENTATION STARTS ---------- */

typedef struct node queuenode;
struct node
{
    Bstnode var;
    struct node *prev;
    struct node *next;
};

typedef struct Queue
{
    int size;
    queuenode *front;
    queuenode *back;
} Queue;

queuenode *InitializeNode(Bstnode T)
{
    queuenode *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->var = T;
    return temp;
}

Queue *InitializeQueue()
{
    Queue *temp = malloc(sizeof(Queue));
    temp->size = 0;
    temp->front = NULL;
    temp->back = NULL;
    return temp;
}

Bstnode Front(Queue *temp) // RETURNS THE FRONT ELEMENT OF THE LIST
{
    return (temp->front->var);
}

int isEmpty(Queue *temp) // CHECKS IF LIST IS EMPTY OR NOT
{
    if (temp->size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *temp, Bstnode d) // ADDS ELEMENT AT THE END OF THE LIST ~ push.back()
{
    queuenode *node = InitializeNode(d);
    if (isEmpty(temp))
    {
        temp->front = node;
        temp->back = node;
    }
    else
    {
        temp->back->next = node;
        node->prev = temp->back;
        temp->back = node;
    }
    temp->size += 1;
}

void dequeue(Queue *temp) // DELETES ELEMENT AT THE FRONT OF THE LIST ~ pop.front()
{
    queuenode *toremove, *newhead;
    toremove = temp->front;
    newhead = temp->front->next;
    if (newhead == NULL)
    {
        temp->back = NULL;
    }
    temp->front = newhead;
    // info deleted = toremove->data;
    free(toremove);
    toremove = NULL;
    temp->size -= 1;
    // return deleted;
}

/* ---------- DEQUE IMPLEMENTATION ENDS ---------- */

Bstnode deleteLeaves(Bstnode root)
{
    if (root == NULL)
        return NULL;
    root->left = deleteLeaves(root->left);
    root->right = deleteLeaves(root->right);

    if (root->e == 0 && root->left == NULL && root->right == NULL)
    {

        return NULL;
    }
    return root;
}

int subTreeSum(Bstnode curNode)
{
    if (curNode == NULL)
    {
        return 0;
    }
    int curSum = curNode->e + subTreeSum(curNode->left) + subTreeSum(curNode->right);
    return curSum;
}

int isBST(Bstnode curNode, int low, int high)
{
    if (curNode == NULL)
    {
        return 1;
    }
    if (curNode->e < low || curNode->e > high)
    {
        return 0;
    }
    return (isBST(curNode->left, low, curNode->e - 1) && isBST(curNode->right, curNode->e + 1, high));
}

int isBSTdec(Bstnode curNode, int low, int high)
{
    if (curNode == NULL)
    {
        return 1;
    }
    if (curNode->e > low || curNode->e < high)
    {
        return 0;
    }
    return (isBSTdec(curNode->left, low, curNode->e + 1) && isBSTdec(curNode->right, curNode->e - 1, high));
}

int solve(Bstnode curNode, int *ans)
{
    if (isBST(curNode, INT_MIN, INT_MAX))
    {
        int minSum = subTreeSum(curNode);
        *ans = min(*ans, minSum);
    }
    if (curNode->left != NULL)
    {
        solve(curNode->left, ans);
    }
    if (curNode->right != NULL)
    {
        solve(curNode->right, ans);
    }
    return 0;
}

int solve2(Bstnode curNode, int *ans)
{
    if (isBSTdec(curNode, INT_MAX, INT_MIN))
    {
        int minSum = subTreeSum(curNode);
        *ans = min(*ans, minSum);
    }
    if (curNode->left != NULL)
    {
        solve2(curNode->left, ans);
    }
    if (curNode->right != NULL)
    {
        solve2(curNode->right, ans);
    }
    return 0;
}

int minimumSumBST(Bstnode root)
{
    int var1 = 999999;
    int var2 = 999999;
    int temp1 = solve(root, &var1);
    int temp2 = solve2(root, &var2);
    int var = min(var1, var2);
    return var;
}

void deleteTree(Bstnode node)
{
    if (node == NULL)
        return;
    deleteTree(node->left);
    deleteTree(node->right);
    free(node);
}

int main()
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll A[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &A[i]);
        }
        if (n == 1)
        {
            printf("%lld\n", A[0]);
            continue;
        }
        Queue *q = InitializeQueue();
        Bstnode root = createNode(A[0]);
        enqueue(q, root);
        for (int i = 1; i < n; i++)
        {

            if (Front(q)->e == 0)
            {
                dequeue(q);
            }

            if (Front(q)->e != 0)
            {
                if (Front(q)->left == NULL)
                {
                    Front(q)->left = createNode(A[i]);
                    enqueue(q, Front(q)->left);
                }
                else
                {
                    Front(q)->right = createNode(A[i]);
                    enqueue(q, Front(q)->right);
                }
            }

            if (Front(q)->left != NULL && Front(q)->right != NULL)
            {
                dequeue(q);
                // continue;
            }
        }
        deleteLeaves(root);
        printf("%d\n", minimumSumBST(root));
        deleteTree(root);
    }
    return 0;
}
