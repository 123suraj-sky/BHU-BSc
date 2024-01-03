#include <stdio.h>

#define MAX 100

int isOrthogonal(float a[][MAX], int m, int n) // a is the given matrix
{
    if (m != n)
        return 0;

    // Find transpose
    float transpose[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            transpose[i][j] = a[j][i];
    }

    // Find product of a[][] and its transpose
    float product[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            float sum = 0;
            for (int k = 0; k < n; k++)
                // Since we are multiplying with transpose of itself. We use
                sum += (a[i][k] * a[j][k]);
            product[i][j] = sum;
        }
    }

    // Check if product is identity matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && product[i][j] != 0)
                return 0;
            if (i == j && product[i][j] != 1)
                return 0;
        }
    }
    return 1;
}

int main()
{
    // int a[][MAX] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    float a[MAX][MAX] = {{1.0f / 3, 2.0f / 3, 2.0f / 3}, {2.0f / 3, 1.0f / 3, -2.0f / 3}, {-2.0f / 3, 2.0f / 3, -1.0f / 3}};

    if (isOrthogonal(a, 3, 3))
        puts("Yes");
    else
        puts("No");

    return 0;
}