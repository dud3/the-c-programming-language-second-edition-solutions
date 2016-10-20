/**
 * Author: Jeremy Yu <ccpalettes@gmail.com>
 * 
 * Solution for Exercise 1-21, Chapter1.
 */

#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 8

int getchars(char s[], int maxline);
void entab(char s1[], char s2[], int tabwidth);

int main(void)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    entab(s1, s2, TAB_WIDTH);
    printf("entab result:\n%s\n", s2);

    return 0;
}

int getchars(char s[], int lim)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < lim - 1)
          s[l++] = c;
    s[l] = '\0';

    return l;
}

// copy characters in s1 to s2 and replace blanks with tabs
void entab(char s1[], char s2[], int w)
{
    int i, j, l, c, blanks;
    int blanksenough;

    i = 0;
    l = 0;
    while ((c = s1[i]) != '\0') {
        if (c == ' ') {
            
            /*
                E.x.: String = "I see now";
                                0123456789; 9 = end of the string (\0)
                
                i = 0
                l = 0
                while(c = s[0]) -> c = 'I'
                    if(c == ' ') -> c != 'I'
                        // Skip...
                    s2[0] = 'I'
                    ++i -> i = 1
                
                i = 1
                l = 1
                while(c = s[1]) -> c = ' '
                    if(c == ' ') -> c == ' '
                        blanksenough = 1
        
                        blanks = 8 - 1 % 8 = 7
                
                        for (j = 1; j < 7; ++j) {
                            if (s1[1 + 2] != ' ') {
                                // Not true
                            }
                            if (s1[1 + 3] != ' ') {
                                // Not true
                            }
                            if (s1[1 + 4] != ' ') {
                                // true
                                ...
                                break;
                            }
                        }
            */
            
            /*
            blanks = w - i % w;
   
            for (j = 1; j < blanks; ++j) {
                if (s1[i + j] != ' ') {
                    blanksenough = 0;
                    break;
                }
            }
            */

            s2[l++] = '\t';
            
        } else {
            
            /* Copy chars if not a space */
            s2[l++] = c;
        }
        
        ++i;
    }
    
    s2[l] = '\0';
}