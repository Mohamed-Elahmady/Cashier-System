/** ------------------------ **/
/**** Sub Linking Section ****/
/** ---------------------- **/

#include "Cash.h"

/** --------------------------- **/
/**** Sub Definetion Section ****/
/** ------------------------- **/

#define PHONE_LENGTH 20

/** ----------------------------------- **/
/**** Sub Global Decleration Section ****/
/** --------------------------------- **/

uint_8 *name_ptr[10000];
uint_8 *phone_ptr[10000][PHONE_LENGTH];
uint_64 customer_counter = 0;
uint_64 cash_register = 0;
FILE *FPTR = NULL;

/** ------------------------------------ **/
/**** Sub Programs Definetion Section ****/
/** ---------------------------------- **/

/******************************************************************************
 * @Breif  : Function to push data into Dynamic Stack .....!!
 * @Param1 : only one Stack that was Created by User .....!!
 * @Param2 : Number of Country .....!!
 * @Param3 : Number of Data that will push into the stack "Stack Size" .....!!
 * @Retval : Stack Status .....!!
 *****************************************************************************/

Stack_Status coin_intialize(Stack **S1,uint_32 Temp,uint_32 S_Max) {
    Stack_Status Stat = Stack_NOK;
    uint_8 *arr_ptr[] = {"EGY","KSA","UAE","KWT"};

    name_ptr[customer_counter] = malloc(250 * sizeof(uint_8));  // Adjust size as needed
        if (name_ptr[customer_counter] == NULL) {
            printf("Memory allocation failed!\n");
            return Stat;
        }

    printf(" \t\t\t\t\t  \t     Enter the Customer Name :  ");
    scanf("%s", name_ptr[customer_counter]);
    fflush(stdin);

    const char *phone_code;
    if (Temp == 0) phone_code = "+20";
    else if (Temp == 1) phone_code = "+966";
    else if (Temp == 2) phone_code = "+971";
    else if (Temp == 3) phone_code = "+965";

    printf(" \t\t\t\t\t  \t     Enter the Customer Phone Number : %s ", phone_code);
    fgets(phone_ptr[customer_counter], 100, stdin);
    phone_ptr[customer_counter][strcspn(phone_ptr[customer_counter], "\n")] = '\0'; // Remove newline character
    // Initialize stack based on selected country
    float_32 *arr;
    if (Temp == 0) {
        float_32 arr_EGY[] = {0.25, 0.5, 1, 5, 10, 20, 50, 100, 200};
        S_Max = 9;
        arr = arr_EGY;
    } else if (Temp == 1) {
        float_32 arr_KSA[] = {0.01, 0.05, 0.1, 0.25, 0.5, 1, 2, 5, 10, 20, 50, 100, 200, 500};
        S_Max = 14;
        arr = arr_KSA;
    } else if (Temp == 2) {
        float_32 arr_AUE[] = {0.01, 0.05, 0.1, 0.25, 0.5, 1, 5, 10, 20, 50, 100, 200, 500, 1000};
        S_Max = 14;
        arr = arr_AUE;
    } else if (Temp == 3) {
        float_32 arr_KWT[] = {0.001, 0.005, 0.01, 0.02, 0.05, 0.1, 0.25, 0.5, 1, 5, 10, 20};
        S_Max = 12;
        arr = arr_KWT;
    }

    *S1 = Create(S_Max, &Stat);
    if (*S1 == NULL || Stat != Stack_OK) {
        printf("Stack creation failed!\n");
        return Stat;
    }

    for (int i = 0; i < S_Max; ++i) {
        Stat = Push(*S1, &arr[i]);
    }
    Stat = Display(*S1, arr_ptr[Temp]);

    return Stat;
}

/**************************************************************************
 * @Breif  : Function to add the Customers Data into File Pointer .....!!
 * @Param1 : Name Pointer that store the name of customer .....!!
 * @Param2 : Phone Pointer that store the Phone number of customer .....!!
 * @Param3 : The Change For The Customer .....!!
 * @Param4 : The Product Price .....!!
 * @Param5 : The Customer pays => .....!!
 * @Retval : Void .....!!
 *************************************************************************/
static void Data_Base(uint_8 *name_ptr, uint_64 phone_ptr, float_32 Res, float_32 p_price, float_32 c_price, uint_8 country_code) {
    const uint_8 *country_codes[] = {"+20", "+966", "+971", "+965"};

    FPTR = fopen("Data.txt", "a+");
    if (FPTR != NULL) {

        fprintf(FPTR, "%u - ",customer_counter+1);
        fprintf(FPTR, "Mr/Mrs : %s\n", name_ptr);
        fprintf(FPTR, "Phone : %s %s\n", country_codes[country_code], phone_ptr);
        fprintf(FPTR, "Bought a product costing %.2f, paid %.2f, and the change is %.2f\n", p_price, c_price, Res);
        fprintf(FPTR, "\n");
        //fclose(FPTR);
        customer_counter++;
    } else {
        printf("Error: Could not open the file!\n");
    }
}

/*********************************************************************
 * @Breif  : Function to Calculate The Change For The Customer .....!!
 * @Param1 : Dynamic Stack has the data that was pushed .....!!
 * @Param2 : The Product Price .....!!
 * @Param3 : The Customer pays => .....!!
 * @Param4 : The Change For The Customer .....!!
 * @Param5 : Number of Country .....!!
 * @Retval : Stack Status .....!!
 ********************************************************************/

Stack_Status division_of_rest(Stack **S1,float_32 P_Price,float_32 C_Price,float_32 *Rest,uint_32 Temp) {
    Stack_Status Stat = Stack_NOK;
    uint_32 int_part = 0;
    float_32 float_part = 0;
    if (NULL == S1) {
        Stat = Stack_NULL;
    }
    else {
        *Rest = C_Price - P_Price;
        if (*Rest < 0) {
            cash_register += 0;
            printf("\t\t\t\t\t||\t     The price is incomplete...!!\t\t\t       ||\n");
             printf("\t\t\t\t\t||\t     Failed purchase...!!\t\t\t               ||\n");
            *Rest = -1;

            Data_Base(name_ptr[customer_counter], phone_ptr[customer_counter], *Rest, P_Price, C_Price, Temp);
        }
        else if(*Rest == 0){
            cash_register += P_Price;
            Data_Base(name_ptr[customer_counter], phone_ptr[customer_counter], *Rest, P_Price, C_Price, Temp);
            printf("\t\t\t\t\t||\t     The price is complete...!!\t\t\t               ||\n");
            printf("\t\t\t\t\t||\t     See You Soon :)  \t\t\t                       ||\n");
        }
        else{
            cash_register += P_Price;
            Data_Base(name_ptr[customer_counter], phone_ptr[customer_counter], *Rest, P_Price, C_Price, Temp);
            float_part = (float)*Rest - (int)*Rest;
            int_part = (int)*Rest;
            printf("\t\t\t\t\t||\t     real_part  = %7hd\t\t\t               ||\n\t\t\t\t\t||\t     float_part = %7.3f\t\t\t               ||\n",int_part,float_part);
        }
        Stat = Stack_OK;
    }
    return Stat;
}

/**************************************************************************************************
 * @Breif  : Function to Calculate The Change For The Customer by the least number of coins .....!!
 * @Param1 : Dynamic Stack has the data that was pushed .....!!
 * @Param2 : The Change For The Customer .....!!
 * @Retval : Stack Status .....!!
 *************************************************************************************************/

Stack_Status The_Rest(Stack *S1,float_32 *Rest){
    Stack_Status Stat = Stack_NOK;
    uint_32 Counter = 0;
    float_32 RES = *Rest;
    if(NULL == S1){
        Stat = Stack_NULL;
    }
    else{
        for(int i = 0; i <S1->Max;i++){
            while(RES - S1->arr[S1->Ptr-i] >= 0)
            {
                Counter++;
                RES = RES - (S1->arr[S1->Ptr-i]);
                //printf("\t\t\t\t\t||\t     ---> %3.5f <---  \t\t       ||\n",S1->arr[S1->Ptr-i]);
                if(RES < S1->arr[S1->Ptr-i]){
                    printf("\t\t\t\t\t||\t     ---> give %hd of %2.3f coin <---\t\t\t       ||\n",Counter,S1->arr[S1->Ptr-i]);
                    Counter = 0;
                }

            }
        }
        printf("\t\t\t\t\t-------------------------------------------------------------------------\n");

    }

}

/***************************************************************
 * @Breif  : Function to End The Cashier System Day .....!!
 * @Param1 : Number greater than or equal 3 to end day .....!!
 * @Retval : Void .....!!
 **************************************************************/

void end_day(uint_32 contine){
    if(contine >= 3){
        fprintf(FPTR,"\nThe End of Day!!\n");
        fprintf(FPTR,"%d was put in the cash register today !! \n",cash_register);
        cash_register = 0;
        fprintf(FPTR,"\n-------------------------------------------------------------------------\n");
    }
}
