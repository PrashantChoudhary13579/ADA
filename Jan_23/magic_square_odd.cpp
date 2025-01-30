#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    int arr[5][5] ={ 0 };

    cout<<"Zero Valued 2D Array"<<endl;
    for(int i = 0 ;i < 5 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int row = 0;
    int col = n/2;
    int i = 1;
    while( i <= n*n )
    {
        arr[row][col] = i;

        int next_row = (row - 1 + n) % n ;
        int next_col = (col - 1 + n) % n ;

        if(arr[next_row][next_col] != 0){
            row = (row + 1)% n;
        }
        else{
            row = next_row;
            col = next_col;
        }
        i++;
    }

    cout<<"Magic Square "<<endl;
     for(int i = 0 ;i < 5 ; i++)
    {
        for(int j = 0 ; j < 5 ; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }


}