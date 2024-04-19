// Samuel Dickerson, Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/15/24
// Description: Specification file for the IntBinaryTree class
// Notes:

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

// Samuel Dickerson, Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/15/24
// Description: Class declaration for IntBinaryTree class, includes a TreeNode struct that consists of a left and right pointer, and an integer value. It also includes private member functions insert, destroySubTree, deleteNode, makeDeletion, displayInOrder, displayPostOrder, displayPreOrder, IndentBlock, PrintTree, and a public constructor, destructor, insert, search, remove, inorder, preorder, and PrintTree. New homework five private member function sortInOrder is included, and public call of sortInOrder and loadArray
// Notes:
class IntBinaryTree {
private:
	struct TreeNode {
		int value;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;

	// Private member functions
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void deleteNode(int, TreeNode*&);
	void makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
	void IndentBlock(int);
	void PrintTree(TreeNode*, int, int);
    void sortInOrder(TreeNode*, int*&, int&); //private member in order sort

public:
	// Constructor
	IntBinaryTree() {
		root = nullptr;
	}

	// Destructor
	~IntBinaryTree() {
		destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(int);
	bool searchNode(int);
	void remove(int);

	void displayInOrder() const {
		displayInOrder(root);
	}

	void displayPreOrder() const {
		displayPreOrder(root);
	}

	void displayPostOrder() const {
		displayPostOrder(root);
	}

	void PrintTree(int Indent = 4, int Level = 0);
    
    //load array function definition
    void loadArray (int*, int);
    
    //public non-recursive in order sort function
    void sortInOrder(int *&A){
        int n = 0;
        sortInOrder(root, A, n);
    };
};
#endif
