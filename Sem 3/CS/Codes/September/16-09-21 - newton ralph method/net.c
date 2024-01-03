#include <stdio.h>
#include <math.h>

float function(float);
float derivative(float);

int main()
{
    float approx_root;
    unsigned short i = 1, n;

    printf("First Approximation: ");
    scanf("%f", &approx_root);

    printf("Iterations: ");
    scanf("%hu", &n);

    while (i <= n)
    {
        approx_root = approx_root - (function(approx_root) / derivative((approx_root)));
        i++;
    }

    printf("One of its root is %f\n", approx_root);

    return 0;
}

float function(float x)
{
    return pow(x, 2) - 5;
}

float derivative(float x)
{
    return 2 * x;
}