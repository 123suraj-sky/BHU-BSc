#include <stdio.h>
#include <math.h>

float f(float x, float y)
{
    return ((pow(y, 2) - pow(x, 2)) / (pow(y, 2) + pow(x, 2))); // y(0) = 1, xn = 0.4, h = 0.2
}

int main()
{
    float x0, y0, xn, yn, h, k1, k2, k3, k4;
    int numberOfSteps; // determine the value where the solution is

    printf("Enter the initial condition for y: ");
    scanf("%f", &y0);
    printf("Enter the initial condition for x: ");
    scanf("%f", &x0);
    printf("Enter the value of x where y to be found: ");
    scanf("%f", &xn);
    printf("Enter the step-width h: ");
    scanf("%f", &h);

    numberOfSteps = (xn - x0) / h;

    for (int i = 0; i < numberOfSteps; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + 0.5 * h, y0 + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y0 + 0.5 * k2);
        k4 = h * f(x0 + h, y0 + k3);

        yn = y0 + ((1.0 / 6) * (k1 + 2 * k2 + 2 * k3 + k4));

        //* Updating Values
        y0 = yn;
        x0 += h;
    }

    printf("\ny(%f) = %f\n", xn, yn);
    return 0;
}