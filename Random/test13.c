#include <stdio.h>
#include <stdlib.h>

/* Handle leap years */
static char *daytab[2];

int main()
{
    int i, j, mday = 31;
    
    for(i = 0; i < 2; i++) {
        daytab[i] = (char *)malloc(sizeof(char));

        for(j = 0; j < 12; j++) {
            
            if(j == 0)
                mday = 0;
            else {
                if(j % 2 == 1)
                    mday = 31;
                else
                    mday = 30;
            }
            
            if(j == 1) {
                if(i == 0)
                    mday = 28;
                else
                    mday = 29;
            }
            
            daytab[i][j] = mday;
        }
    }
    
    printf("%d \n", daytab[0][1]);
    return 0;
}