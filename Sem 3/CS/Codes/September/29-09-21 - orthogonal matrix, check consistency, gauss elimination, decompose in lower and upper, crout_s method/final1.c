// Write a program to check whether a given matrix is orthogonal.
// Exam Roll No. - 20220PHY014

#include <stdio.h>

#define MAX 100 // maximum order of matrix can be 100

void print_matrix(float matrix[MAX][MAX], int order);
int isOrthogonal(float matrix[MAX][MAX], int n);

int main()
{
    float matrix[MAX][MAX] = {{1, 0, 0},
                              {0, 1, 0},
                              {0, 0, 1}};
    int matrixOrder = 3;

    printf("\nYour matrix is:\n");
    print_matrix(matrix, matrixOrder);

    if (isOrthogonal(matrix, matrixOrder))
        puts("\nGiven matrix is orthogonal");
    else
        puts("\nGiven matrix is not orthogonal");

    return 0;
}

void print_matrix(float matrix[MAX][MAX], int order)
{
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
            printf("%10f ", matrix[i][j]);
        printf("\n");
    }
}

int isOrthogonal(float matrix[MAX][MAX], int n)
{
    // Find transpose
    float transpose[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            transpose[i][j] = matrix[j][i];
    }
    printf("\nTanspose of matrix is:\n");
    print_matrix(transpose, n);

    // Find product of matrix and its transpose
    float product[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
                sum += (matrix[i][k] * matrix[j][k]);
            product[i][j] = sum;
        }
    }
    printf("\nProduct of matrix and its tranpose is:\n");
    print_matrix(product, n);

    // Check if the product is identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && product[i][j] != 0)
                return 0;
            if (i == j && product[i][j] != 1)
                return 0;
        }
    }
    return 1;
}