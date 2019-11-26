#include <stdio.h>
#include <string.h>
#include "myBank.h"
double accounts[SIZE][2] = {0};

void openAccount(){
    for (int i = 0; i < SIZE; i++)
    {
        if((int)accounts[i][C0] == 0)
            {
                double sum;
                printf("amount?\n");
                if(scanf("%lf",&sum) != 1)
                {
                    return;
                }
                if(sum <= C0)
                {
                    printf("invalid input\n");
                    return;
                }
                accounts[i][C0] = 1;
                accounts[i][C1] = sum;
                printf("yours account number is:%d\n",(i+ID));
                printf("\n");
                return;
            }
    }
    printf("no empty account available\n");
    return;
}

void getBalance(){
    int accNum;
    printf("enter yours account number:\n");
    if(!scanf("%d",&accNum))
    {
        return;
    }
    if((accNum)>=(ID+SIZE) || (accNum)<ID)
    {
        printf("account does not exist\n");
        return;
    }
    if((int)accounts[accNum-ID][C0])
    {
        printf("yours balance is:%.2lf\n",(accounts[(accNum-ID)][C1]));
        return;
    }
    printf("this account is closed\n");
    return;
}

void deposit(){
    int accNum;
    double sum;
    printf("account number?\n");
    if(!scanf("%d",&accNum))
    {
        return;
    }
    if((accNum)>=(ID+SIZE) || (accNum)<ID || (!(int)accounts[(accNum-ID)][C0]))
    {
        printf("account does not exist\n");
        return;
    }
    printf("amount to deposit?\n");
    if(!scanf("%lf",&sum))
    {
        return;
    }
    if(sum <= C0)
    {
        printf("invalid input\n");
        return;
    }
    if((int)(!accounts[(accNum-ID)][C0]))
    {
        printf("account dons't exist\n");
    }
    else
    {
        accounts[(accNum-ID)][C1] += sum;
        printf("new balance is: %.2lf\n",(accounts[(accNum-ID)][C1]));
        return;  
    }
}

void withdraw(){
    int accNum;
    double amount;
    printf("enter account number\n");
    if(!scanf("%d",&accNum))
    {
        return;
    }
    if((accNum)>=(ID+SIZE) || (accNum)<ID)
    {
        printf("account does not exist\n");
        return;
    }
    if(accounts[(accNum-ID)][C0] == 0)
    {
        printf("this account is closed\n");
        return;
    }
    printf("amount to withdraw:\n");
    if(!scanf("%lf",&amount))
    {
        return;
    }
    if(amount <= 0)
    {
        printf("invalid input\n");
        return;
    }
    else if(accounts[(accNum-ID)][C1] < amount)
    {
        printf("insufficient funs\n");
        return;
    }
    else
    {
        printf("yours new balance is:%.2lf\n",accounts[(accNum-ID)][C1] -= amount);
    }
}

void addInterest(){
    double interest;
    printf("enter interest:\n");
    if(!scanf("%lf",&interest))
    {
        return;
    }
    if(interest <= 0){
        printf("Error, not applicable interest\n");
        return;
    }
    interest = (interest/100)+1;
    for(int i=0;i<SIZE;i++)
    {
        accounts[i][C1] = accounts[i][C1]*interest;
    }
}

void closeAccount(){
    int accNum;
    printf("Enter yours account number\n");
    if(!scanf("%d",&accNum))
    {
        return;
    }
    if((accNum)>=(ID+SIZE) || (accNum)<ID)
    {
        printf("account does not exist\n");
        return;
    }
    if(!accounts[(accNum-ID)][C0])
    {
        printf("This account is already closed\n");
    }
    else
    {
    accounts[(accNum-ID)][C0] = 0;
    accounts[(accNum-ID)][C1] = 0;
    printf("yours account has been closed\n");
    }
}

void printAll(){
    for (int i = 0; i < SIZE; i++)
    {
        if(accounts[i][C0])
        {
        printf("account number:%d\n",(i+ID));
        printf("funs in account:%.2lf\n",accounts[i][C1]);
        }
    }
    
}

void closeAll(){
memset(accounts, 0.0, sizeof(accounts[0][0]) * SIZE * 2);
printf("All accounts are closed\n Goodbye!\n");
}