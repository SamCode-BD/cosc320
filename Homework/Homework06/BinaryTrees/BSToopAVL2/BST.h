#ifndef BST_H_
#define BST_H_

#include "BinaryTree.h"

template <class T, class Node = TreeNode<T>>
class BST : public BinaryTree<T, Node> {
protected:
  void insert(Node *&, Node *&);
  void deleteNode(T, Node *&);
  void makeDeletion(Node *&);
  bool isBST(Node *);

public:
  BST();
  virtual ~BST();

  void insert(T);
  void remove(T);
  bool isBST();

  virtual bool search(const T &);
  virtual Node *findNode(const T &);
};

template <class T, class Node> BST<T, Node>::BST() {}

template <class T, class Node> BST<T, Node>::~BST() {}

template <class T, class Node>
void BST<T, Node>::insert(Node *&nodePtr, Node *&newNode) {
  if (nodePtr == nullptr)
    nodePtr = newNode;
  else if (newNode->value < nodePtr->value)
    insert(nodePtr->left, newNode);
  else
    insert(nodePtr->right, newNode);
}

template <class T, class Node> void BST<T, Node>::insert(T item) {
  Node *newNode = new Node;
  newNode->value = item;
  insert(this->root, newNode);
}

template <class T, class Node> bool BST<T, Node>::search(const T &item) {
  return findNode(item) != nullptr;
}

template <class T, class Node> Node *BST<T, Node>::findNode(const T &item) {
  Node *nodePtr = this->root;

  while (nodePtr) {
    if (nodePtr->value == item)
      return nodePtr;
    else if (item < nodePtr->value)
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  return nullptr;
}

template <class T, class Node> void BST<T, Node>::remove(T item) {
  deleteNode(item, this->root);
}

template <class T, class Node>
void BST<T, Node>::deleteNode(T item, Node *&nodePtr) {
  if (!nodePtr)
    return;

  if (item < nodePtr->value)
    deleteNode(item, nodePtr->left);
  else if (item > nodePtr->value)
    deleteNode(item, nodePtr->right);
  else
    makeDeletion(nodePtr);
}

template <class T, class Node> void BST<T, Node>::makeDeletion(Node *&nodePtr) {
  Node *tempNodePtr = nullptr;

  if (!nodePtr)
    cout << "Cannot delete empty node.\n";
  else if (!nodePtr->right) {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->left;
    delete tempNodePtr;
  } else if (!nodePtr->left) {
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  } else {
    tempNodePtr = nodePtr->right;
    while (tempNodePtr->left)
      tempNodePtr = tempNodePtr->left;
    tempNodePtr->left = nodePtr->left;
    tempNodePtr = nodePtr;
    nodePtr = nodePtr->right;
    delete tempNodePtr;
  }
}

/*
This function is a recursive function to test if the AVL tree
is a BST.
*/
template <class T, class Node> bool BST<T, Node>::isBST(Node *t) {
  if (!t)
    return true;

  bool bstleft = isBST(t->left);
  bool bstright = isBST(t->right);
  bool bstnode = true;
  if (t->left && (t->left->value > t->value))
    bstnode = false;
  if (t->right && (t->right->value < t->value))
    bstnode = false;

  return bstleft && bstright && bstnode;
}

/*
This function initiates a recursive function to test if the AVL tree
is a BST.
*/
template <class T, class Node> bool BST<T, Node>::isBST() {
  if (this->root)
    return isBST(this->root);

  return true;
}


#endif /* BST_H_ */
