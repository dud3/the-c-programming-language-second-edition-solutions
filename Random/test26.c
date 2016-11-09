#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", *start++);

    printf("\n");
}

void print_reverse(byte_pointer start, int len)
{
    int i;
    char *c;

    for (i = len; i > 0; i--)
        *start++;

    for (i = len; i > 0; i--)
        printf(" %.2x", *--start);

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
    int val = 0x12345678;
    byte_pointer valp = (byte_pointer) &val;

    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
    show_bytes(valp, 4);
    show_bytes(valp, 5);
    show_bytes(valp, 6);
    show_bytes(valp, 7);
    show_bytes(valp, 8);

    printf("\n");

    print_reverse(valp, 8);
    print_reverse(valp, 7);
    print_reverse(valp, 6);
    print_reverse(valp, 5);
    print_reverse(valp, 4);
    print_reverse(valp, 3);
    print_reverse(valp, 2);
    print_reverse(valp, 1);
}