#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TABSIZE 4 /* Default tabsize */

int main(int argc, char *argv[])
{

    int c, pos, spaces, i;
    int tabsize[2] = {TABSIZE, TABSIZE};

    while (--argc > 0 && (**++argv == '-' || **argv == '+'))
        switch (**argv)
        {
            case '-':
                if ((pos = atoi(*argv + 1)) > 0)
                    tabsize[0] = pos;
                break;
            case '+':
                if ((pos = atoi(*argv + 1)) > 0)
                    tabsize[1] = pos;
                break;
        }
        
    int j;
    for(j = 0; j < 2; j++)
        printf("%d \n", tabsize[j]);
        
    pos = 0;
    spaces = 0;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        /*
            1. if ('a' == ' ') // false
            2. if (' ' == ' ') // true
        */
        if (c == ' ')
        {
            /*  
                2.
                    i = 1; tabsize[1] - 1;
                    0 < 2 - 1
                    0 < 1
            */
            if (pos < tabsize[i] - 1)
            {
                ++pos; // 1
                ++spaces; // 1
            }
            else
            {
                putchar('\t');
                pos = 0;
                spaces = 0;
                if (i < 1)
                    i++;
            }
        }
        else
        {
            /* 
                1. 'a' != '\t' // true
                skip...
            */
            if (c != '\t')
                while (spaces)
                {
                    putchar(' ');
                    --spaces;
                }
                
            /* 
                1. a 
            */ 
            putchar(c);
            
            /*
                1. 'a' == '\n' // false
            */
            if (c == '\n')
            {
                pos = 0;
                spaces = 0;
                i = 0;
            }
            
            /*
                1. 'a' == '\t' // false
            */
            else if  (c == '\t')
            {
                pos = 0;
                spaces = 0;
                if (i < 1)
                    i++;
            }
            
            /*
                1. true
            */
            else /* normal character */
            {
                /*
                    1. pos = 1
                */
                ++pos;
            
                /* 
                    1.
                        tabsize[0]
                        1 == 1 // true
                    
                        pos = 0
                        i = 1
                */
                if (pos == tabsize[i])
                {
                    pos = 0;
                    if (i < 1)
                        i++;
                }
            }
        }
    }
    
    while (spaces) /* may be left to do */
    {
        putchar(' ');
        --spaces;
    }
        
    return 0;
}