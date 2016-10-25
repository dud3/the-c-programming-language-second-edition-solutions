#include <stdio.h>
#include <string.h>
 
#define SIZE 40
 
int main(void)
{
    char source[SIZE] = "This is the source string";
    char destination[SIZE] = "And this is the destination string";
    char * return_string;
    
    printf("Pointer source: %p\n", source);
    printf( "destination is originally = \"%s\"\n", destination );
    printf("Pointer return_string: %p\n", destination);
    return_string = strcpy( destination, source );
    printf("Pointer return_string: %p\n", return_string);
    printf( "After strcpy, destination becomes \"%p\"\n", destination );
    
    double a, b;
    
    char *c = "AC";
    char *c2 = "AB";
    
    printf("Diff: a-> %d\n", strcmp(c, c2));
}

char *astrcpy(char dest[], char src[])
{
    /* 
        int a = 2;
        int* ptra;
        (int addr ptra)
        
        a = value of `a`
        &a = address of `a`
        
        *(&a) = value of `a`
        
        ptra = &a;
        (ptra addr(a))
        
        print ptra; // address of `a`
        print *ptra; // value of `a`
        
        Points to the firt address of the dest[] array memory location.
        
        &dest[0] = 0x000001
        &dest[1] = 0x000002
        &dest[2] = 0x000003
        
        dest = &dest[0] // Shortcut
        
        (dest + 0) = &dest[0];
        (dest + 1) = &dest[1];
        (dest + 2) = &dest[2];
        
        int arr[3] = {1, 2, 3};
        
    */
    char *ptrd = dest;
    
    int i = 0;
    while(dest[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    
    return ptrd;
}

char *bstrcpy(char *dest, char *src)
{
    char *ptrd = dest;
    
    /*
        dest = src
        dest++ = src++
        
        // Increment the address and asign the value to it
        (dest + 0) = 0x000 // address
        *(dest + 0) = *(src + 0) // value
        
        (dest + 1) = 0x001 // address
        *(dest + 1) = *(src + 1) // value
        
        ...
        
        *(src++) = '\0'
        *(dest++) = '\0'
        
        '\0' means end of the loop?
    */
    while(*(dest++) = *(src++))
        ;
  
    return dest;
}