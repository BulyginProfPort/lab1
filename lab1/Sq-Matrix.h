#ifndef Sq_Matrix_h
#define Sq_Matrix_h

#include <stdio.h>
#include "RingInfo.h"

// Matrix
struct Matrix;
struct Matrix* getMyStruct(struct Matrix* matrix);
void freeMyStruct(struct Matrix* matrix);
void freeMyMatrix(struct Matrix* matrix);

// 1. Создание

void Zeroes(struct Matrix* matrix);
void Identity_Matrix(struct Matrix* matrix);
void AnyValue_Matrix(struct Matrix* matrix);
void randvv(struct Matrix* matrix);

//2. Декомпозиция

void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col);
void* getDet(struct Matrix* matrix, int* tempi, double* tempd);
void GetColumn(struct Matrix* result,struct Matrix* matrix, int num_column);
void GetLine(struct Matrix* result,struct Matrix* matrix, int num_rows);
void transposedMatrix(struct Matrix *matrix);
void inverseMatrix(struct Matrix *matrix, struct Matrix *result);


//3. Операции

struct Matrix* Sum(struct Matrix* result,struct Matrix* m1, struct Matrix* m2);
struct Matrix* Mult(struct Matrix* result, struct Matrix* m1, struct Matrix* m2);
void MultSc (void* scalar, struct Matrix* matrix);
#endif /* Sq_Matrix_h */
