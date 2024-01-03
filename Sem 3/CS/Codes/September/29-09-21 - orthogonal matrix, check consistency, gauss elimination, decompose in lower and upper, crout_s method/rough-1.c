#include <stdio.h>

#define MAX 100 // maximum order of matrix can be 100

void print_matrix(int matrix[MAX][MAX], int order);
int isOrthogonal(int a[MAX][MAX], int n);

int main()
{
    int a[MAX][MAX], matrix_order;

    printf("Enter order of matrix: ");
    scanf("%d", &matrix_order);

    printf("Enter elements of matrix\n");
    for (int i = 0; i < matrix_order; i++)
    {
        for (int j = 0; j < matrix_order; j++)
        {
            printf("Enter matrix element[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nYour matrix is:\n");
    print_matrix(a, matrix_order);

    if (isOrthogonal(a, matrix_order))
        puts("\nGiven matrix is orthogonal");
    else
        puts("\nGiven matrix is not orthogonal");

    return 0;
}

void print_matrix(int matrix[MAX][MAX], int order)
{
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
            printf("%-5d ", matrix[i][j]);
        printf("\n");
    }
}

int isOrthogonal(int a[MAX][MAX], int n) // a is the given matrix and n is the given order
{
    // Finding transpose
    int transpose[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            transpose[i][j] = a[j][i];
    }
    printf("\nTanspose of matrix is:\n");
    print_matrix(transpose, n);

    // Finding product of a[][] and its transpose
    int product[MAX][MAX];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += (a[i][k] * a[j][k]);
            product[i][j] = sum;
        }
    }
    printf("\nProduct of matrix and its tranpose is:\n");
    print_matrix(product, n);

    // Checking if the product is identity matrix
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