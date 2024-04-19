// Author: Samuel Dickerson/ Most implementation from Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/15/24
// Description: // Implementation file for the IntBinaryTree class
// user made functions for homework 5 are at the bottom
// User Interface: none
// Notes:

#include <iostream>
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
        sortInOrder(nodePtr->right, A, i);
    }    
}
