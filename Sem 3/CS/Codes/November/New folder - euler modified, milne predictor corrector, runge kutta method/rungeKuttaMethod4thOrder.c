#include <stdio.h>
#include <math.h>

double f(double x, double y)
{
    return ((pow(y, 2) - pow(x, 2)) / (pow(y, 2) + pow(x, 2)));
}

void main()
{
    double x, y, x0, y0, h, k1, k2, k3, k4;
    printf("Enter the initial condition for y: ");
    scanf("%lf", &y0);
    printf("Enter the initial condition for x: ");
    scanf("%lf", &x0);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf", &x);
    printf("Enter the step-width h: ");
    scanf("%lf", &h);
    printf("\nx\t\ty\t\tk1\t\tk2\t\tk3\t\tk4\n");
    printf("________________________________________________________________________________________\n");

    while ((x - x0) > 0.0000000001)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2.0, y0 + k1 / 2.0);
        k3 = h * f(x0 + h / 2.0, y0 + k2 / 2.0);
        k4 = h * f(x0 + h, y0 + k3);
        printf("%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", x0, y0, k1, k2, k3, k4);

        y = y0 + 1 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

        // Updating Values
        y0 = y;
        x0 += h;
    }

    printf("%lf\t%lf\n", x0, y0);
    printf("________________________________________________________________________________________\n");
    printf("\ny(%lf) = %lf\n\n", x, y);
}