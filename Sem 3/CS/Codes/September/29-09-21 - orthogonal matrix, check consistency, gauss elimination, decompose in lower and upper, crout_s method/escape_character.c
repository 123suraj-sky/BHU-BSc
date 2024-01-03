#include <stdio.h>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        printf("%d, ", a[i]);
    printf("\b\b");
    // printf("\n");

    // int ab = 5;
    // printf("ab is %d", ab);
    // printf("\b");

    return 0;
}