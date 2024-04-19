// Author: Samuel Dickerson
// Creation Date: 4/4/24
// Last Update: 4/10/24
// Description: A program that creates two trees, a BST and an AVL, and then times how long it takes to insert n nodes into an AVL tree with a user specified element range, and separately times the insertion of n nodes into a BST with a user specified element range and one DSW balance call after the insertion. The program outputs both of these numbers.
// User Interface: Asks the user for the number of nodes in the tree and the upper bound of the element range. 
// Notes:

#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "timer.h"

using namespace std;

int main(){
    srand(time(0));
    
    BinaryTree<int> BTree; //creation of trees
    AVLTree<int> ATree;
    
    int numNodes, upperBound; //define elements
    double start, finish;
    
    cout << "How many nodes would you like in the tree?" << endl; // input tree size
    cin >> numNodes;
    
    cout << "What would you like the upper bound of the integer values to be (lower bound is zero)?" << endl; //input upper bound for element range
    cin >> upperBound;
    
    GET_TIME(start); //time process
    for (int i = 0; i < numNodes; i++){ //insert the n nodes with the element range
        ATree.insertNode(rand() % upperBound + 1);
    }
    GET_TIME(finish);
    
    cout << "Time for AVLTree: " << finish - start << endl; //report time
    
    GET_TIME(start); //time process
    for (int i = 0; i < numNodes; i++){ //insert the n nodes with the element range
        BTree.insertNode(rand() % upperBound + 1);
    }
    BTree.balance(); //balance the BST
    GET_TIME(finish);
    
     cout << "Time for BinaryTree: " << finish - start << endl; //report time
    
}
