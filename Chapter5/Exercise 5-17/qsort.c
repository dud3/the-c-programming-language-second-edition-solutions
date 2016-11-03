#include <stdio.h>
#include <string.h>
#include <ctype.h>

void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*
 * quicksort: partition and quicksort recursively
 * have a pivot
 * have two pointers, i and j, which check values lower or greater than a pivot
 *
 * init:
 *  left: 0
 *  right: array_length - 1a
 *
 *  E.x.:
 *                0    1    2    3
 *      array = {"4", "3", "2", "1"}
 *      left: 0
 *      right: 4
 *
 *      Loop 0:
 *          swap(array, 0, 2) // (4 / 2)
 *          array = {"2", "3", "4", "1"}
 *          last = 0
 *
 *          i = 0 + 1; i <= 4; i++
 *
 *              // For now numcmp(...) < 0
 *
 *              i = 1;      v[1] = 3;
 *              left = 0;   v[0] = 2
 *
 *              numcmp(3, 2) < 0; false
 *
 *              ...
 *
 *              i = 2;      v[2] = 4;
 *              left = 0;   v[0] = 2;
 *
 *              numcmp(4, 2) < 0; false
 *
 *              ...
 */
void aqsort(void *v[], int left, int right,
            int (*comp)(const void *, const void *),
            int order, int dir, int column)
{
    int i, last, orderby;

    if(left >= right) {
       return;
    }

    /* {4, 2, 1, 3, 5} */
    swap(v, left, (left + right) / 2);
    last = left;

    for(i = 0; i <= right; i++) {
        printf("%s ", v[i]);
    }

    printf("\nSwap 1: \tleft: %d \tleft + right / 2: %d \n", left, (left + right) / 2);

    for(i = left + 1; i <= right; i++) {

        /*
         * directory ordering, ignore other than: numbers,
         * letters and blank
         */
        if(dir) {
            if(!isdigit(v[i]) && !isalpha(v[i]) && !isspace(v[i]))
                continue;

            if(!isdigit(v[left]) && !isalpha(v[left]) && !isspace(v[left]))
                continue;
        }

        /* order: asc or desc */
        orderby = order ? (*comp)(v[i], v[left]) > 0 :
                          (*comp)(v[i], v[left]) < 0 ;

        if(orderby) {
            printf("\nfor: Swap: \tlast: %d \ti: %d \n", last, i);
            swap(v, ++last, i);
        }

    }

    printf("\nSwap 2: \tleft: %d \tlast: %d \n", left, last);

    printf("aqsort 1: \tleft: %d \tlast - 1: %d \n", left, last - 1);

    printf("aqsort 2: \tlast + 1: %d \tright: %d \n", last + 1, right);

    swap(v, left, last);
    aqsort(v, left, last - 1, comp, order, dir, column);
    aqsort(v, last + 1, right, comp, order, dir, column);
}
