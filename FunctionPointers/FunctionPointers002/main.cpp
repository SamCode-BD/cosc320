/*
Author: Don Spickler
Creation Date: 1/10/2022
Last Update: 1/22/2024
Description: Example of using a function pointer array to alter the called
function.
*/

#include <iostream>

using namespace std;

/*
Description: Simple arithmetic operations to illustrate the call.
Parameters: x, y, doubles.
Return: double result of the arithmetic operation.
*/

double add(double x, double y) { return x + y; }
double sub(double x, double y) { return x - y; }
double mul(double x, double y) { return x * y; }
double div(double x, double y) { return x / y; }

auto div2(auto x, auto y)  {return x/y;} //test to use with function pointers
int main() {
  //function pointers with return types double and integer, and various parameters
  int (*fctptr2)(int, int); 
  double (*fctptr3)(double, int);
  double (*fctptr4)(double, double);


  fctptr2 = div2; 
  cout << fctptr2(2.3, 5.7) << endl;
  fctptr3 = div2;
  cout << fctptr3(2.3, 5.7) << endl;
  fctptr4 = div2;
  cout << fctptr4(2.3, 5.7) << endl;


  cout << "--------" << endl;
  
  // An array of pointers to functions with two double parameters and double
  // return type.
  double (*fctptr[4])(double, double);

  fctptr[0] = add;
  fctptr[1] = sub;
  fctptr[2] = mul;
  fctptr[3] = div;

  for (int i = 0; i < 4; i++)
    cout << fctptr[i](3, 7) << endl;

  return 0;
}
