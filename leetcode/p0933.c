/*
 * LeetCode 933 - Number of Recent Calls
 *
 * Implement a RecentCounter that counts the number of recent ping requests
 * within the past 3000 milliseconds.
 *
 * Approach: Use a circular queue. On each ping(t), enqueue t, then dequeue
 * all entries < t - 3000. The queue size is the answer.
 *
 * Time:  O(1) amortized per call (each element enqueued/dequeued at most once)
 * Space: O(N) where N is max number of pings in a 3000ms window
 */

#include <stdlib.h>

#define MAX_SIZE 10001  /* At most 10^4 calls to ping */

typedef struct {
    int queue[MAX_SIZE];
    int head;
    int tail;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    /* Enqueue the new ping time */
    obj->queue[obj->tail++] = t;

    /* Dequeue all pings older than t - 3000 */
    while (obj->queue[obj->head] < t - 3000) {
        obj->head++;
    }

    /* Number of pings in [t - 3000, t] */
    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */
