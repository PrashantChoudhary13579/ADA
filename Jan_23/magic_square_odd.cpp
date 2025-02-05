#include<iostream>
using namespace std;

void print(int **arr, int n){
    cout<<"Magic Square "<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j<n ;j ++){
               cout<<arr[i][j]<<"\t"; 
            }
            cout<<endl;
        }
}
void magic_square(int **arr, int n){
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
    print(arr,n);
}

int main()
{
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    int **arr = new int *[n];
    for(int i = 0 ; i<n; i++){
        arr[i] = new int [n];
    }

    cout<<"Assigning 0 value to the "<<endl;
    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            arr[i][j] = 0;
        }
    }

    magic_square(arr, n);

}
/*
Output -

Enter the value of n 7
Assigning 0 value to the
Magic Square
28      19      10      1       48      39      30
29      27      18      9       7       47      38
37      35      26      17      8       6       46
45      36      34      25      16      14      5
4       44      42      33      24      15      13
12      3       43      41      32      23      21
20      11      2       49      40      31      22



*/