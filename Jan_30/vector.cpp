#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> v;
    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    v.push_back(3);

    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    v.push_back(4);

    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    v.push_back(5);

    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    v.push_back(6);

    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;

    v.resize(5);
    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;

    v.resize(10);
    cout << "Size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << endl;
    cout << "Printing the values " << endl;
    // for (int i = 0; i < v.size(); i++)
    // {
        
    //     for (int j = 0; j < v.size(); j++)
    //     {
    //         cout << v[j] << " ";
            
            
    //     }
    //     v.pop_back();
    //     // cout<<v[i]<<" ";
    //     cout<<endl;
    // }

    // for each loop
    v.insert(v.begin()+2,11);
    v.insert(v.end()-1,21);
    for(int ele:v){
        cout<<ele<<" ";
    }

    v.erase(v.end()-2);
    v.erase(v.end()-5);
    v.erase(v.end()-8);

    cout<<endl;
    // while loop
    int index = 0;
    while(index < v.size()){
        cout<<v[index++]<<" ";
    }


    // find the last occurrence of an element x in a given vector.
    vector <int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(1);
    int x = 4;
    index = v.size();
    while( index != -1 ){
        if(vec[index] == x)
        {
            cout<<"Index = "<<index<<endl;
            break;
        }
        index--;
        if(index == -1){
            cout<<"Not found"<<endl;
        }
        
    }
    
    return 0;
    


    
}

// v.clear , v.pop_back() , v.erase(pointer), v.insert(), v.push_back(), v.size() , v.resize(), v.capacity(), v.front(), v.begin(), v.end(), v.back()
// v.at(index) , v.front() , v.back() , v[0] , v
