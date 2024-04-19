// Author: Samuel Dickerson
// Creation Date: 3/13/24
// Last Update: 3/13/24
// Description: 
// User Interface: 
// Notes: 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "IntBinaryTree.h"
#include "timer.h"

using namespace std;

int main() {
    srand(time(0));
    int n, max;
    double start, finish;
    IntBinaryTree tree;

    cout << "What size do you want your array to be?" << endl;
    cin >> n;
    
        
    int height = ceil(log2(n)) + 1;
    cout << "Height: " << height << endl;
    int *A = new int[n];
        
    for (int i = 0; i < n; i++)
        A[i] = (rand());
        
    max = A[0];
        
    for (int i = 0; i < n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    cout << endl;
    max = max + 1;
        
        
//         GET_TIME(start);
//         tree.loadArray(A, n);
//         tree.sortInOrder(A);
//         GET_TIME(finish);
//         
//         cout << finish - start << ", " << flush;
    //}
    
    GET_TIME(start)
    tree.insertCompleteTree(height);
    tree.insertArr(A, max, n);
    tree.insertMin();
    tree.rootSort(A, max, n);
    GET_TIME(finish);
    
    cout << finish - start << ", " << flush;
    cout << endl;
//     for (int i = 0; i < n; i++)
//         cout << A[i] << " " << endl;
//     cout << endl;
    

    delete[] A;
    return 0;
}
