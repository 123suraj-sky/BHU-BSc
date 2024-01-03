// Write a program to implement the Lagrange interpolation
// Exam Roll No. --> 20220PHY014

#include <stdio.h>


double Li(int i, int total_given_values, double x[total_given_values + 1], double find_value) // Li(x) is the weighting function
{
    double product = 1;
    for (int j = 0; j <= total_given_values; j++)
        if (j != i)
            product *= (find_value - x[j]) / (x[i] - x[j]);
    return product;
}

double Fn(int total_given_values, double x[total_given_values + 1], double y[total_given_values + 1], double find_value) // Fn(x) --> Lagrangian interpolating polynomial
{
    double sum = 0;
    for (int i = 0; i <= total_given_values; i++)
        sum += (Li(i, total_given_values, x, find_value) * y[i]);
    return sum;
}

void main()
{
    int total_given_values;
    printf("Enter the total number of given values: ");
    scanf("%d", &total_given_values);
    total_given_values--; // as we start counting from 0

    double x[total_given_values + 1], y[total_given_values + 1], find_value; // arrays to store x and y(x) and find_value is the value of x at which we have to find f(x)

    for (int i = 0; i <= total_given_values; i++)
    {
        printf("Enter the value of x%d: ", i);
        scanf("%lf", &x[i]);
        printf("Enter the value of y%d: ", i);
        scanf("%lf", &y[i]);
        printf("\n");
    }

    printf("We have to find the value of f(x) at x = ");
    scanf("%lf", &find_value);

    printf("The interpolated value is %lf\n", Fn(total_given_values, x, y, find_value));
}