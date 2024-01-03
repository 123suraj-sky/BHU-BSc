// Write a program to calculate the value of function at some intermediate point using Newton's Backward Interpolation formula
// Exam Roll No. --> 20220PHY014

#include <stdio.h>

int fact(int total_given_values)
{
    int f = 1, i;
    for (i = 1; i <= total_given_values; i++)
        f = f * i;
    return f;
}

int main()
{
    int total_given_values, del = 31;
    float function_and_values[10][11], product_of_u_and_fx = 1, x, y, u, h; // x for the value to find and y = f(x), h is interval for equally spaced data, u = (x-x0)/h, initial value of y = f(x0)

    printf("\nEnter the total number of given values: ");
    scanf("%d", &total_given_values);
    printf("\n");
    for (int i = 0; i < total_given_values; i++)
    {
        printf("Enter the value of x%d: ", i);
        scanf("%f", &function_and_values[i][0]);
        printf("Enter the value of y%d: ", i);
        scanf("%f", &function_and_values[i][1]);
        printf("\n");
    }

    // Forming Backward difference table
    for (int j = 2; j <= total_given_values; j++)
        for (int i = 0; i < total_given_values - 1; i++)
            function_and_values[i][j] = function_and_values[i + 1][j - 1] - function_and_values[i][j - 1];

    // Printing table
    printf("\nNewton's Backward Difference table is:\n");
    printf("\nx\t\tf(x)\t\t");
    for (int i = 0; i <= total_given_values - 2; i++)
        printf("%c^%d\t\t", del, i + 1);
    for (int i = 0; i < total_given_values; i++)
    {
        printf("\n");
        for (int j = 0; j < total_given_values + 1 - i; j++)
            printf("%f\t", function_and_values[i][j]);
    }

    printf("\n\nEnter value of x to be calculated: ");
    scanf("%f", &x);

    // Calculating f(x)
    h = function_and_values[total_given_values - 1][0] - function_and_values[total_given_values - 2][0];
    u = (x - function_and_values[total_given_values - 1][0]) / h;
    y = function_and_values[total_given_values - 1][1];

    for (int i = 1; i < total_given_values; i++)
    {
        product_of_u_and_fx *= (u + (i - 1));
        y += (function_and_values[total_given_values - 1 - i][i + 1] * product_of_u_and_fx) / fact(i);
    }
    printf("\nFinal Result is:\nf(%f) = %f\n", x, y);
    return 0;
}