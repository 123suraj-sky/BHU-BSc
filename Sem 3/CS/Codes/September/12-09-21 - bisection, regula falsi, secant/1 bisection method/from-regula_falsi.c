// Find a real root of equation f(x)=3x - cos x - 1 = 0 using bisection method correct to two decimal places

// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b)
{
    float y = (3 * *x) - cos(*x) - 1;
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

float absoulte_difference(float a, float b)
{
    float absolute = a - b;
    if (absolute > 0)
        return absolute;
    else
        return -1 * absolute;
}

int main()
{
    float a = 0.5, b = M_PI_4; // f(a) < 0 and f(b) > 0
    float approx;
    int count = 0;

    while (absoulte_difference(a, b) > 0.001)
    {
        count++;
        approx = (a + b) / 2;
        printf("approx is %f\n", approx);
        func(&approx, &a, &b);
    }
    printf("One of its root is %f in %d iterations\n", approx, count);

    return 0;
}