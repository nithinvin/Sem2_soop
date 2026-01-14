#include <stdio.h>

/* Function to swap two elements */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 Partition function
 Pivot is chosen as the first element.
 After partitioning, pivot is placed in its correct position.
*/
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];   // Pivot selection (first element)
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    // Place pivot in its correct position
    swap(&arr[low], &arr[j]);

    return j;   // Pivot index
}

/* Quick Sort function */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    // Print sorted list
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}
