/*
Write a Program to implement Secant method and find a real root of the function f(x) = x - cos(x)

Exam Roll No. --> 20220PHY014
*/

#include <stdio.h>
#include <math.h>

float f(float x) // f is given function
{
    return (x - cos(x));
}

void secant(float initial_guess1, float initial_guess2, float tolerance)
{
    float iteration = 0, next_root, root, check;
    if (f(initial_guess1) * f(initial_guess2) < 0)
    {
        do
        {
            // calculate the intermediate value
            root = ((initial_guess1 * f(initial_guess2)) - (initial_guess2 * f(initial_guess1))) / (f(initial_guess2) - f(initial_guess1));

            // check if x3 is root of equation or not
            check = f(initial_guess1) * f(root);

            // update the value of interval
            initial_guess1 = initial_guess2;
            initial_guess2 = root;

            // update number of iteration
            iteration++;

            // if x0 is the rot of equation then break the loop
            if (check == 0)
                break;
            next_root = ((initial_guess1 * f(initial_guess2)) - (initial_guess2 * f(initial_guess1))) / (f(initial_guess2) - f(initial_guess1));
        } while (fabs(next_root - root) >= tolerance);
        printf("Root of the the given equation is: %f in %f iterations\n", root, iteration);
    }
    else
        printf("Cannot find a root in the given interval\n");
}

int main()
{
    float initial_guess1 = 0.5, initial_guess2 = M_PI_4, tolerance = 0.0001;
    secant(initial_guess1, initial_guess2, tolerance);
    return 0;
}