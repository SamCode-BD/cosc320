/*
 A *uthor: Samuel Dickerson
 Creation Date: 3/4/2024
 Last Update: 3/4/2024
 Description: 
 User Interface:
 Notes: Algorithms and code were taken from either
 Data Structures and Algorithms in C++ by Adam Drozdek or
 Introduction to Algorithms Fourth Edition by Cormen, Leiserson, Rivest, and
 Stein
 */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

#include "Sorts.h"
#include "timer.h"

using namespace std;

// Prototypes
template <class T> void print(T A[], int size);
template <class T> void outputSorted(T A[], int size);

int sortAlg();
bool getNumericType();
//long getArraySize();
//int getModulus();
bool getPrintArrays();
//pair<double, double> getDoubleRange();

int main() {
  srand(time(0));
  
  // Array size
  long n = 0;
  // Timing begin and end times.
  double start, finish;
  // Print the array
  bool printyn = false;
  // Algorithm number
  int alg = 0;
  // Integer or double data
  bool intdata = true;
  // Double data lower and upper bounds.
  double lower = 0, upper = 1;
  //Array with array sizes
  long size[10] = {10000000, 20000000, 30000000, 40000000, 50000000, 60000000, 70000000, 80000000, 90000000, 100000000};
  // Array pointers.
  int *A;
  double *B;
  
  // Get algorithm.
  alg = sortAlg();
  
  // Get data type to store and sort.
  if (alg == 6 || alg == 7) {
    intdata = true;
  } else if (alg == 8) {
    intdata = false;
  } else {
    intdata = getNumericType();
  }
  
  // Get the data bounds.
  if (intdata)
    n = 0;
  else if (alg != 8) {
      //auto vals = getDoubleRange();
      lower = 0;
      upper = 1;
    }
  
  // Print arrays, or not.
  printyn = getPrintArrays();
  
  for (int j = 0; j < 10; j++){
    n = size[j];
    if (alg != 8)
      upper = size[j];
    if (intdata) {
      // Integer data, declare and populate with random numbers.
      A = new int[n];
      for_each(A, A + n, [n](int &i) { i = rand() % n; });
      
      // Print array
      if (printyn)
        print(A, n);
      
      // Get start time.
      GET_TIME(start);
      
      // Sort with selected algorithm.
      if (alg == 1)
        mergeSort(A, n);
      else if (alg == 2)
        quickSort(A, n);
      else if (alg == 3)
        combsort(A, n);
      else if (alg == 4)
        Shellsort(A, n);
      else if (alg == 5)
        heapsort(A, n);
      else if (alg == 6)
        radixsort(A, n, 10);
      else if (alg == 7)
        countsort(A, n);
      else if (alg == 9)
        sort(A, A + n);
      
      // Get end time.
      GET_TIME(finish);
      
      // Print array
      if (printyn)
        print(A, n);
      
      // Check sorting and free memory.
      //outputSorted(A, n);
      
      // Report sort time.
      cout << finish - start << ", " << flush;
      
      delete[] A;
      } 
    else {
      // Double data, declare and populate with random numbers.
      B = new double[n];
      for_each(B, B + n, [lower, upper](double &i) {
        i = (upper - lower) * rand() / RAND_MAX + lower;
      });
      
      // Print array.
      if (printyn)
        print(B, n);
      
      // Get start time.
      GET_TIME(start);
      
      // Sort with selected algorithm.
      if (alg == 1)
        mergeSort(B, n);
      else if (alg == 2)
        quickSort(B, n);
      else if (alg == 3)
        combsort(B, n);
      else if (alg == 4)
        Shellsort(B, n);
      else if (alg == 5)
        heapsort(B, n);
      else if (alg == 8)
        BucketSort(B, n);
      else if (alg == 9)
        sort(B, B + n);
      
      // Get ending time.
      GET_TIME(finish);
      
      // Print array.
      if (printyn)
        print(B, n);
      
      // Check sorting and free memory.
      //outputSorted(B, n);
      
      // Report sort time.
      cout << finish - start << ", " << flush;
      
      delete[] B;
    }
  }
  cout << endl;
  return 0;
}

/*
 Description: Prints the array to the console.
 Parameters: A array and size of the array.
 Return: None
*/
template <class T> void print(T A[], int size) {
  for (int i = 0; i < size; i++)
    cout << A[i] << " ";
  cout << endl;
}

/*
 Description: Checks if the array is sorted and outputs the result.
 Parameters: A array and size of the array.
 Return: None
*/
template <class T> void outputSorted(T A[], int size) {
  if (sorted(A, size))
    cout << "Sorted" << endl;
  else
    cout << "Not Sorted" << endl;
}

/*
 Description: Gets the sorting algorithm to use.
 Parameters: None
 Return: Integer representing the algorithm to use.
*/
int sortAlg() {
  int val = 0;
  
  cout << "Sorting Algorithm" << endl;
  cout << "1. Merge Sort" << endl;
  cout << "2. Quick Sort" << endl;
  cout << "3. Comb Sort" << endl;
  cout << "4. Shell Sort" << endl;
  cout << "5. Heap Sort" << endl;
  cout << "6. Radix Sort" << endl;
  cout << "7. Count Sort" << endl;
  cout << "8. Bucket Sort" << endl;
  cout << "9. Algorithm Library Sort" << endl;
  
  while (val < 1 || val > 9) {
    cout << "Selection: ";
    cin >> val;
  }
  
  return val;
}

/*
 Description: Gets the data type to use for the arrays.
 Parameters: None
 Return: Boolean, true for integer and false for double.
*/
bool getNumericType() {
  int type = 0;
  cout << "Data: 1 = int   2 = double: ";
  cin >> type;
  
  return (type == 1) ? true : false;
}

/*
 Description: Gets a boolean to print the arrays or not.
 Parameters: None
 Return: true to print and false to not.
*/
bool getPrintArrays() {
  char printyn;
  cout << "Print arrays (y/n): ";
  cin >> printyn;
  
  return (tolower(printyn) == 'y') ? true : false;
}

/*
 Description: Gets the data range for double array data.
 Parameters: None
 Return: pair representing the lower and upper bounds to use
 for the data.
*/
// pair<double, double> getDoubleRange() {
//   double lower, upper;
//   cout << "Input lower bound for data range: ";
//   cin >> lower;
//   cout << "Input upper bound for data range: ";
//   cin >> upper;
//   lower = 0;
//   upper = 100000000;
//   
//   return {lower, upper};
// }
