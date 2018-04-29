#include <stdio.h>
#include "kini_alloc.c"

int kini_get_size(KMT kmt) {
    size_t val = kmt->size;
    
    /* size_t to int conversion bullshit */
    return (val <= INT_MAX) ? (int)((size_t)val) : -1;
}

int main(int argv, char **argc) {
    
    KMT k = kini_malloc(sizeof(int) * 4); 

    printf("size allocated=%d\n", kini_get_size(k));

    kini_free(k);
    free(k);
    
    exit(0);
}
