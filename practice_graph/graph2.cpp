#include<iostream>
#include<vector>
using namespace std;

class Graph{
    vector<vector<int>> list;

public:

    void add(int v){
        // this will resize the vector
        list.resize(v+1);

    }
    void display (){
        for(int i=0; i<list.size();i++){
            cout<<i<<"-->";
            for(int j : list[i]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};
int main(){
    Graph g;
    g.add(7);
    g.display();

    return 0;
}