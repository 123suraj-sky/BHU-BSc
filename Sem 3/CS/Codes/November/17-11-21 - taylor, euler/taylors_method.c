// Write a Program to implement Taylor's Series Method to solve Ordinary Differential equation.
// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

float f1(float x, float y)
{
    return (x * (y + 1));
}

float f2(float x, float y)
{
    return (x * f1(x, y)) + y + 1;
}

int main()
{
    float x0, y0, xn, h, yn, number_of_steps, f1(float, float), f2(float, float);

    printf("Enter the initial value of x0 = ");
    scanf("%f", &x0);
    printf("Enter the initial value of y0 = ");
    scanf("%f", &y0);
    printf("Enter the value where solution to be found: ");
    scanf("%f", &xn);
    printf("Enter number of steps to be performed for final solution: ");
    scanf("%f", &number_of_steps);

    h = (xn - x0) / number_of_steps;

    //* Taylor's series of order 2
    for (int i = 0; i < number_of_steps; i++)
    {
        yn = y0 + (h * f1(x0, y0)) + (pow(h, 2) * f2(x0, y0) / 2);
        y0 = yn;
        x0 = x0 + h;
    }

    printf("\nf(%f) = %f\n", xn, yn);
    return 0;
}