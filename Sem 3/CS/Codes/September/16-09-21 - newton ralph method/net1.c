#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Defining equation to be solved.
// Change this equation to solve another problem
#define f(x) 3 * x - cos(x) - 1

// Defining derivative of g(x)
// As you change f(x), change this function also
#define g(x) 3 + sin(x)

int main()
{
    float x0, x1, f0, f1, g0, e;
    int step = 0, N;

    printf("Enter initial guess: \n");
    scanf("%f", &x0);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iteration:\n");
    scanf("%d", &N);

    // Implementing Newton Raphson Method
    do
    {
        g0 = g(x0);
        f0 = f(x0);
        if (g0 == 0)
        {
            puts("Mathematical Error!!");
            exit(0);
        }

        x1 = x0 - f0 / g0;

        x0 = x1;
        step++;
        if (step > N)
        {
            puts("Not convergent");
            exit(0);
        }
        f1 = f(x1);

    } while (fabs(f1) > e);

    printf("One of its root is %f in %d iterations\n", x1, step);

    return 0;
}