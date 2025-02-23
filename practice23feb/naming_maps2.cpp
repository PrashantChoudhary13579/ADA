// The part 1 have a small problem that it produce the output which contains the duplicate values.
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
#include<random>

using namespace std;
int main(){
    map<int, string> stu;
    // Using the map in which each integer value is assign with the name
    vector<string> names ={"Prashant", "Choudhary","Yadav","Bhati", "Rudra","Pratap","Singh"};
    string value;
    cout<<"Enter the names you want to add to the list (Type 'STOP' to finish)"<<endl;
    while(true){
        cout<<"Enter the name ";
        getline(cin,value);
        if(value =="STOP") break;
        names.push_back(value);
    }
    // making a vector and we can add on the values in the vector

    // srand(time(0));

    // random_device rd;
    mt19937 g(time(0));
    // produce a random value each time

    shuffle(names.begin(),names.end(),g);
    // shuffle and give a unique value

    for(int i=1; i<=5;i++){
        stu[i] = names[i-1];
    }
    // assign and filling the value in the stu map (ordered map) from the vector names.
    cout<<endl;
    cout<<"Keys and Values are "<<endl; 
    for(auto itr: stu){
        cout<<"ID: "<<itr.first<<" -> Name: "<<itr.second<<endl;
    }
    // this for loop is used for printing the keys and values from the map.
    return 0;

}





// predefined list should be used but the list should be taken from another .txt file and then operations should be performed 