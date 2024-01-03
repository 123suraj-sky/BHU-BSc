#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, m, an, am;
    // float D[3][3], d[3], C[3][3];
    float C[3][3];
    float x, s[3][3], y[3];

    void LU();
    FILE *FP, *fp1;
    an = 3, am - 3;
    n = 2;

    // the matrix whose inverse to be found
    float D[3][3] = {{2, 4, 6},
                     {4, 9, 3},
                     {6, 3, 4}};

    // storing the matrix value for later camparison
    for (int m = 0; m <= 2; m++)
    {
        for (int j = 0; j <= 2; j++)
        {
            C[m][j] = D[m][j];
        }
    }

    LU(D, n);

    printf(" \nThe matrix LU decomposed\n");
    for (int m = 0; m < 2; m++)
    {
        printf("\t%f\t%f\t%f\n", D[m][0], D[m][1], D[m][2]);
    }

    // To find the inverse [D][y] = [d]
    for (int m = 0; m <= 2; m++)
    {
        // d[0] = 0.0;
        // d[1] = 0.0;
        // d[2] = 0.0;
        float d[3] = {0, 0, 0};
        d[m] = 1.0;

        for (int i = 0; i <= n; i++)
        {
            x = 0.0;
            for (int j = 0; j <= i - 1; j++)
            {
                // x = x + D[i][j] * y[j];
                x += D[i][j] * y[j];
            }
            y[i] = d[i] - x;
        }
        for (int i = n; i >= 0; i--)
        {
            x = 0.0;
            for (j = i + 1; j <= n; j++)
            {
                x += D[i][j] * s[j][m];
                // x = x + D[i][j] * s[j][m];
            }
            s[i][m] = (y[i] - x) / D[i][i];
        }
    }

    /* Print the inverse matrix */
    printf("The Inverse Matrix:\n");
    for (m = 0; m <= 2; m++)
    {
        printf("\t%f\t%f\t%f\n", s[m][0], s[m][1], s[m][2]);
    }

    /* check that  the product of the matrix with its iverse resultsis  indeed a unit matrix  */
    printf("The product\n");
    for (int m = 0; m <= 2; m++)
    {
        for (int j = 0; j <= 2; j++)
        {
            x = 0.0;
            for (int i = 0; i <= 2; i++)
            {
                // x = x + C[m][i] * s[i][j];
                x += C[m][i] * s[i][j];
            }
            printf(" %d    %d    %f \n", m, j, x);
        }
    }
    return 0;
}

void LU(float (*D)[3][3], int n)
{
    int i, j, k, m, an, am;
    float x;
    printf("The matrix \n");
    for (j = 0; j <= 2; j++)
    {
        printf("\t%f\t%f\t%f \n", (*D)[j][0], (*D)[j][1], (*D)[j][2]);
    }
    for (k = 0; k <= n - 1; k++)
    {
        for (j = k + 1; j <= n; j++)
        {
            x = (*D)[j][k] / (*D)[k][k];
            for (i = k; i <= n; i++)
            {
                (*D)[j][i] = (*D)[j][i] - x * (*D)[k][i];
            }
            (*D)[j][k] = x;
        }
    }
}