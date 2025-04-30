#include<iostream>
using namespace std;
// sorting according to the profit
void bubbleSort(int arr[3][30], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[1][j] < arr[1][j + 1]) {
                int profit = arr[1][j];
                int weight = arr[2][j];
                int index = arr[0][j];
                arr[0][j] = arr[0][j + 1];
                arr[1][j] = arr[1][j + 1];
                arr[2][j] = arr[2][j + 1];
                arr[0][j + 1] = index;
                arr[1][j + 1] = profit;
                arr[2][j+1] = weight;
            }
        }
    }
}
// sorting according to the index

void sort(int arr[3][30], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
        if (arr[0][j] > arr[0][j + 1]) {
            int index = arr[0][j];
            int profit = arr[1][j];
            int weight = arr[2][j];
            int check = arr[3][j];
            arr[0][j] = arr[0][j + 1];
            arr[1][j] = arr[1][j + 1];
            arr[2][j] = arr[2][j + 1];
            arr[3][j] = arr[3][j + 1];
            arr[0][j + 1] = index;
            arr[1][j + 1] = profit;
            arr[2][j+1] = weight;
            arr[3][j+1] = check;
        }
    }
}

int main(){
    int C = 100;
    int arr[4][30] ={0};
    
    for(int i=1;i<30;i++){
        arr[0][i] = i;
    }
    int m = 20;
    for (int i = 1; i < 3; i ++){
        for (int j = 0; j< 30; j ++){
            arr[i][j] = rand()%m;
        }
    }
    cout<<"Random generated profit and weight"<<endl;
    // printing the profit and weight table
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j< 30; j ++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }      

    bubbleSort(arr,30);
    cout<<"Sorted according to the profit "<<endl;
    // printing the profit and weight table
    for (int i = 0; i < 4; i ++){
        for (int j = 0; j< 30; j ++){
            cout<< arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    // int n = 30;
    // int select[n] = {0};
    // int i = 0;
    
    for(int i =0; i < 30 && C >= 0;i ++){
        cout<<C<<" ";
        if (arr[2][i] < C){
            arr[3][i] = 1;
        }
        else{
            arr[3][i] = static_cast<float>(float( C) / float(arr[2][i]));
        }
        C = C - arr[2][i];
    }
    cout<<endl;
    cout<<"Item selected "<<endl;
    for(int i =0; i<4 ; i++){
        for(int j=0;j<30;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    int i = 0;
    int total_profit;
    while(arr[3][i]!=0){
        total_profit += arr[1][i];
        i++;

    }
    cout<<"Total profit "<<total_profit<<endl;

    // for(int i=0; i<30; i++){
    //     if(arr[3][i] == 1){

    // }}
    sort(arr,30);
    cout<<"Items showing all"<<endl;
    for(int i =0; i<4 ; i++){
        for(int j=0;j<30;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}