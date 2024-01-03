#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x - 4; // x^2 - 4
}

int main()
{
    int iteration = 0, maxSteps;
    double x1, x2, x3, eps;
    printf("Enter the accuracy desired: \n");
    scanf("%lf", &eps);
    printf("Enter the initial guesses: \nx1 = ");
    scanf("%lf", &x1);
    printf("x2 = ");
    scanf("%lf", &x2);
    printf("Enter the max number of iterations to be performed: ");
    scanf("%d", &maxSteps);

    do
    {
        x3 = ((x1 * f(x2)) - (x2 * f(x1))) / (f(x2) - f(x1));
        x1 = x2;
        x2 = x3;
        iteration++;
    } while (fabs(f(x3)) > eps && iteration <= maxSteps);

    printf("One of its root is: %lf in %d iterations\n", x3, iteration);
    return 0;
}