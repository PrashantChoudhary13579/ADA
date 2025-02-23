// Here we are also doing an example of the map 
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    map<string,int> map = {{"one",1},{"two",2},{"three",3}};

    // cout<<"Key: one, value "<<map["one"]<<endl;
    // cout<<"Key: two, value "<<map["two"]<<endl;
    // cout<<"Key: three, value "<<map["three"]<<endl;

    for(auto a:map){
        cout<<"key: "<<a.first<<", Values: "<<a.second<<endl;
    }

    if(map.count("three")>0){
        cout<<"Key 'three' is in the map"<<endl;
    }
    else{
        cout<<"key 'three' is not in the map"<<endl;
    }
    return 0;
}