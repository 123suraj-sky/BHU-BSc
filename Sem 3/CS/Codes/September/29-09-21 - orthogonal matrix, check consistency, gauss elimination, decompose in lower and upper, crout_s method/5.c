// computing the upper triangular matrix and lower triangular matrix

#include <stdio.h>

void printMatrix(float matrix[10][10], int size);

int main()
{
    int size, row, column, ctr1, ctr2;
    size = 4;
    float matrix[10][10] = {{2, 3, 1, 5},
                            {6, 13, 5, 19},
                            {2, 19, 10, 23},
                            {4, 10, 11, 31}};
    printf("\nYour matrix is:\n");
    printMatrix(matrix, size);

    float lowerTriangle[10][10];
    float upperTriangluar[10][10];

    for (row = 0; row < size; row++)
    {
        for (column = 0; column < size; column++)
        {
            if (row > column) // initialise all elements of lower trianle in upper triangular matrix
                upperTriangluar[row][column] = 0;
            if (row < column) // initialise all elements of upper triangle in lower triangular matrix
                lowerTriangle[row][column] = 0;
            if (row == column) // initialise all diagonal elements of lower triangle in lower triangular matrix
                lowerTriangle[row][column] = 1;
        }
    }

    for (ctr1 = 0; ctr1 < size; ctr1++)
    {
        upperTriangluar[ctr1][ctr1] = matrix[ctr1][ctr1];
        for (ctr2 = ctr1 + 1; ctr2 < size; ctr2++)
        {
            upperTriangluar[ctr1][ctr2] = matrix[ctr1][ctr2];
            lowerTriangle[ctr2][ctr1] = matrix[ctr2][ctr1] / upperTriangluar[ctr1][ctr1];
        }
        for (row = ctr1 + 1; row < size; row++)
        {
            for (column = ctr1 + 1; column < size; column++)
                matrix[row][column] -= (lowerTriangle[row][ctr1] * upperTriangluar[ctr1][column]);
        }
    }

    printf("\nUpper Triangular Matrix:\n");
    printMatrix(upperTriangluar, size);

    printf("\nLower Triangular Matrix:\n");
    printMatrix(lowerTriangle, size);

    return 0;
}

void printMatrix(float matrix[10][10], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
            printf("%10f ", matrix[row][column]);
        printf("\n");
    }
}