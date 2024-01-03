#include <stdio.h>
#include <conio.h>
#include <math.h>

#define ESP 0.0001
#define F(x) (x) * (x)-4 * (x)-10

int main()
{
    float x1, x2, x3, f1, f2, t;
    // clrscr();
    printf("Enter the value of x1: ");
    scanf("%f", &x1);
    printf("Enter the value of x2: ");
    scanf("%f", &x2);
    printf("\n-----------------------------------------------------------------------------\n");
    printf("\nx1\tx2\tx3\tf(x1)\tf(x2)");
    printf("\n\n-----------------------------------------------------------------------------\n");

    do
    {
        f1 = F(x1);
        f2 = F(x2);
        // x3 = x2 - ((f2 * (x2 - x1)) / (f2 - f1));
        x3 = ((x1 * f2) - (x2 * f1)) / (f2 - f1);
        printf("\n%f\t%f\t%f\t%f\t%f\n", x1, x2, x3, f1, f2);
        x1 = x2;
        x2 = x3;
        if (f2 < 0)
        {
            t = fabs(f2);
        }
        else
        {
            t = f2;
        }
    } while (t > ESP);
    printf("\n-----------------------------------------------------------------------------\n");
    printf("One of its root is %f\n", x3);

    return 0;
}