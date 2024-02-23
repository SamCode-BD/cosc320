// Author: Samuel Dickerson
// Creation Date: 2/22/2024
// Last Update: 2/22/2024
// Description: 
// User Interface: 
// Notes: 

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

template <class T> using boolfctptr = bool (*)(const T &, const T &);
template <class T> using voidfctptr = void (*)(T &);
template <class T> int count(T*, T*, const T &, bool (*)(const T &, const T &));
template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, bool (*)(const T &, const T &));
template <class T> void alter(T*, T*, const T &, bool (*)(T &));

template <class T> bool Greater(const T &, const T &);
template <class T> bool Less(const T &, const T &);
template <class T> bool Equal(const T &, const T &);

string ucase(string); 
string lcase(string);
void ucaseref(string &);
void lcaseref(string &);
string substrto(string, string);
bool hassubstr(const string &, const string &);
bool startswith(const string &, const string &);
bool endswith(const string &, const string &);

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
    
    cout << ucase("hello") << endl;
    cout << lcase("WoRlD") << endl;
    string f = "heLLo";
    ucaseref(f);
    cout << f << endl;
    lcaseref(f);
    cout << f;
    string x = "Give them";
    string y = "em";
    cout << substrto(x, y);
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
    int count = 0;
    bool check = false;
    while (A < B){
        check = f(*A,a);
        if (check)
            count++;
        A = A + 1;
    }
    return count;
}

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two iterators of a vector with a templated data type, a constant reference to a templated data type, and a pointer to a function that takes in two constant references of a templated data type and returns a boolean
//Return: integer
//Notes:
template <class T> int count(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, bool (*f)(const T &, const T &)){
    int count = 0;
    bool check = false;
    while (A < B){
        check = f(*A,a);
        if (check)
            count++;
        A = A + 1;
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

//Description:
//Parameters: two pointers to templated data types, a constant reference to a templated data type, a pointer to any function that returns void and has a reference to a templated data type as a parameter
//Return:
//Notes:
template <class T> void alter(T* A, T* B, const T & a, void (*f)(T &)){
    
}

//Description:
//Parameters: two vector iterators of a templated type, a constant reference to a templated data type, and a pointer to any function that returns void and takes in a reference to a templated data type as its parameter
//Return:
//Notes:
template <class T> void alter(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, void (*f)(T &)){
    
}

//Description: Function takes in a string by value, converts it to uppercase and returns the new string
//Parameters: string by value
//Return: string
//Notes:
string ucase(string a){
    int i = 0; //increment used for while loop
    a = a.c_str(); //turn a into a character array
    while (a[i]){ //while a[i] is true
        a[i] = toupper(a[i]); //set the character in the array to it's upper case
        i++; //increment i
    }
    return a; //return the character array
}

//Description: Takes in a string by value, converts it to lowercase and returns the new string
//Parameters: string by value
//Return: string
//Notes:
string lcase(string a){
    int i = 0; //increment used for while loop
    a = a.c_str(); //turn a into a character array
    while (a[i]){ //while a[i] is true
        a[i] = tolower(a[i]); //set the character in the array to it's lower case
        i++; //increment i
    }
    return a; //return the character array
}

//Description: Takes in a string by reference, converts it to uppercase and returns the new string
//Parameters: string by reference
//Return: none
//Notes:
void ucaseref(string & a){
    int i = 0; //increment used for while loop
    a = a.c_str(); //turn a into a character array
    while (a[i]){ //while a[i] is true
        a[i] = toupper(a[i]); //set the character to it's upper case
        i++; //increment i
    }
}

//Description: Takes in a string by reference, converts it to lowercase and returns the new string
//Parameters: string by reference
//Return: none
//Notes:
void lcaseref(string & a){
    int i = 0; //increment used for while loop
    a = a.c_str(); //turn a into a character array
    while (a[i]){ //while a[i] is true
        a[i] = tolower(a[i]); //set the character to it's upper case
        i++; //increment i
    }
}

//Description: returns a substring of the first string up to but not including the second string, if the second string is a substring of the first
//Parameters: two strings passed by value
//Return: string
//Notes:
string substrto(string a, string b){
    char c[a.length()];
    if (hassubstr(a,b)){
        for (int i = 0; i < a.length(); i++){
            for (int j = 0; j < b.length(); j++){
                if (a[i] != a[i+j]){
                    cout << a[i] << endl;
                    cout << a[i+j];
                    c[i] = a[i];
                }
            }
        }
        return c;
    }
}

//Description: returns true if the second string is a substring of the first
//Parameters: two constant references to strings
//Return: boolean
//Notes:
bool hassubstr(const string & a, const string & b){ 
    if (a.length() < b.length())
        return false;
    else
        return a.find(b);
} 

//Description:
//Parameters: two constant references to strings
//Return: boolean
//Notes:
bool startswith(const string & a, const string & b){
    
}

//Description: 
//Parameters: two constant refernces to strings
//Return: boolean
//Notes:
bool endswith(const string & a, const string & b){
    
}
