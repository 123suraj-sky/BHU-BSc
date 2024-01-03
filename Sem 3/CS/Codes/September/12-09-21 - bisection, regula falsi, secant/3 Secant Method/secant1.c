// Find a real root of equation f(x)=x3-x-1=0 using bisection method correct to three decimal places

// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b)
{
    float y = pow(*x, 3) - (2 * *x) - 1;
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

float f(int x)
{
    return pow(x, 2) - (7 * x) + 10;
}

int main()
{
    float x[5];
    x[0] = 1.5, x[1] = 2.5;
    // float approx;
    int count = 0;
    // x[2] = x[1] + x[0];
    // printf("%f is x2\n", x[2]);
    for (int i = 1; i < 5; i++)
    {
        // x[i + 1] = ((x[i - 1] * f(i)) - (x[i] * f(i - 1))) / (f(i) - f(i - 1));

        // x[i + 1] = ((x[i - 1] * f(i)) - (x[i] * f(i - 1)));
        // x[i + 1] = f(i) - f(i - 1);
        // printf("x is %f\n", x[i + 1]);

        // printf("function %d is %f\n", i - 1, f(i - 1));
        // printf("function %d is %f\n", i, f(i));

        // printf("f(%d) - f(%d) = %f\n", i, i - 1, f(i) - f(i - 1));

        // if (f(i) == f(i-1))
        // {
        //     puts("I am batman");
        // }

        count++;
    }

    printf("count is %d\n", count);
    printf("One of its root is %f in %d iterations\n", x[count], count);

    return 0;
}