// graphs are non-linear data structure

// There are two primary ways to implement grpah data structure.
// 1. Using ADjacency Matrix
// 2. Using Adjacency list

/*
Adjacency matrix is a square matrix (2d vector ) used to represent a finite graph 


*/


#include<iostream>
#include<vector>
using namespace std;

class Graph{
    vector<vector<int>> matrix;

    public:
    // Making a constructor to initialize the graph with n vertices
        Graph(int n){
            matrix = vector<vector<int>>(n,vector<int>(n,0));
        }
        void add_edge(int u, int v){
            matrix[u][v] = 1;
            matrix[v][u] = 1;

        }
        void print(){
            cout<<"Adjaceny matrix for the graph: "<<endl;
            int n = matrix.size();

            for(int i=0; i<n; i++){
                for(int j =0; j <n; j++){
                    cout<<matrix[i][j]<<" ";

                }
                cout<<endl;
            }
        }
};

int main(){
    int n = 4;

    Graph g(n);

    // Adding the specified edges
    g.add_edge(0,1);
    g.add_edge(0,2);
    g.add_edge(1,3);
    g.add_edge(2,3);

    g.print();
    return 0;

}