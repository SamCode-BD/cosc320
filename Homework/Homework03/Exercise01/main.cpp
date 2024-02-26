// Author: Samuel Dickerson
// Creation Date: 2/21/2024
// Last Update: 2/23/2024
// Description: A program that contains a function that can count the amount of true returns from the beginning of an array or vector to the end from any function pointer that points to a function that returns a boolean and takes in two constant references to a templated data type as parameters.
// User Interface: none
// Notes: none

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T> using boolfctptr = bool (*)(const T &, const T &);
template <class T> int count(T*, T*, const T &, bool (*)(const T &, const T &));
template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, bool (*)(const T &, const T &));

template <class T> bool Greater(const T &, const T &);
template <class T> bool Less(const T &, const T &);
template <class T> bool Equal(const T &, const T &);

int main() {
    // Arrays for example.
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    int arr2[7] = {4, 4, 2, 9, 0, 3, 4};
    
    long num = count(arr1, arr1 + 7, 3, Greater);
    cout << num << endl;
    num = count(arr1, arr1 + 7, 1, Equal);
    cout << num << endl;
    num = count(arr2, arr2 + 7, 4, Equal);
    cout << num << endl;
    num = count(arr2, arr2 + 7, 4, Less);
    cout << num << endl;
    
    // Vectors for example.
    vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
    vector<int> vec2 = {4, 4, 2, 9, 0, 3, 4};
    num = count(vec1.begin(), vec1.end(), 1, Equal);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Equal);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Less);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Greater);
    cout << num << endl;
    return 0;
}
// will produce the following output;
// 4
// 2
// 3
// 3
// 2
// 3
// 3
// 1

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and a pointer to a function that takes in two constant references of a templated data type and returns a boolean
//Return: integer
//Notes:
template <class T> int count(T* A, T* B, const T & a, bool (*f)(const T &, const T &) ){
    int count = 0; //initialize the count
    bool check = false; //initialize the boolean to be changed by the function
    while (A < B){ //while the beginning is less than the end
        check = f(*A,a); //get the output of the function when it is passed a pointer to the current value of the array and the target value
        if (check) //if the function outputs true then iterate count
            count++; 
        A = A + 1; //iterate the place in the array
    }
    return count;
}

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and a pointer to a function that takes in two constant references of a templated data type and returns a boolean
//Return: integer
//Notes:
template <class T> int count(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, bool (*f)(const T &, const T &)){
    int count = 0; //initialize the count
    bool check = false; //initialize the boolean to be changed by the function
    while (A < B){ //while the beginning is less than the end
        check = f(*A,a); //get the output of the function when it is passed a pointer to the current value of the array and the target value
        if (check) //if the function outputs true then iterate count
            count++; 
        A = A + 1; //iterate the place in the array
    }
    return count;
}

//Description: Returns true if the first parameter value is greater than the second
//Parameters: Two constant references to templated values
//Return: boolean
//Notes:
template <class T> bool Greater(const T & a, const T & b){
    if (a > b)
        return true;
    else
        return false;
}

//Description: Returns true if the first parameter value is less than the second
//Parameters: Two constant references to templated values
//Return: boolean
//Notes:
template <class T> bool Less(const T & a, const T & b){
    if (a < b)
        return true;
    else
        return false;
}

//Description: Returns true if the parameter values are equal to each other
//Parameters: Two constant references to templated values
//Return: boolean
//Notes:
template <class T> bool Equal(const T & a, const T & b){
    if (a == b)
        return true;
    else
        return false;
}
