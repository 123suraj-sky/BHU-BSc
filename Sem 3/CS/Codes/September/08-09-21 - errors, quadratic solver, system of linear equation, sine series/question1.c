// Write a Program to find the absolute, relative, and percentage error of a given number (2/3), take its three approximations at run time, and tell which one is the best approximation?

// Exam Roll No. --> 20220PHY014

#include <stdio.h>

int main()
{
    float givenNumber = (float)2 / 3, bestApproximation;
    float approxNumber[3], absoluteError[3], relativeError[3], percentageError[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter approximate number %d: ", i + 1);
        scanf("%f", &approxNumber[i]);

        // Absolute error
        absoluteError[i] = givenNumber - approxNumber[i];
        printf("Absolute Error: %f\n", absoluteError[i]);

        // Relative Error:
        relativeError[i] = (absoluteError[i]) / givenNumber;
        printf("Relative Error: %f\n", relativeError[i]);

        // Percentage Error:
        percentageError[i] = 100 * relativeError[i];
        printf("Percentage Error: %f\n\n", percentageError[i]);
    }

    // finding best approximation
    bestApproximation = absoluteError[0];
    for (int i = 1; i < 3; i++)
    {
        // taking magnitude of absolute error only
        if (absoluteError[i] < 0)
            absoluteError[i] = -absoluteError[i];

        // finding number with least error
        if (absoluteError[i] < absoluteError[i - 1])
            bestApproximation = approxNumber[i];
    }

    printf("\nThe best approximation is %f\n", bestApproximation);
    return 0;
}