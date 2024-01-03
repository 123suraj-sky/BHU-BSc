/* 
Write a Program to find the cube root of a given number using Bisection method. Accuracy must be entered by the user.

Exam Roll No. --> 20220PHY014
*/

#include <stdio.h>
#include <math.h>

void func(float *x, float *a, float *b, float *num)
{
    float y = pow(*x, 3) - *num;
    if (y < 0)
        *a = *x;
    else if (y > 0)
        *b = *x;
}

float given_func(float x, float num)
{
    return pow(x, 3) - num;
}

int main()
{
    float a, b; // f(a) < 0 and f(b) > 0
    float approx, accuracy, number;
    int count = 0;

    printf("Enter the number whose cube root you want to find: ");
    scanf("%f", &number);
    printf("Enter the accuracy for the result: ", accuracy);
    scanf("%f", &accuracy);

    printf("Enter the 1st approximation a: ");
    scanf("%f", &a);
    printf("Enter the 2nd approximation b: ");
    scanf("%f", &b);

    // printf("a is %f and b is %f\n", a, b);

    while (fabs(a - b) > accuracy)
    {
        count++;
        approx = (a + b) / 2;
        func(&approx, &a, &b, &number);
        if (given_func(approx, number) == 0)
            break;
    }
    printf("\nOne of its root is %f in %d iterations\n", approx, count);

    return 0;
}