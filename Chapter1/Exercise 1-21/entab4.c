#include <stdio.h>
#include <stdlib.h>

#define MAXLEN  1000    // max line length
#define TABSTOP 8       // tabstop width

int get_line(char line[], int maxlen);
char * entab(char line[], int len);

int main(void)
{
    char line[MAXLEN];  // input line container
    char *entabbed;     // entabbed version of input line
    int len = 0;        // input line length
    int e_len = 0;      // entabbed line length

    while((len = get_line(line, MAXLEN)) > 0) {
        // produce entabbed version
        entabbed = entab(line, len);
        while (entabbed[e_len] != '\0') {
            e_len++;
        }

        // print entabbed version
        printf("%s", entabbed);
        if (entabbed[e_len-1] != '\n') {
            printf("\n");
        }

        free(entabbed);
    }

    return 0;
}

int get_line(char line[], int maxlen)
{
    int i = 0;  // current index
    int c;      // current character

    while (i < maxlen-1 && (c = getchar()) != EOF) {
        line[i++] = c;
        if (c == '\n') {
            break;
        }
    }
    line[i] = '\0';

    // clear input buffer of overflow
    if (i > 0 && line[i-1] != '\n') {
        while ((c = getchar()) != '\n' && c != EOF);
    }

    return i;
}

char * entab(char line[], int len)
{
    int i;          // index into original line
    int e;          // index into entabbed version
    int spaces;     // buffered whitespace counter
    char c;         // current char
    char *entabbed; // entabbed version

    e        = 0;
    spaces   = 0;
    entabbed = (char *) malloc(len * sizeof(char) + 1);

    for (i = 0; i < len; i++) {
        c = line[i];

        if (c == ' ') {
            if ((i+1) % TABSTOP == 0) {
                entabbed[e++] = '\t';
                spaces = 0;
            } else {
                spaces++;
            }
        } else {
            while (spaces > 0) {
                entabbed[e++] = ' ';
                spaces--;
            }

            entabbed[e++] = c;
        }
    }

    return entabbed;
}
