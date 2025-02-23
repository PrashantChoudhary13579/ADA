// In this program we are trying to generate the rnadomness of the string from a given string names, let see what will happen 
#include<iostream>
#include<string>
#include<map>
#include<ctime>
#include<vector>
#include<cstdlib>
using namespace std;
int main(){
    map<int, string> stu;
    vector <string> names ={"Prashant", "Rudra", "Rupanshi", "Bhumik", "Pratham", "Nidhi"};
    
    srand(time(0));

    for(int i =1; i<=5;i ++){
        int index = rand()%names.size();
        stu[i] = names[index];
    }

    // now printing the names
    for(auto itr: stu){
        cout<<"ID: "<<itr.first<<" -> Name: "<<itr.second<<endl;
    }
    cout<<endl;
    return 0;
}