/*
 * LeetCode 225 - Implement Stack using Queues
 *
 * Implement a LIFO stack using only two queues.
 * Push is O(n): enqueue to empty queue, then move all elements from other queue.
 * Pop, top, empty are O(1).
 */

#include <stdlib.h>
#include <stdbool.h>

/* Simple queue implemented with a circular buffer */
typedef struct {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} Queue;

Queue *queueCreate(int cap) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * cap);
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = cap;
    return q;
}

void queuePush(Queue *q, int val) {
    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
}

int queuePop(Queue *q) {
    int val = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return val;
}

int queuePeek(Queue *q) {
    return q->data[q->head];
}

bool queueEmpty(Queue *q) {
    return q->size == 0;
}

void queueFree(Queue *q) {
    free(q->data);
    free(q);
}

/* Stack built on top of two queues */
typedef struct {
    Queue *q1;
    Queue *q2;
} MyStack;

MyStack *myStackCreate() {
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->q1 = queueCreate(200);
    stack->q2 = queueCreate(200);
    return stack;
}

void myStackPush(MyStack *obj, int x) {
    /* Push x into the empty queue, then move all from the other queue */
    Queue *empty = queueEmpty(obj->q1) ? obj->q1 : obj->q2;
    Queue *full  = (empty == obj->q1) ? obj->q2 : obj->q1;

    queuePush(empty, x);
    while (!queueEmpty(full)) {
        queuePush(empty, queuePop(full));
    }

    /* Swap so q1 always holds the elements in stack order */
    if (empty != obj->q1) {
        Queue *tmp = obj->q1;
        obj->q1 = obj->q2;
        obj->q2 = tmp;
    }
}

int myStackPop(MyStack *obj) {
    return queuePop(obj->q1);
}

int myStackTop(MyStack *obj) {
    return queuePeek(obj->q1);
}

bool myStackEmpty(MyStack *obj) {
    return queueEmpty(obj->q1);
}

void myStackFree(MyStack *obj) {
    queueFree(obj->q1);
    queueFree(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
