#include "console.h"
#include "Sq-Matrix.h"
#include "RingInfo.h"
#include <stdlib.h>
struct Matrix{
    struct RingInfo* ringInfo;
    int rows;
    int columns;
    int **a;
};
void choose_size(int *size) //Функция для проверки правильного введенного значение размера матрицы
{
    printf("Введите размер матрицы (A x A):\nA = ");
    scanf("%d",size);
    while( (*size) < 1 ){
        printf("Введено некорректное значение, попробуйте ещё раз.\n");
        printf("Введите размер матрицы (A x A):\nA = ");
        scanf("%d",size);
        getchar();
    }
}

void printM(struct Matrix *matrix){
    printf("\nМАТРИЦА\n");
    for (int i = 0; i < matrix->rows ; i++){
        for ( int j = 0; j< matrix->columns; j++){
            printf("%d ",matrix->a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int checkM(struct Matrix *matrix){ // Проверка на пустоту матрицы (была ли она инициализирована, былали ли выделена память под неё). Так же можно проверять чисто по размеру (если size = 0), но скорее всего она может быть инициализирована, просо путая
    if (matrix == NULL){
        return 0;
    }
    else if ( matrix->a == NULL ){
        return 0;
    }
    else{
        return 1; // Матрица была инцициалзирована, под неё была выделена память.
    }
}
