#ifndef Sq_Matrix_h
#define Sq_Matrix_h

#include <stdio.h>
#include "RingInfo.h"

// Matrix
struct Matrix;
void* getNumTemp(int type,struct Matrix* matrix, int *x, double *y);
struct Matrix* getMyStruct(struct Matrix* matrix);
void freeMyStruct(struct Matrix* matrix);
void freeMyMatrix(struct Matrix* matrix);
void freeMyTemp(int* x, double* y);

// 1. Создание

void Zeroes(struct Matrix* matrix, int* x,double* y);
void Identity_Matrix(struct Matrix* matrix, int* x, double *y);
void AnyValue_Matrix(struct Matrix* matrix, int* x, double *y);
void randvv(struct Matrix* matrix, int* x, double* y);

//2. Декомпозиция

void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col);
void* getDet(struct Matrix* matrix, int tempi, double tempd, void* *det);
void GetColumn(struct Matrix* result,struct Matrix* matrix, int num_column);
void GetLine(struct Matrix* result,struct Matrix* matrix, int num_rows);
void transposedMatrix(struct Matrix *matrix, void* temp);
void inverseMatrix(struct Matrix *matrix, struct Matrix *result, int* ti ,double* td, void* det, void* temp);


//3. Операции

void Sum(struct Matrix* result,struct Matrix* matrix1, struct Matrix* matrix2, int* ti, double* td);
void Mult(struct Matrix* result, struct Matrix* matrix1, struct Matrix* matrix2, int* tempi, double* tempd);
void MultSc (void* scalar, struct Matrix* matrix);
#endif /* Sq_Matrix_h */
