#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Defining equation to be solved
#define f(x) 3 * x - cos(x) - 1

// Defining derivative of g(x)
#define g(x) 3 + sin(x)

int main()
{
    float initial_guess, approx_root, f0, f1, g0, tolerance;
    int iteration = 0, max_iteration;

    printf("Enter initial guess: ");
    scanf("%f", &initial_guess);
    printf("Enter tolerable error: ");
    scanf("%f", &tolerance);
    printf("Enter maximum iteration: ");
    scanf("%d", &max_iteration);

    // Implementing Newton Raphson Method
    do
    {
        g0 = g(initial_guess);
        f0 = f(initial_guess);

        // use below code only if there is possibility of g0 = 0
        // if (g0 == 0)
        // {
        // puts("Mathematical Error!!\nAs number divided by zero is not defined\nTry with different initial guess");
        //     exit(0);
        // }

        approx_root = initial_guess - (f0 / g0);
        initial_guess = approx_root;
        iteration++;

        if (iteration > max_iteration)
        {
            puts("\nNot convergent in this interval\nPlease try again!!");
            exit(0);
        }

        f1 = f(approx_root);
    } while (fabs(f1) > tolerance);

    printf("\nOne of its root is %f in %d iterations\n", approx_root, iteration);

    return 0;
}