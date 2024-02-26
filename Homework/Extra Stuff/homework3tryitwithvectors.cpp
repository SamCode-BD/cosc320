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
#include <fstream>

using namespace std;

template <class T> using boolfctptr = bool (*)(const T &, const T &);
template <class T> using voidfctptr = void (*)(T &);
template <class T> int count(T*, T*, const T &, boolfctptr<T>);
template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const T &, boolfctptr<T>);
template <class T> void alter(T*, T*, voidfctptr<T>);
template <class T> void alter(typename vector<T>::iterator, typename vector<T>::iterator, voidfctptr<T>);

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
    
    ifstream inputFile; //open an infile object
    cout << "Input the dictionary file name." << endl; //prompt
    string fileName; //create a fileName string for opening
    cin >> fileName; //take in user input
    inputFile.open(fileName, ios::in); //open the input file object
    
    int size = 0;//declare size variable
    string line; //temporarily store strings for counting
    while (getline(inputFile, line)) //get each line
        size++; //count the number of lines in the file
    string wordArr[size]; //make an array with the size of the file
    cout << size << endl;
    
    inputFile.clear(); //go back to the top of the file 
    inputFile.seekg(0);
    
    int i = 0;
    while (!inputFile.eof() && i < size){ // while not at the end of the file and i is less than size
        getline(inputFile, line); //take in the line of an input file and put it into a string called line
        wordArr[i] = substrto(line, "/"); //set the element of the array to the string returned from the substrto function from line up to "/"
        i++; //increment to the array
    }
    inputFile.close();  //close the file
    
    alter(wordArr, wordArr + size, ucaseref); //change the whole array to upper case
    string the = "THE"; 
    cout << count(wordArr, wordArr + size, the, hassubstr) << endl;
    string er = "ER";
    cout << count(wordArr, wordArr + size, er, endswith) << endl;
    cout << count(wordArr, wordArr + size, the, startswith) << endl;
    string t = "T";
    cout << count(wordArr, wordArr + size, t, startswith) << endl;
    string qTot[] = {"Q", "R", "S", "T", "U"}; //initialize an array of the letters starting at Q up to and including U
    int amount = 0; //set an amount to count the number of words that start with Q up to and including U
    for (int i = 0; i < 5; i++){
        amount += count(wordArr, wordArr + size, qTot[i], startswith); //call the count function for every string in the array 
    }
    cout << amount  << endl; 
    string letters[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M"}; //initialize an array of the letters starting at A up to and including M
    int total = 0; //set a total to count the number of words that start with A up to and including M
    for (int i = 0; i < 13; i++){
        total += count(wordArr, wordArr + size, letters[i], startswith); //call the count function for every string in the array
    }
    cout << total  << endl;
    
/*    
    for (int i = 0; i < size; i++){
        cout << wordArr[i] << " "; //print the array;
    }*/
//     for (int i = 0; i < size; i++){ //for every element in the array take in the file line
//         getline(inputFile, line);
//         cout << wordArr[i];
//     }
//     vector<string> lines;
//     while (getline(inputFile, line))
//         lines.push_back(line);
//     for (const auto& str : lines)
//         cout << str << endl;
//     for (int i = 0; i < size; i++){
//         cout << wordArr[i] << " ";
//     }
    //     cout << ucase("hello") << endl;
    //     cout << lcase("WoRlD") << endl;
    //     string f = "heLLo";
    //     ucaseref(f);
    //     cout << f << endl;
    //     lcaseref(f);
    //     cout << f;
    //     string x = "Give them";
    //     string y = "em";
    //     string g = "banana";
    //     string h = "ba";
    //     cout <<hassubstr(x, y);
    //     cout << endswith(x, y) << endl;
    //     cout << startswith(x, y) << endl;
    //     cout << endswith(g, h) << endl;
    //     cout << startswith(g, h) << endl;
    //     cout << substrto(x, y);
    return 0;
}

//Description: Initializes a integer variable named count, and then iterates through the array from the first pointer parameter to the second pointer parameter, and for each array value, compares it to the target value parameter by way of the function pointer paramter. If the function pointer returns true, the count variable is incremented.
//Parameters: Two pointers to templated data types, a constant reference to a templated data type, and a pointer to a function that takes in two constant references of a templated data type and returns a boolean
//Return: integer
//Notes:
template <class T> int count(T* A, T* B, const T & a, boolfctptr<T> f){
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
template <class T> int count(typename vector<T>::iterator A, typename vector<T>::iterator B, const T & a, boolfctptr<T> f){
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
template <class T> void alter(T* A, T* B, voidfctptr<T> f){
    while (A < B){
        f(*A);
        A = A + 1;
    }
}

//Description:
//Parameters: two vector iterators of a templated type, a constant reference to a templated data type, and a pointer to any function that returns void and takes in a reference to a templated data type as its parameter
//Return:
//Notes:
template <class T> void alter(typename vector<T>::iterator A, typename vector<T>::iterator B, voidfctptr<T> f){
    while (A < B){
        f(*A);
        A = A + 1;
    }
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
    if (hassubstr(a,b)){
        return a.substr(0, a.find(b));
    }
    else
        return a;
}

//Description: returns true if the second string is a substring of the first
//Parameters: two constant references to strings
//Return: boolean
//Notes:
bool hassubstr(const string & a, const string & b){ 
    if (a.find(b) != string::npos){
        return true;
    }
    else
        return false;
} 

//Description: Returns true if the second string is equal to the start of the first
//Parameters: two constant references to strings
//Return: boolean
//Notes:
bool startswith(const string & a, const string & b){
    int bLength = b.length();
    char x[a.length()];  
    strcpy(x, a.c_str());
    char y[bLength];  
    strcpy(y, b.c_str());
    for (int i = 0; i < bLength; i++){
        if (x[i] != y[i])
            return false;
    }
    return true;
}

//Description: Returns true if the second string is equal to the end of the first;
//Parameters: two constant refernces to strings
//Return: boolean
//Notes:
bool endswith(const string & a, const string & b){
    int aLength = a.length();
    int bLength = b.length();
    
    char x[aLength];
    strcpy(x, a.c_str());
    
    char y[bLength];
    strcpy(y, b.c_str());
    
    for (int i = (aLength - 1), j = (bLength - 1); j >= 0; i--, j--){
        if (x[i] != y[j]){
            return false;
        }
    }
    return true;
}

