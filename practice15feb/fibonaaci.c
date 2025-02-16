// Writing the fibonaaci series
#include <stdio.h>

void fibonaaci(int n,int f0, int f1)
{
    if(n == 1) return ;
    if(n ==2 ) return;
    else{
        int fn = f0+f1;
        printf("%d ",fn );
        fibonaaci(n-1,f1,fn);
    }
}
int main()
{
    int n;
    printf("Enter the number ");
    scanf("%d", &n);
    printf("Fibonaaci series ");
    int f0 = 0;
    int f1 = 1;
    if(n == 1){
        printf("%d ",f0);
    }
    else{
        printf("%d ",f0);
        printf("%d ",f1);
        fibonaaci(n,f0,f1);
    }
}