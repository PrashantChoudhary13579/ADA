// In this example we will deal with the size() function
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    map<string,int> map;

    map["appple"] = 5;
    map["banana"] = 12;
    map["pineapple"] = 2;

    cout<<"Size of the map: "<<map.size()<<endl;

    return 0;
}