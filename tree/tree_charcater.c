#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int key;
    struct tree *left, *right;
};

// A utility function to create a new BST node
struct tree *newNode(int item)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->key);
        inorder(root->right);
    }
}
void preorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        postorder(root->right);
        postorder(root->left);
    }
}

// A utility function to insert
// a new node with given key in BST
struct tree *insert(struct tree *node, char key)
{
    // If the tree is empty, return a new node
    if (node == NULL)
        return newNode(key);

    // Otherwise, recur down the tree
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    // Return the (unchanged) node pointer
    return node;
}
void random(FILE *fp, int n)
{
    int r;
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        r = rand() % (91 - 65) + 65;
        fprintf(fp, "%c ", r);
    }
    rewind(fp);
}
int main()
{
    int n;
    struct tree *root = NULL;
    FILE *fp = fopen("random.txt", "w+");
    printf("Enter how many random numbers:\n");
    scanf("%d", &n);
    random(fp, n);
    for (int i = 0; i < n; i++)
    {
        char key;
        fscanf(fp, "%c", &key);
        if (root == NULL)
        {
            root = insert(root, key);
        }
        insert(root, key);
    }
    inorder(root);
    return 0;
}
