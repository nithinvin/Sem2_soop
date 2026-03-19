// LeetCode 49 - Group Anagrams
// Given an array of strings strs, group the anagrams together.
// An anagram is a word formed by rearranging the letters of another word.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a sorted-character key for a string
void sortedKey(const char *s, char *key) {
    strcpy(key, s);
    int len = strlen(key);
    // Simple insertion sort on characters
    for (int i = 1; i < len; i++) {
        char c = key[i];
        int j = i - 1;
        while (j >= 0 && key[j] > c) {
            key[j + 1] = key[j];
            j--;
        }
        key[j + 1] = c;
    }
}

// Hash table entry for grouping anagrams
typedef struct Entry {
    char *key;
    int *indices;
    int count;
    int capacity;
    struct Entry *next;
} Entry;

#define TABLE_SIZE 1024

unsigned long hashStr(const char *s) {
    unsigned long h = 5381;
    while (*s) {
        h = ((h << 5) + h) + (unsigned char)*s;
        s++;
    }
    return h % TABLE_SIZE;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    Entry *table[TABLE_SIZE];
    memset(table, 0, sizeof(table));

    Entry *groups[strsSize]; // pointers to unique groups
    int groupCount = 0;

    char key[301];

    for (int i = 0; i < strsSize; i++) {
        sortedKey(strs[i], key);
        unsigned long h = hashStr(key);

        Entry *e = table[h];
        while (e) {
            if (strcmp(e->key, key) == 0) break;
            e = e->next;
        }
        if (!e) {
            e = malloc(sizeof(Entry));
            e->key = strdup(key);
            e->capacity = 4;
            e->count = 0;
            e->indices = malloc(e->capacity * sizeof(int));
            e->next = table[h];
            table[h] = e;
            groups[groupCount++] = e;
        }
        if (e->count >= e->capacity) {
            e->capacity *= 2;
            e->indices = realloc(e->indices, e->capacity * sizeof(int));
        }
        e->indices[e->count++] = i;
    }

    *returnSize = groupCount;
    char ***result = malloc(groupCount * sizeof(char **));
    *returnColumnSizes = malloc(groupCount * sizeof(int));

    for (int i = 0; i < groupCount; i++) {
        Entry *g = groups[i];
        (*returnColumnSizes)[i] = g->count;
        result[i] = malloc(g->count * sizeof(char *));
        for (int j = 0; j < g->count; j++) {
            result[i][j] = strs[g->indices[j]];
        }
    }

    // Free hash table entries
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry *e = table[i];
        while (e) {
            Entry *next = e->next;
            free(e->key);
            free(e->indices);
            free(e);
            e = next;
        }
    }

    return result;
}

int main(void) {
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int returnSize;
    int *returnColumnSizes;

    char ***res = groupAnagrams(strs, 6, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s%s", res[i][j], j < returnColumnSizes[i] - 1 ? ", " : "");
        }
        printf("]\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    return 0;
}
