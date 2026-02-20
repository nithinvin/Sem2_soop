// 232. Implement Queue using Stacks
// Implement a FIFO queue using only two stacks.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int s1[MAX_SIZE]; // input stack
    int s2[MAX_SIZE]; // output stack
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->top1 = -1;
    q->top2 = -1;
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

// Move all elements from s1 to s2 (reverses order for FIFO)
static void transfer(MyQueue* obj) {
    if (obj->top2 == -1) {
        while (obj->top1 != -1) {
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
}

int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

int main() {
    MyQueue* q = myQueueCreate();

    myQueuePush(q, 1);
    myQueuePush(q, 2);
    printf("peek: %d\n", myQueuePeek(q));   // 1
    printf("pop:  %d\n", myQueuePop(q));     // 1
    printf("empty: %s\n", myQueueEmpty(q) ? "true" : "false"); // false

    myQueueFree(q);
    return 0;
}
