/** ----------------**/
/**** File Guard ****/
/** ------------- **/

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

/** ------------------------ **/
/**** Sub Linking Section ****/
/** ---------------------- **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlatForm.h"


/** ------------------ **/
/**** Stack Members ****/
/** ---------------- **/

typedef struct {

    float_32 *arr;
    uint_32 Max;
    uint_32 Ptr;
    uint_32 count;
}Stack;

typedef enum {
    Stack_NULL,
    Stack_NOK,
    Stack_OK,
    Stack_FULL,
    Stack_NOTFULL,
    Stack_EMPTY,
}Stack_Status;

/** ------------------------------------ **/
/**** Sub Programs Decleration Section ****/
/** ---------------------------------- **/

Stack *Create(uint_32 Max,Stack_Status *Stat);
Stack_Status Push(Stack *S1, float_32 *data);
float_32 *POP(Stack *S1, Stack_Status *Stat);
float_32 *TOP(Stack *S1, Stack_Status *Stat);
Stack_Status Display(Stack *S1,char *ptr);
Stack_Status Destroy(Stack *S1);

#endif //DYNAMIC_STACK_H
