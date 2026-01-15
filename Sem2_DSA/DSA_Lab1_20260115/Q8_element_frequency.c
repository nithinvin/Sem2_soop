// C program to count the frequency of each element of an array
#include <stdio.h>

int main() {
    int n, i, j, count;
    int arr[512], freq[128];

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);

    printf("Input %d elements in the array: ", n);
    for(i = 0; i < n; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array
    }

    for(i = 0; i < n; i++) {
        count = 1;
        if(freq[i] == 0)
            continue;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Mark as counted
            }
        }
        freq[i] = count;
    }

    printf("The frequency of all elements of an array :\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d occurs %d times\n", arr[i], freq[i]);
        }
    }

    return 0;
}
