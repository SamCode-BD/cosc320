//Sam Dickerson, Owen Beabout

#include <iostream>
#include <algorithm>

using namespace std;

template <class T> using updatefct = void (*)(T &);
template <class T> void alter(T*, T*, void (*)(T &));
template <class T> void twice(T &);
template <class T> void print(const T &);

int main(){
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    double arr2[7] = {4, 4, 2 ,9, 0 ,3, 4};
    for_each(arr1, arr1 + 7, print<int>); 
    cout << endl;
    for_each(arr2, arr2 + 7, print<double>);
    cout << endl;
    cout << endl;
    alter(arr1, arr1 + 7, twice);
    alter(arr2, arr2 + 7, twice);
    for_each(arr1, arr1 + 7, print<int>); 
    cout << endl;
    for_each(arr2, arr2 + 7, print<double>);
    alter(arr1 + 3, arr1 + 5, twice);
    alter(arr2 + 1, arr2 + 6, twice);
    cout << endl;
    cout << endl;
    for_each(arr1 + 3, arr1 + 5, print<int>); 
    cout << endl;
    for_each(arr2 + 1, arr2 + 6, print<double>);
}

template <class T> void alter(T* x, T* y, void(*updatefct)(T &)){
    for_each(x, y, updatefct);
}

template <class T> void twice(T &a){
    a = a*2;
}

template <class T> void print(const T &a){
    cout << a << " ";
}
