#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float x[20], y[20], forward_difference[20], find_derivative, h, sum = 0.0, term, first_derivative; // 'h' is finite difference
    int total_given_values, index, flag = 0, sign = 1;

    /* Reading number of data */
    // printf("Enter number of data: ");
    // scanf("%d", &total_given_values);
    total_given_values = 7;

    /* Reading actual data of x and y */
    // printf("Enter data:\n");
    // for (i = 0; i < total_given_values; i++)
    // {
    //     printf("x[%d] = ", i);
    //     scanf("%f", &x[i]);
    //     printf("y[%d] = ", i);
    //     scanf("%f", &y[i][0]);
    //     printf("\n");
    // }
    x[0] = 1, x[1] = 1.1, x[2] = 1.2, x[3] = 1.3, x[4] = 1.4, x[5] = 1.5, x[6] = 1.6;
    y[0] = 7.989, y[1] = 8.403, y[2] = 8.781, y[3] = 9.129, y[4] = 9.451, y[5] = 9.750, y[6] = 10.031;

    h = x[1] - x[0];

    printf("Enter the value at which derivative of the function to be found: ");
    scanf("%f", &find_derivative);

    /* Checking whether given point (find_derivative) is a valid point in x data or not */
    for (int i = 0; i < total_given_values; i++)
    {
        if (fabs(find_derivative - x[i]) < 0.0001)
        {
            /* index of calculation point */
            index = i;
            flag = 1;
            break;
        }
    }

    /* if flag is still 0 then given point (find_derivative)
 is not a valid point (not in list of x data)
 for this calculation */
    if (flag == 0)
    {
        printf("Invalid calculation point. Program exiting...");
        exit(0);
    }

    /* Generating Forward Difference Table */
    for (int i = 1; i < total_given_values; i++)
    {
        for (int j = 0; j < total_given_values - i; j++)
            // y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
            forward_difference[i] = y[i + 1] - y[0];
    }

    /* Applying formula for calculating sum of
 different terms in formula to find derivatives
 using forward difference formula */
    printf("index is %d\n", index);
    printf("term is %f\n", term);
    for (int i = 1; i < total_given_values; i++)
    {
        // term = pow(y[total_given_values - 1][i], i) / i;
        term = pow(forward_difference[i], i) / i;
        sum += sign * term;
        sign = -sign;
    }

    /* Dividing by h */
    first_derivative = sum / h;

    /* Displaying final result */
    printf("First derivative at x = %f is %f\n", find_derivative, first_derivative);

    return 0;
}