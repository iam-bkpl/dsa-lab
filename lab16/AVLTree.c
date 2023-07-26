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
int height(Node *node)
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
Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Right Rotate
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

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
Node *leftRotate(Node *x)
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
Node *insertNode(Node *node, int data)
{
    // Find the correct position to insert the node
    if (node == NULL)
    {
        return (newNode(data));
    }
    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        return (node);
    }
    // updating the balance factor of each node and also balance the tree

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }
    if (balance < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// deleting node
Node *deleteNode(Node *root, int data)
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

    int option = -1;
    int data = -1;

    while (option != 4)
    {
        printf("Enter the option below \n 1. Insert the new data \n 2. Delete a data \n 3. Print the list \n 4. Exit the program \n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter data to insert \n");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;
        case 2:
            printf("Enter data to delete \n");
            scanf("%d", &data);
            root = deleteNode(root, data);
            break;
        case 3:
            printPreOrder(root);
            break;
        default:
            break;
        }
    }
    return 0;
}