#include<stdio.h>
//Current tax slab but without any rebate,reduction and cess.

int main(){
    double income,tax=0;
    printf("Enter annual income:");
    scanf("%lf",&income);

    if(income<=400000){
        tax=0;
    }else if(income<=800000){
        tax=(income-400000)*0.05;
    }else if(income<=1200000){
        tax=(400000*0.05)+ (income-800000)*0.10;
    }else if(income<=1600000){
        tax=(400000*0.05)+ (400000*0.10)+ (income-1200000)*0.15;
    }else if(income<=2000000){
        tax=(400000*0.05)+ (400000*0.10)+ (400000*0.15)+ (income-1600000)*0.20;
    }else if(income<=2400000){
        tax=(400000*0.05)+ (400000*0.10)+ (400000*0.15)+ (400000*0.20)+ (income-2000000)*0.25;
    }else{
        tax=(400000*0.05)+ (400000*0.10)+ (400000*0.15)+ (400000*0.20)+ (400000*0.25)+ (income-2400000)*0.30;
    }

    printf("Your calculated tax is %lf\n",tax);
    return 0;
    
}