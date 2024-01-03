#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ToleranceError 0.0001

void matrix_mul(float matrix1[3][3], float matrix2[3][1], float matrix3[3][1])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            matrix3[i][j] = 0;
            for (int k = 0; k < 3; k++)
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}
float findMax(float array[3][1])
{
    float maximum = array[0][0];
    for (int i = 0; i < 3; i++)
    {
        if (maximum < array[i][0])
            maximum = array[i][0];
    }
    return maximum;
}

int isEqual(float matrix1[3][1], float matrix2[3][1])
{
    if (matrix1[0][0] == matrix2[0][0] && matrix1[1][0] == matrix2[1][0] && matrix1[2][0] == matrix2[2][0])
        return 1;
    return 0;
}

int main()
{
    float result[3][1], eigenValue;
    // int i, j, k;

    float matrix[3][3] = {{1, 2, 0},
                          {2, 1, 0},
                          {0, 0, -1}};

    float initial_guess[3][1] = {0, 1, 0};

    while (1)
    {
        matrix_mul(matrix, initial_guess, result);
        eigenValue = findMax(result);
        for (int i = 0; i < 3; i++)
            result[i][0] /= eigenValue;

        // if (isEqual(initial_guess, result) == 1)
        //     break;
        for (int i = 0; i < 3; i++)
        {
            if ((initial_guess[i][0] - result[i][0]) < ToleranceError)
            {
                break;
            }
        }

        for (int i = 0; i < 3; i++)
            initial_guess[i][0] = result[i][0];
    }

    printf("Greatest Eigen Value = %f", eigenValue);
    printf("\nAny one of Eigen Vector: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            printf("%.2f", result[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return 0;
}