// Write a program to implement Newton's Divided Difference table
// Exam Roll No. --> 20220PHY014

#include <stdio.h>

void findDividedDifference(float x[], float y[][10], int total_given_values);
void printDifferenceTable(float x[], float y[][10], int total_given_values);

int main()
{
    int total_given_values;
    printf("Enter total given values: ");
    scanf("%d", &total_given_values);
    float y[10][10], x[total_given_values];

    for (int i = 0; i < total_given_values; i++)
    {
        printf("Enter the value of x%d: ", i);
        scanf("%f", &x[i]);
        printf("Enter the value of f(x%d): ", i);
        scanf("%f", &y[i][0]);
        printf("\n");
    }

    findDividedDifference(x, y, total_given_values);
    printDifferenceTable(x, y, total_given_values);
    return 0;
}

void findDividedDifference(float x[], float y[][10], int total_given_values)
{
    for (int i = 1; i < total_given_values; i++)
        for (int j = 0; j < total_given_values - i; j++)
            y[j][i] = (y[j][i - 1] - y[j + 1][i - 1]) / (x[j] - x[i + j]);
}

void printDifferenceTable(float x[], float y[][10], int total_given_values)
{
    int del = 30;
    printf("x\t\tf(x)\t\t%c\t\t%c2\t\t%c3\n", del, del, del);
    for (int i = 0; i < total_given_values; i++)
    {
        printf("%f\t", x[i]);
        for (int j = 0; j < total_given_values - i; j++)
            printf("%f\t", y[i][j]);
        printf("\n");
    }
}