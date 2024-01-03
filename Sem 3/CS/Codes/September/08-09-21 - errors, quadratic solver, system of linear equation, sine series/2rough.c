#include <stdio.h>
#include <math.h>
#define TOLERANCE 0.001
// x2 - 2*x + 1 = 0

int main()
{
    float x, temp;
    int iteration = 0;
    printf("Enter intial guess of x: ");
    scanf("%f", &x); // guess should be greater than 1/2
                     // 2*x-1>0
                     // 2*x>1
                     // x>1/2

    do
    {
        iteration++;
        temp = x;
        x = sqrt(2 * x - 1);
    } while (fabs(temp - x) > TOLERANCE);

    printf("One of its root its %f in %d iterations\n", x, iteration);
    return 0;
}