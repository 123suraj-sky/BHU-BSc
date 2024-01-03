#include <stdio.h>
#include <math.h>

int main()
{
    float x = 0.36;
    float y = (x * pow(M_E, x)) - 1;
    
    printf("y is %f\n", y);

    return 0;
}