#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; // allocbuf = &allocbuf[0]

char *fn(void);
char *zalloc(int);
int callme(void);

char *zalloc(int n)
{
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    
    /* 
      Increment amount of memory to be used.
      Which would be equivalent to: allocbuf[n] (E.x.: allocbuf[10])
      
      1. allocp = allocbuf[0]
      2. (allocp += n) = allocbuf[n]
    */
    allocp += n;
    
    /*
      Would simply return us the beginning memory address.
    
      By now allocp has been incremented n times, allocp = 1(initial) + 10(n)
      we simply substract 10(n) from allocp, which gives us what we started with.
    */
    return allocp - n;
  } else
    return NULL;
}

void afree(char *p)
{
  /*
    This simply means, if the pointer is between this array.
    
    p = memory address of some char.
    allocbuf = start memory address of the array.
    allocbuf + ALLOCSIZE = end memory address of the array.
  */
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}

char *fn()
{
  return "foo";
}

int main()
{
  printf("Before the call: \n");
  
  printf("%p\n", &allocbuf[0]);
  printf("%p\n", allocp);
  printf("%p\n", allocp + 1);
  
  char *z = zalloc(100);

  printf("After the call: \n");
  
  printf("%p\n", allocp);
  printf("%p\n", z);

  return 0;
}

int callme()
{
  return 1;
}
