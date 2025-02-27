#include<iostream>
#include<vector>
using namespace std;
// null graph - with no edges
// trivial grpah - with only one vertex
// undirected graph - containing edges but do not direction
// directed graph - containing edges and direction
// connected graph - all nodes are visited
// disconnected graph - atleast one node is unvisited
// regular graph - degree of every vertex = k 
// complete graph - each node there is an edge to each other node.
// cycle graph - graph in form of cycle
// cyclic graph - containing atleat one cycle
// weighted graph - edges already specified with a suitable weight

// implementing the graph into adjacency matrix

// incase of directed graph 

class Graph{
    vector<vector<int>> matrix;
public:
    Graph (int n){
        matrix = vector<vector<int>>(n,vector<int>(n,0));
    }
    void add_edge(int u, int v){
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    void display(){
        cout<<"Matrix : "<<endl;
        int n= matrix.size();
        for(int i=0 ; i< n;i ++){
            for(int j=0; j <n ; j++){
                cout<<matrix[i][j] <<" ";
            }
            cout<<endl;
        }
    }

};


int main(){
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    Graph g(n);
    g.display();
    g.add_edge(1,0);
    g.add_edge(1,3);
    g.add_edge(0,0);
    g.add_edge(2,2);
    g.display();
    return 0;
}