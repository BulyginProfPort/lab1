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
void Zeroes(struct Matrix* matrix,struct RingInfo* ringInfo,int rows, int columns);
void Identity_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int rows, int columns);
void AnyValue_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int value, int rows, int columns);
void randvv(struct Matrix* matrix,int rows, int columns);
//2. Декомпозиция
void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col);
int getDet(struct Matrix* m);
struct Matrix* GetColumn(struct Matrix* result,struct Matrix* m, int num_column);
struct Matrix* GetLine(struct Matrix* result,struct Matrix* m, int num_line);
void transposedMatrix(struct Matrix *matrix);
void inverseMatrix(struct Matrix *matrix, struct Matrix *result);

//3. Операции

struct Matrix* Sum(struct Matrix* result,struct Matrix* m1, struct Matrix* m2);
struct Matrix* Mult(struct Matrix* result, struct Matrix* m1, struct Matrix* m2);
void MultSc (int scalar, struct Matrix* matrix);

#endif /* Sq_Matrix_h */
