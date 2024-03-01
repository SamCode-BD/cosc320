// Author: Samuel Dickerson
// Creation Date: 2/27/2024
// Last Update: 2/27/2024
// Description: A program that counts comparisons of data to a target value in an array or vector by way of one count function. The function has parameters: two values of a templated container type P, a constant reference to a templated value type T, and a function of templated type FCT. The fourth parameter of the count functions is templated so that it can take in the lambda expressions and function pointers, and use them interchangeably in the body of the count to actually count the values that are of the condition of the function. There are also four calls to a count function in which a lambda expression that returns true if a is less than or equal to b is passed as the fourth parameter. 
// User Interface: none
// Notes: must type cast the count functions to the type of the array or vector being passed 

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//Function prototypes
template <class T, class P, class FCT> long count(P, P, const T &, FCT); // templates data types as T, container types as P, and function pointers as FCT
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

//Description: Initializes a integer variable named count, and then iterates through the container of type P from the first element to the last element, and, for each element of the templated container, compares it to the target value parameter by way of the templated function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two templated containers of type P, a constant reference to a templated data type T, and function of a templated type FCT type
//Return: long
//Notes:
template <class T, class P, class FCT> long count(P A, P B, const T & a, FCT f ){
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
