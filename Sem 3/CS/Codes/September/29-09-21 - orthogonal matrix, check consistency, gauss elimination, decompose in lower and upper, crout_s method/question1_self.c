#include <stdio.h>

int main()
{
    // Take matrix input
    int n;
    int matrix[n][n];

    transpose(matrix);
    multiply(matrix, transpose(matrix));
    check_with_identity(multiply(matrix, transpose(matrix)));

    return 0;
}