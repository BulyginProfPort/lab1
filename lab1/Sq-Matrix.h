#ifndef Sq_Matrix_h
#define Sq_Matrix_h

#include <stdio.h>
#include "RingInfo.h"

// Matrix
struct Matrix;
struct Matrix* getMyStruct(struct Matrix* matrix);
// 1. Создание
void Zeroes(struct Matrix* result,struct RingInfo* ringInfo,int size);
void Identity_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int size);
void AnyValue_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int value, int size);
void randvv(struct Matrix* matrix,int size);

void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col);
int getDet(struct Matrix* m);
struct Matrix* GetColumn(struct Matrix* result,struct Matrix* m, int num_column);
struct Matrix* GetLine(struct Matrix* result,struct Matrix* m, int num_line);
void transposedMatrix(struct Matrix *matrix);
void inverseMatrix(struct Matrix *matrix, struct Matrix *result);


struct Matrix* Sum(struct Matrix* result,struct Matrix* m1, struct Matrix* m2);
struct Matrix* Mult(struct Matrix* result, struct Matrix* m1, struct Matrix* m2);
struct Matrix* MultSc(int scalar, struct Matrix* m);

#endif /* Sq_Matrix_h */
