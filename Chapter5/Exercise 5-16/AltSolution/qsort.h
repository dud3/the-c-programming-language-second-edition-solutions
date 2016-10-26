/*
 * *lineptr[] - pointers to strings(array of chars)
 * dir - directory ordering, ignores chars other than numbers, letters and blank.
 */
void qsort(void *lineptr[], int left, int right,
            int (*comp)(const void *, const void *),
            int order, int fold, int dir);