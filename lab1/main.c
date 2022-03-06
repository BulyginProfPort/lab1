#include <stdio.h>
#include <stdlib.h>
#include "Sq-Matrix.h"
#include "RingInfo.h"
#include "console.h"
#include <time.h>

#define printName(a)((printf("Какой тип чиселв в %s вы хотите использовать?\n1.Целочисленные.\n2.Вещественные.\n",#a)))

int main(){
    srand(time(NULL));
    int* tempi = NULL;
    double* tempd  = NULL;
    int selected = 0,chsc = 0, size = 0;
    void* scalar = NULL;
    void* det = NULL;
    struct Matrix* matrix1 = NULL;
    struct Matrix* matrix2 = NULL;
    struct Matrix* result = NULL;

    matrix1 = getMyStruct(matrix1);
    result = getMyStruct(result);

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
                    freeMyMatrix(matrix1);
                    size = 0;
                    printName(matrix1);
                    Zeroes(matrix1);
                    
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 2){
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    Identity_Matrix(matrix1);

                    printM(matrix1);
                    goto A;
                }
                if (select1 == 3){
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    randvv(matrix1);
                    
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 4){
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    AnyValue_Matrix(matrix1);
                    
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
                    
                    det = malloc(sizeof(void*));
                    tempd = malloc(sizeof(void*));
                    tempi = malloc(sizeof(void*));
                    
                    getDet(matrix1,tempi,tempd);
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
                    printf("Пожалуйста, ведите тип числа, которого хотите умножить на матрицу.\n1. Целое число.\n2. Вещественное число.\n");
                    scanf("%d",&chsc);
                    while(chsc > 2 || chsc < 0 || checkMultSc(chsc, matrix1) != 1){
                        printf("Введено некорректное значение, попробуйте ещё раз.\n");
                        scanf("%d",&chsc);
                        getchar();
                    }
                    scalar = malloc(sizeof(void*));
                    
                    if (chsc == 1){
                        printf("Введите число (скаляр): ");
                        scanf("%d",(int*)scalar);
                    }
                    else if(chsc ==  2){
                        printf("Введите число (скаляр): ");
                        scanf("%lf",(double*)scalar);
                    }
                    MultSc(scalar, matrix1);
                    printM(matrix1);
                    free(scalar);
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
                    
                    int row = 0;
                    
                    printf("Введите номер строки, которой хотите получить: ");
                    scanf("%d",&row);
                    while( checkLinColNum(1, row, matrix1) != 0 ){
                        printf("Введен номер несуществующей строки, попробуйте ещё раз: ");
                        scanf("%d",&row);
                        getchar();
                    }
                    GetLine(result, matrix1, row);
                    
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
                    
                    printf("Введите номер столбца, которой хотите получить: ");
                    scanf("%d",&column);
                    while(checkLinColNum(2, column, matrix1) != 0){
                        printf("Введен номер несущетвующего столбца, попробуйте ещё раз: ");
                        scanf("%d",&column);
                        getchar();
                    }
                    GetColumn(result, matrix1, column);
                    
                    printM(result);
                    goto A;
                }
            }
            goto A;
        }
        if (selected == 3){
            int select3 = 0;
            if ( (checkM(matrix1) == 1) && (checkM(matrix2) == 1) ){
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
            }
            else{
                printf("Ошибка! 2 матрица не задана, задайте 2-ую матрицу.\n");
                
                goto A;
            }
        }
    }
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    
    return 0;
}
