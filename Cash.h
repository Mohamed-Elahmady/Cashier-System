/** --------------- **/
/**** File Guard ****/
/** ------------- **/

#ifndef CASH_H

/** ------------------------ **/
/**** Sub Linking Section ****/
/** ---------------------- **/

#define CASH_H
#include "Dynamic Stack.h"

/** ------------------------------------ **/
/**** Sub Programs Decleration Section ****/
/** ---------------------------------- **/

Stack_Status coin_intialize(Stack **S1,uint_32 Max,uint_32 S_Max) ;
Stack_Status division_of_rest(Stack **S1,float_32 P_Price,float_32 C_Price,float_32 *Rest,uint_32 Temp);
Stack_Status The_Rest(Stack *S1,float_32 *Rest);
void end_day(uint_32 contine);


#endif //CASH_H
