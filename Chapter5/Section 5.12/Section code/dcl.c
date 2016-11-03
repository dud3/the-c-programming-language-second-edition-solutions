#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS };

int tokentype;
char token[MAXTOKEN]; /*last token string */
char name[MAXTOKEN]; /*identifier name */
char datatype[MAXTOKEN]; /*data type = char, int, etc. */
char out[1000];

void dcl(void);
void dirdcl(void);
int gettoken(void);

/*
Grammar:

	dcl:			optional * direct-dcl
	direct-dcl:		name
					(dcl)
					direct-dcl()
					direct-dcl[optional size]

E.x.:
	Exp: int a
	a -> dcl
	dcl -> dir-dcl
	dir->dcl -> name

	Exp: int (*arr[])
	(*arr[]) -> dcl
	dcl -> dir-dcl -> (...)
	dir-dcl -> []
	dir-dcl -> *
	dir-dcl -> arr
	dir-dcl -> name
*/

int main() /* convert declaration to words */
{
    while (gettoken() != EOF) {    /* 1st token on line */
		while (tokentype != '\n') {

			/* 1. gettoken() gets the datatype from the token  */
	        strcpy(datatype, token);

	        /* 2. Init out to end of the line? */
	        out[0] = '\0';

			 /* parse rest of line */
	        dcl();

	    	if (tokentype != '\n')
	    		printf("syntax error\n");

	       printf("%s: %s %s\n", name, out, datatype);
		}
    }

    return 0;
}

int gettoken(void) /* return next token */
{
	int i;
    int c, getch(void);
    void ungetch(int);
    char *p = token;

	/* Skip blank spaces and tabs */
    while ((c = getch()) == ' ' || c == '\t')
    	;

    /* Assume anything past one of these characters is something
	 * we do not care to process. */
	if (c == ';' || c == '{' || c == '=') {
		while (c != '\n')
			c = getch();
	}

    if (c == '(') {

        if ((c = getch()) == ')') {

            strcpy(token, "()"); /* [2][3] */
            return tokentype = PARENS; /* [4] */

        } else {
            ungetch(c);
            return tokentype = '(';
        }

    } else if (c == '[') {

        for (*p++ = c, i = 0; (c = getch()); ++i) {
        	if (isdigit(c)) {
				*p++ = c;
        	} else if (c == ']') {
				*p++ = c;
				break;
			} else {
				printf("error: missing ]\n");
				*p++ = ']';
				ungetch(c);
				break;
			}
        }

        *p = '\0';
        return tokentype = BRACKETS;

    } else if (isalpha(c) || c == '_') {

		/* Reads the next character of input */
        for (*p++ = c; isalnum(c = getch()) || c == '_';) {
            *p++ = c;
        }

        *p = '\0';
        ungetch(c); /* Get back the space, tab */

        return tokentype = NAME;

    } else
        return tokentype = c;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; ) /* count *'s */
        ns++;

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

	if (tokentype == '\n') {
		return;
	}

    if (tokentype == '(') {

        dcl();

        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME) { /* variable name */
        strcpy(name, token);
    }
    else
        printf("error: expected name or (dcl)\n");

    while ((type = gettoken()) == PARENS || type == BRACKETS) {

        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }

    }
}
