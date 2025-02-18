#include <iostream>

using namespace std;

// any function calls itself is a recursive function
// every recursive function contains two parts, base case and transition

void display(int n, int i = 1) {
    // base
    if (i > n)return;

    // transition
    cout << i << endl;
    display(n, i+1);
} // O(n)

// add 1 -> n
int add (int n) {
    //base
    if (n < 0)return 0;
    // transition
    return(n + add(n-1));
} // O(n)

// add(4)
// 4 + add(3)
// 4 + (3 + add(2))
// 4 + (3 + (2 + add(1)))
// 4 + (3 + (2 + 1 + (0)))
// 10

// fibonacci sequence
// 1 1 2 3 5 8 13 21...
int fib(int n) {
    // base
    if (n <= 2)return 1;
    // transition
    return fib(n-1) + fib(n-2);
}
// fib(4)
// fib(3) + fib(2)
// (fib(2) + fib(1)) + fib( 2)
int main(){
    int n = 6;
    display(10);
    cout << add(10) << endl;
    cout << fib(10) << endl;
    return 0;
}
