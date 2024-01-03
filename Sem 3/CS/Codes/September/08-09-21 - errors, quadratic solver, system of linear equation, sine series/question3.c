/*
Write a program to solve the following system of linear equations

2x+3y=6
4x+9y=15
*/

// Exam Roll No. --> 20220PHY014


#include <stdio.h>

int main()
{
    float x, y;
    int a1, b1, c1, a2, b2, c2;
    
    puts("\nEquation 1 is 2x + 3y = 6");
    puts("Equation 2 is 4x + 9y = 15");

    /* 
    For a1x + b1y + c1 = 0 & a2x + b2y + c2 = 0
    x = (c2*b1 - c1*b2) / (a1*b2 - a2*b1)
    y = (c2*a1 - c1*a2) / (a2*b1 - a1*b2)
    */

    a1 = 2, b1 = 3, c1 = -6, a2 = 4, b2 = 9, c2 = -15;

    x = (float)(c2 * b1 - c1 * b2) / (a1 * b2 - a2 * b1);
    y = (float)(c2 * a1 - c1 * a2) / (a2 * b1 - a1 * b2);

    printf("\nx = %f\n", x);
    printf("y = %f\n", y);

    return 0;
}