/*
linear equation is:
2y + z = 4
x + y + 2z = 6
2x + y + z = 7
*/

#include <stdio.h>

#define M 10

void swap(float a[][M], int j, int k, int c);
int PerformOperation(float a[][M], int n);
int CheckConsistencY(float a[][M], int n, int flag);
void PrintResult(float a[][M], int n, int flag);

int main()
{
    float matrix[M][M] = {{0, 2, 1, 4},
                          {1, 1, 2, 6},
                          {2, 1, 1, 7}};

    int order = 3, flag = 0;

    // Performing Matrix transformation
    flag = PerformOperation(matrix, order);

    if (flag == 1)
        flag = CheckConsistencY(matrix, order, flag);

    PrintResult(matrix, order, flag);
    return 0;
}

void swap(float a[][M], int j, int k, int c) // swap values of a[j][k] and a[j + c][k]
{
    float temp = a[j][k];
    a[j][k] = a[j + c][k];
    a[j + c][k] = temp;
}

int PerformOperation(float a[][M], int n) // function to reduce matrix to reduced row echelon form
{
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    for (i = 0; i < n; i++) // Performing elementary opertions
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
                swap(a, j, k, c);
        }
        for (j = 0; j < n; j++)
        {
            if (i != j) // Excluding all i == j
            {
                float pro = a[j][i] / a[i][i]; // converting matrix to reduced row, echelon form (diagonal matrix)
                for (k = 0; k <= n; k++)
                    a[j][k] = a[j][k] - (a[i][k] * pro);
            }
        }
    }
    return flag;
}

int CheckConsistencY(float a[][M], int n, int flag)
{
    int i, j;
    float sum;

    flag = 3;// flag == 2 for infinite solution & flag == 3 for No solution
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

void PrintResult(float a[][M], int n, int flag)
{
    if (flag == 2)
        printf("The matrix has infinite solutions --> consistent\n");
    else if (flag == 3)
        printf("The matrix has no solution --> Inconsistent\n");
    else
        printf("The matrix has unique solution --> consistent\n");
}