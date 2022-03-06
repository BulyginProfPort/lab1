#include "Sq-Matrix.h"
#include "console.h"
#include <stdlib.h>
#include <time.h>
struct Matrix{
    struct RingInfo* ringInfo;
    int rows;
    int columns;
    void* **a;
};

struct Matrix* getMyStruct(struct Matrix* matrix){
    matrix = malloc(sizeof(struct Matrix));
    matrix->ringInfo = malloc(sizeof(struct RingInfo));
    matrix->ringInfo->det = NULL;
    matrix->a = NULL;
    return matrix;
}
void freeMyStruct(struct Matrix* matrix){
    if (matrix != NULL){
        if (matrix->a != NULL){
            for (int i = 0; i < matrix->rows; i++){
                free(matrix->a[i]);
            }
            free(matrix->a);
        }
        if (matrix->ringInfo != NULL){
            free(matrix->ringInfo);
        }
        free(matrix);
    }
}
void freeMyMatrix(struct Matrix* matrix){
    if (matrix != NULL){
        if (matrix->a != NULL){
            for (int i = 0; i < matrix->rows; i++){
                free(matrix->a[i]);
            }
            free(matrix->a);
        }
    }
}

// 1. Создание

void Zeroes(struct Matrix* matrix){
    int *x = NULL;
    double *y = NULL;
    int m = 0;
    selectedType(matrix);
    choose_size(matrix);
    matrix->a = malloc ( matrix->rows * sizeof(int*));

    if(matrix->ringInfo->size == sizeof(int)){
        x = malloc( (matrix->columns * matrix->rows) * sizeof(int) );
        for (int i  = 0; i < matrix->rows * matrix->columns; i++){
            x[i] = 0;
        }
    }
    
    if(matrix->ringInfo->size == sizeof(double)){
        y = malloc( (matrix->columns * matrix->rows) * sizeof(double) );
        for (int i  = 0; i < matrix->rows * matrix->columns; i++){
            y[i] = 0.0;
        }
    }
    
    for ( int i = 0; i < matrix->rows; i++ ){
        matrix->a[i] = malloc( matrix->columns * sizeof(void*) );
        for ( int j = 0; j < matrix->columns; j++ ){
            if (matrix->ringInfo->size == sizeof(int) ){
                matrix->a[i][j] = &x[m];
            }
            else if( matrix->ringInfo->size == sizeof(double) ){
                matrix->a[i][j] = &y[m];
            }
            m++;
        }
    }
}

void Identity_Matrix(struct Matrix* matrix){
    int *x = NULL;
    double *y = NULL;
    selectedType(matrix);
    choose_size(matrix);
    int m = (matrix->rows - 1);

    if (matrix->ringInfo->size == sizeof(int) ){
        x = malloc( (matrix->columns * matrix->rows) * sizeof(int*) );
        for (int i = 0; i < (matrix->columns * matrix->rows); i++ ){
            if (i > m){
                x[i] = 0;
            }
            else{
                x[i] = 1;
            }
        }
    }
    
    if(matrix->ringInfo->size == sizeof(double)){
        y = malloc( (matrix->columns * matrix->rows) * sizeof(double*) );
        for (int i = 0; i < (matrix->columns * matrix->rows); i++ ){
            if (i > m){
                y[i] = 0.0;
            }
            else{
                y[i] = 1.0;
            }
        }
    }
    
    matrix->a = malloc ( matrix->rows * sizeof(void*));
    
    for (int i=0;i < matrix->rows;i++){
        matrix->a[i] = malloc( matrix->columns * sizeof(void*) );
        for (int j = 0; j < matrix->columns; j++){
            
            if (i != j){
                m++;
                if ( matrix->ringInfo->size == sizeof(int) ){
                    matrix->a[i][j] = &x[m];
                }
                if ( matrix->ringInfo->size == sizeof(double) ){
                    matrix->a[i][j] = &y[m];
                }
                
            }
            else{
                if ( matrix->ringInfo->size == sizeof(int) ){
                    matrix->a[i][j] = &x[i];
                }
                if ( matrix->ringInfo->size == sizeof(double) ){
                    matrix->a[i][j] = &y[i];
                }
            }
        }
    }
}

void AnyValue_Matrix(struct Matrix* matrix){
    int* x = NULL;
    double* y = NULL;
    int m = 0;
    selectedType(matrix);
    choose_size(matrix);

    matrix->a = malloc ( matrix->rows * sizeof(void*));
    
    printf("Введите число, из которого хотите создать матрицу.\n");
    
    if (matrix->ringInfo->size == sizeof(int) ){
        x = malloc( matrix->columns * matrix->rows * sizeof(int));
        scanf("%d",&x[0]);
        for (int i = 1; i < matrix->columns * matrix->rows; i++){
            x[i] = x[i-1];
        }
    }
    else if (matrix->ringInfo->size == sizeof(double) ){
        y = malloc(matrix->columns * matrix->rows * sizeof(double));
        scanf("%lf",&y[0]);
        for (int i = 1; i < matrix->columns * matrix->rows; i++){
            y[i] = y[i-1];
        }
    }
    for (int i = 0; i < matrix->rows; i++){
        matrix->a[i] = malloc( matrix->columns * sizeof(void*));
        for (int j = 0; j < matrix->columns; j++){
            if(matrix->ringInfo->size == sizeof(int)){
                matrix->a[i][j] = &x[m];
            }
            if(matrix->ringInfo->size == sizeof(double)){
                matrix->a[i][j] = &y[m];
            }
            m++;
        }
    }
}

void randvv(struct Matrix* matrix){
    int* x = NULL;
    double* y = NULL;
    int m = 0;
    selectedType(matrix);
    choose_size(matrix);

    if (matrix->ringInfo->size == sizeof(int)){
        x = malloc( matrix->rows * matrix->columns * sizeof(int) );
    }
    else if(matrix->ringInfo->size == sizeof(double)){
        y = malloc( matrix->rows * matrix->columns * sizeof(double) );
    }
    
    matrix->a = malloc( matrix->rows * sizeof(void*));
    for ( int i = 0; i < matrix->columns; i++ ){
        matrix->a[i] = malloc( matrix->rows * sizeof(void*));
        for ( int j = 0; j < matrix->columns; j++ ){
            if ( matrix->ringInfo->size == sizeof(int) ){
                x[m] = (int)rand()%9;
                matrix->a[i][j] = &x[m];
            }
            if (matrix->ringInfo->size == sizeof(double) ){
                y[m] = (double)(rand()%9);
                matrix->a[i][j] = &y[m];
            }
            m++;
        }
    }
}

// 2. Декомпозиция

void GetColumn(struct Matrix* result,struct Matrix* matrix, int num_column){
    result->a = malloc( matrix->rows * sizeof(void*) );
    result->rows = matrix->rows;
    result->columns = 1;
    result->ringInfo->size = matrix->ringInfo->size;
    for ( int i = 0; i < matrix->columns; i++){
        result->a[i] = malloc( sizeof(void*) );
        result->a[i][0] = matrix->a[i][num_column-1];
    }
}

void GetLine(struct Matrix* result,struct Matrix* matrix, int num_rows){
    result->rows = 1;
    result->columns = matrix->columns;
    result->ringInfo->size = matrix->ringInfo->size;
    result->a = malloc( sizeof(void*) );
    result->a[0] = malloc( matrix->columns * sizeof(void*) );
    for ( int j = 0; j < matrix->columns; j++){
        result->a[0][j] = matrix->a[num_rows-1][j];
    }
}

void transposedMatrix(struct Matrix *matrix){
    void* temp;
    temp = malloc(sizeof(void*));
    for (int i = 0; i < matrix->rows; i++){
        for (int j = 0; j < i; j++){
            temp = matrix->a[i][j];
            matrix->a[i][j] = matrix->a[j][i];
            matrix->a[j][i] = temp;
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

void* getDet(struct Matrix* matrix, int* tempi, double* tempd){
    int sign = 1;
    void* det = NULL;
    det = malloc(sizeof(void*));
    if (matrix->columns == matrix->rows){
        if ( (matrix->rows < 1)){
            printf("Ошибка! Дана неправильная матрица. Попробуйте создать матрицу.\n");
        }
        
        else if (matrix->rows == 1){
            det = matrix->a[0][0];
            return (det);
        }
        
        else if (matrix->rows == 2){
            if ( matrix->ringInfo->size == sizeof(int) ){
                *tempi = ( (*(int*)matrix->a[0][0]) * (*(int*)matrix->a[1][1]) ) - ( (*(int*)matrix->a[0][1]) * (*(int*)matrix->a[1][0]) );
                det = tempi;
            }
            if ( matrix->ringInfo->size == sizeof(double) ){
                *tempd = ( (*(double*)matrix->a[0][0]) * (*(double*)matrix->a[1][1]) ) - ( (*(double*)matrix->a[0][1]) * (*(double*)matrix->a[1][0]) );
                det = tempd;
            }
            return (det);
        }
        
        else if (matrix->rows > 2){
            struct Matrix* newMatrix = NULL;
            newMatrix = getMyStruct(newMatrix);
            newMatrix->rows = matrix->rows - 1;
            newMatrix->columns = matrix->columns - 1;
            newMatrix->ringInfo->size = matrix->ringInfo->size;
            newMatrix->a = malloc( newMatrix->rows * sizeof(void*) );
            
            for(int i = 0; i < newMatrix->rows; i++) {
                newMatrix->a[i] = malloc( newMatrix->rows * sizeof(void*) );
            }
            
            for(int j = 0; j < matrix->rows; j++){
                getMinor(matrix,newMatrix, 0, j);
                if ( matrix->ringInfo->size == sizeof(int) ){
                    *tempi = ( *(int*)det + ( (int)sign * (*(int*)matrix->a[0][j] ) *  (*(int*)getDet(newMatrix,tempi,tempd) ) ) );
                    det = tempi;
                }
                if ( matrix->ringInfo->size == sizeof(double) ){
                    *tempd = *(double*)det + ( (double)sign * *(double*)matrix->a[0][j] * *(double*)getDet(newMatrix,tempi,tempd) );
                    det = tempd;
                    
                }
                
                sign = -sign;
            }
            freeMyStruct(newMatrix);
        }
    }
    if (matrix->ringInfo->size == sizeof(int)){
        matrix->ringInfo->det = malloc (sizeof(int));
        matrix->ringInfo->det = det;
        printf("det = %d\n", *(int*)matrix->ringInfo->det);

    }
    else if (matrix->ringInfo->size == sizeof(double)){
        matrix->ringInfo->det = malloc (sizeof(double));
        matrix->ringInfo->det = det;
        printf("det = %lf\n", *(double*)matrix->ringInfo->det);
    }
    
    return det;
}

void inverseMatrix(struct Matrix *matrix, struct Matrix *result){
    int sign = 1, m = 0;
    int* ti = NULL;
    double* td = NULL;
    int* tempi = NULL;
    double* tempd = NULL;
    
    if (matrix->columns == matrix->rows){
        
        struct Matrix* newMatrix = malloc(sizeof(struct Matrix));
        newMatrix->ringInfo = malloc(sizeof(struct RingInfo));
        newMatrix->ringInfo->size =matrix->ringInfo->size;
        newMatrix->rows = matrix->rows - 1;
        newMatrix->columns = matrix->columns - 1;
        newMatrix->a = malloc( newMatrix->rows * sizeof(void*));
        
        for (int i = 0; i < newMatrix->rows; i++){
            newMatrix->a[i] = malloc( newMatrix->rows * sizeof(void*));
        }
        
        result->a = malloc(matrix->rows * sizeof(void*));
        result->ringInfo = malloc(sizeof(struct RingInfo));
        result->ringInfo->size = matrix->ringInfo->size;
        result->rows = matrix->rows;
        result->columns = matrix->columns;
        
        ti = malloc(result->rows * result->columns * sizeof(void*));
        tempi = malloc(sizeof(void*));
        tempd = malloc(sizeof(void*));

        for (int i = 0; i < matrix->rows; i++){
            result->a[i] = malloc(matrix->rows * sizeof(void*));
            for (int j = 0; j < matrix->columns; j++){
                
                getMinor(matrix,newMatrix, i, j);
    
                if  ( result->ringInfo->size == sizeof(int) ){
                    ti[m] = (int)sign * *(int*)getDet(newMatrix,tempi,tempd);
                    result->a[i][j] = &ti[m];
                }
                
                if  (result->ringInfo->size == sizeof(double) ){
                    td[m] = (double)sign * *(double*)getDet(newMatrix,tempi,tempd);
                    *(double*)result->a[i][j] = (double)sign * *(double*)getDet(newMatrix,tempi,tempd);
                }
                sign = -sign;
                m++;
            }
        }
        transposedMatrix(result);
        freeMyStruct(newMatrix);
    }
}


// 3. Операции
struct Matrix* Sum(struct Matrix* result,struct Matrix* matrix1, struct Matrix* matrix2){
    int tempi;
    double tempd;
    if(matrix1->ringInfo->size == matrix2->ringInfo->size){
        if (matrix1->columns == matrix1->rows || matrix2->columns == matrix2->rows){
            if (matrix1->rows == matrix2->rows){
                for (int i = 0; i < matrix1->rows; i++){
                    result->a[i] = malloc( matrix1->rows * sizeof(void*));
                    for (int j=0; j < matrix1->columns; i++ ){
                        if ( matrix1->ringInfo->size == sizeof(int) ){
                            tempi = *(int*)matrix1->a[i][j] + *(int*)matrix2->a[i][j];
                            result->a[i][j] = &tempi;
                        }
                        if (matrix1->ringInfo->size == sizeof(double)){
                            tempd = *(double*)matrix1->a[i][j] + *(double*)matrix2->a[i][j];
                            result->a[i][j] = &tempd;
                        }
                    }
                }
            }
        }
    }
    return result;
}

void MultSc (void* scalar, struct Matrix* matrix){
    for (int i = 0; i < matrix->rows; i++){
        for (int j = 0; j < matrix->columns; j++){
            if ( matrix->ringInfo->size == sizeof(int) ){
                *(int*)matrix->a[i][j] = *(int*)matrix->a[i][j] * (*(int*)scalar) ;
            }
            if( matrix->ringInfo->size == sizeof(double) ){
                *(double*)matrix->a[i][j] = *(double*)matrix->a[i][j] * (*(double*)scalar);
            }
        }
    }
}


struct Matrix* Mult(struct Matrix* result, struct Matrix* matrix1, struct Matrix* matrix2){
    int tempi;
    double tempd;
    if(matrix1->ringInfo->size == matrix2->ringInfo->size){
        if (matrix1->columns == matrix2->rows){
            for (int i = 0; i < matrix1->rows; i++){
                result->a[i] = malloc( matrix1->rows * sizeof(void*));
                for (int j = 0; j < matrix1->columns; j++){
                    if ( matrix1->ringInfo->size == sizeof(int) ){
                        tempi = (*(int*)matrix1->a[i][j]) * (*(int*)matrix2->a[j][i]) ;
                        tempi = *(int*)result->a[i][j] + tempi;
                        result->a[i][j] = &tempi;
                    }
                    if ( matrix1->ringInfo->size == sizeof(double) ){
                        tempd = (*(double*)matrix1->a[i][j]) * (*(double*)matrix2->a[i][j]) ;
                        tempd = *(double*)result->a[i][j] + tempd;
                        result->a[i][j] = &tempd;
                    }
                }
            }
        }
    }
    return result;
}

struct Matrix* SumLinComb(int scalar, struct Matrix* matrix, int numLine){
    struct Matrix* template;
    template = malloc( sizeof(struct Matrix) );
    if (matrix->columns == matrix->rows){
        template->a = malloc( matrix->rows * sizeof(void*) );
        for (int i = 0; i < matrix->rows; i++){
            template->a[i] = malloc( matrix->rows * sizeof(void*) );
        }
        for (int i = 0; i < matrix->rows; i++){
            for (int j = 0; j < matrix->columns; j++){
                template->a[i][j] = matrix->a[i][j];
            }
        }
    }
    return matrix;
}
