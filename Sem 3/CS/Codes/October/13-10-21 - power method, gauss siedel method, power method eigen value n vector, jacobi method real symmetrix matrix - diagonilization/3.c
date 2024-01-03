// Write a program to implement Power method to find the largest Eigen values and vectors.
// Exam Roll No. --> 20220PHY014

#include <stdio.h>
#include <math.h>

#define ToleranceError 0.00001

int main()
{
    float x_new[3];
    float temp, lambda_new, lambda_old;
    int iteration = 1;
    float matrix[3][3] = {{1, 2, 0},
                          {2, 1, 0},
                          {0, 0, -1}};
    float x[3] = {0, 1, 0}; //notes: initial guess is 0, 1, 0

    /* Initializing Lambda_Old */
    lambda_old = 1;
/* Multiplication */
up:
    for (int i = 0; i < 3; i++)
    {
        temp = 0;
        for (int j = 0; j < 3; j++)
            temp += (matrix[i][j] * x[j]);
        x_new[i] = temp;
    }
    /* Replacing */
    for (int i = 0; i < 3; i++)
        x[i] = x_new[i];

    /* Finding Largest */
    lambda_new = fabs(x[0]);
    for (int i = 0; i < 3; i++)
    {
        if (fabs(x[i]) > lambda_new)
            lambda_new = fabs(x[i]);
    }
    /* Normalization */
    for (int i = 1; i < 3; i++)
        x[i] /= lambda_new;

    /* Display */
    printf("\n\nSTEP %d:\n", iteration);
    printf("Eigen Value = %f\n", lambda_new);
    printf("Eigen Vector:\n");
    for (int i = 0; i < 3; i++)
        printf("%f\t", x[i]);

    /* Checking Accuracy */
    if (fabs(lambda_new - lambda_old) > ToleranceError)
    {
        lambda_old = lambda_new;
        iteration++;
        goto up;
    }
    return (0);
}