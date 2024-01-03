#include <stdio.h>
// #include <conio.h>
#include <math.h>

long int factorial(int n);

int main()
{
    int x;
    float sum, r;
    char c;

    printf("You have this series:-1+x/1! + x^2/2! + x^3/3! + x^4/4!..x^x/x!");
    printf("To which term you want its sum of ?  ");
    scanf("%d", &x);
    sum = 0;
    for (int i = 1; i <= x; i++)
        sum = sum + ((float)pow(x, i) / (float)factorial(i));

    printf("The sum of %d terms is %f", x, 1 + sum);

    fflush(stdin);
    // getch();
}

long int factorial(int n)
{
    if (n <= 1)
        return (1);
    else
        n = n * factorial(n - 1);
    return (n);
}