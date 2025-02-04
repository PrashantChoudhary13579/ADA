#include<iostream>
using namespace std;

void print(int **arr, int n){
    cout<<"Magic Square :"<<endl;
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<arr[i][j]<<" ";
        }
         cout<<endl;
    }
   
}
void magic_square(int **arr, int n){
    int row = 0; int col = n/2;
    int i= 1;
    while(i <= n*n){

        arr[row][col] = i;
        int new_row = row -1;
        int new_col = col -1;
        if(new_row < 0){
            new_row = n-1;
        }
        if(new_row >= n){
            new_row = 0;
        }
        if(new_col < 0){
            new_col = n-1;
        }
        if(new_col >= n){
            new_col = 0;
        }

        if(arr[new_row][new_col]!= 0){
            row += 1;
        }
        else{
            row = new_row;
            col = new_col;
        }
        i++;

    }
    print(arr,n);
}
int main(){
    cout<<"Enter size (n x n)"<<endl;
    int n;
    cin>>n;
    // dynamic memeory allocation through new 
    int **arr = new int*[n];
    for(int i = 0 ; i < n ; i ++){
        arr[i] = new int[n];
    }
    cout<<"Enter the digits "<<endl;
    for(int i= 0 ; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=0;
        }
    }

    magic_square(arr,n);
    return 0;

}