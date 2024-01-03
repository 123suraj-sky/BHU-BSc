// Write a Program to implement Simpson's 1/3 rule for finding the integral of a given function
// 20220PHY014

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1 / (1 + pow(x, 2));
}

int main()
{
    float lower_limit, upper_limit, sum, h, f(float);
    int equal_width;
    
    printf("Enter the lower limit: ");
    scanf("%f", &lower_limit);
    printf("Enter the upper limit: ");
    scanf("%f", &upper_limit);

    printf("Enter the value of equal width: ");
    scanf("%d", &equal_width);

    h = (upper_limit - lower_limit) / equal_width;

    sum = f(lower_limit) + f(upper_limit);
    for (int i = 1; i < equal_width; i++)
    {
        if (i % 2 == 0)
            sum += 2 * f(lower_limit + i * h);
        else
            sum += 4 * f(lower_limit + i * h);
    }
    sum *= (h / 3);

    printf("The value of integration is: %f\n", sum);
    return 0;
}