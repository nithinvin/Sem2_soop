#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void sortRows(int mat[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
        insertionSort(mat[i], c);
}

void sortColumns(int mat[10][10], int r, int c)
{
    int temp[10];

    for (int j = 0; j < c; j++)
    {
        /* copy column into temp array */
        for (int i = 0; i < r; i++)
            temp[i] = mat[i][j];

        /* sort the column */
        insertionSort(temp, r);

        /* copy back to matrix */
        for (int i = 0; i < r; i++)
            mat[i][j] = temp[i];
    }
}

void printMatrix(int mat[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int mat[10][10], r, c;

    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    sortRows(mat, r, c);
    printf("\nRow-wise sorted matrix:\n");
    printMatrix(mat, r, c);

    sortColumns(mat, r, c);
    printf("\nColumn-wise sorted matrix:\n");
    printMatrix(mat, r, c);

    return 0;
}
