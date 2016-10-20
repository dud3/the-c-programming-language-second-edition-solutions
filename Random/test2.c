#include <stdio.h>

void astrcat(char s[], char t[])
{
	int i, j;

	i = j = 0;

	while (s[i] != '\0')
		i++;

	while ((s[i++] = t[j++]) != '\0')
		;
}

void pstrcat(char *s, char *t)
{
	while(*s)
		s++;
	
	while((*s++ = *t++))
		;
}

int main()
{
	char s[3] = "abc";
	char t[2] = "de";

	printf("%s \n", s);
	printf("%s \n", t);
	
	pstrcat(s, t);
	
	printf("%s \n", s);
	
	return 0;
}