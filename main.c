/**************************************
 *  Author : Mohammed Gharieb
 *  Date   : 08 / 09 / 2024
 *  Breif  : Chashier System
 *************************************/

/** --------------------- **/
/**** Liinking Section ****/
/** ------------------- **/

#include <stdio.h>
#include <stdlib.h>
#include "Cash.h"
#include "Dynamic Stack.h"

/** ------------------------------- **/
/**** Global Decleration Section ****/
/** ----------------------------- **/

Stack *S1 = NULL;
Stack_Status Stat = Stack_NOK;

sint_32 Temp = 0;
uint_32 S_Max = 0;
uint_32 Continue = 0;

float_32 P_Price = 0;
float_32 C_Price = 0;
float_32 Rest = 0;


/** ------------------------- **/
/**** Main Program Section ****/
/** ----------------------- **/

int main() {

    // Choose The Country For Starting
    label2:
    printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t|| \t     Enter The number of your Country                          ||\n");
    printf("\t\t\t\t\t|| \t     For EGY Press \"0\"                                         ||\n\t\t\t\t\t|| \t     For KSA Press \"1\"                                         ||\n"
           "\t\t\t\t\t|| \t     For AUE Press \"2\"                                         ||\n\t\t\t\t\t|| \t     For KWT Press \"3\"                                         ||\n"
           "\t\t\t\t\t|| \t     And Press \"-1\" to close The Program                       ||\n");
    printf("\t\t\t\t\t-------------------------------------------------------------------------\n");

    printf(" \t\t\t\t\t  \t     Your Country code = \t");
    scanf("%d",&Temp);


    /*printf(" \t\t\t\t\t\t  \t     Enter the Customer Name : ");
    scanf("%s",&name_ptr[customer_counter]);
    fflush(stdin);
    printf(" \t\t\t\t\t\t  \t     Enter the Customer Phhone Number : +20");
    scanf("%i",&phone_ptr[customer_counter]);
    fflush(stdin);*/

        label1:
    if (Temp > 3) {
        //! For Invalid Country........!!
        printf("\t\t\t\t\t|| \t Invalid country yet please try again !!     \t\t\t||\n");
        goto label1;
    }
    if (Temp == -1) {
    //! To Close the System........!!
    exit(0);
    }
    else {
        //! Enter Product info
        Stat = coin_intialize(&S1,Temp,S_Max);
        printf(" \t\t\t\t\t \t     Enter the Product Price  :    \t\t\t");
        scanf("%f",&P_Price);
        printf(" \t\t\t\t\t \t     Enter the Customer funds :    \t\t\t");
        scanf("%f",&C_Price);
        printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
        if (P_Price < 0 || C_Price < 0) {
            printf("\t\t\t\t\t||\t     invalid Price....!!\t\t      \t\t\t||\n");
        }
        else{
            //! For Calculating the Change ........!!
            Stat = division_of_rest(&S1,P_Price,C_Price,&Rest,Temp);
            printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
            //! For Calculating the Change in least number of coin ........!!
            The_Rest(S1,&Rest);
            //! To continue using the System ........!!
            printf("\t\t\t\t\t||\t     Enter Number to make the next action :\t\t       ||\n");
            printf("\t\t\t\t\t||\t     For continue the Same System \"1\"\t\t\t       ||\n"
                   "\t\t\t\t\t||\t     For change the Country \"2\"\t\t\t               ||\n"
                   "\t\t\t\t\t||\t     For Exit The Program \"any key\"\t\t\t       ||\n");
            printf("\t\t\t\t\t-------------------------------------------------------------------------\n");
            printf("\t\t\t\t\t\t     The System N =    \t\t\t");
            scanf("%d",&Continue);
            switch(Continue){
            case 1:
                goto label1;
                break;
            case 2:
                goto label2;
                break;
            default:
                end_day(Continue);
                exit(0);
                break;
            }
        }
    }
    return 0;
}

/********************************************************************************************************************************
 ============================================ Start History Log =================================================================
              @Date                                 @brief
              -- / -- / ----                        PlatForm intialization "64 CPU FOR PC + GCC Compiler" ....!!
              08 / 08 / 2024                        Stack DS and Pushing Coins into THe Stack ....!!
              08 / 12 / 2024                        Algorithm To Calculate The Least Number of Coins to return The Change ....!!
              08 / 14 / 2024                        File Pointer To Store All Purchases OP ....!!
              08 / 15 / 2024                        The Shape of The Program in the Terminal "CMD" ....!!
============================================ End History Log ====================================================================
********************************************************************************************************************************/
