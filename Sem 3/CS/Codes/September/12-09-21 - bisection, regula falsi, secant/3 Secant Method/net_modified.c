#include <stdio.h>
#include <math.h>

#define F(x) (((x) * (x)) - (4 * (x)) - 10) // outer bracket is must
// F(x) = x*x - 4*x - 10

int main()
{
    float x1, x2, x3, f1, f2, tolerance;
    int iteration = 0;
    printf("Enter the approx range of roots: ");
    scanf("%f%f", &x1, &x2);

    do
    {
        iteration++;

        x3 = ((x1 * F(x2)) - (x2 * F(x1))) / (F(x2) - F(x1));
        x1 = x2;
        x2 = x3;

        tolerance = fabs(F(x2)); // as F(x2) tending to 0
    } while (tolerance > 0.001);

    printf("\nOne of its root is %f in %d iterations\n", x3, iteration);
    return 0;
}