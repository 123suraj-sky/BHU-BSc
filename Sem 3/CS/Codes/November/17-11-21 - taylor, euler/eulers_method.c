// Write a Program to implement Euler's Method to solve Ordinary Differential equation.
// Exam Roll No. - 20220PHY014

#include <stdio.h>

#define slope(x, y) (x * (y + 1))

int main()
{
    float x0, y0, xn, h, yn, number_of_steps;

    printf("Enter the initial value of x0 = ");
    scanf("%f", &x0);
    printf("Enter the initial value of y0 = ");
    scanf("%f", &y0);
    printf("Enter the value where solution to be found: ");
    scanf("%f", &xn);
    printf("Enter the value of h: ");
    scanf("%f", &h);

    number_of_steps = (xn - x0) / h;

    // Euler's Method
    for (int i = 0; i < number_of_steps; i++)
    {
        yn = y0 + h * slope(x0, y0);
        y0 = yn;
        x0 += h;
    }

    printf("\nf(%f) = %f\n", xn, yn);
    return 0;
}