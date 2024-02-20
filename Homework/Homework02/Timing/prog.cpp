/*
 * Author: Samuel Dickerson
 * Creation Date: 2/16/2024
 * Last Update: 2/16/2024
 * Description: A program that asks the user for an array size, populates an integer arrray with numbers in a way that is appropriate to the scenario being tested (best, worst, or average case running time), and times the sort of four basic sorting algorithms. 
 * User Interface: User must enter the size of an integer array. 
 * Notes:
 */
//include chrono library for timing, algorithm for swap function, iostream
#include <chrono> 
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

//Function Prototypes

template <class T> void bubble(T[], int);
template <class T> void insertion(T[], int);
template <class T> void selection(T[], int);
template <class T> void bubblesort2(T[], int);
template <class T> void timeSort(T[], int , void (*fctptr)(T[], int))

int main(){
    //seed random
    srand(time(0));
    
    //an array of function pointers with template array and integer size parameters
    template <class T>
    void (*fctptr[4])(T[], int);
    
    //populate the function pointer array with the four sorts
    fctptr[0] = bubble
    fctptr[1] = insertion
    fctptr[2] = selection
    fctptr[3] = bubblesort2
    
    //size of the integer array
    int size; 
    cout << "Enter an integer to populate the array with" << end; //ask for n
    cin >> size;
    
    //three dynamically created integer arrays with n elements, one for each scenario
    int A[] = new int[size];
    int A1[] = new int[size];
    int A2[] = new int[size];
    
    // for loop to populate an array of n values sorted from least to greatest in order to simulate best case scenario
    for (int i = 0; i < size; i++){
        A[i] = i;
    }
    
    //for loop to populate an array of n values sorted from greatest to least in order to simulate worst case scenario    
    for (int i = 0; i < size; i++){
        A1[i] = size - i;
    }
    
    //for loop to populate an array of n values sorted randomly to simulate average case scenario
    for (int i = 0; i < size; i++){
        A2[i] = rand() % size + 1;
    }
    
    //print the arrays to see if they populate correctly
    for (int i = 0; i < size; i++){
        cout << A[i] << endl;
        cout << A1[i] << endl;
        cout << A2[i] << endl;
    }
    
    timeSort(A, size);
    timeSort(A1, size);
    timeSort(A2, size);
    
    //print the arrays to see if they populate correctly
    for (int i = 0; i < size; i++){
        cout << A[i] << endl;
        cout << A1[i] << endl;
        cout << A2[i] << endl;
    }
    
    delete[] A;
    delete[] A1;
    delete[] A2;
    return 0;
}
/*
Description: A function to time four different sorts and report the time. The function uses an array of function pointers that have been set equal to the four different sort functions.
Parameters: A array of templated values, integer value for the size of the array, a pointer to a function with parameters of a templated array and an integer
Return: None
Notes: timing code taken from Spickler's function pointer folder #3,#4,#5,#7
*/
template <class T> void timeSort(T A[], int size, void (*fctptr)(T[], int)){
    for (int i = 0; i < 4; i++){
        auto start = high_resolution_clock::now();
        fctptr[i](A, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time to sort with algorithm" << i << ": "
        << duration.count() / 1000000.0 << " seconds" << endl;
    }
}

//Description: Array sort using bubble sort algorithm
// Parameters: templated array, integer
// Return: void
// Notes:

template <class T> void bubble(T A[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                T temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

//Description: Array sort using insertion sort algorithm
// Parameters: templated array, integer
// Return: void
// Notes:

template <class T> void insertion(T A[], int size) {
    for (int i = 0; i < size; i++) {
        int j = 0;
        T val = A[i];
        for (j = i; j > 0 && A[j - 1] > val; j--)
            A[j] = A[j - 1];
        A[j] = val;
    }
}

//Description: Array sort using selection sort algorithm
// Parameters: templated array, integer
// Return: void
// Notes:

template <class T> void selection(T A[], int size) {
    int minindex;
    for (int i = 0; i < size; i++) {
        minindex = i;
        for (int j = i; j < size; j++)
            if (A[j] < A[minindex])
                minindex = j;
            T val = A[i];
        A[i] = A[minindex];
        A[minindex] = val;
    }
}

//Description: Array sort using advanced bubble sort algorithm which includes a boolean catch to break out if the array is sorted
// Parameters: templated array, integer
// Return: void
// Notes:
template<class T> void bubblesort2(T A[], int size){
    bool again = true;
    for (int i = 0; i < size-1 && again; i++)
        for (int j = size-1; again = false; j>1; --j)
            if (A[j] < A[j-1]){
                swap(A[j], data[j-1];
                again = true;
            }
}

