#include <stdio.h>
#include <math.h>

#define MAX 20

float func(float x, float y)
{
    return -x * y * y;
}

float eulerMethod(float x0, float y0, float h, float yn, float numberOfSteps)
{
    for (int i = 0; i < numberOfSteps; i++)
    {
        yn = y0 + h * func(x0, y0);
        y0 = yn;
        x0 += h;
    }
    return yn;
}

int main()
{
    float x0, y0, xn, yn, h, yn_temp, numberOfSteps;

    x0 = 0;
    y0 = 2;
    h = 0.1;
    xn = 0.2;
    // yn_temp = 1.136140;

    numberOfSteps = (xn - x0) / h;

    yn = eulerMethod(x0, y0, h, yn_temp, numberOfSteps);
    yn_temp = yn;

    printf("Euler is %f\n", yn);

    yn = y0 + (h / 2) * (func(x0, y0) + func(xn, eulerMethod(x0, y0, h, yn_temp, numberOfSteps)));
    printf("Euler modified is %f\n", yn);

    return 0;
}