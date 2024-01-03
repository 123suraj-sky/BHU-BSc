#include <stdio.h>

#define f1(x, y) x *y
#define f2(x, y) y + x *f1(x, y)

int main()
{
    float func1 = f1(2, 5);
    float func2 = f2(2, 5);

    printf("func1 is %f\n", func1);
    printf("func2 is %f\n", func2);


    return 0;
}