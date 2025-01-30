// 2D peak through iteration
# include <iostream>
using namespace std;

void two_d_peak(int arr[][3], int n){
    for (int i = 0;i < n;i ++){
        for (int j = 0 ;j < n ; j ++)
        {
            if ((arr[i][j] > arr[i-1][j] )&&(arr[i][j] > arr[i+1][j] )&&(arr[i][j] > arr[i][j-1] )&&(arr[i][j] > arr[i][j+1] )){
            cout<<"Peak element is "<<arr[i][j]<<" at ("<<i<<","<<j<<")"<<endl;
            break;
            }
        }
    }
}
int main(){
    int arr[3][3]={{2,5,8},{5,3,9},{1,4,7}};
    two_d_peak(arr,3);
}