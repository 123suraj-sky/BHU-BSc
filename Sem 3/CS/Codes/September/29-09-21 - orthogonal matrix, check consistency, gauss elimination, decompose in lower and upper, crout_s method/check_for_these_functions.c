#include <stdio.h>
#include <math.h> // below functions belong to math.h

int main()
{
    int d = rint(7.12);
    d = rint(7.7);
    d = rint(7.4);
    int r = remainder(10, 3);
    printf("r is %d\n", r);
    int e = round(7.8);
    printf("d is %d\ne is %d\n", d, e);

    /*
    Other functions to check
    roundf(5.5);
    roundl(5.3);
    rintf(5.6);
    rintl(7.8);
    remainderf(5, 3);
    remainderl(5, 3);
    rmtmp();
    
    */
    return 0;
}