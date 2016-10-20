#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int zgetline(char *line, int max);

int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    
    /*
        argc = numner of arguments.
        --argc removees the first argument which is the program name itself.
        
        (*++argv)[0] = (*++argv) and [0]
        (*++argv) = ++argv and *argv
        
            Step by step:
                1. ++argv = increment the pointer address.
                2. *argv = access the values inside this address.
                3. [0] = get the first character from the string.
            
            E.x.:
                find -n something
                
                (*++argv)[0] =  argv[i][0]
                argv = 0x000000.
                *argv = 'find'.
                ++argv = 0x000001
                *argv = '-n'
                *argv[0] = '-'
                *argv[1] = 'n'
                
                *++argv[0] = *(++(argv[0]))
                argv[0] = 0x000001
                ++(argv[0]) = 0x000002
                *(++(argv[0])) = 'n'
    */

    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal options %c", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }
    
    if (argc != 1)
        printf("Unsage: find -x -n pattern \n");
    else
        while (zgetline(line, MAXLINE) > 0) {
            lineno++;
            
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
        
    return found;
}

/* 
    s[] is passed by reference:
    which means that we can access this variable from the caller function
*/
int zgetline(char s[], int max)
{
    int c, i, l;

    /* 
        getchar() waits and waits while we input, 
        once enter is hit it does loop over everything.
    */
    for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        
        /* 
            Push chars into this array, s[l++] is the same as s[l]; l++;
            E.x.: 
                s[0] = "S";
                s[1] = "o";
                s[2] = "m";
                s[3] = "e";
                s[4] = "s";
                s[5] = "t";
                s[6] = "r";
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