// Here is an implementation of the map

#include<iostream>
#include<string>
#include<map>

using namespace std;
int main(){
    map<int,int> marks;

    // One way of inserting the values in map
    marks.insert(pair<int,int>(1,90));
    marks.insert(pair<int,int>(2,80));
    marks.insert(pair<int,int>(3,95));
    marks.insert(pair<int,int>(4,78));
    marks.insert(pair<int,int>(5,89));
    marks.insert(pair<int,int>(6,90));

    // Another way of inserting the values in map using direct assigning.
    marks[7] = 70;;
    // printing map 
    map<int,int> ::iterator itr= marks.begin();
    cout<<"\tMarks of ADA "<<endl;
    cout<<"\tRollno\t Marks"<<endl;
    while(itr != marks.end()){
        cout<<"\t"<<itr->first<<"\t"<<itr->second<<endl;
    
        itr++;
    }
    cout<<endl;
    
    // assigning the elements from marks to toppers
    map<int,int> toppers(marks.begin(),marks.end());
    cout<<"Toppers from marks "<<endl;
    cout<<"\tRollno\t Marks\t"<<endl;
    for(itr = toppers.begin(); itr!= toppers.end();itr++){
        cout<<"\t"<<itr->first<<"\t"<<itr->second<<endl;
        
    }
    cout<<endl;
    
    // removing all the elemenst with key less than 3 in toppers
    cout<<"Removing the elements "<<endl; 
    cout<<"\tRollno\t Marks\t"<<endl;
    toppers.erase(toppers.begin(),toppers.find(3));
    for(itr = toppers.begin();itr != toppers.end();itr++){
        cout<<"\t"<<itr->first<<"\t"<<itr->second<<endl;
    }
    cout<<endl;

    // removing the specific element with key = 4
    int num;
    num = toppers.erase(4);
    cout<<"Removing / Erasing the key= 4"<<endl;
    cout<<"\tRollno\t Marks\t"<<endl;

    for(itr = toppers.begin();itr != toppers.end();itr++){
        cout<<"\t"<<itr->first<<"\t"<<itr->second<<endl;
    }
    cout<<endl;


   
    return 0;
    
}