// Author: Samuel Dickerson/ Most implementation from Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/13/24
// Description: // Implementation file for the IntBinaryTree class
// user made functions for homework 5 are at the bottom
// User Interface: none
// Notes:

#include <iostream>
#include <cmath>
#include "IntBinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);     // Search the left branch
	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num) {
	TreeNode *newNode = nullptr;	// Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
	if (nodePtr) {
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num) {
	TreeNode *nodePtr = root;

	while (nodePtr) {
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num) {
	deleteNode(num, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	} else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else {
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************

void IntBinaryTree::IndentBlock(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
//****************************************************************

void IntBinaryTree::PrintTree(TreeNode *t, int Indent, int Level) {
	if (t != NULL) {
		PrintTree(t->right, Indent, Level + 1);
		IndentBlock(Indent * Level);
		cout << t->value << "\n";
		PrintTree(t->left, Indent, Level + 1);
	}
}

//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left.
//****************************************************************

void IntBinaryTree::PrintTree(int Indent, int Level) {
	if (root != NULL)
		PrintTree(root, Indent, Level);
}

// Description: This function takes an array of integer values and iterates through each element, adding the element as node in a binary search tree
// Parameters: an array of integer values, an integer value for the size of the array
// Return: none
// Notes: 
void IntBinaryTree::loadArray(int *A, int n){
    for (int i = 0; i < n; i++)
        insertNode(A[i]);
}

// Description: a recursive function that does an inorder walk of a binary search tree, and at each visit, assigns the value of an array to the value of the node, and increments the array index.
// Parameters: The function takes in a pointer to a root node as a parameter, a pointer to an array by reference as a second parameter, and a integer value by reference as a third parameter.
// Return: none
// Notes: 
void IntBinaryTree::sortInOrder(TreeNode* nodePtr, int *&A, int& i){
    if (nodePtr){
        sortInOrder(nodePtr->left, A, i);
        A[i++] = nodePtr->value;
        //cout << A[i] << " " << nodePtr->value << " " << i << endl;
        sortInOrder(nodePtr->right, A, i);
    }    
}

// Description: 
// Parameters: a pointer by reference to a TreeNode structure
// Return: none
// Notes: 
void IntBinaryTree::insertCompleteTree(TreeNode *&nodePtr, int i, int height){
    if (i < height){
        nodePtr = new TreeNode();
        nodePtr->value = 0;
        insertCompleteTree(nodePtr->left, i + 1, height); 
        insertCompleteTree(nodePtr->right, i + 1, height);
    }
}

// Description: 
// Parameters: a pointer by reference to a TreeNode structure
// Return: none
// Notes: 
void IntBinaryTree::insertArr(TreeNode *&nodeptr, int *&A, int &i, int max, int sizeArr){
    if (nodeptr){
        insertArr(nodeptr->left, A, i, max, sizeArr);
        insertArr(nodeptr->right, A, i, max, sizeArr);
        if (!nodeptr->left && !nodeptr->right){
            if (i < sizeArr)
                nodeptr->value = A[i++];
            else
                nodeptr->value = max;
        }
    }
}

// Description: 
// Parameters: a pointer by reference to a TreeNode structure
// Return: none
// Notes: 
void IntBinaryTree::insertMin(TreeNode *&nodeptr){
    if (nodeptr->left && nodeptr->right){ //if the node has both children
        insertMin(nodeptr->left); //recursive call on left child
        insertMin(nodeptr->right); //recursive call on right child
        nodeptr->value = min(nodeptr->left->value, nodeptr->right->value); //set value of the current node to the min value of the two children
    }
}

// Description: 
// Parameters: a pointer by reference to a TreeNode structure
// Return: none
// Notes: 
void IntBinaryTree::rootSort(TreeNode *&nodeptr, int *&A, int &i, int max, int sizeArr){
    TreeNode* tmp = nodeptr; //create a tmp = to the root node passed
    //cout << "tmp is made" << endl;
    for (int i = 0; i < sizeArr; i++){ //for loop for every array element
        A[i] = nodeptr->value; //cout << "element set" << endl;//set first element of array to min value which is in root
        //nodeptr->value = max; cout << "max set" << endl;// set root value to max
        while (nodeptr->left != nullptr && nodeptr->right != nullptr){ //while nodeptr != null
            //cout << "while loop begun" << endl;
            if (nodeptr->left->value == A[i]){ //if left value is equal to min value, or first array element, then go left
                //cout << "left if statement true" << endl;
                nodeptr = nodeptr->left;
                //cout << "nodeptr moved left" << endl;
                nodeptr->value = max; //replace min value with max
                //cout << "min replaced with max on left" << endl;
            }
            else {//min is on the right
                //cout << "min is on the right true" << endl;
                nodeptr = nodeptr->right; //go right
                //cout << "nodeptr moved right" << endl;
                nodeptr->value = max; //replace min with max;
                //cout << "min replaced with max on right" << endl;
            }
        }
        nodeptr = tmp; //set nodeptr back to the root
        //cout << "nodeptr set back to root" << endl;
        insertMin(nodeptr); //insert min so that the next minimum value will populate array
        //cout << "insert min called" << endl;
    }
}

