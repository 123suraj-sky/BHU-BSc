// Write a program to find the root of a Quadratic equation using the Formula method

// Exam Roll No. --> 20220PHY014

#include <stdio.h>
#include <math.h>

int main()
{
    printf("*** Programme to find all roots of quadratic equation ***\n\n");
    int a, b, c;
    int d; // discriminent

    printf("Enter the values of a, b, c:-\n");
    scanf("%d%d%d", &a, &b, &c);

    printf("\nYour quadratic equation is %dx^2 + %dx + %d\n", a, b, c);
    d = ((pow(b, 2)) - (4 * a * c));

    float r1, r2; // 'r1', 'r2' means roots
    r1 = (-b + pow(d, 0.5)) / (2 * a);
    r2 = (-b - pow(d, 0.5)) / (2 * a);

    if (d > 0)
        printf("\nThis equation have real roots\nAnd its roots are %f and %f\n", r1, r2);
    else if (d == 0)
        printf("\nThis equation have equal roots\nAnd its equal root is %f\n", r1);
    else
    {
        printf("\nThis equation have imaginary roots\nAnd its roots are (-%d + %.2fi) / (%d)\n", b, sqrt(-d), 2 * a);
        printf("and (-%d - %.2fi) / (%d)\n", b, sqrt(-d), 2 * a);
    }
    return 0;
}

/*
x2 - 2*x + 1 = 0
x2 = 2*x - 1
x = sqrt(2*x-1)
*/