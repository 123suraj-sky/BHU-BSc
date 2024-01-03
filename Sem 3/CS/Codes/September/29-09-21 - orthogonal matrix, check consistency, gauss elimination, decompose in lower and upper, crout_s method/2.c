// gauss jordan elimination method

#include <stdio.h>

#define M 10

void swap(float a[][M], int *j, int *k, int *c);
void PrintMatrix(float a[][M], int n);
int PerformOperation(float a[][M], int n);
void PrintResult(float a[][M], int n, int flag);
int CheckConsistencY(float a[][M], int n, int flag);

int main()
{
    float a[M][M] = {{0, 2, 1, 4},
                     {1, 1, 2, 6},
                     {2, 1, 1, 7}};

    // Order of matrix(n)
    int n = 3, flag = 0;

    // Performing Matrix transformation
    flag = PerformOperation(a, n);

    if (flag == 1)
        flag = CheckConsistencY(a, n, flag);

    // Printing Final matrix
    printf("Final Augumented Matrix is:\n");
    PrintMatrix(a, n);
    printf("\n");

    // Printing Solutions (if exit)
    PrintResult(a, n, flag);
    printf("\n");

    return 0;
}

// Swap function
void swap(float a[][M], int *j, int *k, int *c)
{
    float temp = a[*j][*k];
    a[*j][*k] = a[*j + *c][*k];
    a[*j + *c][*k] = temp;
}

// Function to print matrix
void PrintMatrix(float a[][M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            printf("%10f ", a[i][j]);
        printf("\n");
    }
}

// function to reduce matrix to reduced row echelon form
int PerformOperation(float a[][M], int n)
{
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    // Performing elementary opertions
    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            c = 1;
            while ((i + c) < n && a[i + c][i] == 0)
                c++;
            if ((i + c) == n)
            {
                flag = 1;
                break;
            }
            for (j = i, k = 0; k <= n; k++)
                swap(a, &j, &k, &c);
        }
        for (j = 0; j < n; j++)
        {
            // Excluding all i == j
            if (i != j)
            {
                // converting matrix to reduced row
                // echelon form (diagonal matrix)
                float pro = a[j][i] / a[i][i];
                for (k = 0; k <= n; k++)
                    a[j][k] = a[j][k] - (a[i][k] * pro);
            }
        }
    }
    return flag;
}

// Function to print the desired result if unique solutions exists, otherwise prints no solution or infinite solutions depending upon the input given
void PrintResult(float a[][M], int n, int flag)
{
    printf("Result is: ");
    if (flag == 2)
        printf("Infinite solutions Exists\n");
    else if (flag == 3)
        printf("No solution extsts\n");

    // Printing the solution by dividing constants by their respective diagonal elements
    else
    {
        for (int i = 0; i < n; i++)
            printf("%f, ", a[i][n] / a[i][i]);
        printf("\b\b\b");
    }
}

// To check whether infinite solutions exists or no solution exists
int CheckConsistencY(float a[][M], int n, int flag)
{
    int i, j;
    float sum;

    // flag == 2 for infinite solution
    // flag == 3 for No solution
    flag = 3;
    for (i = 0; i < n; i++)
    {
        sum = 0;
        for (j = 0; j < n; j++)
            sum += a[i][j];
        if (sum == a[i][j])
            flag = 2;
    }
    return flag;
}