#include<iostream>
using namespace std;

void one_peak(int arr[], int low, int high,int count){

    int mid = low + (high - low)/2;

    if(arr[mid] < arr[mid-1]) return one_peak(arr, low, mid-1,count+1);

    if(arr[mid] < arr[mid+1]) return one_peak(arr, mid+1, high,count+1);

   
    else
        {
            cout<<"Peak element is "<<arr[mid]<<endl;
            cout<<"Value of count "<<count;
            // break;
        }
    

}

int main(){
    int a[10] = {1,4,6,5,3,5,9,51,4,7};
    int count = 0;
    one_peak(a,0,9,count);

}