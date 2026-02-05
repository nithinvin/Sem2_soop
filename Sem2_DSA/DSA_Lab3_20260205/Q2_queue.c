#include <stdio.h>

#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void enqueue() {
    int item;

    if (rear == QUEUE_SIZE - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = item;

    printf("Inserted %d into the queue.\n", item);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
