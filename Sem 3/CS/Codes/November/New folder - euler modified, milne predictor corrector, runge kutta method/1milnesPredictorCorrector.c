#include <stdio.h>
#include <math.h>
#define MAX 7

float f(float x, float y) // f(x, y) = x + y
{
    return x + y;
}

float PicardsMethod(float x)
{
    return (1 + x + pow(x, 2) + pow(x, 3) / 3 + pow(x, 4) / 24); // returns value of 3rd iteraion
}

int main()
{
    float x[MAX], y[MAX], h, totalSteps;
    int num; // determine the value where the solution is i.e. y[num]

    printf("Enter intial value of x: ");
    scanf("%f", &x[0]);
    printf("Enter intial value of y: ");
    scanf("%f", &y[0]);
    printf("Enter the value to be found: ");
    scanf("%f", &x[MAX - 1]);
    printf("Enter step size(h): ");
    scanf("%f", &h);

    for (int i = 1; i < MAX; i++)
    {
        x[i] = x[0] + i * h;
        y[i] = PicardsMethod(x[i]);
    }

    totalSteps = (x[MAX - 1] - x[0]) / h;
    for (int i = 4; i <= totalSteps; i++)
    {
        //* Predictor
        y[i] = y[i - 4] + (4 * h / 3) * (2 * f(x[i - 3], y[i - 3]) - f(x[i - 2], y[i - 2]) + 2 * f(x[i - 1], y[i - 1]));

        //* Corrector
        y[i] = y[i - 2] + (h / 3) * (f(x[i - 2], y[i - 2]) + 4 * f(x[i - 1], y[i - 1]) + f(x[i], y[i]));
    }

    num = (x[MAX - 3] - x[0]) / h; // for x[num] = 0.2
    printf("y(%f) = %f\n", x[num], y[num]);

    num = (x[MAX - 1] - x[0]) / h; // for x[num] = 0.3
    printf("y(%f) = %f\n", x[num], y[num]);

    return 0;
}