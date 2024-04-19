// Author: Samuel Dickerson
// Creation Date: 4/10/24
// Last Update: 4/17/24
// Description: Program that times the insertion of n nodes into AVL tree, then the insertion of n nodes into a red black tree, then calculates the length of the IPL for the AVL and red black, then times the insertion of a provided amount of insertion and deletion cycles and times the cycles for both trees. All outputs are sent to a comma separated list in .txt file
// User Interface: Asks the user for the number of nodes in the tree, upper bound of element range, and the amount of insertion and deletion cycles
// Notes:

#include <iostream>
#include "RBTree.h"
#include "AVLTree.h"
#include "timer.h"
#include "fstream"

using namespace std;

int main(){
    srand(time(0));
    
    AVLTree<int> AVLtree; //create trees
    RBTree<int> RBtree;
    
    int numNodes, upperBound, cycles; //define elements
    double start, finish;
    
    ofstream outputFile; //create output stream for a file to copy data to spreadsheet
    outputFile.open("data.txt");
    
    cout << "How many nodes would you like in the tree?" << endl; // input tree size
    cin >> numNodes;
    
    cout << "What would you like the upper bound of the integer values to be (lower bound is zero)?" << endl; //input upper bound for element range
    cin >> upperBound;
    
    cout << "How many insertion and deletion cycles would you like to do?" << endl;
    cin >> cycles;
    
    GET_TIME(start);
    for (int i = 0; i < numNodes; i++){ //insert the n nodes with the element range to AVL Tree
        AVLtree.insertNode(rand() % upperBound + 1);
    }
    GET_TIME(finish);
    
    cout << "Time for AVLTree: " << finish - start << endl; //report time
    outputFile << finish - start << ", "; //output to file for comma separated list to spreadsheet
    
    GET_TIME(start);
    for (int i = 0; i < numNodes; i++){ //insert the n nodes with the element range to Red-Black Tree
        RBtree.insert(rand() % upperBound + 1);
    }
    GET_TIME(finish);
    
    cout << "Time for Red-Black Tree: " << finish - start << endl; //report time
    outputFile << finish - start << ", "; //output to file for comma separated list to spreadsheet
    
    double avlIPL = AVLtree.getIPL();
    cout << "The average internal path length of the AVL tree is: " << avlIPL << endl;
    
    double rbIPL = RBtree.getIPL();
    cout << "The average internal path length of the Red-Black tree is: " << rbIPL << endl;
    
    
    GET_TIME(start); 
    for (int i = 0; i < cycles; i++){ //for the amount of cycles
        AVLtree.insertNode(rand() % upperBound + 1); //insert node
        int delVal = rand() % upperBound + 1; //create a nodevalue
        while (!AVLtree.searchNode(delVal)) //search for it until its found
            delVal = rand() % upperBound + 1;
        AVLtree.remove(delVal); //delete node with value
    }
    GET_TIME(finish);
    
    cout << "Time for insertion/deletion cycles of AVL tree: " << finish - start << endl;
    outputFile << finish - start << ", "; //output to file for comma separated list to spreadsheet
    
    GET_TIME(start);
    for (int i = 0; i < cycles; i++){
        RBtree.insert(rand() % upperBound + 1); //for the amount of cycles 
        int delVal = rand() % upperBound + 1; //insert node
        while (!RBtree.find(delVal)) //while node not found get new node value
            delVal = rand() % upperBound + 1;
        RBtree.remove(delVal); //delete node with value
    }
    GET_TIME(finish);

    cout << "Time for insertion/deletion cycles of Red-Black Tree: " << finish - start << endl;
    outputFile << finish - start << ", "; //output to file for comma separated list to spreadsheet
    
    outputFile << avlIPL << ", "; //output to file for comma separated list to spreadsheet
    outputFile << rbIPL;
}
