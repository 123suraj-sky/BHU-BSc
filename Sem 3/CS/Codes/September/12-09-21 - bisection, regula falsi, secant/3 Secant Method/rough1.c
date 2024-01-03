#include <stdio.h>

#define F(x) (((x) * (x)) - (4 * (x)) - 10) // outer bracket is necessary
// F(x) = x*x - 4*x - 10

int main()
{
    float x1 = 5, x2 = 6, x3;
    x3 = x1 * F(x2);
    // (F(x2) - F(x1));

    // F(x1) = -5
    // F(x2) = 2
    // 10 - -30 = 40

    printf("x3 is %f\n", x3);

    return 0;
}