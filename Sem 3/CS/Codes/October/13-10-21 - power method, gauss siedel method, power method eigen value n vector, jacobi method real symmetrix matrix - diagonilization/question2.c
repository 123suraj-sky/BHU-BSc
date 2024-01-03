/* 
   Write a program to implement Gauss Seidel method for system of Linear equations.
   Exam Roll No. --> 20220PHY014

   Given Equations:  20x + y - 2z = 17
                     3x + 20y - z = -18
                     2x - 3y + 20z = 25

   So, x = (17 - y + 2z) / 20
       y = (-18 - 3x + z) / 20
       z = (25 - 2x + 3y) / 20
*/
#include <stdio.h>
#include <math.h>

#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20
#define ToleranceError 0.0001

int main()
{
   float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, error_in_x, error_in_y, error_in_z; //* 0, 0, 0 is the initial guess
   int iteration = 1;
   do
   {
      x1 = f1(x0, y0, z0);
      y1 = f2(x1, y0, z0);
      z1 = f3(x1, y1, z0);
      printf("Iteration %d:\nx = %0.4f\ny = %0.4f\nz = %0.4f\n\n", iteration, x1, y1, z1);

      error_in_x = fabs(x0 - x1);
      error_in_y = fabs(y0 - y1);
      error_in_z = fabs(z0 - z1);

      iteration++;

      //* Assigning values for next iteration
      x0 = x1;
      y0 = y1;
      z0 = z1;
   } while (error_in_x > ToleranceError && error_in_y > ToleranceError && error_in_z > ToleranceError);

   printf("Solution: x = %0.3f, y = %0.3f and z = %0.3f in %d iterations\n", x1, y1, z1, iteration - 1);
   return 0;
}