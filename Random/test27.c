#include <stdio.h>
#include <string.h>

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
    char *bin[] = {
        "0000",
        "0001",
        "0010",
        "0011",
        "0100",
        "0101",
        "0110",
        "0111",
        "1000",
        "1001",
        "1010",
        "1011",
        "1100",
        "1101",
        "1110",
        "1111"
    };

    char *hex[] = {
        "0",
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "A",
        "B",
        "C",
        "D",
        "E",
        "F"
    };

    char *hexstr = "98FDEC00";

    printf("%s - %s\n", hexstr, hex[0]);

    int i;
    int j;
    for(i = 0; i < strlen(hexstr); i++) {
        for(j = 0; j < (sizeof(hex) / sizeof(hex[0])); j++) {

            if(hexstr[i] == hex[j][0])
                printf("[%c]: %s \n", hexstr[i], bin[j]);

        }
    }

    printf("%d \n", 1 | 10);

    /*
               2    1    4    3    3    5    0    0
        i = 0010 0001 0100 0011 0011 0101 0000 0000

               8    4    0    c    5    5    4    A
        f = 1000 0100 0000 1100 0101 0101 0100 1010

        00100001010000 1100110101 00000000
          100001000000 1100010101 0101001010
    */

    /*
        a.

           F    F    F    F    F    F    B    A
        1001 1000 1111 1101 1110 1100 1011 1010 | OR
        1111 1111 1111 1111 1111 1111 1011 1010

        1111 1111 1111 1111 1111 1111 1011 1010

        b.

        1001 1000 1111 1101 1110 1100 1011 1010 | EXLUSIVE OR
        0000 0000 0000 0000 0000 0000 1111 1111

        1001 1000 1111 1101 1110 1100 0100 0101

        c.

        1001 1000 1111 1101 1110 1100 1011 1010 | AND
        1111 1111 1111 1111 1111 1111 0000 0000

        1001 1000 1111 1101 1110 1100 0000 0000
    */
}