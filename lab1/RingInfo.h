#ifndef RingInfo_h
#define RingInfo_h

#include <stdio.h>

struct RingInfo
{
    size_t size;
    int* (*sum)(int*, int*);
    int* zero;
    int* (*minus)(int*);
    int* (*mult)(int*, int*);
    int* one;
};

#endif /* RingInfo_h */
