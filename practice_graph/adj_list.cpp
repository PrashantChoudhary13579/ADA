// About the adjacency list 
#include<iostream>
#include<vector>
using namespace std;

void addedge(vector<vector<int>>& adj, int i, int j){
    adj[i].push_back(j);
    adj[j].push_back(i);
}

void display(const vector<vector<int>> &adj)
{
    for(int i=0;i <adj.size(); i ++){
        cout<<i<<" : ";
        for(int j : adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){

    int v = 5;
    vector<vector<int>> adj(v);

    addedge(adj,2,3);
    addedge(adj,2,1);
    addedge(adj,0,3);
    addedge(adj,1,0);
    addedge(adj,1,3);

    cout<<"Adjacency list: "<<endl;
    display(adj);
    return 0;
}