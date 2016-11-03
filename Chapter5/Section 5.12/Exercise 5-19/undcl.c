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
*/

int main() /* convert declaration to words */
{
    int type;
    int prev_type = '\0';
    char temp[MAXTOKEN];

    while(gettoken() != EOF) {

        strcpy(out, token);

        while((type = gettoken()) != '\n') {

            if (type == PARENS || type == BRACKETS) {

				if (prev_type == '*') {
					sprintf(temp, "(%s)", out);
					strcpy(out, temp);
				}

				strcat(out, token);

			} else if (type == '*') {

                sprintf(temp, "*%s", out);
				strcpy(out, temp);

            } else if(type == NAME) {

                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);

            } else
                printf("Invalid input at %s\n", token);

            prev_type = type;
        }

        prev_type = '\0';
        printf("%s\n", out);
    }

    return 0;
}

int gettoken(void) /* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;        /* [1] */

	/* Skip blank spaces and tabs */
    while ((c = getch()) == ' ' || c == '\t')
    	;

    if (c == '(') {

        if ((c = getch()) == ')') {

            strcpy(token, "()"); /* [2][3] */
            return tokentype = PARENS; /* [4] */

        } else {
            ungetch(c);
            return tokentype = '(';
        }

    } else if (c == '[') {

        for (*p++ = c; (*p++ = getch()) != ']'; )
        	;

        *p = '\0';
        return tokentype = BRACKETS;

    } else if (isalpha(c)) {

		/* Reads the next character of input */
        for (*p++ = c; isalnum(c = getch()); ) /* SUPPOSING [5] */
            *p++ = c;

        *p = '\0';
        ungetch(c); /* Get back the space or tab */

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

    if (tokentype == '(') {

        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");

    } else if (tokentype == NAME) /* variable name */
        strcpy(name, token);
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
