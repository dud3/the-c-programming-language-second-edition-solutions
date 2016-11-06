#include <stdio.h>
#include <string.h>

int main()
{
  const int arr[10];

  char const_str[] = "const";

  printf("strcmp: %c\n", const_str[0]);

  printf("strcmp: %d\n", strcmp("const", "const"));

  printf("strcmp: %d\n", strcmp("const char a", "const"));

  printf("isalnum: %d", isalnum('a'));
  
  return 0;
}
