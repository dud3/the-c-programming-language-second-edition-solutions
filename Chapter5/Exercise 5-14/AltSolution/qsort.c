#include <string.h>

void swap(void *v[], int i, int j) 
{
    char *temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(void *v[], int left, int right, 
            int (*comp)(void const *, void const *), int order) 
{
    int i, last, orderby;
    
    if(left >= right) {
       return;
    }

    /* Cut it in the middle */
    swap(v, left, (left + right) / 2);
    last = left;
    
    for(i = left + 1; i <= right; i++) {
        
        orderby = order ? (*comp)(v[i], v[left]) > 0 : 
                          (*comp)(v[i], v[left]) < 0 ;
        if(orderby) {
            swap(v, ++last, i);
        }
       
    }
    
    swap(v, left, last);
    qsort(v, left, last - 1, comp, order);
    qsort(v, last + 1, right, comp, order);
}