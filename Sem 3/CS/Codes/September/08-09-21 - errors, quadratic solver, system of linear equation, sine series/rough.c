#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int power = pow(-1, i);
        printf("%d\n", power);

        // float sum = 0;
        // int power = 1;
        // for (int i = 0; i < 5; i++)
        // {
        //     printf("pow is %f\n", pow(2, power));
        //     power += 2;
        //     printf("power is %d\n", power);
        // }
        // printf("%f\n", M_PI/6);
        // printf("%f\n", (float)pow(3.14, 3));
    }

    int a = pow(-1, 2);
    printf("a is %d\n", a);
    return 0;
}