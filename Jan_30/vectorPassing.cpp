#include<iostream>
#include<vector>
using namespace std;

// 1st code

// void print(vector<int> &data){
//     for (int i = 0; i < data.size(); i++){
//         cout<<data[i]<<" ";
//     }
// }

// int main(){
//     vector <int> v = {1,2,3,4,5,6,7,9};
//     print(v);

// }


// 2nd Code
int main(){
    vector <vector<int>> numbers = {{11,22,33},{222,333,444}};

    for(int i = 0; i <2;i++){
        for(int j = 0; j < 3; j++){
            cout<<numbers[i][j]<<" ";
        }
        cout<<endl;
    }
}