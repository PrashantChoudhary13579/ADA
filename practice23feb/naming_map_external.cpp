// In this program we are taking the values into a vector from an external .txt file into the vector and we will further add on the names to the vector as well as to the file too . 
// We will append in the file not overwrite in it.
#include<iostream>
#include<map>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
// using while loop
void print(vector<string> &v){
    int i=0;
    while(i< v.size()){
        cout<<v[i]<<" ";
        i++;
    }
    cout<<endl;
}
// using for loop
void print1(vector<string> &v){
    cout<<"Vector Elements : "<<endl;
    for(int itr=0; itr< v.size();itr++){
        cout<<v[itr]<<" ";
    }
    cout<<endl;
}

// using the range-based for loop
void print2(vector<string> &v){
    cout<<"Vector Elements: "<<endl;
    for(string num : v){
        cout<<num<<" ";
    }
    cout<<endl;
}
// using vector::iterator
void print3(vector<string> &v){
    cout<<"Vector elements: "<<endl;
    for(vector<string>::iterator it= v.begin(); it!= v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
// using vector::at() 
void print4(vector<string> &vec){
    cout<<"Vector elements: "<<endl;
    for(size_t i=0; i<vec.size();i++){
        cout<<vec.at(i)<<" ";
    }
    cout<<endl;
}
int main(){
    map<int,string> stu;
    ifstream file("names.txt");
    // if(!file){
    //     cout<<"Error while opening the file"<<endl;
    //     return 1;
    // }
    vector <string> names;
    string str;
    print(names);
    while(file>>str){
        names.push_back(str);
    }
    file.close();
    print(names);

    // using copy() with ostream_iterator
    // copy(names.begin(),names.begin()+3,
    // ostream_iterator<string>(cout,"  "));

    // cout<<"Enter the names to add (type STOP for finishing)"<<endl;
    // while(true){
    //     cout<<"Enter the name ";
    //     getline(cin,value);
    //     if(value == "STOP") break;
    //     names.push_back(value);
    // }
    
    // shuffling names randomly
    mt19937 g(time(0));
    shuffle(names.begin(),names.end(),g);

    for(int i = 1; i <=5 && i<=names.size() ;i++){
        stu[i] = names[i-1];
    }

    // displaying the selected random numbers
    cout<<"Displaying the numbers "<<endl;
    for(auto itr: stu){
        cout<<"ID: "<<itr.first<<" -> Name: "<<itr.second<<endl;
    }
    return 0;


}