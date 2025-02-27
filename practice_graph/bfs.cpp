// Here I am learning about the breadth first search and BFS for a graph 
// Prashant choudhary is writing the code for it

// Bfs means searching at each level from left to right acc. to adj. matrix 

// BFS is used in many places like - dijkstra , kahn, prims algorithm , to detect cycle in a directed graph , find the shortest path in an unweighted graph 

/* Approach -

1. Enqueue the given source vertex as entered from the user into the queue 
2. And mark it as visited by enabling them true
3. While the queue ! = 0 
4. dequeue the node and mark as visited and print it value (visited = true)
5. And enqueue it's neighbour into the queue
6. AS the process goes on mark them visited to those which are dequeued from it .
7. Repeat the step until the queue == empty

*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj, int s){
    // the size will be stored in n
    int n = adj.size();
    // creating a vector to store the result of traversal
    vector<int> result;
    // creating a queue for bfs
    queue<int> q;
    // creating a vector for marking visited as true and false
    vector<bool> visited(n,false);

    // starting
    visited[s] = true;
    q.push(s);

    // iterate it
    while(!q.empty()){
        int current = q.front();
        q.pop();
        result.push_back(current);

        for(int x : adj[current]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
    return result;
}
int main(){
    vector<vector<int>> adj = {{2,3,1},{0},{0,4},{0},{2}};
    // 
    int src = 0;
    vector<int> ans = bfs(adj,src);

    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}

// bfs means breath first search
// so it will traverse from level 1 , level 2 , and so on ...
// 