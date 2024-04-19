/*
 Author: Samuel Dickerson
 Creation Date: 3/4/2024
 Last Update: 3/9/2024
 Description: A program that will time various array sizes for different sorting algorithms and report the times back in a comma separated list.
 User Interface: User will be asked for the algorithm to use, the
type of data (int or double) if applicable, and to print the array to the console or not.
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
  //Array of array sizes
  //long size[12] = {50000000, 100000000, 150000000, 200000000, 250000000, 300000000, 350000000, 400000000, 450000000, 500000000, 550000000, 600000000} //array used for quick sort
  //long size[10] = {50000000, 100000000, 150000000, 200000000, 250000000, 300000000, 350000000, 400000000, 450000000, 500000000}; //array used for merge sort, algorithm library sort, radix of 10 with 0 to max size random elements
  //long size[10] = {100000000, 200000000, 300000000, 400000000, 500000000, 600000000, 700000000, 800000000, 900000000, 1000000000}; //array values for radix of 100 and radix of 1000 with 0 to max size elements
  //long size[15] = {100000000, 200000000, 300000000, 400000000, 500000000, 600000000, 700000000, 800000000, 900000000, 1000000000, 1100000000, 1200000000, 1300000000, 1400000000, 1500000000}; //array values for radix of 10000 with 0 to max size elements, radix of 10, 100, 1000, and 10000 for elements between 0 and 1000, count sort with both 0 to max size and 0 to 1000
  //long size[10] = {25000000, 50000000, 75000000, 100000000, 125000000, 150000000, 175000000, 200000000, 225000000, 250000000}; //array for shell and heap sort
  long size[12] = {25000000, 50000000, 75000000, 100000000, 125000000, 150000000, 175000000, 200000000, 225000000, 250000000, 275000000, 300000000}; //array used for comb sort and bucket sort
  // Array pointers.
  int *A;
  double *B;
  
  // Get algorithm.
  alg = sortAlg();
  
  // Get data type to store and sort.
  if (alg == 6 || alg == 7) { //if radix or count sort, data type set to integer
    intdata = true;
  } else if (alg == 8) { //if bucket sort, data type set to double
    intdata = false;
  } else {
    intdata = getNumericType();
  }
  
  // Get the data bounds.
  if (intdata) //keep n zero if int data
    n = 0;
  else if (alg != 8) { // if not count sort leave lower and upper equal to 0 and 1
      //auto vals = getDoubleRange();
      lower = 0;
      upper = 1;
    }
  
  // Print arrays, or not.
  printyn = getPrintArrays();
  
  for (int j = 0; j < 12; j++){ //for loop from 0 to size of array
    n = size[j]; //set n equal to the element of the array of array sizes so each size can be tested
    if (alg != 8) // as long as the algorithm is not bucket sort, upper set to size[j]
      upper = size[j];
    if (intdata) {
      // Integer data, declare and populate with random numbers.
      A = new int[n];
      for_each(A, A + n, [n](int &i) { i = rand() % n; }); //modulus by size of the array, or modulus by 1000 for specific cases such as radix, 1000 was hardcoded when needed
      
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
        radixsort(A, n, 10000); //radix was hardcoded when needed 
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
