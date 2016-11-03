#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

char *alloc(int);

int getLine(char *s, int maxline)
{
  int c, i;

   c = getchar();
   maxline--;

   for(i = 0; c != EOF && c != '\n' && maxline > 0; i++,
         c = getchar(), maxline--) {
       s[i] = c;
   }

   if(c == '\n') {
       s[i] = c;
       i++;
   }

   s[i] = '\0';
   return i;
}

int readlines(char *lineptr[], int maxlines)
{
   int len, nlines;
   char line[MAXLEN];

   nlines = 0;

   while((len = getLine(line, MAXLEN)) > 0) {
      if(nlines >= maxlines ||
         (lineptr[nlines] = malloc(sizeof(char) * len)) == NULL)
         return -1;
      else {
         line[len - 1] = '\0'; /* delete new line */
         strcpy(lineptr[nlines], line);
         nlines++;
      }
   }

   return nlines;
}

void writelines(char *lineptr[], int nlines)
{
   int i;

   for(i = 0; i < nlines; i++) {
      printf("%s\n", lineptr[i]);
   }
}