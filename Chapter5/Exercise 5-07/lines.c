/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 5-07, Chapter5.
 */

#include <stdio.h>
#include <string.h>
#include "lines.h"

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            
            /* remove newline insert end of the line */
            line[len-1] = '\0'; 
            
            /* 
                Assign and increment the value 
                lineptr => array of pointers, holds pointers as it's elements
                E.x.: 
                    lineptr[0] points to 0x000001
                    lineptr[1] points to 0x000002
                    ...
                    
                _getline(...) returns line[] array filled in with chars,
                E.x: 
                    loop 1: 
                        line = "abc";
                        lineptr[0] = line;
                        
                    loop 2: 
                        line = "xyz";
                        lineptr[1] = line;
                        
                    ...
            */
            strcpy(lineptr[nlines++], line);
        }
        
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* 
    s[] is passed by reference:
    which means that we can access this variable from the caller function
*/
int _getline(char s[], int max)
{
    int c, i, l;

    /* 
        getchar() waits and waits while we input, 
        once enter is hit it does loop over everything.
    */
    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        
        /* 
            Push chars into this array, s[l++] is the same as s[l]; l++;
        */
        if (i < max - 1) {
            s[l++] = c;
        }
    }
    
    /* Handle the new line at the end */
    if (c == '\n' && l < max - 1)
        s[l++] = c;
        
    s[l] = '\0';

    return l;
}
