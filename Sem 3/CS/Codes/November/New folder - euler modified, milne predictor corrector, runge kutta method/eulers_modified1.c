#include <stdio.h>
#include <math.h>

// consider the differetial equation for a given x and y will return v
double f(double x, double y)
{
    double v = y - 2 * x * x + 1;
    return v;
}

// predicts the next value for a given (x,y) and step size h using Euler method
double predict(double x, double y, double h)
{
    // value of next y(predicted) is returned
    double y1p = y + h * f(x, y);
    return y1p;
}

// corrects the predicted value using Modified Euler method
double correct(double x, double y, double x1, double y1, double h)
{
    // (x,y) are of previous step and x1 is the increased x for next step and y1 is predicted y for next step
    double e = 0.00001;
    double y1c = y1;
    do
    {
        y1 = y1c;
        y1c = y + 0.5 * h * (f(x, y) + f(x1, y1));
    } while (fabs(y1c - y1) > e); // every iteration is correcting the value of y using average slope
    return y1c;
}

void printFinalValues(double x, double xn, double y, double h)
{
    int i = 1;
    while (x < xn)
    {
        double x1 = x + h;
        double y1p = predict(x, y, h);
        double y1c = correct(x, y, x1, y1p, h);

        printf("Iteration %d:\nPredicted value = %lf\nCorrected Value = %lf\n\n", i, y1p, y1c);
        i++;

        x = x1;
        y = y1c;
    }
    // at every iteration first the value of for next step is first predicted and then corrected
    printf("The final value of y at x = %lf is: %lf\n", x, y);
}

// void printFinalValues(double x, double xn, double y, double h)
// {
//     while (x < xn)
//     {
//         double x1 = x + h;
//         double y1p = predict(x, y, h);
//         double y1c = correct(x, y, x1, y1p, h);
//         x = x1;
//         y = y1c;
//     }
//     // at every iteration first the value of for next step is first predicted and then corrected
//     printf("The final value of y at x = %lf is: %lf\n", x, y);
// }

int main()
{
    // here x and y are the initial given condition, so x = 0 and y = 0.5
    double x = 0, y = 0.5;

    // final value of x for which y is needed
    double xn = 1;

    // step size
    double h = 0.2;

    printFinalValues(x, xn, y, h);

    return 0;
}