#include<iostream>
using namespace std;

void One_Dim_peak(int arr[], int n){
    // int arr [n];
    if (arr[0] > arr[1])
    cout<<"Peak element is "<<arr[0]<<endl;

    if(arr[n]> arr[n-1])
    cout<<"Peak element is "<<arr[n]<<endl;

    for(int i = 1;i< n;i++){
        if(arr[i]>= arr[i-1] && arr[i]> arr[i+1]) {
            cout<<"Peak element is "<<arr[i]<<endl;
        }

    }

}

int main()
{
    int a[10] = {1,4,6,8,3,5,9,51,4,7};
    One_Dim_peak(a,9);
}