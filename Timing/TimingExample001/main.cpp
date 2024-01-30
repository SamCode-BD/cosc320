/*
Author: Don Spickler
Creation Date: 1/25/2024
Last Update: 1/25/2024
Description:  Example of how to time a process in C++ using the chrono
library.
User Interface: None
Notes: None
*/

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
  // Define and populate a vector of random values.
  srand(time(0));
  vector<int> values(10000000);

  for (unsigned int i = 0; i < values.size(); i++)
    values[i] = rand();

  // Get start time.
  auto start = high_resolution_clock::now(); //auto type automatically sets the data type for what it needs to be, in this instance from what the high resolution clock is supposed to be

  // Do process to be timed.
  sort(values.begin(), values.end()); //vector iterators, tell you where you are in the vector, .begin() is the beginning of the vector, .end() is the end
  
  // Get stop time.
  auto stop = high_resolution_clock::now();

  // Take the difference to get elapsed time.
  auto elapsed = duration_cast<microseconds>(stop - start);

  // Report time.
  cout << "Time to sort: " << elapsed.count() << " microseconds" << endl;
  cout << "Time to sort: " << elapsed.count() / 1000000.0 << " seconds" << endl;

  // Reuse of auto typed variables.
  start = high_resolution_clock::now();
  sort(values.begin(), values.end());
  stop = high_resolution_clock::now();
  elapsed = duration_cast<microseconds>(stop - start);

  cout << "Time to sort: " << elapsed.count() << " microseconds" << endl;
  cout << "Time to sort: " << elapsed.count() / 1000000.0 << " seconds" << endl;

  return 0;
}
