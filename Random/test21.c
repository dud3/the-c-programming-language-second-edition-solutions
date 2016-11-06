#include <stdio.h>

void fn(int a) 
{
    printf("%d \n", a);
}

int main()
{
    void (*ptrfn)(int) = fn;
    ptrfn(20);
    
    return 0;
}