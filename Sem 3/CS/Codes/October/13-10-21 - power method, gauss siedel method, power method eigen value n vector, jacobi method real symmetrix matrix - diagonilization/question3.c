// Write a program to implement Power method to find the largest Eigen values and vectors.
// Exam Roll No. --> 20220PHY014

#include <stdio.h>
#include <math.h>

#define SIZE 10
#define ToleranceError 0.0001

int main()
{
    float x_new[SIZE];
    float temp, lambda_new, lambda_old;
    int i, j, matrix_order = 3, iteration = 1;

    float matrix[SIZE][SIZE] = {{1, 2, 0},
                                {2, 1, 0},
                                {0, 0, -1}};

    float x[3] = {0, 1, 0}; //notes: initial guess is 0, 1, 0

    lambda_old = 1;
run_again:
    //* finding x_new
    for (int i = 0; i < matrix_order; i++)
    {
        temp = 0.0;
        for (int j = 0; j < matrix_order; j++)
            temp += matrix[i][j] * x[j];
        x_new[i] = temp;
    }

    //* Assigning x_new to x
    for (int i = 0; i < matrix_order; i++)
        x[i] = x_new[i];

    //* Finding Largest element in x
    lambda_new = fabs(x[0]);
    for (int i = 1; i < matrix_order; i++)
    {
        if (fabs(x[i]) > lambda_new)
            lambda_new = fabs(x[i]);
    }

    //* Eigen matrix after dividing by largest element
    for (int i = 0; i < matrix_order; i++)
        x[i] /= lambda_new;

    printf("\n\nIteration %d:\n", iteration);
    printf("Eigen Value = %f\n", lambda_new);
    printf("Eigen Vector = ");
    for (int i = 0; i < matrix_order; i++)
    {
        if (i == 0)
            printf("[%f\t", x[i]);
        else if (i == 2)
            printf("%f]", x[i]);
        else
            printf("%f\t", x[i]);
    }

    //* repeat this process till the required condition is meet
    if (fabs(lambda_new - lambda_old) > ToleranceError)
    {
        lambda_old = lambda_new;
        iteration++;
        goto run_again;
    }
    printf("\n\nSo, finally after %d iterations\nEigen Value = %f\nAnd\nEigen Vector = [%f\t%f\t%f]\n", iteration, lambda_new, x[0], x[1], x[2]);
    return (0);
}