#include <stdio.h>
#include <math.h>

float f(float x)
{
    printf("y is %f\n", pow(x, 3) - (4 * x) - 9);
    return pow(x, 3) - (4 * x) - 9;
}

int main()
{
    float y, approx, a, b;
    a = 2, b = 3;
    // y = pow(x, 3) - (4 * x) - 9;
    // printf("y is %f\n", y);

    approx = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
    printf("approx is %f\n", approx);
    return 0;
}
/*


*/