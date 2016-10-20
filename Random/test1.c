#include <stdio.h>

int astrcmp(char *s, char *t)
{
	int i;

	for (i = 0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
			
	return s[i] - t[i];
}

int pstrcmp(char *s, char *t)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	
	return *s - *t;
}

int main()
{
	
	char a = 'a';
	char *lineptr[5];
	
	lineptr[0] = &a;
	lineptr[1] = &a;
	lineptr[2] = &a;
	lineptr[3] = &a;
	lineptr[4] = &a;
	
	printf("%p \n", &a);

	int i = 0;
	
	for(; i < 5; i++)
		printf("%c \n", *lineptr[i]);
	
	int c = pstrcmp("abc", "bbg");
	int e = pstrcmp("abc", "cbg");

	printf("%d \n", c);
	printf("%d \n", e);
	
	return 0;
}