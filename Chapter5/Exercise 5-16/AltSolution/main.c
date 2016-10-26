#include <stdio.h>
#include <string.h>

#include "alloc.h"
#include "line.h"
#include "qsort.h"
#include "cmp.h"

char *lineptr[MAXLINES];

int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int numeric = 0;
    int order = 0;
    int fold = 0;
    int dir = 0;

    while(--argc > 0 && ++argv) {
        if(strcmp(*argv, "-n") == 0)
            numeric = 1;

        if(strcmp(*argv, "-r") == 0)
            order = 1;

        if(strcmp(*argv, "-f") == 0)
            fold = 1;

        if(strcmp(*argv, "-d") == 0)
            dir = 1;
    }

    if((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        /*
            qsort with custome soring function passed as a parameter
            throught pointers
        */
        int (*cmp)(const void *, const void *);
        if(numeric)
            cmp = numcmp;
        else
            if(fold)
                cmp = foldcmp;
            else
                cmp = strcmp;

        /*
            Alternative: qsort(
                (void **) lineptr, 0, nlines - 1,
                (int (*)(void*, void*))(numberic ? numcmp : strcmp)
            );
        */
        qsort((void **) lineptr, 0, nlines - 1, cmp, order, fold, dir);

        printf("Sorted and tailed:\n");
        writelines(lineptr, nlines);

        return 0;
    } else {
        printf("error: input to big to sort\n");
        return 1;
    }
}