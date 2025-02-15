// On 15 feb 11:33
// Writing the program of prime number using the recurrsion
/*
1. Input the n number and send it to the finding_prime(n,2);
2. finding_prime(n,current){
    if(n<current) return;
    if(isPrime == True){
        print(number )}

    }
    finding_prime(n, current+1);

3. isPrime(current, current_root){
    if(current <current_root ) return false;
    if(current_root == 1) return true
    if(current % current_root == 0) return false;
    isPrime(current,current_root -1 );
    
    }

*/
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPrime(int current,int root){
    if(current<root) return false;
    if(root == 1) return true;
    if(current % root == 0) return false;
    return isPrime(current,root -1);
    
}

void finding_prime(int num,int current){
    if(num < current) return ; // Base case
    if(isPrime(current,sqrt(current))){
        printf("%d ",current);
    }
    finding_prime(num,current+1);
}
int main(){
    int num;
    printf("Enter the number ");
    scanf("%d",&num);
    printf("Prime numbers ");
    finding_prime(num ,2);
}