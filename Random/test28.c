#include <stdio.h>

int main()
{
    /*
        Generate result of z consisting of
        x modified bits according to the bits of m.

        bis = z to 1 where m is 1
        bic = z to 0 where m is 1

        bis:
            z = 0001 | OR
            m = 0101
                0101

            z | m

        bic:
            z = 1001
            m = 0101 | NOT
                1010 | AND
                1000

            z && ~m
    */

    int bis(int x, int m)
    {
        int result = x | m;
        return result;
    }

    int bic(int x, int m)
    {
        int result = x & ~m;
        return result;
    }

    int bis_r = bis(10, 20);
    int bic_r = bic(10, 20);

    printf("bis_r: %d \nbic_r: %d \n", bis_r, bic_r);

    return 0;
}