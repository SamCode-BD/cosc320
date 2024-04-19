// Author: Samuel Dickerson
// Creation Date: 3/13/24
// Last Update: 3/15/24
// Description: A program that populates an array of user input size with values from 0 to RAND_MAX, then calculates the necessary height of a complete tree for the bottom row to include one node for every array element, then sets a max value to 1 + the maximum value of the array, and finally times the sorting process. The sorting process consists of making a complete tree of height h, inserting the array to the bottom row of the tree, inserting the minimum values to the above nodes, and then replacing the root with the next largest node until all the array elements have been accounted for.
// User Interface: asks user for an array size
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
    
    //initialize variables
    int n, max; //array size, max elemet of array
    double start, finish;
    IntBinaryTree tree;

    cout << "What size do you want your array to be?" << endl;
    cin >> n;
    
        
    int height = ceil(log2(n)) + 1; //find height of tree to be used later
    cout << "Height: " << height << endl;
    int *A = new int[n]; //make new array of n size
        
    for (int i = 0; i < n; i++)
        A[i] = (rand()); //populate with random values
        
    max = A[0]; //set max to a value
        
    for (int i = 0; i < n; i++){ //iterate through the array to find the max
        if (A[i] > max){
            max = A[i];
        }
    }
    cout << endl;
    max = max + 1; //add one to the array max to get element E outside of array
        
    GET_TIME(start) //time process
    tree.insertCompleteTree(height); //create empty tree of height h
    tree.insertArr(A, max, n); //insert array to bottom layer
    tree.insertMin(); //insert min values for each node above bottom layer
    tree.rootSort(A, max, n); //sort
    GET_TIME(finish);
    
    cout << finish - start << ", " << flush; //output time
    cout << endl;

    delete[] A;
    return 0;
}
