#include <stdio.h>
#define MAX 10

void print_matrix(int a[][MAX], int row, int column)
{
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
            printf("%-5d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i, j, k, size, flag = 1;
    int a[10][10], temp[10][10], identify_check[10][10], sum = 0;

    printf("Enter the size of square matrix = ");
    scanf("%d", &size);

    printf("Enter Elements in matrix\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix is:\n");
    print_matrix(a, size, size);

    // Transpose of given matrix
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            temp[i][j] = a[j][i];
    }
    printf("Transpose of matrix is:\n");
    print_matrix(temp, size, size);

    // Multiplying given A with A^t(A Transpose)
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            for (k = 0; k < size; k++)
                sum += (a[i][k] * temp[k][j]);
            identify_check[i][j] = sum;
            sum = 0;
        }
    }

    printf("Product of matrix and its transpose is:\n" );
    print_matrix(identify_check, size, size);

    // Checking whether A * A^t resulted in identity Matrix or not
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (i == j && identify_check[i][j] != 1)
                flag = 0;
            if (i != j && identify_check[i][j] != 0)
                flag = 0;
        }
    }

    // Checking for Orthogonal Matrix or not
    if (flag == 1)
        printf("Given Matrix is Orthogonal Matrix\n");
    else
        printf("Given Matrix is not an Orthogonal Matrix\n");

    return 0;
}