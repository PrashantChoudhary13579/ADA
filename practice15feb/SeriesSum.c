// Writing a program for printing the sum of the series -  1/1! + 1/2! +1/3! +.... + 1/n! 

/*

Algorithm:

int factorial(int n,int f){
    if (n == 1) return 1;
    else{
        f = f*n;    
        
    }
    return factorial(n-1,f);
}
float Series(int n, int value,float sum){
    if(n == value) return sum;
    else{
        sum += 1/factorial(value,1);
    }
    Series (n,value+1,sum);
}



*/


#include<stdio.h>
int factorial(int n){
    if(n==0) return 1;
    if (n == 1) return 1;
   
    return n*factorial(n-1);
}
float Series(int n, int value,float sum){
    if(n < value) return sum;
    
    sum += 1.0/factorial(value);
    
    return Series (n,value+1,sum);
}

int main(){
    int n;
    printf("Enter the value of n ");
    scanf("%d",&n);

    float s = Series(n,1,0);
    printf("Sum = %f\n",s);
    // printf("Factorail = %d ",factorial(5,1));
    return 0;
}