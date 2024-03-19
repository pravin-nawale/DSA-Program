#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findHeight(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if(leftHeight>rightHeight)
       return 1 + leftHeight;
       else
       return 1 + rightHeight;
}


void printLeafNodes(struct Node* root) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        printf("%d ", root->data);

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}


struct Node* mirrorTree(struct Node* root) {
    if (root == NULL)
        return NULL;

   
    struct Node* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);

    return root;
}


void printLevelOrder(struct Node* root, int level) {
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}


int findTreeHeight(struct Node* root) {
    int height = findHeight(root);
    return height;
}


void levelOrderPrint(struct Node* root) {
    int height = findTreeHeight(root);
    for (int i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        printLevelOrder(root, i);
        printf("\n");
    }
}

int main() {
    
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Original Tree (Level-wise): ");
    levelOrderPrint(root);
    printf("\n");

   
    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    printf("Leaf Nodes: ");
    printLeafNodes(root);
    printf("\n");

   
    struct Node* mirrorRoot = mirrorTree(root);
    printf("Mirror Image (Level-wise): ");
    levelOrderPrint(mirrorRoot);
    printf("\n");

    return 0;
}