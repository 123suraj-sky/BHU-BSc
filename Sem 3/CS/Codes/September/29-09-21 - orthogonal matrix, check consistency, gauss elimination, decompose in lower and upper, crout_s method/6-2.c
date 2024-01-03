#include <stdio.h>
#include <stdlib.h>

void printMatrix(float matrix[10][10], int order);

void lower_upper_triangular(float matrix[10][10], int order)
{
    int row, column, ctr1, ctr2;
    printf("\nYour matrix is:\n");
    printMatrix(matrix, order);

    float lowerTriangle[10][10];
    float upperTriangluar[10][10];
    float Y[10];

    for (row = 0; row < order; row++)
    {
        for (column = 0; column < order; column++)
        {
            if (row > column) // initialise all elements of lower trianle in upper triangular matrix
                upperTriangluar[row][column] = 0;
            if (row < column) // initialise all elements of upper triangle in lower triangular matrix
                lowerTriangle[row][column] = 0;
            if (row == column) // initialise all diagonal elements of lower triangle in lower triangular matrix
                lowerTriangle[row][column] = 1;
        }
    }

    for (ctr1 = 0; ctr1 < order; ctr1++)
    {
        upperTriangluar[ctr1][ctr1] = matrix[ctr1][ctr1];
        for (ctr2 = ctr1 + 1; ctr2 < order; ctr2++)
        {
            upperTriangluar[ctr1][ctr2] = matrix[ctr1][ctr2];
            lowerTriangle[ctr2][ctr1] = matrix[ctr2][ctr1] / upperTriangluar[ctr1][ctr1];
        }
        for (row = ctr1 + 1; row < order; row++)
        {
            for (column = ctr1 + 1; column < order; column++)
                matrix[row][column] -= (lowerTriangle[row][ctr1] * upperTriangluar[ctr1][column]);
        }
    }

    solution(Y, upperTriangluar, order);
}

void solution(float x[10], float a[10][10], int n)
{
    x[n] = a[n][n + 1] / a[n][n];
    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] -= (a[i][j] * x[j]);
        }
        x[i] /= a[i][i];
    }
    for (int i = 0; i < n; i++)
        printf("x[%d] = %f\n", i + 1, x[i]);
}

int main()
{
    int order = 4;
    float matrix[10][10] = {{2, 3, 1, 5},
                            {6, 13, 5, 19},
                            {2, 19, 10, 23},
                            {4, 10, 11, 31}};

    lower_upper_triangular(matrix, order);

    return 0;
}

void printMatrix(float matrix[10][10], int order)
{
    for (int row = 0; row < order; row++)
    {
        for (int column = 0; column < order; column++)
            printf("%10f ", matrix[row][column]);
        printf("\n");
    }
}