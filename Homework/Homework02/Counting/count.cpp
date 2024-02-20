/*
 * Author: Samuel Dickerson
 * Creation Date: 2/19/2024
 * Last Update: 2/19/2024
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

template <class T> long bubble(T[], int);
template <class T> long insertion(T[], int);
template <class T> long selection(T[], int);
template <class T> long bubblesort2(T[], int);
template <class T> void countSort(T[], T[], int);  
template <class T> void printArray(T[], int);
template <class T> void randomShuffle(T[], int);

int main(){
    //seed random
    srand(time(0));
    
    //arrSize of the integer array
    int arrSize;
    cout << "Enter an integer to populate the array with" << endl; //ask for n
    cin >> arrSize;
    
    //three dynamically created integer arrays with n elements, one to seed each scenario (necessary to reset the testing arrays after each sorting algorithm runs)
    int *seedA = new int[arrSize];
    int *seedA1 = new int[arrSize];
    int *seedA2 = new int[arrSize];
    
    //three dynamically created integer arrays with n elements, one for each scenario
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
    
    //for loop to populate an array of n values sorted from least to greatest
    for (int i = 0; i < arrSize; i++){
        seedA2[i] = i;
    }
    //random shuffle function to scramble the entries, so that the result will be a completely random array of n integers with no duplication
    randomShuffle(seedA2, arrSize);
    //for loop to seed the three arrays that will be passed to the timing and sorting algorithms. This will have to be used every time a new sort is ran.
    for (int i = 0; i < arrSize; i++){
        A[i] = seedA[i];
        A1[i] = seedA1[i];
        A2[i] = seedA2[i];
    }
    
    cout << "Best Cases" << endl;
    countSort(A, seedA, arrSize);
    cout << endl;
    
    cout << "Worst Cases" << endl;
    countSort(A1, seedA1, arrSize);
    cout << endl;

    cout << "Average Cases" << endl;
    countSort(A2, seedA2, arrSize);
    cout << endl;

    delete[] A;
    delete[] A1;
    delete[] A2;
    delete[] seedA;
    delete[] seedA1;
    delete[] seedA2;
    return 0;
}

/*
Description: A function that randomly shuffles a templated array by creating two random values that are used as array indexes and swapping them. The random numbers are generated and the array values are swapped n times because they are put into a for loop that runs as many times as the size of the array. 
Parameters: An array of templated values, integer value for the size of the array
Return: None
Notes: 
*/

template <class T> void randomShuffle(T A[], int arrSize){
    for (int i = 0; i < arrSize; i++){
        int num1 = rand() % arrSize + 0;
        int num2 = rand() % arrSize + 0;
        swap(A[num1], A[num2]);
    }
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
Description: A function to count the operations of four different sorts and print the number. The function uses an array of function pointers that have been set equal to the four different sort functions.
Parameters: Two arrays of templated values, integer value for the size of the array
Return: None
Notes:
*/

template <class T> void countSort(T A[], T seedA[], int arrSize){
    long count = 0;
    long (*fctptr[4])(T[], int);
    fctptr[0] = bubble;
    fctptr[1] = insertion;
    fctptr[2] = selection;
    fctptr[3] = bubblesort2;
    for (int i = 0; i < 4; i ++){
        count = fctptr[i](A, arrSize);
        cout << "Amount of operations for algorithm " << i + 1 << ": " << count/10000 << " tens of thousands" << endl;
        for (int j = 0; j < arrSize; j++){
            A[j] = seedA[j];
        }
    }
}

//Description: Array sort using bubble sort algorithm. There is also a count variable that counts the amount of arithmetic and logic operations being done throughout the program. The count variable does not count it's own operations.
// Parameters: templated array, integer
// Return: long
// Notes:

template <class T> long bubble(T A[], int arrSize) {
    long count = 0;
    for (int i = 0; i < arrSize - 1; i++, count += 4) {
        for (int j = 0; j < arrSize - i - 1; j++, count += 5) {
            count += 3;
            if (A[j] > A[j + 1]) {
                T temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                count += 5;
            }
        }
    }
    return count;
}

//Description: Array sort using insertion sort algorithm. There is also a count variable that counts the amount of arithmetic and logic operations being done throughout the program. The count variable does not count it's own operations.
// Parameters: templated array, integer
// Return: long
// Notes:

template <class T> long insertion(T A[], int arrSize) {
    long count = 0;
    for (int i = 0; i < arrSize; i++, count += 3) {
        int j = 0;
        T val = A[i];
        count += 2;
        for (j = i; j > 0 && A[j - 1] > val; j--, count += 6){
            A[j] = A[j - 1];
            count += 2;
        }
        A[j] = val;
        count += 1;
    }
    return count;
}

//Description: Array sort using selection sort algorithm. There is also a count variable that counts the amount of arithmetic and logic operations being done throughout the program. The count variable does not count it's own operations.
// Parameters: templated array, integer
// Return: long
// Notes:

template <class T> long selection(T A[], int arrSize) {
    int minindex;
    long count = 1;
    for (int i = 0; i < arrSize; i++, count += 3) {
        minindex = i;
        count += 1;
        for (int j = i; j < arrSize; j++, count += 3){
            count += 1;
            if (A[j] < A[minindex]){
                minindex = j;
                count += 1;
            }
        }
        T val = A[i];
        A[i] = A[minindex];
        A[minindex] = val;
        count += 3; 
    }
    return count;
}

//Description: Array sort using advanced bubble sort algorithm which includes a boolean catch to break out if the array is sorted. There is also a count variable that counts the amount of arithmetic and logic operations being done throughout the program. The count variable does not count it's own operations.
// Parameters: templated array, integer
// Return: long
// Notes:
template<class T> long bubblesort2(T A[], int arrSize){
    bool again = true;
    long count = 1;
    for (int i = 0; i < arrSize-1 && again; i++, count += 6)
        for (int j = arrSize-1, again = false; j > i; --j, count += 5){
            count += 3;
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                again = true;
                count += 6;
            }
        }
    return count;
}

