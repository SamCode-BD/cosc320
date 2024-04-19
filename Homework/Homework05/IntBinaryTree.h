// Samuel Dickerson, Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/13/24
// Description: Specification file for the IntBinaryTree class
// Notes:

#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

// Dr. Spickler
// Creation Date: 3/13/24
// Last Update: 3/13/24
// Description: Class declaration for IntBinaryTree class, includes a TreeNode struct that consists of a left and right pointer, and an integer value. It also includes private member functions insert, destroySubTree, deleteNode,
// makeDeletion, displayInOrder, displayPostOrder, displayPreOrder, IndentBlock, PrintTree, and a public constructor, destructor, insert, search, remove, inorder, preorder, and PrintTree
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
    void sortInOrder(TreeNode*, int*&, int&);
    void insertCompleteTree(TreeNode*&, int, int);
    void insertArr(TreeNode *&, int*&, int&, int, int);
    void insertMin(TreeNode *&);
    void rootSort(TreeNode *&, int*&, int&, int, int);

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
    
    //in order sort function
    void sortInOrder(int *&A){
        int n = 0;
        sortInOrder(root, A, n);
    };
    
    void insertCompleteTree(int height){
        int i = 0;
        insertCompleteTree(root, i, height);
    };
    
    void insertArr(int *&A, int max, int n){
        int i = 0;
        insertArr(root, A, i, max, n);
    };
    
    void insertMin(){
        insertMin(root);
    }
    
    void rootSort(int *&A, int max, int n){
        int i = 0;
        rootSort(root, A, i, max, n);
    };
};
#endif
