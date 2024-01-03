

#include <stdio.h>
#include <math.h>
// #include <conio.h>

// #define f(x,y) (y*y-x*x)/(y*y+x*x)

float f(float x, float y)
{
    return (((2 * x * y) + exp(x)) / (pow(x, 2) + x * (exp(x))));
}

int main()
{
    float x0 = 1, y0 = 0, xn = 1.2, h, yn, k1, k2, k3, k4, k;
    int i, n = 2;
    // clrscr();
    // printf("Enter Initial Condition\n");
    // printf("x0 = ");
    // scanf("%f", &x0);
    // printf("y0 = ");
    // scanf("%f", &y0);
    // printf("Enter calculation point xn = ");
    // scanf("%f", &xn);
    // printf("Enter number of steps: ");
    // scanf("%d", &n);

    /* Calculating step size (h) */
    h = (xn - x0) / n;
    printf("h is %f\n", h);

    /* Runge Kutta Method */
    printf("\nx0\ty0\tyn\n");
    for (i = 0; i < n; i++)
    {
        k1 = h * (f(x0, y0));
        k2 = h * (f((x0 + h / 2), (y0 + k1 / 2)));
        k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
        k4 = h * (f((x0 + h), (y0 + k3)));
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        printf("%f\t%f\t%f\n", x0, y0, yn);
        x0 = x0 + h;
        y0 = yn;
    }

    /* Displaying result */
    printf("\nValue of y at x = %0.2f is %f\n", xn, yn);

    // getch();
    return 0;
}