#include "RBTree.h"
#include "set.h"
#include <vector>

#include <iostream>
using namespace std;

int main(){
    Set<int> mySet;
    Set<int> mySet2;
    cout << mySet.getSize() << endl;
    cout << mySet.isEmpty() << endl;
    
    mySet.insert(7);
    mySet.insert(4);
    mySet.insert(18);

    
    cout << mySet.getSize() << endl;
    cout << mySet.isEmpty() << endl;
    
    mySet.erase(18);
    
    cout << mySet.getSize() << endl;
    cout << mySet.isEmpty() << endl;
    
    cout << mySet.find(7) << endl;
    cout << mySet.find(1244) << endl;
    
    mySet.insert(5);
    mySet.insert(11);
    mySet.insert(24);
    mySet.insert(24);
    
    vector<int> myVec;
    mySet.toVector(myVec);
    
    for (int i = 0; i < mySet.getSize(); i++)
        cout << myVec[i] << " ";
    cout << endl;
    
    int* arr = new int[mySet.getSize()];
    mySet.toArray(arr);
    
    for (int i = 0; i < mySet.getSize(); i++){
        cout << arr[i] << " ";
    }
    
    if (mySet != mySet2){
        cout << "true" << endl;
    };
    
    mySet2.insert(5);
    mySet2.insert(11);
    mySet2.insert(4);
    mySet2.insert(7);
    mySet2.insert(24);
    mySet2.insert(25);
    
    if (mySet == mySet2){
        cout << "True" << endl;
    }
    
    Set<int> mySet3;
    mySet3.insert(11);
    mySet3.insert(25);
    
    Set<int> mySet4;
    mySet4.insert(4);
    mySet4.insert(5);
    mySet4.insert(7);
    mySet4.insert(11);
    mySet4.insert(24);
    
    cout << (mySet3 < mySet) << endl;
    cout << (mySet < mySet3) << endl;
    cout << (mySet3 < mySet2) << endl;
    cout << (mySet4 < mySet) << endl;
    
    cout << (mySet3 > mySet) << endl;
    cout << (mySet > mySet3) << endl;
    cout << (mySet3 > mySet2) << endl;
    cout << (mySet2 > mySet3) << endl;
    
    cout << (mySet <= mySet2) << endl;
    cout << (mySet3 <= mySet) << endl;
    cout << (mySet4 <= mySet) << endl;
    
    cout << (mySet >= mySet2) << endl;
    cout << (mySet3 >= mySet) << endl;
    cout << (mySet4 >= mySet) << endl;
    
    cout << mySet;
    
    Set<int> mySet5;
    mySet5.insert(100);
    
    
    Set<int> mySet3u5;
    mySet3u5 = mySet3 + mySet5;
    
    
}
