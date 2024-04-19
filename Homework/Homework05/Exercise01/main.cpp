// Author: Samuel Dickerson
// Creation Date: 3/13/24
// Last Update: 3/15/24
// Description: Program asks user for an array size, then takes in that size and populates an array with random values up to RAND_MAX, and times the process of loading that array into a binary tree and doing an inorder sort of the tree. The program outputs the time the load and sort takes to run.
// User Interface: Asks user to input the size of the array to be sorted
// Notes: 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "IntBinaryTree.h"
#include "timer.h"

using namespace std;

int main() {
    srand(time(0));
    
    //initialize variables
    int n; //array size
    double start, finish;
    IntBinaryTree tree;

    cout << "What size do you want your array to be?" << endl;
    cin >> n;
    
    int *A = new int[n]; //make array
        
    for (int i = 0; i < n; i++) //populate with random values
        A[i] = (rand());

    GET_TIME(start); //time process
    tree.loadArray(A, n);
    tree.sortInOrder(A);
    GET_TIME(finish);
        
    cout << finish - start << ", " << flush; //output
    
    delete[] A;
    return 0;
}
