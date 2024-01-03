#include <stdio.h>
#include <math.h> // only for M_PI

void main()
{
    int i, n = 10; // n is the number of terms
    float x, sum, t;

    printf(" Enter the value for x : ");
    scanf("%f", &x);

    // printf(" Enter the value for n : ");
    // scanf("%d", &n);

    x = x * M_PI / 180;
    t = x;
    sum = x;

    /* Loop to calculate the value of Sine */
    for (i = 1; i <= n; i++)
    {
        t = (t * (-1) * x * x) / (2 * i * (2 * i + 1));
        sum += t;
    }

    printf(" The value of Sin(%f) = %.4f\n", x, sum);
}