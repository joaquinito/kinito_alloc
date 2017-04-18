/*
 * Ricardo Joaquinito allocator v0.1 - "For those who forget the size they have allocated"
 *
 * License: CC0
*/

#include <stdlib.h>
#include <limits.h>

/* TODO
#define free kini_free
*/

#define malloc kini_malloc

/* 'size' is public (via kini_get_size),
 * the 'ptr' shall be private and free using
 * the 'kini_free' function (tdb in release 0.2).
*/
typedef struct kini_malloc_t {
    void *ptr;
    size_t size;
}*KMT;

KMT kini_malloc(size_t size) {
    #undef malloc
    KMT ret = (KMT) malloc(sizeof(KMT));

    ret->ptr = malloc(size);
    #define malloc kini_malloc
    ret->size = size;

    return ret;
}

