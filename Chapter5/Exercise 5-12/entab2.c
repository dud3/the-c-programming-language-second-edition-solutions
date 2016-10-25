#include <stdio.h>
#include <stdlib.h> /* for atoi() */

#define MAXLINE 1000
#define DEFAULTTABWIDTH 8
#define MAXTABSTOPS 10

int getchars(char *s, int max);
void entab(char *s1, char *s2, int tabwidth[]);

int main(int argc, char **argv)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    int w[MAXTABSTOPS + 1];
    int i, tab, j;

    /* Max arguments */
    if (argc > MAXTABSTOPS)
        argc = MAXTABSTOPS;
        
    /*
        i = 2;
        Skip the program name.
    */
    j = 0;
    for (i = 2; i <= argc; ++i) {
        tab = atoi(*++argv); /* Convert string to integer */
        if (tab > 0) /* Number of tabs */
            w[j++] = tab;
    }
    if (i == 2)
        w[j++] = DEFAULTTABWIDTH;
        
    /* Empty tab */
    w[j] = 0;

    printf("Usage example: entab 2 4 6\n");

    printf("Input some characters, then press enter:\n");
    while (getchars(s1, MAXLINE) == 0)
        ;

    entab(s1, s2, w);
    printf("entab result:\n%s\n", s2);

    return 0;
}

int getchars(char *s, int max)
{
    int c, i, l;

    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if (i < max - 1) {
            *s++ = c;
            l++;
        }
    *s = '\0';

    return l;
}

// copy characters in s1 to s2 and replace blanks with tabs
void entab(char *s1, char *s2, int w[])
{
    int i, j, c, blanks, k;
    int blanksenough;

    i = 0;
    k = 0;
    while ((c = *s1) != '\0') {
        if (c == ' ') {
            
            blanksenough = 1;
            
            /* Tabs */
            if (w[k] == 0)
                k = 0;
            
            /* 
                w[k] = 2
                2 - 0 % 2
                2 % 2 = 0
                ...
            */
            
            blanks = w[k] - i % w[k];
            k++;
            
            /* Are there more blanks? */
            for (j = 1; j < blanks; ++j) {
                
                /*
                    blanks = 4
                    j = 2;
                    *(s1 + 2) = s1[2] = ' ';
                    *(s1 + 3) = s1[3] = 'b';
                    break;
                */
                
                /* *(s1 + j) = s1[j] */
                if (*(s1 + j) != ' ') {
                    blanksenough = 0;
                    break;
                }
            }
            
            /*  Amount of spaces matched?, if so, replce it by a tab. */
            if (blanksenough) {
                *s2++ = '\t';
                s1 += blanks;
                i += blanks;
            
            /* Not enough spaces? well assign the chars the way they ares */
            } else {
                *s2++ = c;
                i++;
                ++s1;
            }
            
        /* Push chars if no blank space found... */
        } else {
            *s2++ = c; /* Assign to the 2nd array */
            i++;
            ++s1;
        }
    }
    
    /* Make sure it ends properly */
    *s2++ = '\0';
}