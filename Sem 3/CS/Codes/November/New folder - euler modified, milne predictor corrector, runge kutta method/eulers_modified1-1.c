#include <stdio.h>
#include <math.h>
#define TOLERANCE 0.00001

double f(double x, double y)
{
    return y - 2 * x * x + 1;
}

void EulersModifiedMethod(double x0, double xn, double y0, double h)
{
    int iteration = 1;
    while (x0 < xn)
    {
        double x1, y1Predicted, y1Corrected;

        x1 = x0 + h;                      // Next iteration
        y1Predicted = y0 + h * f(x0, y0); // Finds y1Corrected

        // Finds y1Corrected
        y1Corrected = y1Predicted;
        do
        {
            y1Predicted = y1Corrected;
            y1Corrected = y0 + 0.5 * h * (f(x0, y0) + f(x1, y1Predicted));
        } while (fabs(y1Corrected - y1Predicted) > TOLERANCE);

        printf("\nIteration %d:\nPredicted value = %lf\nCorrected Value = %lf\n", iteration, y1Predicted, y1Corrected);
        iteration++;

        // Updating value for next iteration
        x0 = x1;
        y0 = y1Corrected;
    }
    printf("\nThe final value of y at x = %lf is: %lf\n", x0, y0);
}

int main()
{
    double x0, y0, xn, h;
    printf("Enter the intial value of x: ");
    scanf("%lf", &x0); // x = 0
    printf("Enter the intial value of y: ");
    scanf("%lf", &y0); // y = 0.5
    printf("Enter the value to be found: ");
    scanf("%lf", &xn); // xn = 1
    printf("Enter the step size(value of h): ");
    scanf("%lf", &h); // h = 0.2

    EulersModifiedMethod(x0, xn, y0, h);

    return 0;
}