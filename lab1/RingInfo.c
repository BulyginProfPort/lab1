#include "RingInfo.h"
#include <stdlib.h>
struct RingInfo ringInfo;

struct RingInfo* Create(
    size_t size,
    int* (*sum)(int*, int*),
    int* zero,
    int* (*minus)(int*),
    int* (*mult)(int*, int*),
    int* one)
{
    struct RingInfo* ringInfo = malloc(sizeof(struct RingInfo));
    ringInfo->size = size;
    ringInfo->zero = zero;
    ringInfo->minus = minus;
    ringInfo->one = one;
    return ringInfo;
}
