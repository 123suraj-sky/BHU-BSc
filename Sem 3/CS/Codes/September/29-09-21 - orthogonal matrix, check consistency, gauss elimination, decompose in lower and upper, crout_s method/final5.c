// Write a program to implement Crout's method.
// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

void printMatrix(float matrix[10][10], int order);

int main()
{
    int order = 3;
    float solution[10], lower[10][10], upper[10][10];

    float linearEquation[10][10] = {{2, 1, 4, 12},    // 2x + y + 4z = 12
                                     {8, -3, 2, 20},   // 8x - 3y + 2z = 20
                                     {4, 11, -1, 33}}; // 4x + 11y - z = 33

    for (int i = 0; i < order; i++)
        lower[i][0] = linearEquation[i][0];

    for (int j = 1; j <= order; j++)
        upper[0][j] = (linearEquation[0][j] / lower[0][0]);

    for (int p = 1; p < order; p++)
    {
        for (int i = p; i < order; i++)
        {
            for (int k = 0; k < p; k++)
                linearEquation[i][p] -= lower[i][k] * upper[k][p];
            lower[i][p] = linearEquation[i][p];
        }
        for (int j = p + 1; j <= order; j++)
        {
            for (int k = 0; k < p; k++)
                linearEquation[p][j] -= lower[p][k] * upper[k][j];
            upper[p][j] = linearEquation[p][j] / lower[p][p];
        }
    }

    for (int k = 0; k < order; k++)
    {
        int i = (order - k - 1);
        solution[i] = upper[i][order];
        for (int j = i + 1; j < order; j++)
            solution[i] -= (upper[i][j] * solution[j]);
    }

    printf("\nThe result is:\n");
    for (int i = 0; i < order; i++)
        printf("x[%d] = %f\n", i, solution[i]);

    return 0;
}

void printMatrix(float matrix[10][10], int order)
{
    for (int row = 0; row < order; row++)
    {
        for (int column = 0; column < order + 1; column++)
            printf("%10f ", matrix[row][column]);
        printf("\n");
    }
}