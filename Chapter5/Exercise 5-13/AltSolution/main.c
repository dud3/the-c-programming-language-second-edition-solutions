#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alloc.h"
#include "line.h"

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int tailn);

void qqsort(char *lineptr[], int left, int right);

int main(int argc, char *argv[])
{
    /* Handle arguments */
    
    --argc;
    ++argv;
    
    /* tail -n x */
    if(argc > 2) {
        printf("tail: only two parameters allowed\nexample: tail -n 5\n");
        exit(1);
    }
    
    int tailn = 10; /* Default tail lines */

    while(argc-- > 0) {
        if(**argv == '-') {
        
            switch((*argv)[1]) {
                case 'n':
                    /* Next argument after n */
                    tailn = atoi(*++argv);
                    if(tailn == 0) {
                        printf("tail: input of `-n %s` isn't an integer\n", *argv);
                        exit(1);
                    }
                    break;
                
                default:
                    printf("tail: command %s not found\n", *argv);
                    break;
            }
            
        }
    }

    int nlines; /* number of input lines read */
    
    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qqsort(lineptr, 0, nlines - 1);
        
        if(nlines < tailn)
            tailn = nlines;
        
        printf("Sorted and tailed:\n");
        writelines(lineptr, nlines, tailn);
        
        return 0;
    } else {
        printf("error: input to big to sort\n");
        return 1;
    }
}