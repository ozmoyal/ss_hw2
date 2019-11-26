#include <stdio.h>
#include <string.h>
#include "myBank.h"
int main(){
char c ;
do{
printf("O for open new account\n");
printf("B for check yours balance\n");
printf("D for deposit\n");
printf("W for withdraw\n");
printf("C for close yours account\n");
printf("I for add interest\n");
printf("P for priint all accounts\n");
printf("E to close all accounts\n");
scanf(" %c",&c);
switch(c)
    {
        case 'O':
            openAccount();
            break;
        case 'B':
            getBalance();
            break;
        case 'D':
            deposit();
            break;
        case 'W':
            withdraw();
            break;
        case 'C':
            closeAccount();
            break;
        case 'I':
            addInterest();
            break;
        case 'P':
            printAll();
            break;
        case 'E':
            closeAll();
            break;
        // operator doesn't match any case constant
        default:
            printf("Error! operator is not correct\n");
    }
} while(c!= 'E');

return 0;
}