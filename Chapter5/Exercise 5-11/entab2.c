#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 8

void setchar(char s[], int c, int maxline);
void entab(char s1[], char s2[], int tabwidth);

int main(int argc, char **argv)
{
    char s1[MAXLINE];
    char s2[MAXLINE];

    if(argc > 2 || argc == 1) {
        printf("Usage: entab2 'text goes here' \n");
        /* Only single argument allowed and must be wrapped with 'text' */
        /* Error handling ... */
        
        return -1;
    }
    
    int j = 0;
    while(argv[1][j] != '\0') {
        s1[j] = argv[1][j];
        j++;
    }

    entab(s1, s2, TAB_WIDTH);
    printf("entab result:\n%s\n", s2);

    return 0;
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

            blanksenough = 1;
            blanks = w - i % w;

            for (j = 1; j < blanks; ++j)
                if (s1[i + j] != ' ') {
                    blanksenough = 0;
                    break;
                }
            if (blanksenough) {
                s2[l++] = '\t';
                i += blanks - 1;
            } else {
                s2[l++] = c;
            }
        } else {
            s2[l++] = c;
        }
        ++i;
    }
    s2[l] = '\0';
}