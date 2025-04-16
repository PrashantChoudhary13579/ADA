#include<iostream>
#include<set>
#include<climits>
#include<utility>
using namespace std;

#define N 8
#define INF INT_MAX

void display(set<int> s){
    for(int val : s){
        cout << val << " ";
    }
    cout << endl;
}

void Unvisited(int graph[N][N]){
    set<int> un;
    for(int i = 0; i < N; i++){
        un.insert(i);
    }
    cout << "Initially Unvisited vertices: ";
    display(un);
}

pair<int, int> min_Edge(int graph[N][N]){
    int min = INF;
    pair<int, int> p = {-1, -1};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j && graph[i][j] < min){
                min = graph[i][j];
                p = {i, j};
            }
        }
    }
    return p;
}

pair<int, int> next_min(int graph[N][N], set<int> &visited){
    int min = INF;
    int from = -1, to = -1;

    for(int u : visited){
        for(int v = 0; v < N; v++){
            if(visited.find(v) == visited.end() && graph[u][v] < min){
                min = graph[u][v];
                from = u;
                to = v;
            }
        }
    }

    return {from, to};
}

void prims(int graph[N][N], set<int> &visited, int temp[N-1][2]){
    pair<int, int> p = min_Edge(graph);
    temp[0][0] = p.first;
    temp[0][1] = p.second;
    visited.insert(p.first);
    visited.insert(p.second);

    for(int i = 1; i < N-1; i++){
        pair<int, int> pi = next_min(graph, visited);
        if (pi.first == -1 || pi.second == -1) {
            cout << "Graph is not connected or invalid input.\n";
            break;
        }
        temp[i][0] = pi.first;
        temp[i][1] = pi.second;
        visited.insert(pi.second);  // only insert the newly visited node
    }
}

int main(){
    int graph[N][N] =
    {{INF, 1, 2, 5, INF, INF, INF, INF},
     {INF, INF, INF, INF, 4, 11, INF, INF},
     {INF, INF, INF, INF, 9, 5, 16, INF},
     {INF, INF, INF, INF, INF, INF, 2, INF},
     {INF, INF, INF, INF, INF, INF, INF, 18},
     {INF, INF, INF, INF, INF, INF, INF, 13},
     {INF, INF, INF, INF, INF, INF, INF, 2},
     {INF, INF, INF, INF, INF, INF, INF, INF}};

    Unvisited(graph);

    set<int> visited;
    int temp[N-1][2] = {0}; // N-1 edges in a spanning tree

    prims(graph, visited, temp);

    cout << "\nEdges in Minimum Spanning Tree (MST):\n";
    int totalCost = 0;
    for(int i = 0; i < N-1; i++){
        int u = temp[i][0];
        int v = temp[i][1];
        int w = graph[u][v];
        cout << "(" << u << "," << v << ") -> Cost: " << w << endl;
        totalCost += w;
    }

    cout << "\nTotal Cost of MST: " << totalCost << endl;

    cout << "\nFinal Visited Nodes: ";
    display(visited);

    return 0;
}
