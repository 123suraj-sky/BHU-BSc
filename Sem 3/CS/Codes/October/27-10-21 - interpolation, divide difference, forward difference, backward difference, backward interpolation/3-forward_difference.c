// Write a program to implement Forward Difference Table
// Exam Roll No. --> 20220PHY014

#include <stdio.h>

int main()
{
    float function_and_values[100][101];
    int total_given_values, del = 30; // character "del" will print triangle like structure

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

    // Forming Forward difference table
    for (int j = 2; j <= total_given_values; j++)
        for (int i = 0; i < total_given_values - 1; i++)
            function_and_values[i][j] = function_and_values[i + 1][j - 1] - function_and_values[i][j - 1];

    // Printing table
    printf("\nNewton's Forward Difference table is:\n");
    printf("\nx\t\tf(x)\t\t");
    for (int i = 0; i <= total_given_values - 2; i++)
        printf("%c^%d\t\t", del, i + 1);
    for (int i = 0; i < total_given_values; i++)
    {
        printf("\n");
        for (int j = 0; j < total_given_values + 1 - i; j++)
            printf("%f\t", function_and_values[i][j]);
    }
    printf("\n");
    return 0;
}