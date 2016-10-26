#include <stdio.h>
#include "alloc.h"

static char allocbuf[BUFSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
   
   /* 
      allocbuf
         points to the first element of this array
      
      allocbuf + BUFSIZE
         icrements the array to the last momory allocation
         
      allocp 
         points to the first element of allocbufp[...]
      
      allocp += n
         increments allocp to the next available space on allocbuf[...]
      
      allocp - n
         returns the previous pointer to the last incremented(allocp += n)
   */
   
   printf("allocbuf: \t%p\n", allocbuf);
   printf("allocbuf+: \t%p\n", allocbuf + BUFSIZE);
   printf("allocp: \t%p\n", allocp);
   printf("allocp n: \t%d\n", n);
   
   if(allocbuf + BUFSIZE - allocp >= n) {
       allocp += n;
       return allocp - n;
   }
   else {
       return NULL;
   }
}