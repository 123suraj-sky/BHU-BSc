#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) x *x *x - 2 * x - 5 // x*x*x - 2*x - 5

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int step = 0, N;

    printf("Enter initial guesses: ");
    scanf("%f%f", &x0, &x1);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    do
    {
        f0 = f(x0);
        f1 = f(x1);
        if (f0 == f1)
        {
            printf("Mathematical Error!!");
            exit(0);
        }
        x2 = x1 - (x1 - x0) * f1/(f1-f0);
        f2 = f(x2);
        x0 = x1;
        f0 = f1;
        x1 = x2;
        f1 = x2;

        step++;

        if (step > N)
        {
            printf("Not Convergentn");
            exit(0);
        }
    } while (fabs(f2)>e);
    
    printf("root is %f\n", x2);
    return 0;
}