#include "stdio.h"
#define TABSIZE 6   /*Tab increment size*/

int main() {
 int c, no_blanks, pos, no_tabs;
 no_blanks = 0; /*number of blamks required*/
 no_tabs = 0; /* number of tabs required*/
 
 for (pos = 1; (c = getchar()) != EOF; ++pos) {
  if (c == ' ') {
   if (pos % TABSIZE != 0)
    ++no_blanks;
   else {
    no_blanks = 0;
    ++no_tabs;
   }
  } else {
   for (; no_tabs > 0; --no_tabs)
    putchar('\t');
   if (c == '\t')
    no_blanks = 0;
   else
    for (; no_blanks > 0; --no_blanks)
     putchar(' ');
   putchar(c);
   if (c == '\n')
    pos = 0;
   else if (c == '\t')
    pos = pos + (TABSIZE - (pos - 1) % TABSIZE);
 
  }
 }
 
 return 0;
}