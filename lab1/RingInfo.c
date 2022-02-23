#include "RingInfo.h"
#include <stdlib.h>
struct RingInfo ringInfo;

struct RingInfo* Create(
    size_t size,
    void* (*sum)(void*, void*, void*),
    void* zero,
    void* (*minus)(void*),
    void* (*mult)(void*, void*),
    void* one)
{
    struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    
    ringInfo->size = size;
    ringInfo->sum = sum;
    ringInfo->zero = zero;
    ringInfo->minus = minus;
    ringInfo->mult = mult;
    ringInfo->one = one;
    
    return ringInfo;
}

void sumInt(void* a1, void* a2, void* res)
{
    int* inta1 = (int*)a1;
    int* inta2 = (int*)a2;
    int* resint = (int*)res;
    *resint = *inta1 + *inta2;
}

void sumFloat(void* a1, void* a2, void* res)
{
    float* fa1 = (float*)a1;
    float* fa2 = (float*)a2;
    float* fres = (float*)res;
    *fres = *fa1 + *fa2;
}

void sumDouble(void* a1, void* a2, void* res)
{
    double* fa1 = (double*)a1;
    double* fa2 = (double*)a2;
    double* fres = (double*)res;
    *fres = *fa1 + *fa2;
}

