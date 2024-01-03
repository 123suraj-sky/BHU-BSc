#include <stdio.h>
#include <math.h>

#define slope(x, y) (2 * x + cos(y))
#define tolerance 0.005

float mod(float x1, float x2)
{
    if (x1 > x2)
        return x1 - x2;
    return x2 - x1;
}

float eulerMethod(float x0, float y0, float h, float yn, float numberOfSteps)
{
    for (int i = 0; i < numberOfSteps; i++)
    {
        yn = y0 + h * slope(x0, y0);
        y0 = yn;
        x0 += h;
    }
    return yn;
}

float eulerModifiedMethod(float x0, float y0, float h, float yn, float numberOfSteps)
{
    float temp;
    do
    {
        for (int i = 0; i < numberOfSteps; i++)
        {
            yn = y0 + (h / 2) * (slope(x0, y0) + slope(numberOfSteps * h + x0, eulerMethod(x0, y0, h, yn, numberOfSteps)));
            y0 = yn;
            x0 += h;
        }
        temp = yn;
        eulerModifiedMethod(x0, y0, h, yn, numberOfSteps);
        printf("y0 is %f\nyn is %f\n", y0, yn);
    } while (mod(yn, temp) > tolerance);
    return yn;
}

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

    printf("\nf(%f) = %f\n", xn, eulerModifiedMethod(x0, y0, h, yn, number_of_steps));
    return 0;
}