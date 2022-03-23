#include "test.h"
#include "Sq-Matrix.h"
#include <stdlib.h>
#include "console.h"
struct Matrix{
    struct RingInfo* ringInfo;
    int rows;
    int columns;
    void* **a;
};
int testMultInt(){
    struct Matrix* matrix1 = NULL;
    int n11 = 1, n12 = 2,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(int);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc( matrix1->rows * sizeof(void*));
    for ( int i = 0; i < matrix1->columns; i++ ){
        matrix1->a[i] = malloc( matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    
    struct Matrix* matrix2 = NULL;
    int n21 = 1,n22 = 0,n23 = 0,n24 = 1;
    matrix2 = malloc(sizeof(struct Matrix));
    matrix2->rows = 2;
    matrix2->columns = 2;
    matrix2->ringInfo = malloc(sizeof(struct RingInfo));
    matrix2->ringInfo->size = sizeof(int);
    matrix2->a = malloc( matrix2->rows * sizeof(void*));
    for ( int i = 0; i < matrix2->columns; i++ ){
        matrix2->a[i] = malloc( matrix2->columns * sizeof(void*));
    }
    matrix2->a[0][0] = &n21;
    matrix2->a[0][1] = &n22;
    matrix2->a[1][0] = &n23;
    matrix2->a[1][1] = &n24;
    
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    int* ti = NULL;
    double* td = NULL;
    
    ti = getNumTemp(1,matrix1, ti, td);
    Mult(result, matrix1, matrix2, ti, td);
    
    if (*(int*)result->a[0][0] == n11 && *(int*)result->a[0][1] == n12 && *(int*)result->a[1][0] == n13 && *(int*)result->a[1][1] == n14){
        ti = freeMyTemp(ti, td);
        freeMyStruct(matrix1);
        freeMyStruct(matrix2);
        freeMyStruct(result);
        return 1;
    }
    ti = freeMyTemp(ti, td);
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    return 0;
}
int testMultDbl(){
    struct Matrix* matrix1 = NULL;
    double n11 = 1, n12 = 2,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(double);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc( matrix1->rows * sizeof(void*));
    for ( int i = 0; i < matrix1->columns; i++ ){
        matrix1->a[i] = malloc( matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    
    struct Matrix* matrix2 = NULL;
    double n21 = 1,n22 = 0,n23 = 0,n24 = 1;
    matrix2 = malloc(sizeof(struct Matrix));
    matrix2->rows = 2;
    matrix2->columns = 2;
    matrix2->ringInfo = malloc(sizeof(struct RingInfo));
    matrix2->ringInfo->size = sizeof(double);
    matrix2->a = malloc( matrix2->rows * sizeof(void*));
    for ( int i = 0; i < matrix2->columns; i++ ){
        matrix2->a[i] = malloc( matrix2->columns * sizeof(void*));
    }
    matrix2->a[0][0] = &n21;
    matrix2->a[0][1] = &n22;
    matrix2->a[1][0] = &n23;
    matrix2->a[1][1] = &n24;
    
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    int* ti = NULL;
    double* td = NULL;

    td = getNumTemp(1,matrix1, ti, td);
    Mult(result, matrix1, matrix2, ti, td);
     
    if (*(double*)result->a[0][0] == n11 && *(double*)result->a[0][1] == n12 && *(double*)result->a[1][0] == n13 && *(double*)result->a[1][1] == n14){
        td = freeMyTemp(ti, td);
        freeMyStruct(matrix1);
        freeMyStruct(matrix2);
        freeMyStruct(result);
        return 1;
    }
    td = freeMyTemp(ti, td);
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    return 0;
}
int testMultScInt(){
    int x1 = 3;
    void* scalar = NULL;
    scalar = &x1;
    int n11 = 1, n12 = 2 ,n13 = 3, n14 = 4;
    int n21 = 3,n22 = 6,n23 = 9,n24 = 12;
    
    struct Matrix* matrix1 = NULL;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(int);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc( matrix1->rows * sizeof(void*));
    for ( int i = 0; i < matrix1->columns; i++ ){
        matrix1->a[i] = malloc( matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    
    MultSc(scalar, matrix1);
    if(*(int*)matrix1->a[0][0] == n21 && *(int*)matrix1->a[0][1] == n22 && *(int*)matrix1->a[1][0] == n23 && *(int*)matrix1->a[1][1] == n24){
        freeMyStruct(matrix1);
        return 1;
    }
    return 0;
}
int testMultScDbl(){
    void* scalar = NULL;
    double n11 = 2,n12 = 4,n13 = 6,n14 = 8, x = 0.5;
    double n21 = 1,n22 = 2,n23 = 3,n24 = 4;
    scalar = &x;
    struct Matrix* matrix = NULL;
    matrix = malloc(sizeof(struct Matrix));
    matrix->ringInfo = malloc(sizeof(struct RingInfo));
    matrix->ringInfo->size = sizeof(double);
    matrix->rows = 2;
    matrix->columns = 2;
    matrix->a = malloc( matrix->rows * sizeof(void*));
    for ( int i = 0; i < matrix->columns; i++ ){
        matrix->a[i] = malloc( matrix->columns * sizeof(void*));
    }
    matrix->a[0][0] = &n11;
    matrix->a[0][1] = &n12;
    matrix->a[1][0] = &n13;
    matrix->a[1][1] = &n14;
    MultSc(scalar, matrix);
    if(*(double*)matrix->a[0][0] == n21 && *(double*)matrix->a[0][1] == n22 && *(double*)matrix->a[1][0] == n23 && *(double*)matrix->a[1][1] == n24){
        freeMyStruct(matrix);
        return 1;
    }
    return 0;
}
int testSumInt(){
    struct Matrix* matrix1 = NULL;
    int n11 = 1, n12 = 2 ,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(int);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc(matrix1->rows * sizeof(void*));
    for (int i = 0; i < matrix1->rows; i++){
        matrix1->a[i] = malloc(matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    
    int n21 = 3,n22 = 6,n23 = 9,n24 = 12;
    struct Matrix* matrix2 = NULL;
    matrix2 = malloc(sizeof(struct Matrix));
    matrix2->ringInfo = malloc(sizeof(struct RingInfo));
    matrix2->ringInfo->size = sizeof(int);
    matrix2->rows = 2;
    matrix2->columns = 2;
    matrix2->a = malloc(matrix2->rows * sizeof(void*));
    for (int i = 0; i < matrix2->rows; i++){
        matrix2->a[i] = malloc(matrix2->columns * sizeof(void*));
    }
    matrix2->a[0][0] = &n21;
    matrix2->a[0][1] = &n22;
    matrix2->a[1][0] = &n23;
    matrix2->a[1][1] = &n24;
    
    int* ti = NULL;
    double* td = NULL;

    ti = getNumTemp(1,matrix1, ti, td);
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    Sum(result, matrix1, matrix2, ti, td);
    if(*(int*)result->a[0][0] == (n11 + n21) && *(int*)result->a[0][1] == (n12 + n22) && *(int*)result->a[1][0] == (n13 + n23) && *(int*)result->a[1][1] == (n14 + n24) ){
        ti = freeMyTemp(ti, td);
        freeMyStruct(matrix1);
        freeMyStruct(matrix2);
        freeMyStruct(result);
        return 1;
    }
    ti = freeMyTemp(ti, td);
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    return 0;
}
int testSumDbl(){
    struct Matrix* matrix1 = NULL;
    double n11 = 1, n12 = 2 ,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(double);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc(matrix1->rows * sizeof(void*));
    for (int i = 0; i < matrix1->rows; i++){
        matrix1->a[i] = malloc(matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    
    double n21 = 3,n22 = 6,n23 = 9,n24 = 12;
    struct Matrix* matrix2 = NULL;
    matrix2 = malloc(sizeof(struct Matrix));
    matrix2->ringInfo = malloc(sizeof(struct RingInfo));
    matrix2->ringInfo->size = sizeof(double);
    matrix2->rows = 2;
    matrix2->columns = 2;
    matrix2->a = malloc(matrix2->rows * sizeof(void*));
    for (int i = 0; i < matrix2->rows; i++){
        matrix2->a[i] = malloc(matrix2->columns * sizeof(void*));
    }
    matrix2->a[0][0] = &n21;
    matrix2->a[0][1] = &n22;
    matrix2->a[1][0] = &n23;
    matrix2->a[1][1] = &n24;
    
    int* ti = NULL;
    double* td = NULL;

    td = getNumTemp(1,matrix1, ti, td);
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    Sum(result, matrix1, matrix2, ti, td);
    if(*(double*)result->a[0][0] == (n11 + n21) && *(double*)result->a[0][1] == (n12 + n22) && *(double*)result->a[1][0] == (n13 + n23) && *(double*)result->a[1][1] == (n14 + n24) ){
        td = freeMyTemp(ti, td);
        freeMyStruct(matrix1);
        freeMyStruct(matrix2);
        freeMyStruct(result);
        return 1;
    }
    td = freeMyTemp(ti, td);
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    return 0;
}


int testGetMinorInt(){
    struct Matrix* matrix1 = NULL;
    int n11 = 1, n12 = 2 ,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(int);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc(matrix1->rows * sizeof(void*));
    for (int i = 0; i < matrix1->rows; i++){
        matrix1->a[i] = malloc(matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
        
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    result->ringInfo = malloc(sizeof(struct RingInfo));
    result->rows = matrix1->rows - 1;
    result->columns = matrix1->columns - 1;
    result->ringInfo->size = matrix1->ringInfo->size;
    result->a = malloc( result->rows * sizeof(void*) );
    
    for(int i = 0; i < result->rows; i++) {
        result->a[i] = malloc( result->rows * sizeof(void*) );
    }
    
    getMinor(result,matrix1, 0, 0);
    if (*(int*)result->a[0][0] == n14){
        freeMyStruct(matrix1);
        freeMyStruct(result);
        return 1;
    }
    
    freeMyStruct(matrix1);
    freeMyStruct(result);
    return 0;
}
int testGetMinorDbl(){
    struct Matrix* matrix1 = NULL;
    double n11 = 1, n12 = 2 ,n13 = 3, n14 = 4;
    matrix1 = malloc(sizeof(struct Matrix));
    matrix1->ringInfo = malloc(sizeof(struct RingInfo));
    matrix1->ringInfo->size = sizeof(double);
    matrix1->rows = 2;
    matrix1->columns = 2;
    matrix1->a = malloc(matrix1->rows * sizeof(void*));
    for (int i = 0; i < matrix1->rows; i++){
        matrix1->a[i] = malloc(matrix1->columns * sizeof(void*));
    }
    matrix1->a[0][0] = &n11;
    matrix1->a[0][1] = &n12;
    matrix1->a[1][0] = &n13;
    matrix1->a[1][1] = &n14;
    struct Matrix* result = NULL;
    result = malloc(sizeof(struct Matrix));
    result->ringInfo = malloc(sizeof(struct RingInfo));
    result->rows = matrix1->rows - 1;
    result->columns = matrix1->columns - 1;
    result->ringInfo->size = matrix1->ringInfo->size;
    result->a = malloc( result->rows * sizeof(void*) );
    
    for(int i = 0; i < result->rows; i++) {
        result->a[i] = malloc( result->rows * sizeof(void*) );
    }
    
    getMinor(result,matrix1, 0, 0);
    
    if (*(double*)result->a[0][0] == n14){
        freeMyStruct(matrix1);
        freeMyStruct(result);
        return 1;
    }
    
    freeMyStruct(matrix1);
    freeMyStruct(result);
    return 0;
}
