// Making a menu driven program using switch case
/*

main(){
    print("Enter the option you want to perform
            1. Add
            2. Subtract
            3. Multiply
            4. Divide
            ");
    scanf("%d",&n);
    print("Enter two number ");
    scanf("%d%d",&a,&b);
    switch(n):
        case 1: 
                int sum = a+b;
                printf("Sum = ",sum);
        case 2: 
            printf("Value = ",a-b);
        case 3:
            printf("Value = ",a*b);
        case 4:
            printf("Value = ",a/b);
        default:
            exit();
}

*/
#include<stdio.h>

int main(){
    int n;
    printf("Enter the option you want to perform \n1. Add \n2. Subtract \n3. Multiply \n4. Divide\n Option ");
    scanf("%d",&n);
    int a, b;
    printf("Enter two number ");
    scanf("%d%d",&a,&b);
    int sum ;
    switch(n){
        case 1: 
            sum =a+b;
            printf("Addition = %d",sum);
            break;
        case 2: 
            printf("Subtraction = %d",a-b);
            break;
        case 3:
            printf("Multiplication =  %d ",a*b);
            break;
        case 4:
            printf("Division = %d ",a/b);
            break;
        default:
            printf("Default case is Matched.");
            break;
    }
    return 0;
}