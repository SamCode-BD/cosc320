/*
 * Author: Samuel Dickerson
 * Creation Date: 2/16/2024
 * Last Update: 2/16/2024
 * Description: A program that asks the user for an array arrSize, populates an integer arrray with numbers in a way that is appropriate to the scenario being tested (best, worst, or average case running time), and times the sort of four basic sorting algorithms. 
 * User Interface: User must enter the arrSize of an integer array. 
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
template <class T> void timeSort(T[], T[], int);   /*void (*fctptr[4])(T[], int)*/
template <class T> void printArray(T[], int);
//template <class T> void seedArray(T[], T[], T[], int);

int main(){
    //seed random
    srand(time(0));
    
    //arrSize of the integer array
    int arrSize;
    cout << "Enter an integer to populate the array with" << endl; //ask for n
    cin >> arrSize;
    
    //three dynamically created integer arrays with n elements, one for each scenario
    int *seedA = new int[arrSize];
    int *seedA1 = new int[arrSize];
    int *seedA2 = new int[arrSize];
    
    int *A = new int[arrSize];
    int *A1 = new int[arrSize];
    int *A2 = new int[arrSize];
    
    // for loop to populate an array of n values sorted from least to greatest in order to simulate best case scenario
    for (int i = 0; i < arrSize; i++){
        seedA[i] = i;
    }
    
    //for loop to populate an array of n values sorted from greatest to least in order to simulate worst case scenario    
    for (int i = 0; i < arrSize; i++){
        seedA1[i] = arrSize - i;
    }
    
    //for loop to populate an array of n values sorted randomly to simulate average case scenario
    for (int i = 0; i < arrSize; i++){
        seedA2[i] = rand() % arrSize + 1;
    }
    //for loop to seed the three arrays that will be passed to the timing and sorting algorithms. This will have to be used every time a new sort is ran.
    for (int i = 0; i < arrSize; i++){
        A[i] = seedA[i];
        A1[i] = seedA1[i];
        A2[i] = seedA2[i];
    }
    
    //fctptr[0] = bubble;
    //fctptr[1] = insertion;
    //fctptr[2] = selection;
    //fctptr[3] = bubblesort2;
    
    //print the arrays to see if they populate correctly
    printArray(A, arrSize);
    printArray(A1, arrSize);
    printArray(A2, arrSize);
    
    cout << "Best Cases" << endl;
    timeSort(A, seedA, arrSize);
    cout << endl;
    
    cout << "Worst Cases" << endl;
    timeSort(A1, seedA1, arrSize);
    cout << endl;

    cout << "Average Cases" << endl;
    timeSort(A2, seedA2, arrSize);
    cout << endl;
    
//    timeSort(A, arrSize, insertion);
//    timeSort(A1, arrSize, insertion);
//    timeSort(A2, arrSize, insertion);
    
    /*print the arrays to see if they populate correctly
    printArray(A[], arrSize);
    printArray(A1[], arrSize);
    printArray(A2[], arrSize);
    */
    
    delete[] A;
    delete[] A1;
    delete[] A2;
    return 0;
}

/*
Description: A function that prints out all the contents of an array
Parameters: An array of templated values, integer value for the size of the array
Return: None
Notes: 
*/

template <class T> void printArray(T A[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

/*
Description: A function to time four different sorts and report the time. The function uses an array of function pointers that have been set equal to the four different sort functions.
Parameters: A array of templated values, integer value for the size of the array, a pointer to a function with parameters of a templated array and an integer
Return: None
Notes: timing code taken from Spickler's function pointer folder #3,#4,#5,#7
*/

template <class T> void timeSort(T A[], T seedA[], int arrSize){
    void (*fctptr[4])(T[], int);
    fctptr[0] = bubble;
    fctptr[1] = insertion;
    fctptr[2] = selection;
    fctptr[3] = bubblesort2;
    for (int i = 0; i < 4; i ++){
        //cout << "Before Sort:" << endl;
        //printArray(A, arrSize);
        auto start = high_resolution_clock::now();
        fctptr[i](A, arrSize);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time to sort with algorithm" << " " << i + 1 << ": "
        << duration.count() / 1000000.0 << " seconds" << endl;
        //cout << "After Sort" << endl;
        //printArray(A, arrSize);
        for (int j = 0; j < arrSize; j++){
            A[j] = seedA[j];
        }
       // cout << "After Reset: " << endl;
       // printArray(A, arrSize);
    }
}

//Description: Array sort using bubble sort algorithm
// Parameters: templated array, integer
// Return: void
// Notes:

template <class T> void bubble(T A[], int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - i - 1; j++) {
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

template <class T> void insertion(T A[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
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

template <class T> void selection(T A[], int arrSize) {
    int minindex;
    for (int i = 0; i < arrSize; i++) {
        minindex = i;
        for (int j = i; j < arrSize; j++)
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
template<class T> void bubblesort2(T A[], int arrSize){
    bool again = true;
    for (int i = 0; i < arrSize-1 && again; i++)
        for (int j = arrSize-1, again = false; j>i; --j)
            if (A[j] < A[j-1]){
                T temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                //swap(A[j], A[j-1]);
                again = true;
            }
}

