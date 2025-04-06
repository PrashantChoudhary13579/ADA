#include<iostream>
#include<vector>
#include<climits>
using namespace std;

#define N 12
#define INF INT_MAX

void ShortestDistance(int graph[N][N]){

    vector<int> dist(N,INF);
    dist[N-1] = 0;
    cout<<N-1<<" -> "<<dist[N-1]<<endl;
    vector<int> d(N,-1);
    int val;
    for(int i = N-2; i>=0 ; i--){    
        for( int j = i+1 ; j < N ; j++){
            if(graph[i][j] != INF && graph[i][j] + dist[j] < dist[i])
            {
                dist[i] = graph[i][j] + dist[j];
                d.push_back(j);
            }

        }
    }

    cout<<"Minimum distance from source to sink = "<<dist[0]<<endl;
}

int main(){
    
    int grap[12][12]={
        {INF, 7 , 3 , 1 , 4 ,INF,INF,INF,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF, 8 , 4 ,INF,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF, 6 , 10,INF,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF, 2 , 11,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF, 4 ,INF,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,INF, 8 ,INF,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,INF, 14, 13,INF,INF},
        {INF,INF,INF,INF,INF,INF,INF,INF,INF, 12, 6 ,INF},
        {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF, 4 },
        {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF, 7 },
        {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF, 9 },
        {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF}
    };
    ShortestDistance(grap);
    return 0;
}


// int graph[N][N] =
    // {{INF, 1, 2, 5, INF, INF, INF, INF},
    //  {INF, INF, INF, INF, 4, 11, INF, INF},
    //  {INF, INF, INF, INF, 9, 5, 16, INF},
    //  {INF, INF, INF, INF, INF, INF, 2, INF},
    //  {INF, INF, INF, INF, INF, INF, INF, 18},
    //  {INF, INF, INF, INF, INF, INF, INF, 13},
    //  {INF, INF, INF, INF, INF, INF, INF, 2},
    // {INF, INF, INF, INF, INF, INF, INF, INF}};
 