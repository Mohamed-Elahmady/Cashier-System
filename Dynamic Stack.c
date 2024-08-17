
#include "Dynamic Stack.h"


/********************************************************************************************
 * @Breif  : Function to Create Stack DS Based on array by Dynamic Memory Allocation .....!!
 * @Param1 : The Maximum Number of ELmemnts "The Country Determine it" .....!!
 * @Param2 : Stack Status .....!!
 * @Retval : Stack DS .....!!
 *******************************************************************************************/

Stack *Create(uint_32 Max,Stack_Status *Stat) {
    Stack *S1 = NULL;
    if(NULL == Stat) {
        *Stat = Stack_NULL;
    } else {
        S1 = (Stack *)malloc(sizeof(Stack));
        if (NULL == S1) {
            *Stat = Stack_NOK;
        } else {
            S1->arr = (float_32 *)calloc(Max,sizeof(uint_32));
            if (NULL == S1->arr) {
                *Stat = Stack_NOK;
            } else {
                S1->count = 0;
                S1->Ptr = -1;
                S1->Max = Max;
                *Stat = Stack_OK;
            }
        }
    }
    return S1;
}

/****************************************************************************
 * @Breif  : Function Determines The Stack Case (Empty/FULL/NOTFULL) .....!!
 * @Param1 : Stack DS .....!!
 * @Retval : Stack Status .....!!
 ****************************************************************************/

static Stack_Status Case(Stack *S1) {
    Stack_Status Stat = Stack_NOK;
    if (NULL == S1) {
        Stat = Stack_NULL;
    } else {
        if (S1->Ptr == (S1->Max)-1) {
            Stat = Stack_FULL;
        } else if (S1->Ptr == -1) {
            Stat = Stack_EMPTY;
        }
        else {
            Stat = Stack_NOTFULL;
        }
    }
    return Stat;
}

/*********************************************************
 * @Breif  : Function to Push Coin into The Stack .....!!
 * @Param1 : Stack DS .....!!
 * @Param2 : Coin to Push .....!!
 * @Retval : Stack Status .....!!
 ********************************************************/

Stack_Status Push(Stack *S1, float_32 *data) {
    Stack_Status Stat = Stack_NOK;
    if (NULL == S1 || NULL == data) {
        Stat = Stack_NULL;
    } else {
        if (Case(S1) == Stack_FULL) {
            Stat = Stack_NOK;
        } else {
            (S1->Ptr)++;
            (S1->count)++;
            S1->arr[S1->Ptr] = *data;
            Stat = Stack_OK;
        }
    }
    return Stat;
}

/********************************************************
 * @Breif  : Function to POP Coin From The Stack .....!!
 * @Param1 : Stack DS .....!!
 * @Param2 : Stack Status .....!!
 * @Retval : Coin Was Poped .....!!
 *******************************************************/

float_32 *POP(Stack *S1, Stack_Status *Stat) {
    float_32 *value = NULL;
    if (NULL == S1 || NULL == Stat) {
        *Stat = Stack_NULL;
    } else {
        if (Case(S1) == Stack_EMPTY) {
            *Stat = Stack_NOK;
        } else {
            *value = S1->arr[S1->Ptr];
            (S1->Ptr)--;
            (S1->count)--;
            *Stat = Stack_OK;
        }
    }
    return value;
}

/******************************************************************
 * @Breif  : Function to return Coin From The Top of Stack .....!!
 * @Param1 : Stack DS .....!!
 * @Param2 : Stack Status .....!!
 * @Retval : Coin in The Top .....!!
 *****************************************************************/

float_32 *TOP(Stack *S1, Stack_Status *Stat) {
    float_32 *value = NULL;
    if (NULL == S1 || NULL == Stat) {
        *Stat = Stack_NULL;
    } else {
        if (Case(S1) == Stack_EMPTY) {
            *Stat = Stack_NOK;
        } else {
            *value = S1->arr[S1->Ptr];
            *Stat = Stack_OK;
        }
    }
    return  value;
}

/***********************************************************************
 * @Breif  : Function to Display All Coins From The Stack .....!!
 * @Param1 : Stack Ds Have all Coins .....!!
 * @Param2 : Array of Pointers have all Couuntries Abriviations .....!!
 * @Retval : Stack Status .....!!
 **********************************************************************/

Stack_Status Display(Stack *S1,char *ptr) {
    Stack_Status Stat = Stack_NOK;
    if (NULL == S1) {
        Stat = Stack_NULL;
    } else {
        if (Case(S1) == Stack_EMPTY) {
            Stat = Stack_NOK;
        }
        else {
            printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t||\t     You have in %s the coin :\t\t\t               ||\n",ptr);
            printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
            for (int i = 0; i < S1->Max; ++i) {
                printf("\t\t\t\t\t||\t\t   %2.3f \t\t\t\t\t       ||\n",S1->arr[i]);
            }
            printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
            Stat= Stack_OK;
            }
    }
    return  Stat;
}

/*************************************************
 * @Breif  : Function to Destroy Stack DS .....!!
 * @Param1 : Stack DS .....!!
 * @Retval : Stack Status .....!!
 ************************************************/

Stack_Status Destroy(Stack *S1) {
    Stack_Status Stat = Stack_NOK;
    if (NULL == S1) {
        Stat = Stack_NULL;
    } else {
        free(S1->arr);
        free(S1);
        S1 = NULL;
        Stat = Stack_OK;
    }
    return  Stat;
}
