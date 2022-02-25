#include "Sq-Matrix.h"
#include "console.h"
#include <stdlib.h>
#include <time.h>
struct Matrix{
    struct RingInfo* ringInfo;
    int rows;
    int columns;
    int **a;
};

struct Matrix* getMyStruct(struct Matrix* matrix){
    matrix = malloc(sizeof(struct Matrix));
    matrix->a = NULL;
    return matrix;
}
void freeMyStruct(struct Matrix* matrix){
    for (int i = 0; i < matrix->rows; i++){
        free(matrix->a[i]);
    }
    free(matrix->a);
    free(matrix);
}
void freeMyMatrix(struct Matrix* matrix){
    for (int i = 0; i < matrix->rows; i++){
        free(matrix->a[i]);
    }
    free(matrix->a);
}
// 1. Создание

void Zeroes(struct Matrix* matrix,struct RingInfo* ringInfo,int rows, int columns){
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->a = malloc ( matrix->rows * sizeof(int*));
    for ( int i = 0; i < matrix->rows; i++ ){
        matrix->a[i] = (int*)malloc( matrix->columns * sizeof(int) );
        for ( int j = 0; j < matrix->columns; j++ ){
            matrix->a[i][j] = 0;
            }
        }
}

void Identity_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int rows, int columns){
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->a = malloc ( matrix->rows * sizeof(int*));
    for (int i=0;i < matrix->rows;i++){
        matrix->a[i] = malloc( matrix->columns * sizeof(int));
        for (int j = 0; j < matrix->columns; j++){
            if (i != j){
                matrix->a[i][j] = 0;
            }
            else{
                matrix->a[i][j] = 1;
            }
        }
    }
}

void AnyValue_Matrix(struct Matrix* matrix,struct RingInfo* ringInfo,int value, int rows, int columns){
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->a = malloc ( matrix->rows * sizeof(int*));
    for (int i = 0; i < matrix->rows; i++){
        matrix->a[i] = malloc( matrix->columns * sizeof(int));
        for (int j = 0; j < matrix->columns; j++){
            matrix->a[i][j] = value;
        }
    }
}

void randvv(struct Matrix* matrix,int rows, int columns){
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->a = malloc ( matrix->rows * sizeof(int*));
    for ( int i = 0; i < matrix->columns; i++ ){
        matrix->a[i] = malloc( matrix->columns * sizeof(int) );
        for ( int j = 0; j < matrix->columns; j++ ){
            matrix->a[i][j]=(rand()%9)+1;
        }
    }
}

// 2. Декомпозиция

struct Matrix* GetColumn(struct Matrix* result,struct Matrix* matrix, int num_column){
    result->a = malloc( matrix->rows * sizeof(int*) );
    result->rows = matrix->rows;
    result->columns = 1;
    for ( int i = 0; i < matrix->columns; i++){
        result->a[i] = malloc( sizeof(int) );
        result->a[i][0] = matrix->a[i][num_column-1];
    }
    return result;
}

struct Matrix* GetLine(struct Matrix* result,struct Matrix* matrix, int num_rows){
    result->rows = 1;
    result->columns = matrix->columns;
    result->a = malloc( sizeof(int*) );
    result->a[0] = malloc( matrix->columns * sizeof(int) );
    for ( int j = 0; j < matrix->columns; j++){
        result->a[0][j] = matrix->a[num_rows-1][j];
    }
    return result;
}

void transposedMatrix(struct Matrix *matrix){
    int t=0;
    for (int i = 0; i < matrix->rows; i++){
        for (int j = 0; j < i; j++){
            t = matrix->a[i][j];
            matrix->a[i][j] = matrix->a[j][i];
            matrix->a[j][i] = t;
        }
    }
}


void getMinor(struct Matrix* matrix, struct Matrix* new_matrix, int line, int col){
    int markerl = 0, markercol = 0;
    for  (int i = 0; i < new_matrix->rows; i++){
        if (i == line){
            markerl = 1;
        }
        markercol = 0;
        for (int j = 0; j < new_matrix->columns; j++){
            if (j == col){
                markercol = 1;
            }
            new_matrix->a[i][j] = matrix->a[i+markerl][j+markercol];
        }
    }

}

int getDet(struct Matrix* matrix){
    int det = 0, sign = 1;
    if (matrix->columns == matrix->rows){
        if ( (matrix->rows < 1)){
            printf("Ошибка! Дана неправильная матрица. Попробуйте создать матрицу.\n");
        }
        else if (matrix->rows == 1){
            return (matrix->a[0][0]);
        }
        else if (matrix->rows == 2){
            return (matrix->a[0][0] * matrix->a[1][1] - matrix->a[0][1] * matrix->a[1][0]);
        }
        else{
            struct Matrix* newMatrix = malloc(sizeof(struct Matrix));
            newMatrix->rows = matrix->rows - 1;
            newMatrix->columns = matrix->columns - 1;
            
            newMatrix->a = malloc( newMatrix->rows * sizeof(int*) );
            for(int i = 0; i < newMatrix->rows; i++) {
                newMatrix->a[i] = malloc( newMatrix->rows * sizeof(int) );
            }
            for(int j = 0; j < matrix->rows; j++){
                getMinor(matrix,newMatrix, 0, j);
                det = det + (sign * matrix->a[0][j] * getDet(newMatrix) );
                sign = -sign;
            }
            freeMyStruct(newMatrix);
        }
        
    }
    return det;
}

void inverseMatrix(struct Matrix *matrix, struct Matrix *result){
    int sign = 1;
    
    if (matrix->columns == matrix->rows){
        
        struct Matrix* newMatrix = malloc(sizeof(struct Matrix));
        newMatrix->rows = matrix->rows - 1;
        newMatrix->columns =matrix->columns - 1;
        newMatrix->a = malloc( newMatrix->rows * sizeof(int*));
        
        for (int i = 0; i < newMatrix->rows; i++){
            newMatrix->a[i] = malloc( newMatrix->rows * sizeof(int));
        }
        result->a = malloc(matrix->rows * sizeof(int*));
        result->rows = matrix->rows;
        result->columns = matrix->columns;
        
        for (int i = 0; i < matrix->rows; i++){
            result->a[i] = malloc(matrix->rows * sizeof(int));
            for (int j = 0; j < matrix->columns; j++){
                getMinor(matrix,newMatrix, i, j);
                result->a[i][j] = sign * getDet(newMatrix);
                sign = -sign;
            }
        }
        transposedMatrix(result);
        freeMyStruct(newMatrix);
    }
}


// 3. Операции
struct Matrix* Sum(struct Matrix* result,struct Matrix* matrix1, struct Matrix* matrix2){
    //struct Matrix* result = malloc(sizeof(struct Matrix));
    if (matrix1->columns == matrix1->rows || matrix2->columns == matrix2->rows){
        if (matrix1->rows == matrix2->rows){
            for (int i = 0; i < matrix1->rows; i++){
                result->a[i] = malloc( matrix1->rows * sizeof(int*));
                for (int j=0; j < matrix1->columns; i++ ){
                    result->a[i][j] = matrix1->a[i][j] + matrix2->a[i][j];
                }
            }
        }
    }
    return result;
}

void MultSc (int scalar, struct Matrix* matrix){
    if (matrix->columns == matrix->rows){
        for (int i = 0; i < matrix->rows; i++){
            for (int j = 0; j < matrix->columns; j++){
                matrix->a[i][j] = matrix->a[i][j] * scalar;
            }
        }
    }
}

struct Matrix* Mult(struct Matrix* result, struct Matrix* matrix1, struct Matrix* matrix2){
    //struct Matrix* result = malloc(sizeof(struct Matrix));
    if (matrix1->columns == matrix2->rows){
        for (int i = 0; i < matrix1->rows; i++){
            result->a[i] = malloc( matrix1->rows * sizeof(int*));
            for (int j = 0; j < matrix1->columns; j++){
                result->a[i][j] += matrix1->a[i][j] * matrix2->a[j][i];
            }
        }
    }
    return result;
}

struct Matrix* SumLinComb(void* scalar, struct Matrix* matrix, int numLine){
    struct Matrix* template;
    template = malloc( sizeof(struct Matrix*) );
    if (matrix->columns == matrix->rows){
        template->a = malloc( matrix->rows * sizeof(int*) );
        for (int i = 0; i < matrix->rows; i++){
            template->a[i] = malloc( matrix->rows * sizeof(int) );
        }
        for (int i = 0; i < matrix->rows; i++){
            for (int j = 0; j < matrix->columns; j++){
                template->a[i][j] = matrix->a[i][j];
            }
        }
    }
    return matrix;
}
