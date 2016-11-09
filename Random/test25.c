#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *start++);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x, sizeof(void *));
}

int main()
{
    int i = 3490593; /* 21 43 35 00 */
    show_int(i);

    float f = 3490593.0f; /* 84 0c 55 4a */
    show_float(f);

    int *p = &i;
    show_pointer(p);
}