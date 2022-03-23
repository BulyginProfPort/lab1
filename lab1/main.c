#include <stdio.h>
#include <stdlib.h>
#include "Sq-Matrix.h"
#include "RingInfo.h"
#include "console.h"
#include <time.h>
#include "test.h"

#define printName(a)((printf("Какой тип чиселв в %s вы хотите использовать?\n1.Целочисленные.\n2.Вещественные.\n",#a)))

int main(){
    srand(time(NULL));

    int* x1 = NULL;
    double* y1 = NULL;
    int* x2 = NULL;
    double* y2 = NULL;
    int* ti = NULL;
    double* td = NULL;
    
    void* scalar = NULL;
    void* det = NULL;
    void* temp = NULL;

    struct Matrix* matrix1 = NULL;
    struct Matrix* matrix2 = NULL;
    struct Matrix* result = NULL;

    int selected = 0,chsc = 0, size = 0, k = 0;

    matrix1 = getMyStruct(matrix1);
    result = getMyStruct(result);
    if (testMultInt() == 1){
        printf("Тест 1.1 успешно пройден\n");
    }
    else{
        printf("В 'Тест 1.1' ошибка\n");
    }
    if (testMultDbl() == 1){
        printf("Тест 1.2 успешно пройден\n");
    }
    else{
        printf("В 'Тест 1.2' ошибка\n");
    }
    
    if (testMultScInt() == 1){
        printf("Тест 2.1 успешно пройден\n");
    }
    else{
        printf("В 'Тест 2.1' ошибка\n");
    }
    if (testMultScDbl()== 1){
        printf("Тест 2.2 успешно пройден\n");
    }
    else{
        printf("В 'Тест 2.2'ошибка\n");
    }
    if (testSumInt()== 1){
        printf("Тест 3.1 успешно пройден\n");
    }
    else{
        printf("В 'Тест 3.1'ошибка\n");
    }
    if (testSumDbl()== 1){
        printf("Тест 3.2 успешно пройден\n");
    }
    else{
        printf("В 'Тест 3.2'ошибка\n");
    }
    if (testGetMinorInt()== 1){
        printf("Тест 4.1 успешно пройден\n");
    }
    else{
        printf("В 'Тест 4.1'ошибка\n");
    }
    if (testGetMinorDbl()== 1){
        printf("Тест 4.2 успешно пройден\n");
    }
    else{
        printf("В 'Тест 4.2'ошибка\n");
    }
    printf("\n");
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
                    freeMyTemp(x1, y1);
                    x1 = NULL;
                    y1 = NULL;
                    freeMyMatrix(matrix1);
                    size = 0;
                    printName(matrix1);
                    k =  selectedType(matrix1);
                    choose_size(matrix1);
                    if ( k == 1 ){
                        x1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    else if ( k == 2 ){
                        y1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    Zeroes(matrix1,x1 ,y1);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 2){
                    freeMyTemp(x1, y1);
                    x1 = NULL;
                    y1 = NULL;
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    k =  selectedType(matrix1);
                    choose_size(matrix1);
                    if ( k == 1 ){
                        x1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    else if ( k == 2 ){
                        y1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    Identity_Matrix(matrix1,x1,y1);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 3){
                    freeMyTemp(x1, y1);
                    x1 = NULL;
                    y1 = NULL;
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    k =  selectedType(matrix1);
                    choose_size(matrix1);
                    if ( k == 1 ){
                        x1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    else if ( k == 2 ){
                        y1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    randvv(matrix1,x1,y1);
                    printM(matrix1);
                    goto A;
                }
                if (select1 == 4){
                    freeMyTemp(x1, y1);
                    x1 = NULL;
                    y1 = NULL;
                    freeMyMatrix(matrix1);
                    printName(matrix1);
                    
                    k =  selectedType(matrix1);
                    choose_size(matrix1);
                    if ( k == 1 ){
                        x1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    else if ( k == 2 ){
                        y1 = getNumTemp(1,matrix1, x1, y1);
                    }
                    AnyValue_Matrix(matrix1,x1,y1);
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
                    int tempi = 0;
                    double tempd  = 0.0;
                    if (selectedType(matrix1) == 1){
                        det = malloc(sizeof(void*));
                        det = getDet(matrix1,tempi,tempd,&det);
                        printf("det = %d\n",*(int*)det);
                    }
                    else if(selectedType(matrix1) == 2){
                        det = malloc(sizeof(void*));
                        det = getDet(matrix1,tempi,tempd,&det);
                        printf("det = %f\n",*(double*)det);
                    }
                    goto A;
                }
                if (select2 == 2){
                    if ( checkM(matrix1) == 0){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    temp = malloc(sizeof(void*));
                    transposedMatrix(matrix1,temp);
                    printM(matrix1);
                    free(temp);
                    goto A;
                }
                if (select2 == 3){
                    
                    if ( checkM(matrix1) == 0 ){
                        printf("Ошибка! Дана пустая матрица. Попробуйте создать матрицу.\n");
                        goto A;
                    }
                    int* ti = NULL;
                    double* td = NULL;
                    void* temp = NULL;
                    det = malloc(sizeof(void*));
                    
                    k = selectedType(matrix1);
                    temp = getNumTemp(2, matrix1, temp, temp);
                    
                    if ( k == 1 ){
                        ti = getNumTemp(1,matrix1, ti, td);
                    }
                    else if ( k == 2 ){
                        td = getNumTemp(1,matrix1, ti, td);
                    }
                    
                    inverseMatrix(matrix1, result,ti,td,det,temp);
                    printM(result);
                    if ( k == 1 ){
                        ti = freeMyTemp(ti, td);
                    }
                    else if ( k == 2 ){
                        td = freeMyTemp(ti, td);
                    }
                    free(temp);
                    free(det);
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
            int select3 = 0 , select1 = 0;
            if ( matrix2 == NULL){
                matrix2 = getMyStruct(matrix2);
                printf("Какую марицу вы хотите создать?\n"
                    "1. Матрицу нулей.\n"
                    "2. Еденичную матрицу.\n"
                    "3. Матрицу из произвольных чисел.\n"
                    "4. Матрицы из введённого числа.\n"
                    "5. Exit.\n");
                scanf("%d",&select1);
                if (select1 == 1){
                    size = 0;
                    printName(matrix2);
                    k = selectedType(matrix2);
                    choose_size(matrix2);
                    if ( k == 1 ){
                        x2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    else if ( k == 2 ){
                        y2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    Zeroes(matrix2,x2 ,y2);
                    printM(matrix2);
                }
                if (select1 == 2){
                    printName(matrix2);
                    k =  selectedType(matrix2);
                    choose_size(matrix2);
                    if ( k == 1 ){
                        x2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    else if ( k == 2 ){
                        y2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    Identity_Matrix(matrix2,x2,y2);
                    printM(matrix2);
                }
                if (select1 == 3){
                    freeMyMatrix(matrix2);
                    printName(matrix2);
                    k =  selectedType(matrix2);
                    choose_size(matrix2);
                                        
                    if ( k == 1 ){
                        x2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    else if ( k == 2 ){
                        y2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    randvv(matrix2,x2,y2);
                }
                if (select1 == 4){
                    freeMyMatrix(matrix2);
                    printName(matrix2);
                    
                    k =  selectedType(matrix2);
                    choose_size(matrix2);
                    if ( k == 1 ){
                        x2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    else if ( k == 2 ){
                        y2 = getNumTemp(1,matrix2, x2, y2);
                    }
                    AnyValue_Matrix(matrix2,x2,y2);
                    printM(matrix2);
                }
            }
            if ( (checkM(matrix1) == 1) && (checkM(matrix2) == 1) ){
                printM(matrix1);
                printM(matrix2);
                printf("Какую операцию вы хотите произвести?\n"
                        "1. Сумма матриц.\n"
                        "2. Произведение матриц.\n"
                        "3. Exit.\n");
                scanf("%d",&select3);
                while (select3 < 3){
                    if (select3 == 1){
                        freeMyStruct(result);
                        result = getMyStruct(result);
            
                        if ( k == 1 ){
                            ti = getNumTemp(1,matrix1, ti, td);
                        }
                        else if ( k == 2 ){
                            td = getNumTemp(1,matrix1, ti, td);
                        }
                        Sum(result, matrix1, matrix2,ti,td);
                        printM(result);
                        if ( k == 1 ){
                            ti = freeMyTemp(ti, td);
                        }
                        else if ( k == 2 ){
                            td = freeMyTemp(ti, td);
                        }
                        goto A;
                    }
                    if (select3 == 2){
                        freeMyStruct(result);
                        result = getMyStruct(result);
                        
                        if ( k == 1 ){
                            ti = getNumTemp(1,matrix1, ti, td);
                        }
                        else if ( k == 2 ){
                            td = getNumTemp(1,matrix1, ti, td);
                        }
                        Mult(result, matrix1, matrix2,ti,td);
                        printM(result);
                        if ( k == 1 ){
                            ti = freeMyTemp(ti, td);
                        }
                        else if ( k == 2 ){
                            td = freeMyTemp(ti, td);
                        }
                        goto A;
                    }
                }
                goto A;
            }
        }
        goto A;
    }
    freeMyStruct(matrix1);
    freeMyStruct(matrix2);
    freeMyStruct(result);
    if ( k == 1 ){
        x1 = freeMyTemp(x1, y1);
    }
    else if ( k == 2 ){
        y1 = freeMyTemp(x1, y1);
    }
    if ( k == 1 ){
        x2 = freeMyTemp(x2, y2);
    }
    else if ( k == 2 ){
        y2 = freeMyTemp(x2, y2);
    }
    return 0;
}
