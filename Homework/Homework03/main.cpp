#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T> using boolfctptr = bool (*)(const &T, const &T);
template <class T> int count(*T, *T, const &T, boolfctptr);
template <class T> int count(typename vector<T>::iterator, typename vector<T>::iterator, const &T, boolfctptr);

template <class T> bool Greater(const &T, const &T);
template <class T> bool Less(const &T, const &T);
template <class T> bool Equal(const &T, const &T);

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
