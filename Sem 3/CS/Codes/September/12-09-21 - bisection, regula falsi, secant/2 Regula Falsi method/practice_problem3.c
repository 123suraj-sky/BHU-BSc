// Find a real root of equation f(x)=3x-cos x-1=0 using Regula Falsi method correct to two decimal places

// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b)
{
    float y = (3 * *x) - cos(*x) - 1; // given function
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

float f(float *x)
{
    return ((3 * *x) - cos(*x) - 1);
}

int main()
{
    float a = 0.5, b = M_PI_4; // f(a) < 0 and f(b) > 0
    float approx = 0;
    int count = 0;

    while (fabs(f(&approx)) > 0.001)
    {
        count++;
        approx = ((a * f(&b)) - (b * f(&a))) / (f(&b) - f(&a));
        func(&approx, &a, &b);
        printf("approx is %f in count %d\n", approx, count);
    }
    printf("One of its root is %f in %d iterations\n", approx, count);

    return 0;
}