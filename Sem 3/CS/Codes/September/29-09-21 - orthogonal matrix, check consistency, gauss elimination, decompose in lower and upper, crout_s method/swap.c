#include <stdio.h>

int main()
{
    int a = 3, b = 5;
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("a is %d\nb is %d\n", a, b);

    return 0;
}