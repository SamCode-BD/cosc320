// Author: Samuel Dickerson
// Creation Date: 2/26/2024
// Last Update: 2/26/2024
// Description: 
// User Interface: none
// Notes: none

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T> using boolfctptr = bool (*)(const T &, const T &);
template <class T> int count(T*, T*, const T &, auto);
//template <class T> int count(T*, T*, const T &, boolfctptr<T>);
template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, auto);
//template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, boolfctptr<T>);

template <class T> bool GreaterEqual(T, T);

int main() {
    
    auto Greater = [](auto a, auto b) {return (a > b);};
    
    auto Less = [](auto a, auto b) {return (a < b);};
    
    auto Equal = [](auto a, auto b) {return (a == b);};
    // Arrays for example.
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    double arr2[7] = {4, 4, 2, 9, 0, 3, 4};
    //vectors for example.
    vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
    vector<double> vec2 = {4, 4, 2, 9, 0, 3, 4};
    //function calls for array 1
//     cout << count(arr1, arr1 + 7, 3, Greater) << endl;
//     cout << count(arr1, arr1 + 7, 1, Equal) << endl;
//     cout << count(arr1, arr1 + 7, 1, Less) << endl;
    cout << count(arr1, arr1 + 7, 2, GreaterEqual) << endl;
    //function calls for array 2
//     cout << count(arr2, arr2 + 7, 4, Greater) << endl;
//     cout << count(arr2, arr2 + 7, 4, Equal) << endl;
//     cout << count(arr2, arr2 + 7, 7, Less) << endl;
    cout << count(arr2, arr2 + 7, 5, GreaterEqual) << endl;
    //function calls for vector 1
//     cout << count(vec1.begin, vec1.end(), 3, Greater) << endl;
//     cout << count(vec1.begin, vec1.end(), 1, Equal) << endl; 
//     cout << count(vec1.begin, vec1.end(), 1, Less) << endl;
    cout << count(vec1.begin, vec1.end(), 2, GreaterEqual) << endl;
    //function calls for vector 2
//     cout << count(vec2.begin, vec2.end(), 4, Greater) << endl;
//     cout << count(vec2.begin, vec2.end(), 4, Equal) << endl;
//     cout << count(vec2.begin, vec2.end(), 7, Less) << endl;
    cout << count(vec2.begin, vec2.end(), 5, GreaterEqual) << endl;
//     long num = count(arr1, arr1 + 7, 3, Greater);
//     cout << num << endl;
//     num = count(arr1, arr1 + 7, 1, Equal);
//     cout << num << endl;
//     num = count(arr2, arr2 + 7, 4, Equal);
//     cout << num << endl;
//     num = count(arr2, arr2 + 7, 4, Less);
//     cout << num << endl;
    
    //Vectors for example.
//     vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
//     vector<double> vec2 = {4, 4, 2, 9, 0, 3, 4};
//     num = count(vec1.begin(), vec1.end(), 1, Equal);
//     cout << num << endl;
//     num = count(vec2.begin(), vec2.end(), 4, Equal);
//     cout << num << endl;
//     num = count(vec2.begin(), vec2.end(), 4, Less);
//     cout << num << endl;
//     num = count(vec2.begin(), vec2.end(), 4, Greater);
//     cout << num << endl;
    return 0;
}

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and a pointer to a function that takes in two constant references of a templated data type and returns a boolean
//Return: integer
//Notes:
template <class T> int count(T* A, T* B, const T & a, auto f ){
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
template <class T> int count(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, auto f){
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

template <class T> bool GreaterEqual(T a, T b) {
    return (a >= b);
}
