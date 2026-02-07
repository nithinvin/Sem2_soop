#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Function Prototypes */
void insertAtNth(int pos, int val);
void deleteNode(int val);
void search(int val);
void sortList();
void reverseList();
void removeDuplicates();
void getNthNode(int pos);
void display();

/* Main Menu */
int main() {
    int choice, val, pos;

    while (1) {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at Nth position\n");
        printf("2. Delete a node\n");
        printf("3. Search an element\n");
        printf("4. Sort the list (No Swapping)\n");
        printf("5. Reverse the list (No Swapping)\n");
        printf("6. Remove duplicates\n");
        printf("7. Get Nth node\n");
        printf("8. Display list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter position and value: ");
            scanf("%d %d", &pos, &val);
            insertAtNth(pos, val);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteNode(val);
            break;

        case 3:
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(val);
            break;

        case 4:
            sortList();
            break;

        case 5:
            reverseList();
            break;

        case 6:
            removeDuplicates();
            break;

        case 7:
            printf("Enter position: ");
            scanf("%d", &pos);
            getNthNode(pos);
            break;

        case 8:
            display();
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

/* Insert at Nth Position */
void insertAtNth(int pos, int val) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete Node by Value */
void deleteNode(int val) {
    struct node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

/* Search */
void search(int val) {
    struct node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == val) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found\n");
}

/* Sort List (No Swapping Data) */
void sortList() {
    struct node *sorted = NULL;
    struct node *curr = head;

    while (curr != NULL) {
        struct node *next = curr->next;

        /* Insert curr into sorted list */
        if (sorted == NULL || curr->data < sorted->data) {
            curr->next = sorted;
            sorted = curr;
        } else {
            struct node *temp = sorted;
            while (temp->next != NULL && temp->next->data < curr->data)
                temp = temp->next;

            curr->next = temp->next;
            temp->next = curr;
        }

        curr = next;
    }

    head = sorted;
    printf("List sorted successfully\n");
}

/* Reverse List (Change Links Only) */
void reverseList() {
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed\n");
}

/* Remove Duplicates */
void removeDuplicates() {
    struct node *curr = head, *temp, *prev;

    while (curr != NULL) {
        prev = curr;
        temp = curr->next;

        while (temp != NULL) {
            if (temp->data == curr->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    printf("Duplicates removed\n");
}

/* Get Nth Node */
void getNthNode(int pos) {
    struct node *temp = head;

    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        printf("Invalid position\n");
    else
        printf("Node at position %d is %d\n", pos, temp->data);
}

/* Display */
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
