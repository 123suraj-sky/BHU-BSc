// Write a program to find the sum of the first 10 terms of a "sine series"

// sin(x) = x - x^3/3! + x^5/5! - ...

// Exam Roll No. --> 20220PHY014

#include <stdio.h>
#include <math.h>

int factorial(int num);

int main()
{
    int power = 1;          // power of x in series
    float x, temp, sum = 0; // 'x' is angle of sine and 'temp' a temporary to store x in degrees and 'sum' is the sum upto 10th term of the series

    printf("Enter x in degree: ");
    scanf("%f", &x);

    // storing x in temp to write answer in degrees
    temp = x;

    // converting x to radian
    x *= M_PI / 180;

    for (int i = 0; i < 10; i++)
    {
        sum += (pow(-1, i) * (pow(x, power) / factorial(power)));
        power += 2;
    }
    printf("sin(%f) = %f\n", temp, sum);
    return 0;
}

int factorial(int num)
{
    int fact = 1;
    for (int i = num; i > 1; i--)
        fact *= i;

    return fact;
}