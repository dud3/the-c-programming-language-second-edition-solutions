#include <stdio.h>

int main()
{
	char a = 'a';
	char *lineptr[5];
	
	printf("%p \n", &a);
	
	lineptr[0] = &a;
	lineptr[1] = &a;
	lineptr[2] = &a;
	lineptr[3] = &a;
	lineptr[4] = &a;

	int i = 0;
	for(; i < 5; i++)
		printf("%c \n", *lineptr[i]);
	
	return 0;
}