//
//  console.h
//  lab1
//
//  Created by Фёдор Булыгин on 19.02.2022.
//

#ifndef console_h
#define console_h

#include <stdio.h>
#include "Sq-Matrix.h"
#include "RingInfo.h"

struct Matrix;
void choose_size(struct Matrix* matrix);
void printM(struct Matrix* m );
int checkM(struct Matrix* matrix);
int checkMultSc(int a, struct Matrix* matrix);
int checkLinColNum(int type,int num, struct Matrix* matrix);
void selectedType(struct Matrix* matrix);


#endif /* console_h */
