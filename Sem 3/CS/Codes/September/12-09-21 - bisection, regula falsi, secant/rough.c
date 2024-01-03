#include <stdio.h>
#include <math.h>

int absolute(int *x)
{
    if (*x < 0)
    {
        *x = *x * -1;
        return *x;
    }
    else
        return *x;
}

int main()
{
    // int a = 4, b = 1;
    // printf("abs() is %d\n", abs(a - b));

    // float x;
    // puts("enter x ");
    // scanf("%f", &x);
    // // int y = pow(x, 3) - (2 * x) - 5;
    // float y = (x * pow(M_E, x)) - 1;
    // printf("y is %f\n", y);

    int a = -2, b = -1;
    printf("a is %d\n", abs(a));
    printf("b is %d\n", abs(b));
    printf("a is %d\n", absolute(&a));
    printf("b is %d\n", absolute(&b));
    return 0;
}