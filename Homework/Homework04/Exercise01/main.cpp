// Author: Samuel Dickerson
// Creation Date: 2/26/2024
// Last Update: 2/27/2024
// Description: A program that counts comparisons of data to a target value in an array or vector by way of two count functions. The first has four parameters: a pointer to a templated value that marks the beginning of an array, a pointer to a templated value that marks the end of an array, a constant reference to a templated value, and an auto parameter. The second also has four parameters: a templated vector iterator that marks the beginning of the vector, a templated vector iterator that marks the end of the vector, a constant reference to a templated value, and an auto parameter. The fourth parameter of the count functions is auto so that it can take in the lambda expressions and GreaterEqual function (created to take in two templated data types and return true if the first is greater or equal to the second), and use them in the body of the count to actually count the values that are of the condition of the function. There are also four calls to a count function in which a lambda expression that returns true if a is less than or equal to b is passed as the fourth parameter. 
// User Interface: none
// Notes: must type cast the count functions to the type of the array or vector being passed 

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//Function prototypes
template <class T> long count(T*, T*, const T &, auto);
template <class T> long count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, auto);
template <class T> bool GreaterEqual(T, T);

int main() {
    
    auto Greater = [](auto a, auto b) {return (a > b);}; //lambda expression to return true if a is greater than b and false otherwise
     
    auto Less = [](auto a, auto b) {return (a < b);}; //lambda expression to return true if a is less than b and false otherwise
    
    auto Equal = [](auto a, auto b) {return (a == b);}; //lambda expression to return true if a is equal than b and false otherwise
    // Arrays for example.
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    double arr2[7] = {4, 4, 2, 9, 0, 3, 4};
  
    //function calls for array 1
    cout << count<int>(arr1, arr1 + 7, 3, Greater) << endl; //cast all to int because arr1 is an int
    cout << count<int>(arr1, arr1 + 7, 1, Equal) << endl;
    cout << count<int>(arr1, arr1 + 7, 1, Less) << endl;
    cout << count<int>(arr1, arr1 + 7, 2, GreaterEqual<int>) << endl;
    
    //function calls for array 2
    cout << count<double>(arr2, arr2 + 7, 4, Greater) << endl; //cast all to double because arr2 is a double
    cout << count<double>(arr2, arr2 + 7, 4, Equal) << endl;
    cout << count<double>(arr2, arr2 + 7, 7, Less) << endl;
    cout << count<double>(arr2, arr2 + 7, 5, GreaterEqual<double>) << endl;
  
    //vectors for example.
    vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
    vector<double> vec2 = {4, 4, 2, 9, 0, 3, 4};
    
    //function calls for vector 1
    cout << count<int>(vec1.begin(), vec1.end(), 3, Greater) << endl;   //cast all to int because vec1 is an int
    cout << count<int>(vec1.begin(), vec1.end(), 1, Equal) << endl; 
    cout << count<int>(vec1.begin(), vec1.end(), 1, Less) << endl;
    cout << count<int>(vec1.begin(), vec1.end(), 2, GreaterEqual<int>) << endl;
    
    //function calls for vector 2
    cout << count<double>(vec2.begin(), vec2.end(), 4, Greater) << endl; //cast all to double because vec2 is a double
    cout << count<double>(vec2.begin(), vec2.end(), 4, Equal) << endl;
    cout << count<double>(vec2.begin(), vec2.end(), 7, Less) << endl;
    cout << count<double>(vec2.begin(), vec2.end(), 5, GreaterEqual<double>) << endl;
    
    //function calls with less than or equal to lambda expression in the fourth parameter
    cout << count<int>(arr1, arr1 + 7, 5, [](auto a, auto b) -> bool{return a <= b;}) << endl; //cast to int for arr1, lambda expression that returns true if a is less than or equal to b as fourth parameter
    cout << count<double>(arr2, arr2 + 7, 5, [](auto a, auto b) -> bool{return a <= b;}) << endl; //cast to double for arr2, lambda expression that returns true if a is less than or equal to b as fourth parameter
    cout << count<int>(vec1.begin(), vec1.end(), 5, [](auto a, auto b) -> bool{return a <= b;}) << endl; //cast to int for vec1, lambda expression that returns true if a is less than or equal to b as fourth parameter
    cout << count<double>(vec2.begin(), vec2.end(), 5, [](auto a, auto b) -> bool{return a <= b;}) << endl; //cast to double for vec2, lambda expression that returns true if a is less than or equal to b as fourth parameter
    
    return 0;
}

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and an auto function
//Return: long
//Notes:
template <class T> long count(T* A, T* B, const T & a, auto f ){
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
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and an auto function
//Return: long
//Notes:
template <class T> long count(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, auto f){
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

//Description: Returns true if the first templated value is greater than or equal to the second and false otherwise
//Parameters: Two templated data types
//Return: boolean
//Notes:

template <class T> bool GreaterEqual(T a, T b) {
    return (a >= b);
}
