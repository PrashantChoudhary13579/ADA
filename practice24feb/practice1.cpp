// Passing by pointer vs passing by reference in c++

// Passing by pointer 
/*

#include<iostream>
using namespace std;

void swap(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}
// Driven code
int main(){

    int a = 45;
    int b = 132;
    cout<<"Before swapping "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;

    swap(&a,&b);
    
    cout<<"After swapping "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;

}
    */
// Passing by reference 
#include<iostream>
using namespace std;

void swap(int &a, int &b){
    int z = a;
    a = b;
    b = z;
}
int main(){
    int a = 1;
    int b = 2;
    cout<<"Before swapping "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    
    swap(a,b);
    
    cout<<"After swap "<<endl;
    cout<<"a = "<<a<<" b = "<<b<<endl;




}