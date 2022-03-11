#include "console.h"
#include "Sq-Matrix.h"
#include "RingInfo.h"
#include <stdlib.h>
struct Matrix{
    struct RingInfo* ringInfo;
    int rows;
    int columns;
    void* **a;
};
void choose_size(struct Matrix* matrix) //Функция для проверки правильного введенного значение размера матрицы
{
    int size;
    printf("Введите размер матрицы (A x A):\nA = ");
    scanf("%d",&size);
    while( size < 1 ){
        printf("Введено некорректное значение, попробуйте ещё раз.\n");
        printf("Введите размер матрицы (A x A):\nA = ");
        scanf("%d",&size);
        getchar();
    }
    matrix->rows = size;
    matrix->columns = size;
}

void printM(struct Matrix *matrix){
    printf("\nМАТРИЦА\n");
    for (int i = 0; i < matrix->rows ; i++){
        for ( int j = 0; j< matrix->columns; j++){
            if (matrix->ringInfo->size == sizeof(int)){
                printf("%d ", *(int*)(matrix->a[i][j]) );
            }
            if (matrix->ringInfo->size == sizeof(double)){
                printf("%lf ",*(double*)(matrix->a[i][j]) );
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

int checkM(struct Matrix *matrix){
    if (matrix == NULL){
        return 0;
    }
    if (matrix->a == NULL){
        return 0;
    }
    return 1;
}
int checkMultSc(int a, struct Matrix* matrix){
    if ( a == 1 || matrix->ringInfo->size == sizeof(int) ){
        return 1;
    }
    if ( a == 2 || matrix->ringInfo->size == sizeof(double) ){
        return 1;
    }
    else return 0;
    
}
int checkLinColNum(int type,int num, struct Matrix* matrix){
    if (type == 1){
        if (num > matrix->rows){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (type == 2){
        if (num > matrix->columns){
            return 1;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int selectedType(struct Matrix* matrix){
    int a = 0;
    if (matrix->ringInfo->size != 0){
        if ( matrix->ringInfo->size == sizeof(int) ){
            return 1;
        }
        if ( matrix->ringInfo->size == sizeof(double) ){
            return 2;
        }
    }
    scanf("%d",&a);
    while (a > 2 || a < 1){
        printf("Введено некорректное значение, попробуйте ещё раз.\n");
        scanf("%d",&a);
        getchar();
    }
    if ( a == 1 ){
        matrix->ringInfo->size = sizeof(int);
        return 1;
    }
    if ( a == 2 ){
        matrix->ringInfo->size = sizeof(double);
        return 2;
    }
    return 0;
}
