#include <stdio.h>
#include <math.h>

#define TOLERANCE 0.000001

float f(float);
float derivative(float);

int main()
{
    float approxRoot;
    unsigned short iteration = 0, maxIteration;

    printf("\n*** Program to find cube root of 5 ***\n\n");
    printf("First Approximation: ");
    scanf("%f", &approxRoot);

    printf("Maximum Iterations: ");
    scanf("%hu", &maxIteration);

    while (iteration <= maxIteration)
    {
        approxRoot -= (f(approxRoot) / derivative((approxRoot)));

        // break from the loop when we get the result upto certain TOLERANCE
        if (f(approxRoot) <= TOLERANCE)
            break;
        iteration++;
    }

    // if the first approxRoot is very far away from actual root or TOLERANCE limit not matched
    if (f(approxRoot) >= TOLERANCE)
        puts("\nYou need to enter more number of iteration to get the roots.\nPlease try again!!");
    else
        printf("\nOne of its root is %f in %hu iterations\n", approxRoot, iteration);

    return 'a';
}

float f(float x)
{
    return pow(x, 2) - 5; // f(x) = x^2 - 5
}

float derivative(float x) // f'(x) = 2x
{
    return 2 * x;
}