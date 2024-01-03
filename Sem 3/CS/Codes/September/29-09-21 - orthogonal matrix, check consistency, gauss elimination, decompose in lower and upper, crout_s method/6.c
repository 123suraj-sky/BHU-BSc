// crouts method

#include <stdio.h>
#include <math.h>

int main()
{
    // declaring the variables
    int i, j, k, p, n;
    float x[10], arr[10][10], b[10][10], u[10][10];

    // taking the order of the matrix
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    // taking the coefficient matrix
    printf("Enter the coefficients of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    // taking the constant terms
    printf("Enter the constants:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &arr[i][n]);
    }

    // performing crout's method
    for (i = 0; i < n; i++)
    {
        b[i][0] = arr[i][0];
    }

    for (j = 1; j <= n; j++)
    {
        u[0][j] = (arr[0][j] / b[0][0]);
    }

    for (p = 1; p < n; p++)
    {
        for (i = p; i < n; i++)
        {
            for (k = 0; k < p; k++)
            {
                arr[i][p] -= b[i][k] * u[k][p];
            }
            b[i][p] = arr[i][p];
        }
        for (j = p + 1; j <= n; j++)
        {
            for (k = 0; k < p; k++)
            {
                arr[p][j] -= b[p][k] * u[k][j];
            }
            u[p][j] = arr[p][j] / b[p][p];
        }
    }

    for (k = 0; k < n; k++)
    {
        i = (n - k - 1);
        x[i] = u[i][n];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= (u[i][j] * x[j]);
        }
    }

    // displaying the result
    printf("\nThe result is:\n");
    for (i = 0; i < n; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}

/*
order = 3

coefficients of matrix
2 1 4
8 -3 2
4 11 -1

constants --> 12 20 33

result is
x[0]= 3
x[1]= 2
x[2]= 1
*/