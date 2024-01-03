/* 
Write a Program to implement Newton Raphson method and find a real root of the funciton f(x) = x - cos(x)

Exam Roll No. --> 20220PHY014
*/

#include <stdio.h>
#include <math.h>

#define tolerance 0.001

float function(float);
float derivative(float);

int main()
{
    float approx_root;
    unsigned short iteration = 0, max_iteration;

    printf("Enter your approximation: ");
    scanf("%f", &approx_root);

    printf("Maximum Iterations: ");
    scanf("%hu", &max_iteration);

    while (iteration <= max_iteration)
    {
        approx_root = approx_root - (function(approx_root) / derivative((approx_root)));

        // break from the loop when we get the result upto certain tolerance
        if (function(approx_root) <= tolerance)
            break;

        iteration++;
    }

    printf("\nOne of its root is %f in %hu iterations\n", approx_root, iteration);

    // if the first approx_root is very far away from actual root or tolerance limit not matched
    if (function(approx_root) >= tolerance)
        puts("\nThis is not the final/correct root.\nYou need to enter more number of iteration\nPlease try again!!");

    return 0;
}

float function(float x)
{
    return (x - cos(x)); // f(x) = x - cos(x)
}

float derivative(float x) // f'(x) = 1 + sin(x)
{
    return (1 + sin(x));
}