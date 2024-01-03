// Write a program to implement Jacobi method for diagonalization of real symmetric matrix.
// Exam Roll No. --> 20220PHY014

#include <stdio.h>
#include <math.h>

#define N 2               //notes: N is number of loops
#define Tolerance 0.00001 //notes: Tolerance for the accuracy of the result

float x, angle, large, sum = 0; //notes: large for finding largest element in matrix and sum used in product of matrix
int iNew = 0, jNew = 0;         //notes: corresponding to largest element in matrix

void findingResult(float a_mat[3][3], float b_mat[3][3], float b_inv_mat[3][3], float b_inv_a[3][3], float d_b_inv_a_b[3][3]);
void productMatrix(float mat1[3][3], float mat2[3][3], float product[3][3]);
void displayMatrix(float mat[3][3]);

int main()
{
    float bMatrix[3][3], bInverse[3][3], b_inverse_a[3][3], final[3][3];
    float aMatrix[3][3] = {{1, 1.41421, 2},
                           {1.41421, 3, 1.41421},
                           {2, 1.41421, 1}};
    for (int i = 0; i < N; i++)
    {
        printf("Iteration %d:\n", i + 1);

        //* finding largest element
        large = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if ((i != j) && (aMatrix[i][j] >= large))
                {
                    large = aMatrix[i][j];
                    iNew = i, jNew = j;
                }
            }
        }

        //* finding angle for orthogonal matrix
        if (aMatrix[iNew][iNew] == aMatrix[jNew][jNew])
            angle = M_PI_4;
        else
        {
            x = (2 * aMatrix[iNew][jNew]) / (aMatrix[iNew][iNew] - aMatrix[jNew][jNew]);
            angle = atan(x) / 2;
        }

        //* assigning orthogonal matrices --> if the matrix is symmetric then there are only 3(each has one symmetric) possible position for largest off-diagonal element
        if (iNew == 1 && jNew == 0)
        {
            float bMatrix[3][3] = {{cos(angle), -sin(angle), 0},
                                   {sin(angle), cos(angle), 0},
                                   {0, 0, 1}};

            float bInverse[3][3] = {{cos(angle), sin(angle), 0},
                                    {-sin(angle), cos(angle), 0},
                                    {0, 0, 1}};

            findingResult(aMatrix, bMatrix, bInverse, b_inverse_a, final);
        }
        else if (iNew == 2 && jNew == 0)
        {
            float bMatrix[3][3] = {{cos(angle), 0, -sin(angle)},
                                   {0, 1, 0},
                                   {sin(angle), 0, cos(angle)}};

            float bInverse[3][3] = {{cos(angle), 0, sin(angle)},
                                    {0, 1, 0},
                                    {-sin(angle), 0, cos(angle)}};

            findingResult(aMatrix, bMatrix, bInverse, b_inverse_a, final);
        }
        else if (iNew == 2 && jNew == 1)
        {
            float bMatrix[3][3] = {{1, 0, 0},
                                   {0, cos(angle), -sin(angle)},
                                   {0, sin(angle), cos(angle)}};

            float bInverse[3][3] = {{1, 0, 0},
                                    {0, cos(angle), sin(angle)},
                                    {0, -sin(angle), cos(angle)}};

            findingResult(aMatrix, bMatrix, bInverse, b_inverse_a, final);
        }

        //* Assigning new matrix A equals to the final previous matrix
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                aMatrix[i][j] = final[i][j];
        }

        if (i == (N - 1))
        {
            int k = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if ((i != j) && (aMatrix[i][j] >= Tolerance))
                        k++;
                }
            }
            if (k != 0) // if the resultant matrix not match the required Tolerance
                printf("Try with more number of loops to get more accurate result\n");
        }
    }
    return 0;
}

void findingResult(float a_mat[3][3], float b_mat[3][3], float b_inv_mat[3][3], float b_inv_a[3][3], float d_b_inv_a_b[3][3])
{
    sum = 0;
    productMatrix(b_inv_mat, a_mat, b_inv_a);

    sum = 0;
    productMatrix(b_inv_a, b_mat, d_b_inv_a_b);

    printf("Matrix A is:\n");
    displayMatrix(a_mat);
    printf("Matrix D is:\n");
    displayMatrix(d_b_inv_a_b);
}

void productMatrix(float mat1[3][3], float mat2[3][3], float product[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
                sum += mat1[i][k] * mat2[k][j];
            product[i][j] = sum;
            sum = 0;
        }
    }
}

void displayMatrix(float mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%-6f\t", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}