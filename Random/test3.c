#include <stdio.h>

int strend(char *s, char *t)
{
	while(*s) 
		s++;

	if(*t == *(s - 1))
		return 1;

	return 0;
}

int main()
{
	char s[] = "abc";
	char *t = "c";

	int c = strend(s, t);
	
	printf("%d \n", c);
	
	return 0;
}