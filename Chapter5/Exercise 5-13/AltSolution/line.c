#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"

char *alloc(int);

int getLine(char *s, int maxline) {
  int c, i;

   c = getchar();
   maxline--;
   
   for(i = 0; c != EOF && c != '\n' && maxline > 0; i++, c = getchar(), maxline--) {
       s[i] = c;
   }

   if(c == '\n') {
       s[i] = c;
       i++;
   }
   
   s[i] = '\0';
   return i;
}

int readlines(char *lineptr[], int maxlines) {
   int len, nlines;
   char /* *p, *cplineptr[MAXLEN], */ line[MAXLEN];

   nlines = 0;
   
   while((len = getLine(line, MAXLEN)) > 0) {
      // p = alloc(len);
      if(nlines >= maxlines /* || p == NULL */)
         return -1;
      else {
         line[len - 1] = '\0'; /* delete new line */
         // strcpy(p, line);
         strcpy(lineptr[nlines++], line);
      }
   }
   
   return nlines;
}

void writelines(char *lineptr[], int nlines, int tailn) {
   int i;
   
   if(tailn == 0)
      tailn = nlines; 
   
   for(i = nlines - tailn; i < nlines; i++) {
      printf("%s\n", lineptr[i]);
   }
}

void swap(char *v[], int i, int j) {
   char *temp;

   temp = v[i];
   v[i] = v[j];
   v[j] = temp;
}

int numcmp(char *s1, char *s2) {
   double v1, v2;

   v1 = atof(s1);
   v2 = atof(s2);

   if(v1 < v2) {
       return -1;
   }
   else if(v1 > v2) {
       return 1;
   }
   else {
       return 0;
   }
}

void qqsort(char *v[], int left, int right) {
   int i, last;

   if(left >= right) {
       return;
   }

   swap(v, left, (left + right) / 2);
   last = left;

   for(i = left + 1; i <= right; i++) {
       if(strcmp(v[i], v[left]) < 0) {
           swap(v, ++last, i);
       }
   }

   swap(v, left, last);
   qqsort(v, left, last - 1);
   qqsort(v, last + 1, right);
}