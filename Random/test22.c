#include <stdio.h>

#define BUFSIZE 100

int getch(void);
void ungetch(int c);

int buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;     /* next free position in buf */

int main(void)
{
	int i = 0;
	char ch;

	puts("\nInput an integer followed by a char:\n");

	/*
	 * read chars until non digit or EOF
	 *
	 * 1. ch = getch()
	 * 2. bufp = 0
	 * 3. getchar() -> now getchar waits while we enter on the keyboard
	 * 5. type '12ab'
	 * 4. click `enter`
	 * 5. gets back to while(...) start looping
	 *	5.0. ch = 1; isdigit(1) -> true
	 *	5.1. ch = 2; isdigit(2) -> true
	 *	5.2. ch = 'a'; isdigit('a') -> flase
	 *
	 * 6. Last getch() is ch = 'a'
	 * 7. 'a' != EOF
	 * 8. bufp = 0
	 * 9. ungetch('a')
	 * 10. buf[0] = 'a'
	 * 11. bufp = 1
	 *
	 * 12. getch()
	 * 13. --buf = 1 - 1 = 0;
	 * 14. return buf[0]
	 *
	 * 15. print 'a'
	 *
	 */
	while ((ch = getch()) != EOF && isdigit(ch)) {
		printf("in-ch: %c \n", ch);
		i = 10 * i + ch - 48; /* convert ASCII into int value */
	}

	printf("ch: %c \n", ch);
	if (ch != EOF) /* if non digit char was read, push it back into input buffer */
		ungetch(ch);

	printf("\n\ni = %d, next char in buffer = %c\n", i, getch());
	return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
	printf("\ngetch -> bufp: %d\n", bufp);
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push a character back onto the input */
void ungetch(int c)
{
	printf("\nungetch -> bufp: %d\n", bufp);
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters \n");
	else
		buf[bufp++] = c;
}
