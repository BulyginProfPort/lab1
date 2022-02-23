#ifndef RingInfo_h
#define RingInfo_h

#include <stdio.h>

struct RingInfo
{
    size_t size;
    void* (*sum)(void*, void*, void*);
    void* zero;
    void* (*minus)(void*);
    void* (*mult)(void*, void*);
    void* one;
};

void sumInt(void* a1, void* a2, void* res);
void sumFloat(void* a1, void* a2, void* res);
void sumDouble(void* a1, void* a2, void* res);

#endif /* RingInfo_h */
