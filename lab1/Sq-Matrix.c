#include "Sq-Matrix.h"
#include "console.h"
#include <stdlib.h>
#include <time.h>
struct Matrix{
    struct RingInfo* ringInfo;
    int mSize;
    int **a;
};

struct Matrix* getMyStruct(struct Matrix* matrix){
    matrix = malloc(sizeof(struct Matrix));
    matrix->a = NULL;
    return matrix;
}

// 1. Создание

void Zeroes(struct Matrix* matrix,struct RingInfo* ringInfo,int size){
    matrix->mSize = size;
    matrix->a = malloc ( matrix->mSize * sizeof(int*));
    for ( int i = 0; i < size; i++ ){
        matrix->a[i] = (int*)malloc( matrix->mSize * sizeof(int) );
        for ( int j = 0; j < size; j++ ){
            matrix->a[i][j] = 0;
            }
        }
}

void Identity_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int size){
    matrix->mSize = size;
    matrix->a = malloc ( matrix->mSize * sizeof(int*));
    for (int i=0;i<size;i++){
        matrix->a[i] = malloc( matrix->mSize * sizeof(int));
        for (int j=0; j<size; j++){
            if (i!=j){
                matrix->a[i][j] = 0;
            }
            else{
                matrix->a[i][j] = 1;
            }
        }
    }
}

void AnyValue_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int value, int size){
    matrix->mSize = size;
    matrix->a = malloc ( matrix->mSize * sizeof(int*));
    for (int i = 0; i < matrix->mSize; i++){
        matrix->a[i] = malloc( matrix->mSize * sizeof(int));
        for (int j = 0; j < matrix->mSize; j++){
            matrix->a[i][j] = value;
        }
    }
}

void randvv(struct Matrix* matrix,int size){
    matrix->mSize = size;
    matrix->a = malloc ( matrix->mSize * sizeof(int*));
    for ( int i = 0; i < matrix->mSize; i++ ){
        matrix->a[i] = (int*) malloc( matrix->mSize * sizeof(int) );
        for ( int j = 0; j < matrix->mSize; j++ ){
            matrix->a[i][j]=(rand()%9)+1;
        }
    }
}

// 2. Декомпозиция

struct Matrix* GetColumn(struct Matrix* result,struct Matrix* matrix, int num_column){
    for ( int i = 0; i < matrix->mSize; i++){
        for (int j = 0 ; j < matrix->mSize; j++){
            result->a[i][num_column] = matrix->a[i][num_column];
        }
    }
    return result;
}

struct Matrix* GetLine(struct Matrix* result,struct Matrix* matrix, int num_line){
    result->mSize = matrix->mSize;
    for ( int j=0; j < matrix->mSize; j++){
        result->a[0][j] = matrix->a[num_line][j];
    }
    return result;
}

void transposedMatrix(struct Matrix *matrix){
    int t=0;
    for (int i = 0; i < matrix->mSize; i++){
        for (int j = 0; j < i; j++){
            t = matrix->a[i][j];
            matrix->a[i][j] = matrix->a[j][i];
            matrix->a[j][i] = t;
        }
    }
}


void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col){
    int markerl = 0, markercol = 0;
    for  (int i = 0; i < new_matrix->mSize; i++){
        if (i == line){
            markerl = 1;
        }
        markercol = 0;
        for (int j = 0; j < new_matrix->mSize; j++){
            if (j == col){
                markercol = 1;
            }
            new_matrix->a[i][j] = matrix->a[i+markerl][j+markercol];
        }
    }
}

int getDet(struct Matrix* matrix){
    int det = 0, sign = 1;
    if (matrix->mSize < 1){
        
    }
    else if (matrix->mSize == 1){
        return (matrix->a[0][0]);
    }
    else if (matrix->mSize == 2){
        return (matrix->a[0][0] * matrix->a[1][1] - matrix->a[0][1] * matrix->a[1][0]);
    }
    else{
        struct Matrix* newMatrix = malloc(sizeof(struct Matrix));
        newMatrix->mSize = matrix->mSize - 1;
        newMatrix->a = malloc( newMatrix->mSize * sizeof(int*) );
        for(int i = 0; i < matrix->mSize; i++) {
            newMatrix->a[i] = malloc( newMatrix->mSize * sizeof(int) );
        }
        
        for(int j = 0; j < matrix->mSize; j++){
            getMinor(matrix,newMatrix, 0, j);
            det = det + (sign * matrix->a[0][j] * getDet(newMatrix) );
            sign = -sign;
        }

        for(int i = 0; i < matrix->mSize-1; i++) {
            free(newMatrix->a[i]);
        }
        free(newMatrix->a);
        free(newMatrix);
    }
    return det;
}

void inverseMatrix(struct Matrix *matrix, struct Matrix *result){
    int sign = 1;
    result->mSize = matrix->mSize;
    struct Matrix* newMatrix = malloc(sizeof(struct Matrix));
    newMatrix->mSize = matrix->mSize - 1;
    newMatrix->a = malloc( newMatrix->mSize * sizeof(int*));
    printM(matrix);
    for (int i = 0; i < newMatrix->mSize; i++){
        newMatrix->a[i] = malloc( newMatrix->mSize * sizeof(int));
    }
    result->a = malloc(matrix->mSize * sizeof(int*));
    for (int i = 0; i < matrix->mSize; i++){
        result->a[i] = malloc(matrix->mSize * sizeof(int));
        for (int j = 0; j < matrix->mSize; j++){
            getMinor(matrix,newMatrix, i, j);
            result->a[i][j] = sign * getDet(newMatrix);
            sign = -sign;
        }
    }
    transposedMatrix(result);
    for(int i = 0; i < newMatrix->mSize; i++) {
        free(newMatrix->a[i]);
    }
    free(newMatrix->a);
    free(newMatrix);
}


// 3. Операции

struct Matrix* Sum(struct Matrix* result,struct Matrix* m1, struct Matrix* m2){
    //struct Matrix* result = malloc(sizeof(struct Matrix));
    if (m1->mSize == m2->mSize){
        for (int i = 0; i < m1->mSize; i++){
            result->a[i] = malloc( m1->mSize * sizeof(int*));
            for (int j=0; j < m1->mSize; i++ ){
                result->a[i][j] = m1->a[i][j] + m2->a[i][j];
            }
        }
    }
    return result;
}
struct Matrix* MultSc(int scalar, struct Matrix* m){
    for (int i = 0; i < m->mSize; i++){
        m->a[i] = malloc (m->mSize * sizeof(int*));
        for (int j = 0; j < m->mSize; j++){
            m->a[i][j] = m->a[i][j] * scalar;
        }
    }
    return m;
}

struct Matrix* Mult(struct Matrix* result, struct Matrix* m1, struct Matrix* m2){
    //struct Matrix* result = malloc(sizeof(struct Matrix));
    for (int i = 0; i < m1->mSize; i++){
        result->a[i] = malloc( m1->mSize * sizeof(int*));
        for (int j = 0; j < m1->mSize; j++){
            result->a[i][j] += m1->a[i][j] * m2->a[j][i];
        }
    }
    return result;
}


//struct Matrix* SumLinComb(void* scalar, struct Matrix* m, int numLine){}
