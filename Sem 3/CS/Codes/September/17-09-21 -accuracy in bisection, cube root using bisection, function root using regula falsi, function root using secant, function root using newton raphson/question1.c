/* 
Write a Program to find the number of iterations required to obtain a desired level of accuracy in Bisection(Take the necessary inputs required)

Exam Roll No. --> 20220PHY014
*/

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b)
{
    float y = pow(*x, 3) - (*x) - 1;
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

int main()
{
    float a = 1, b = 2; // f(a) < 0 and f(b) > 0
    float approx;
    int count = 0;

    while (fabs(a - b) > 0.001)
    {
        count++;
        approx = (a + b) / 2;
        func(&approx, &a, &b);
    }
    printf("One of its root is %f in %d iterations\n", approx, count);

    return 0;
}