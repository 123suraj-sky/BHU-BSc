// Given equation is x^3 + x - 1

#include <stdio.h>
#include <math.h>

float f(float x) // f is given function
{
    return pow(x, 3) + x - 1;
}

void secant(float x1, float x2, float tolerance)
{
    float iteration = 0, next_root, root, check;
    if (f(x1) * f(x2) < 0)
    {
        do
        {
            // calculate the intermediate value
            root = ((x1 * f(x2)) - (x2 * f(x1))) / (f(x2) - f(x1));

            // check if x3 is root of equation or not
            check = f(x1) * f(root);

            // update the value of interval
            x1 = x2;
            x2 = root;

            // update number of iteration
            iteration++;

            // if x0 is the rot of equation then break the loop
            if (check == 0)
                break;
            next_root = ((x1 * f(x2)) - (x2 * f(x1))) / (f(x2) - f(x1));
        } while (fabs(next_root - root) >= tolerance);
        printf("Root of the the given equation is: %f in %f iterations\n", root, iteration);
    }
    else
        printf("Cannot find a root in the given interval\n");
}

int main()
{
    float x1 = 0, x2 = 1, tolerance = 0.0001;
    secant(x1, x2, tolerance);
    return 0;
}