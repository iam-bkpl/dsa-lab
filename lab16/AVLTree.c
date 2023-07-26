#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct Node
{
    struct Node *left;
    int data;
    struct Node *right;
    int height;
};
typedef struct Node Node;

// calculating height
int height(struct Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Creating Node
struct Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Right Rotate
struct Node *rightRotate(Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Left Rotate
struct Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balancing factor
int getBalance(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

// Insertion
struct Node *insertNode(Node *root, int data)
{
    // Find the correct position to insert the node
    if (root == NULL)
    {
        return (newNode(data));
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        return (root);
    }
    // updating the balance factor of each node and also balance the tree

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    if (balance > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

struct Node *minValueNode(Node *root)
{
    Node *node = root;
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

// deleting node
struct Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp->left == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printPreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d \n", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int main()
{
    Node *root = NULL;
    root = insertNode(root, 2);
    root = insertNode(root, 1);
    root = insertNode(root, 7);
    root = insertNode(root, 4);
    root = insertNode(root, 5);
    root = insertNode(root, 3);
    root = insertNode(root, 8);

    printPreOrder(root);

    // root = deleteNode(root, 2);

    // printf("\n After deleting : \n");
    // printPreOrder(root);

    return 0;
}