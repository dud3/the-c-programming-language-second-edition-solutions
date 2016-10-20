    #include <stdio.h>
    #include <string.h>
    
    #define MAXLEN 1000
    
    int zgetline(char s[], int max)
    {
        int c, i, l;
        
        printf("Wait... \n");
    
        /* 
            getchar() waits and waits while we input, enter is hit, it loops over everything.
        */
        for (i = 0, l = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
            
            printf("%d\n", i);
            
            if (i < max - 1) {
                s[l++] = c;
            }
        }
        
        if (c == '\n' && l < max - 1)
            s[l++] = c;
            
        s[l] = '\0';
    
        return l;
    }
    
    int main()
    {
        int len;
        char line[MAXLEN];

        while ((len = zgetline(line, MAXLEN)) > 0) {
            printf("Len: %d \n", len);
        }

        return 0;
    }
