// Write a Program to implement Numerical Differentiation using Newton's Backward difference Formula
// 20220PHY014

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x[20], y[20][20], find_derivative, h, sum_of_terms = 0.0, first_derivative, term; // 'h' is finite difference
    int total_given_values, index, check_validation = 0;

    printf("Enter total given number of data points: ");
    scanf("%d", &total_given_values);

    for (int i = 0; i < total_given_values; i++)
    {
        printf("Enter the value of x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("Enter the value of y[%d] = ", i);
        scanf("%f", &y[i][0]);
        printf("\n");
    }

    h = x[1] - x[0];

    printf("Enter the value at which derivative of the function to be found: ");
    scanf("%f", &find_derivative);

    // Checking for validation of given point
    for (int i = 0; i < total_given_values; i++)
    {
        if (fabs(find_derivative - x[i]) < 0.0001)
        {
            index = i; // index of calculation point
            check_validation = 1;
            break;
        }
    }

    // if given point is not a valid point i.e. its value is varies much from x[i]
    if (check_validation == 0)
    {
        printf("Next time try with different data point!!!\n");
        exit(0);
    }

    // Forming Backward difference table
    for (int i = 1; i < total_given_values; i++)
        for (int j = total_given_values - 1; j > i - 1; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];

    // Applying formula to find differentiation
    for (int i = 1; i <= index; i++)
    {
        term = pow(y[index][i], i) / i;
        sum_of_terms += term;
    }
    first_derivative = sum_of_terms / h; // finally dividing by 'h' to get the result

    printf("f'(%f) = %f\n", find_derivative, first_derivative);
    return 0;
}