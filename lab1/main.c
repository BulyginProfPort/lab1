#include <stdio.h>
#include <stdlib.h>
#include "Sq-Matrix.h"
#include "RingInfo.h"
#include "console.h"
#include <time.h>

int main(){
    srand(time(NULL));
    
    int selected = 0, size = 0, det = 0, scalar = 0, choose = 0;
    
    struct Matrix* matrix1 = NULL;
    struct Matrix* matrix2 = NULL;
    struct Matrix* result = NULL;
    struct RingInfo* ringInfo = NULL;
    
    matrix1 = getMyStruct(matrix1);
    result = getMyStruct(result);
    
    ringInfo = malloc(sizeof(struct RingInfo));
    
    printf("Какой тип чисел вы хотите использовать?\n"
           "1. Целочисленные числа\n"
           "2. Вещественные числа\n");
    scanf("%d",&choose);
    
A:  printf("1. Создать матрицу.\n"
           "2. Операции над матрицой\n"
           "3. Операции над матрицами\n"
           "4. Exit.\n");
    scanf("%d", &selected);
    while(selected < 4){
        if (selected == 1){
            int select1 = 0;
            printf("Какую марицу вы хотите создать?\n"
                   "1. Матрицу нулей.\n"
                   "2. Еденичную матрицу.\n"
                   "3. Матрицу из произвольных чисел.\n"
                   "4. Матрицы из введённого числа.\n"
                   "5. Exit.\n");
            scanf("%d",&select1);
            while (select1 < 5){
                if (select1 == 1){
                    if ( checkM(matrix1) == 1){
                        freeMyMatrix(matrix1);
                    }
                    size = 0;
                    choose_size(&size); 
                    Zeroes(matrix1, ringInfo, size, size);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 2){
                    if ( checkM(matrix1) == 1){
                        freeMyMatrix(matrix1);
                    }
                    choose_size(&size);
                    Identity_Matrix(matrix1, ringInfo, size, size);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 3){
                    if ( checkM(matrix1) == 1){
                        freeMyMatrix(matrix1);
                    }
                    choose_size(&size);
                    randvv(matrix1,size,size);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 4){
                    int value;
                    if ( checkM(matrix1) == 1){
                        freeMyMatrix(matrix1);
                    }
                    choose_size(&size);
                    printf("Введите число, из которого хотите создать матрицу.\n");
                    scanf("%d",&value);
                    AnyValue_Matrix(matrix1, ringInfo, value, size,size);
                    printM(matrix1);
                    goto A;
                }
            }
            goto A;
        }
        if (selected == 2){
            int select2 = 0;
            printf("Какую операцию вы хотите произвести?\n"
                   "1. Вычислить определитель матрицы.\n"
                   "2. Получить транспонированную матрицу.\n"
                   "3. Получение обратной матрицы.\n"
                   "4. Умножение матрицы на скаляр.\n"
                   "5. Добавление линейной комбинации к строке.\n"
                   "6. Получение строки матрицы.\n"
                   "7. Получение столбца матрицы.\n"
                   "8. Exit.\n");
            
            scanf("%d",&select2);
            while (select2 < 8){
                if (select2 == 1){
                    if ( checkM(matrix1) == 0){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    det = getDet(matrix1);
                    printf("det = %d\n",det);
                    goto A;
                }
                if (select2 == 2){
                    if ( checkM(matrix1) == 0){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    transposedMatrix(matrix1);
                    printM(matrix1);
                    goto A;
                }
                if (select2 == 3){
                    if ( checkM(matrix1) == 0 ){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    inverseMatrix(matrix1, result);
                    printM(result);
                    goto A;
                }
                if (select2 == 4){
                    if ( checkM(matrix1) == 0 ){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    printf("Введите число (скаляр): ");
                    scanf("%d",&scalar);
                    MultSc(scalar, matrix1);
                    printM(matrix1);
                    goto A;
                }
                if (select2 == 5){
                    
                }
                if (select2 == 6){
                    if ( checkM(matrix1) == 0 ){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    freeMyStruct(result);
                    result = getMyStruct(result);
                    
                    int line = 0;
                    
                    printf("Введите номер строки, которой хотите получить: ");
                    scanf("%d",&line);
                    
                    GetLine(result, matrix1, line);
                    
                    printM(result);
                    goto A;
                }
                if (select2 == 7){
                    if ( checkM(matrix1) == 0 ){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    freeMyStruct(result);
                    result = getMyStruct(result);
                    
                    int column = 0;
                    
                    printf("Введите номер строки, которой хотите получить: ");
                    scanf("%d",&column);
                    
                    GetColumn(result, matrix1, column);
                    
                    printM(result);
                    goto A;
                }
            }
            goto A;
        }
        if (selected == 3){
            if ( (checkM(matrix1) == 1) && (checkM(matrix2) == 1) ){
                
            }
            int select3 = 0;
            printf("Какую операцию вы хотите произвести?\n"
                   "1. Сумма матриц.\n"
                   "2. Произведение матриц.\n"
                   "3. Exit.\n");
            scanf("%d",&select3);
            while (select3 < 3){
                if (select3 == 1){
                    Sum(result, matrix1, matrix2);
                    printM(result);
                    goto A;
                }
                if (select3 == 2){
                    Mult(result, matrix1, matrix2);
                    printM(result);
                    goto A;
                }
            }
            goto A;
        }
    }
    
    if (checkM(matrix1) != 0 ){
        freeMyStruct(matrix1);
    }
    else if (matrix1 != NULL || checkM(matrix1) == 0){
        free(matrix1);
    }
    
    if (checkM(matrix2) != 0 ){
        freeMyStruct(matrix2);
    }
    else if (matrix2 != NULL || checkM(matrix2) == 0){
        free(matrix2);
    }
    
    if (checkM(result) != 0 ){
        freeMyStruct(result);
    }
    else if (result != NULL || checkM(result) == 0){
        free(result);
    }
    free(ringInfo);
    
    return 0;
}
