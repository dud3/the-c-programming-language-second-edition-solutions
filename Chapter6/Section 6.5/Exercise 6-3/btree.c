#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getch.h"

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);

struct tnode *talloc(void);
char *strdup(const char *s);

int getword(char *, int);
int issymalphanum(char);

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while(getword(word, MAXWORD) != EOF) {
        if(isalnum(word[0])) {

            /*
                1. root = null
                2. root = points to newly created node
            */
            root = addtree(root, word);
        }
    }

    treeprint(root);
    return 0;
}

/*
    1.
        p = NULL
        create tnode
        1st pointer->tnode

    2.
        p = 1st
        cmp = strcmp(word, 1st->word)
        cmp > create right node (1st->right), 1st->right = NULL
        create new node, return pointer to it p->left = new node
        return to main

    3. Wait for new words

    4. Iterate
*/
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if(p == NULL) {

        p = talloc();
        p->word = strdup(w);
        p->count = 1;
        p->left = NULL;
        p->right = NULL;

        /*
         * compare only first 6 chars
         * todo: get the input from shell argv
         */
    } else if((cond = strncmp(w, p->word, 6)) == 0) {
        p->count++;
    } else if(cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }

    return p;
}

void treeprint(struct tnode *p)
{
    if(p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(const char *s)
{
    char *p;

    p = (char *) malloc(strlen(s) + 1);
    if(p != NULL)
        strcpy(p, s);

    return p;
}

int getword(char *word, int lim)
{
    int c;
    char *w = word;

    /* Skip spaces */
    while(isspace(c = getch()))
        ;

    if(c != EOF) {
        *w++ = c;
    }

    if(!issymalphanum(c)) {
        *w = '\0';
        return c;
    }

    /* skip comments */
    if(c == '/') {
        c = getch();

        if(c == '*') {
            while((c = getch()) != '*' && c != '\0')
                ;

            /* check for ending '/' */
            if((c = getch()) == '/')
                ungetch(c);
        }
    }

    /* Loop on   rest of the string */
    for(; --lim > 0; w++) {
        /* New line or space */
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