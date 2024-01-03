#include <stdio.h>
#include <math.h>

//* Example 1
// y = x + y, y(0) = 0
// // required macros defined below:
// #define Y1(x) (1 + x + pow(x, 2) / 2)
// #define Y2(x) (1 + x + pow(x, 2) + pow(x, 3) / 6)
// #define Y3(x) (1 + x + pow(x, 2) + pow(x, 3) / 3 + pow(x, 4) / 24)
//// #define Y4(x) (1 + x + pow(x, 2) + pow(x, 3) / 3 + pow(x, 4) / 12 + pow(x, 5) / 120)3

//* Example 2
// f = x+y*y, y(0)=0
#define Y1(x) (pow(x, 2) / 2)
#define Y2(x) ((pow(x, 2) / 2) + (pow(x, 5) / 20))
#define Y3(x) ((pow(x, 2) / 2) + (pow(x, 5) / 20) + (pow(x, 8) / 160) + (pow(x, 11) / 4400))

//* main function from net
// int main()
// {
//     double start_value = 0, end_value = 1, allowed_error = 0.1, temp;
//     double y1[30], y2[30], y3[30], y4[30];
//     int count;
//     for (temp = start_value, count = 0;
//          temp <= end_value;
//          temp += allowed_error, count++)
//     {
//         y1[count] = Y1(temp);
//         y2[count] = Y2(temp);
//         y3[count] = Y3(temp);
//         y4[count] = Y4(temp);
//     }
//     printf("\nX\n");
//     for (temp = start_value;
//          temp <= end_value;
//          temp += allowed_error)
//         //  temp = temp + allowed_error)
//         printf("%lf\t", temp);
//     printf("\n\nY(1)\n");
//     for (temp = start_value, count = 0;
//          temp <= end_value;
//          temp += allowed_error, count++)
//         printf("%lf\t", y1[count]);
//     printf("\n\nY(2)\n");
//     for (temp = start_value, count = 0;
//          temp <= end_value;
//          temp += allowed_error, count++)
//         printf("%lf\t", y2[count]);
//     printf("\n\nY(3)\n");
//     for (temp = start_value, count = 0;
//          temp <= end_value;
//          temp += allowed_error, count++)
//         printf("%lf\t", y3[count]);
//     printf("\n\nY(4)\n");
//     for (temp = start_value, count = 0;
//          temp <= end_value;
//          temp += allowed_error, count++)
//         printf("%lf\t", y4[count]);
//     printf("\n");
//     return 0;
// }

//* main function by self for Example 1
int main()
{
    double x;
    printf("Enter the value where value to be found: ");
    scanf("%lf", &x);

    printf("y1 = %lf\n", Y1(x));
    printf("y2 = %lf\n", Y2(x));
    printf("y3 = %lf\n", Y3(x));

    return 0;
}