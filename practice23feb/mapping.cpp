#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    // creating a map of string to integers

    map<string,int> mp;
    // the key = string, and value in it is integer 
    // in map, the first one which we want to write in the map is the key and the second which we write is type of value we want to take in it. 

    // therefore mp["string"] = integer 

    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    //getting an iterator pointing to the first element in the map
    map<string,int>::iterator it = mp.begin();
    // this declare an iterator which starts from begin as the value in it 

    // And then the while loop will go on further until it comes to the end of the map happens 

    while(it != mp.end()){
        cout<<"Key: "<< it->first<<", Value: "<<it->second<<endl;
        ++it;
    }

}

// We are having a time complexity of O(n)
// We are having a space complexity of O(n)
// where n is the size of the map.