// C program to demonstrate insert
// operation in binary
// search tree.

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

struct tree *minValueNode(struct tree *node)
{
    struct tree *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new root */
struct tree *deleteNode(struct tree *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct tree *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// A utility function to do inorder traversal of BST
void inorder_i(struct tree *root)
{
    if (root != NULL)
    {
        inorder_i(root->left);
        printf("%d ", root->key);
        inorder_i(root->right);
    }
}
void inorder_d(struct tree *root)
{
    if (root != NULL)
    {
        inorder_d(root->right);
        printf("%d ", root->key);
        inorder_d(root->left);
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
struct tree *insert(struct tree *node, int key)
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

// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct tree *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Enter what u want to delete:\n");
    int key;
    scanf("%d", &key);
    root = deleteNode(root, key);
    // Print inorder traversal of the BST
    printf("Inorder increasing\n");
    inorder_i(root);
    printf("\nInorder decreasing\n");
    inorder_d(root);
    printf("\npreorder\n");
    preorder(root);
    printf("\npostorder\n");
    postorder(root);

    return 0;
}