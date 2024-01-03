#include <stdio.h>

int main()
{
    // float x[20], y[20][20]; // arrays to store function data points
    float function_and_values[100][101];
    int total_given_values, del = 31;

    printf("Enter the total number of given values: ");
    scanf("%d", &total_given_values);
    printf("\n");
    for (int i = 0; i < total_given_values; i++)
    {
        printf("Enter the value of x%d: ", i);
        // scanf("%f", &x[i]);
        scanf("%f", &function_and_values[i][0]);
        printf("Enter the value of y%d: ", i);
        // scanf("%f", &y[i][0]);
        scanf("%f", &function_and_values[i][1]);
        printf("\n");
    }

    // Forming Backward Difference Table
    // for (int i = 1; i < total_given_values; i++)
    //     for (int j = total_given_values - 1; j > i - 1; j--)
    //         // y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    //         function_and_values[i][j] = function_and_values[i][j - 1] - function_and_values[i - 1][j - 1];
    for (int j = 2; j <= total_given_values; j++)
        for (int i = 0; i < total_given_values; i++)
            // y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
            function_and_values[i][j] = function_and_values[i][j - 1] - function_and_values[i - 1][j - 1];

    // Printing Table
    // printf("\nBACKWARD DIFFERENCE TABLE\n\n");
    // for (int i = 0; i < total_given_values; i++)
    // {
    //     printf("%f", x[i]);
    //     for (int j = 0; j <= i; j++)
    //         printf("\t%f", y[i][j]);
    //     printf("\n");
    // }
    //////////////
    printf("\nNewton's Backward Difference table is:\n");
    printf("\nx\t\tf(x)\t\t");
    for (int i = 0; i <= total_given_values - 2; i++)
        printf("%c^%d\t\t", del, i + 1);
    for (int i = 0; i < total_given_values; i++)
    {
        printf("\n");
        for (int j = 0; j < total_given_values + 1 - i; j++)
        {
            if (j >= 2)
            {
                // break;
                printf("if%f\t", function_and_values[i][j + 1]);
            }
            else
            {
                printf("else%f\t", function_and_values[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}