#include <iostream>
using namespace std;


int main() {
    // & => reference operator || address-of operator
    // * => dereference operator || content-of operator
    int x = 10;
    cout << x << endl; // 10
    cout << &x << endl; // 0x--------

    // pointers
    int * ptr = &x;
    cout << ptr << endl;
    cout << *ptr << endl;

    *ptr += 5; // x += 5
    cout << x << endl;

    // pointer to pointer
    int ** ptrptr = &ptr;
    // try to know what each value represents
    cout << &ptrptr << " " << ptrptr << " " << *ptrptr << " " << **ptrptr << endl;

    cout << "\n\n\n\n\n\n";


    int arr[5] = {0,1,2};

    int * ptr2 = &arr[0]; // equivalent to => int * ptr2 = arr;
    cout << ptr2 << " " << arr <<  endl; // address of the first element
    cout << *(ptr2+1) << " " << *(arr+1) <<endl; // content of the second element
    cout << ptr2[2] << endl; // same as arr[2]

    // nullptr
    int * ptr3 = nullptr;
    cout << ptr3 << endl; // 0

    // casting
    int a =5, b=2;
    cout << a/static_cast<float>(b) << endl; // 2.5
    cout << a/float(b) << endl; // 2.5
    cout << a/b << endl; // 2

    void * ptr4;
    ptr4 = &x;
    // cout << *ptr4 << endl; // error
    cout << *static_cast<int *>(ptr4) << endl; // 15

    return 0;
}
