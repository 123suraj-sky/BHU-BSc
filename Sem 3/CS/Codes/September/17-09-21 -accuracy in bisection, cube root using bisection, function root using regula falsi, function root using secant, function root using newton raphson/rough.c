#include <stdio.h>
#include <math.h>

int main()
{
    float x = M_PI_4;
    float y = (x)-cos(x);

    printf("y is %f\n", y);
    printf("fabs(x) = %f\n", fabs(x));
    printf("fabs(x) = %f\n", fabs(x - y));

    return 0;
}