#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ofstream file("used_detail.txt");
    if(file.is_open()){
        file<<"Name: Prashant Choudhary\n";
        file<<"Age: 20\n";
        cout<<"Data written successfully!\n";
        file.close();
    }
    else{
        cout<<"Error opening the file";
    }
    return 0;
}

// ofstream - for writing inside the file.
// ifstream - for reading from the file.

