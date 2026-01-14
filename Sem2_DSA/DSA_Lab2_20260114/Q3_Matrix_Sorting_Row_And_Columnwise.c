#include <stdio.h>

/* Insertion sort for 1D array */
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

/* Sort each row in non-decreasing order */
void sortRows(int mat[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
        insertionSort(mat[i], c);
}

/* Sort each column in non-decreasing order */
void sortColumns(int mat[10][10], int r, int c)
{
    int temp[10];

    for (int j = 0; j < c; j++)
    {
        /* Copy column into temp array */
        for (int i = 0; i < r; i++)
            temp[i] = mat[i][j];

        /* Sort the column */
        insertionSort(temp, r);

        /* Copy back into matrix */
        for (int i = 0; i < r; i++)
            mat[i][j] = temp[i];
    }
}

/* Print matrix */
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
    int mat[10][10], rowMat[10][10], colMat[10][10];
    int r, c;

    printf("Enter number of rows and columns:\n");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
            rowMat[i][j] = mat[i][j];   /* copy for row-wise sorting */
            colMat[i][j] = mat[i][j];   /* copy for column-wise sorting */
        }
    }

    /* Row-wise sorting */
    sortRows(rowMat, r, c);
    printf("\nRow-wise sorted matrix:\n");
    printMatrix(rowMat, r, c);

    /* Column-wise sorting */
    sortColumns(colMat, r, c);
    printf("\nColumn-wise sorted matrix:\n");
    printMatrix(colMat, r, c);

    return 0;
}
