#include <stdio.h>

int main()
{
  char buf[256];
  setbuffer(stderr, buf, 256);
  fprintf(stderr, "Error: no more oxygen.\n");
  buf[1] = 'R';
  buf[2] = 'R';
  buf[3] = 'O';
  buf[4] = 'R';
  fflush(stderr);
  
  return 0;
}