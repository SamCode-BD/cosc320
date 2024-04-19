#ifndef SET_H_
#define SET_H_
#include <iostream>

#include "RBTree.h"
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Set{
private:
//     struct Element{
//         RBTreeNode<T> *element;
//     };
    
    void clear();
public: 
    RBTree<T> rbTree;
    Set(){};
    Set(const Set& copySet){};
    ~Set(){};
    
    //function definitions
    void insert(T);
    void erase(T);
    bool find(const T&);
    bool isEmpty();
    int getSize() const;
    void toVector(vector<T> &);
    void toArray(T*&) const;
    
    bool operator==(const Set& otherSet) const{
        if (getSize() != otherSet.getSize())
            return false;
        T* arr1 = new T[getSize()];
        T* arr2 = new T[otherSet.getSize()];
        
        toArray(arr1);
        otherSet.toArray(arr2);
        
        for (int i = 0; i < getSize(); i++){
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
        
        delete[] arr1;
        delete[] arr2;
    }
    
    bool operator!=(const Set& otherSet) const{
        if (getSize() != otherSet.getSize())
            return true;
        T* arr1 = new T[getSize()];
        T* arr2 = new T[otherSet.getSize()];
        
        toArray(arr1);
        otherSet.toArray(arr2);
        
        for (int i = 0; i < getSize(); i++){
            if (arr1[i] != arr2[i])
                return true;
        }
        return false;
        delete[] arr1;
        delete[] arr2;
    }
    
    bool operator<(const Set& otherSet) const{
        if (getSize() >= otherSet.getSize())
            return false;
        T* arr1 = new T[getSize()];
        T* arr2 = new T[otherSet.getSize()];
        T* tmp = new T[getSize()];
        toArray(arr1);
        otherSet.toArray(arr2);
        
        for (int i = 0; i < getSize(); i++){
            for (int j = 0; j < otherSet.getSize(); j++){
                if (arr1[i] == arr2 [j])
                    tmp[i] = arr1[i];
            }
        }
        for (int i = 0; i < getSize(); i++){
            if (arr1[i] != tmp[i])
                return false;
        }
        return true;
        
        delete[] arr1;
        delete[] arr2;
        delete[] tmp;
    }
    
    bool operator<=(const Set& otherSet) const{
        if (getSize() > otherSet.getSize())
            return false;
        T* arr1 = new T[getSize()];
        T* arr2 = new T[otherSet.getSize()];
        T* tmp = new T[getSize()];
        toArray(arr1);
        otherSet.toArray(arr2);
        
        for (int i = 0; i < getSize(); i++){
            for (int j = 0; j < otherSet.getSize(); j++){
                if (arr1[i] == arr2 [j])
                    tmp[i] = arr1[i];
            }
        }
        for (int i = 0; i < getSize(); i++){
            if (arr1[i] != tmp[i])
                return false;
        }
        return true;
        delete[] arr1;
        delete[] arr2;
        delete[] tmp;
    }
    
    bool operator>(const Set& otherSet) const{
        if (otherSet.getSize() >= getSize())
            return false;
        T* arr1 = new T[otherSet.getSize()];
        T* arr2 = new T[getSize()];
        T* tmp = new T[otherSet.getSize()];
        otherSet.toArray(arr1);
        toArray(arr2);
        
        for (int i = 0; i < otherSet.getSize(); i++){
            for (int j = 0; j < getSize(); j++){
                if (arr1[i] == arr2[j])
                    tmp[i] = arr1[i];
            }
        }
        for (int i = 0; i < otherSet.getSize(); i++){
            if (arr1[i] != tmp[i])
                return false;
        }
        return true;
        delete[] arr1;
        delete[] arr2;
        delete[] tmp;
    }
    
    bool operator>=(const Set& otherSet) const{
        if (otherSet.getSize() > getSize())
            return false;
        T* arr1 = new T[otherSet.getSize()];
        T* arr2 = new T[getSize()];
        T* tmp = new T[otherSet.getSize()];
        otherSet.toArray(arr1);
        toArray(arr2);
        
        for (int i = 0; i < otherSet.getSize(); i++){
            for (int j = 0; j < getSize(); j++){
                if (arr1[i] == arr2[j])
                    tmp[i] = arr1[i];
            }
        }
        for (int i = 0; i < otherSet.getSize(); i++){
            if (arr1[i] != tmp[i])
                return false;
        }
        return true;
        
        delete[] arr1;
        delete[] arr2;
        delete[] tmp;
    }
    
    Set operator+(const Set& otherSet) const{
        Set<T> newSet;
        
        T* arr1 = new T[getSize()];
        T* arr2 = new T[otherSet.getSize()];
        
        int maxSize =  max(getSize(), otherSet.getSize());
//         if (getSize() < otherSet.getSize()){
//             maxSize = otherSet.getSize();
//         }
//         else
//             maxSize = getSize();
        
        toArray(arr1);
        otherSet.toArray(arr2);
        cout << "i made it here";
        for (int i = 0; i < maxSize; i++){
            mySet.rbTree.insert(arr1[i]);
            //newSet.rbTree.insert(arr2[i]);
        }
        return newSet;
    }
    
    friend ostream& operator<<(ostream& os, const Set& mySet){
        T* arr1 = new T[mySet.getSize()];
        mySet.toArray(arr1);
        os << "{";
        for (int i = 0; i < mySet.getSize()-1; i++){
            os << arr1[i] << ", ";
        }
        os << arr1[mySet.getSize()-1];
        os << "}";
        return os;
    }
};

template <class T>
bool Set<T>::isEmpty(){
    if (rbTree.getRoot() == nullptr){ //getRoot returns pointer the root, if null set is empty
        return true;
    }
    else                            //else set not empty
        return false;
}

template <class T>
int Set<T>::getSize() const{
    int size = 0;
    rbTree.inOrderTraverse(size);
    return size;
}

template <class T>
void Set<T>::clear(){
    rbTree.clear();
}

template <class T>
void Set<T>::insert(T val){
    if (rbTree.find(val)){
        return;
    }
    rbTree.insert(val);
}

template <class T>
void Set<T>::erase(T val){
    rbTree.remove(val);
}

template <class T>
bool Set<T>::find(const T& val){
    if (rbTree.find(val))
        return true;
    else
        return false;
}

template <class T>
void Set<T>::toVector(vector<T>& vec){
    rbTree.inOrderTraverse(vec);
}

template <class T>
void Set<T>::toArray(T*& arr) const{
    rbTree.inOrderTraverse(arr);
}

#endif
