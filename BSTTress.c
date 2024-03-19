#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    char name[50];
    char phone[15];
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(char name[], char phone[]) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, char name[], char phone[]) {
    if (root == NULL)
        return createNode(name, phone);

    if (strcmp(name, root->name) < 0)
        root->left = insertNode(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = insertNode(root->right, name, phone);

    return root;
}

struct TreeNode* searchNode(struct TreeNode* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return searchNode(root->left, name);
    
    return searchNode(root->right, name);
}

struct TreeNode* minValueNode(struct TreeNode* node) {
    struct TreeNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct TreeNode* deleteNode(struct TreeNode* root, char name[]) {
    if (root == NULL)
        return root;

    if (strcmp(name, root->name) < 0)
        root->left = deleteNode(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = deleteNode(root->right, name);
    else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = minValueNode(root->right);

        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);

        root->right = deleteNode(root->right, temp->name);
    }
    return root;
}

void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%s: %s\n", root->name, root->phone);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int choice;
    char name[50], phone[15];

    do {
        printf("\nPhone List Menu:\n");
        printf("1. Search for a name\n");
        printf("2. Insert a new name\n");
        printf("3. Delete an existing name\n");
        printf("4. Print the entire phone list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter name to search: ");
                scanf("%s", name);
                struct TreeNode* result = searchNode(root, name);
                if (result != NULL)
                    printf("Phone number: %s\n", result->phone);
                else
                    printf("Name not found\n");
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                root = insertNode(root, name, phone);
                printf("Name added successfully\n");
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                struct TreeNode* toDelete = searchNode(root, name);
                if (toDelete != NULL) {
                    root = deleteNode(root, name);
                    printf("Name deleted successfully\n");
                } else {
                    printf("Name not found\n");
                }
                break;
            case 4:
                printf("Phone List:\n");
                inOrderTraversal(root);
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 5);

    // Free allocated memory before exiting
    free(root);

    return 0;
}
