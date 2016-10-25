int getLine(char *s, int maxline);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int tailn);
void swap(char *v[], int i, int j);
int numcmp(char *s1, char *s2);
void qqsort(char *v[], int left, int right);

#define MAXLINES 500 /* max #lines to be sorted */
#define MAXLEN 100 /* max length of any input line */