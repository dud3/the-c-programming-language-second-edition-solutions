#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "any", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "int", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

#define NKEYS (sizeof keytab / sizeof keytab[0])

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);
int issymalphanum(char);

int main()
{
    char word[MAXWORD];
    struct key *p;

    while(getword(word, MAXWORD) != EOF) {
        if(issymalphanum(word[0])) {

            p = binsearch(word, keytab, NKEYS);
            if(p != NULL)
                p->count++;

            for(p = keytab; p < keytab + NKEYS; p++)
                if(p->count > 0)
                    printf("%4d %s\n", p->count, p->word);

        }
    }

    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while(low < high) {
        mid = low + (high - low) / 2; /* can't add pointers */

        if((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if(cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return NULL;
}

int getword(char *word, int lim)
{
    int c;
    char *w = word;

    /* 1. E.x.: word = 'int' */

    /* 2. Get all the chars */
    while(isspace(c = getch()))
        ;

    /* 3. Get all the chars; *w = 'i' */
    if(c != EOF) {
        *w++ = c;
    }

    /* 4. Skip; !c; */
    if(!issymalphanum(c)) {
        *w = '\0';
        return c;
    }

    /*
        5. increment until new line.
            a. getch() = 'i' (step 3); *w = 'i';
            b. getch() = 'n' (step 5); *w = 'n';
            c. getch() = 't' (step 5); *w = 't';
            d. getch() = '\n' (step 5); *w = '\n';
                d.a. ungetch(*w);
                break;
    */
    for(; --lim > 0; w++) {
        if(!issymalphanum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

int issymalphanum(char c)
{

    if((int)c >= 33 && (int)c <= 126)
        return 1;

    return 0;
}