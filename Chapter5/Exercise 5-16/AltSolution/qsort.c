#include <string.h>
#include <ctype.h>

void swap(void *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(void *v[], int left, int right,
            int (*comp)(void const *, void const *),
            int order, int dir)
{
    int i, last, orderby;

    if(left >= right) {
       return;
    }

    /* Cut it in the middle */
    swap(v, left, (left + right) / 2);
    last = left;

    for(i = left + 1; i <= right; i++) {

        /* directory ordering, ignore other than: numbers, letters and blank */
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
            swap(v, ++last, i);
        }

    }

    swap(v, left, last);
    qsort(v, left, last - 1, comp, order, dir);
    qsort(v, last + 1, right, comp, order, dir);
}