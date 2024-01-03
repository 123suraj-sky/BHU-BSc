// Write a program to implement Gauss elimination method
// Exam Roll No. - 20220PHY014

#include <stdio.h>
#include <math.h>

#define N 3

int forwardElim(double mat[N][N + 1]); // tells whether a matrix is singular or not
void backSub(double mat[N][N + 1]);
void gaussianElimination(double mat[N][N + 1]);
void swap_row(double mat[N][N + 1], int i, int j);
void print(double mat[N][N + 1]);

int main()
{
    double mat[N][N + 1] = {{3, 2, -4, 3},   // 3x + 2y - 4z = 3
                            {2, 3, 3, 15},   // 2x + 3y + 3z = 15
                            {5, -3, 1, 14}}; // 5x - 3y + z = 14

    gaussianElimination(mat);

    return 0;
}

void gaussianElimination(double mat[N][N + 1])
{
    int singularFlag = forwardElim(mat);

    if (singularFlag != -1) // if matrixis singular
    {
        printf("Singular Matrix\n");

        if (mat[singularFlag][N]) // if the RHS of equation corresponding to zero row is 0, system has infinitely many solutios, else inconsistent
            printf("Inconsistent System\n");
        else
            printf("May have infinitely many solutions\n");
        return;
    }
    backSub(mat); // get solution to system and print it using backward subsitution
}

void swap_row(double mat[N][N + 1], int i, int j)
{
    for (int k = 0; k <= N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

void print(double mat[N][N + 1])
{
    for (int i = 0; i < N; i++, printf("\n"))
    {
        for (int j = 0; j <= N; j++)
            printf("%lf ", mat[i][j]);
    }
    printf("\n");
}

int forwardElim(double mat[N][N + 1])
{
    for (int k = 0; k < N; k++)
    {
        // Initialize maximum value and index for pivot
        int iMax = k;
        int vMax = mat[iMax][k];

        for (int i = k + 1; i < N; i++) // find greater amplitude for pivot if any
        {
            if (abs(mat[i][k]) > vMax)
                vMax = mat[i][k], iMax = i;
        }

        if (!mat[k][iMax]) // if a prinicipal diagonal element is zero, it denotes that matrix is singular, and will lead to a division by zero later
            return k;       // matrix is singular

        if (iMax != k) // Swap the greatest value row with current row
            swap_row(mat, k, iMax);

        for (int i = k + 1; i < N; i++)
        {
            double f = mat[i][k] / mat[k][k]; // factor f to set current row kth element to 0, and subsequentl remaining kth column to 0

            for (int j = k + 1; j <= N; j++) // subtract fth multiple of corresponding kth row element
                mat[i][j] -= (mat[k][j] * f);

            mat[i][k] = 0; // filling lower triangular matrix with zeros
        }
    }
    return -1;
}

void backSub(double mat[N][N + 1])
{
    double x[N]; // An array to store solution

    for (int i = N - 1; i >= 0; i--) // start calculating from last equation up to the first
    {
        x[i] = mat[i][N]; // start with the RHS of the equation

        for (int j = i + 1; j < N; j++) // Initialize j to i+1 since matrix is upper triangular
            x[i] -= mat[i][j] * x[j];   // subtract all the lhs values except the coefficient of the variable whose value is being calculated

        x[i] /= mat[i][i]; // divide the RHS by the coefficient of the unknown being calculated
    }
    printf("\nSolution for the system:\n");
    for (int i = 0; i < N; i++)
        printf("%lf\n", x[i]);
}