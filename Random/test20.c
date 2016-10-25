#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptrarr[20];
    char name[20];
    char name_a[10];
    
    fgets(name, sizeof(name), stdin);
    fgets(name_a, sizeof(name_a), stdin);
    
    ptrarr[0] = name;
    ptrarr[1] = name_a;
    
    printf("\nname: %s", name);
    printf("\nname: %s", ptrarr[0]);
    printf("\nname: %s", ptrarr[1]);
    
    char c[] = "20";
    int ci = atoi(c);
    
    printf("c1: %d\n", ci);
    
    return 0;
}