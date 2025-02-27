#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<vector<int>>& matrix, int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
    // both are showing that they are connected through an edge 
}
void display( vector<vector<int>> & matrix){
    cout<<"Matrix: "<<endl;
    for(int i = 0 ;i <matrix.size(); i++){
        // for(int j :matrix[i]){
        //     cout<<matrix[i][j]<<" ";
        // }
        for(int j = 0 ; j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    // initializing the vector matrix with 0 
    vector<vector<int>> matrix(n,vector<int>(n,0));

    addedge(matrix, 2,3);
    addedge(matrix, 4,3);
    addedge(matrix, 1,1);
    addedge(matrix, 3,2);
    addedge(matrix, 0,3);
    addedge(matrix, 4,0);

    display(matrix);

    return 0;



}