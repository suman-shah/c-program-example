#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct BT_Node
{
    DataType val;
    struct BT_Node *left, *right;
} BT_Node;

typedef struct BT
{
    BT_Node *root;
} BT;

// Initalize a binary tree node and return a pointer to it
BT_Node *BT_Node_init(DataType val)
{
    BT_Node *n = malloc(sizeof(BT_Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

// Create a binary tree and return it
// arr is n x 3, where for the ith node
// arr[i][0] is parent, arr[i][1] is left/right, arr[i][2] is value
BT *create_BT(int **arr, int n)
{
    BT *b = (BT *)malloc(sizeof(BT));
    BT_Node *nodes[n];
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = BT_Node_init(arr[i][2]);
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr[i][0] == -1)
        {
            b->root = nodes[i];
        }
        else
        {
            if (arr[i][1] == 0)
            {
                nodes[arr[i][0]]->left = nodes[i];
            }
            else
            {
                nodes[arr[i][0]]->right = nodes[i];
            }
        }
    }
    return b;
}

void delete_BT(BT_Node *curr)
{
    if (curr == NULL)
    {
        return;
    }
    delete_BT(curr->left);
    delete_BT(curr->right);
    free(curr);
}

void inorder(BT_Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(BT_Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BT_Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}

// Taking input in specified format and creating a binary tree
int main()
{
    int n;
    scanf("%d", &n);
    int **arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
    {
        arr[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < n; ++i)
    {
        int p, c, val;
        scanf("%d %d %d", &p, &c, &val);
        arr[i][0] = p;
        arr[i][1] = c;
        arr[i][2] = val;
    }
    BT *b = create_BT(arr, n);
    // inorder(b->root);
    printf("\n");
    // preorder(b->root);
    printf("\n");
    postorder(b->root);
    printf("\n");
    // delete_BT(b->root);
    // free(b);
}
