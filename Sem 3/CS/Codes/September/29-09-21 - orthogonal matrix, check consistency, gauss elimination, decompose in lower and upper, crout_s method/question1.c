// Write a program to check whether a given matrix is orthogonal.

// Exam Roll No. - 20220PHY014

#include <stdio.h>

int main()
{
    int rows, columns, c, d, k, sum = 0; // c, d, k are variables for loops
    int matrix[10][10], transpose[10][10], product[10][10];

    printf("Enter the number of rows and columns of matrix:\n");
    scanf("%d%d", &rows, &columns);

    if (rows != columns)
    {
        puts("The Matrix isn't orthogonal\nOrthogonality conditions only applicable for square matrix");
        goto end;
    }

    // Taking data from user
    for (c = 0; c < rows; c++)
    {
        for (d = 0; d < columns; d++)
        {
            printf("Enter element matrix[%d][%d]: ", c + 1, d + 1);
            scanf("%d", &matrix[c][d]);
        }
    }

    // Making transpose of given matrix
    for (c = 0; c < rows; c++)
    {
        for (d = 0; d < columns; d++)
            transpose[d][c] = matrix[c][d];
    }

    // Matrix multiplication of matrix and its transpose
    for (c = 0; c < rows; c++)
    {
        for (d = 0; d < columns; d++)
        {
            for (k = 0; k < columns; k++)
                sum += (matrix[c][k] * transpose[k][d]);
            product[c][d] = sum;
            sum = 0;
        }
    }

    // Checking if the product is equalt to identity matrix
    for (c = 0; c < rows; c++)
    {
        for (d = 0; d < columns; d++)
        {
            if (c == d) // diagonal elements
            {
                if (product[c][d] != 1)
                    break;
            }
            else
            {
                if (product[c][d] != 0)
                    break;
            }
        }
        if (d != rows)
            break;
    }

    if (c != rows)
        puts("The Matrix isn't orthogonal");
    else
        puts("The Matrix is orthogoanl");
end:
    return 0;
}