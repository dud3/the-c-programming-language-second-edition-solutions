#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{   
    char *c = "-10";
    int i = atoi(c);
    printf("%d\n", i);
    
    if(0) {
        printf("Condition: %d \n", 0);   
    } else {
        printf("Condition: %d \n", 1);
    }
}