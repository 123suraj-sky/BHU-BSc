/*
Write a Program to find a real root of the function f(x) = x - cox(x), using Regula Falsi method.

Exam Roll No. --> 20220PHY014
*/

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b)
{
    float y = (*x) - cos(*x);
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

float given_func(float *x)
{
    return (*x) - cos(*x);
}

int main()
{
    float a = 0.5, b = M_PI_4; // f(a) < 0 and f(b) > 0
    float approx = 0;
    int count = 0;

    while (fabs(given_func(&approx)) > 0.001)
    {
        count++;
        approx = ((a * given_func(&b)) - (b * given_func(&a))) / (given_func(&b) - given_func(&a));
        func(&approx, &a, &b);
    }
    printf("One of its root is %f in %d iterations\n", approx, count);

    return 0;
}