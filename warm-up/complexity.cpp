#include <iostream>
using namespace std;


int main() {
    // what is complexity
    // why it's important
    // what is "O" notation
    // 9 7 18 0 1 2


    // constant time O(1)
    // O => order
    // it will always run in constant time no matte how large the number is
    int a=1000000,b=1345;
    a + b;
    cout << a;
    a/b;
    a*b;
    //...

    // linear time O(n)
    // time growth proportionally with n
    int n =10;
    for(int i=0; i< n; i++)
    {
        a = a+b;
        cout << a;
        // O(1)
    }
    // O(n)

    // logarithmic time O(log(n))
    // the number of steps is the log n
    // if the n equals 8 => 3, 4 => 2
    // 1024 => 10
    // 1 billion => 30 !!!
    n = 1000;
    while(n>0){
        cout << n; //O(1)
        n/=2;
    } // O(log(n))


    // linearithmic time O(nlog(n))
    // logarithmic time for n steps
    for(int i=0; i<n; i++){
        int num = i;
        while(num>0){
            cout << num << " ";
            num/=2;
            // 1
        }
        // log
        cout << endl;
    }
    //n

    // quadritic time O(n^2)
    n = 1000;
    int m = 1000;
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
          cout << n << endl; // 1
        } // n
    } // n
    // O(n^2)
    for(int j = 0; j< m; j++){
        cout << m << endl;
    }
    // O(n^2 + m)


    // notes
    int n =10;
    for(int i=0; i<n; i++){
        for(int j =0; j<=i; j++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    // n*(n+1)/2
    // O(n^2)


    for(int i=0; i<n; i++){
        for(int j =0; j<n + 20; j++){
            cout << n << endl;
        }
    } // O(n^2)

    n = 1000;
    bool vis[1001]{};
    for(int i =0; i<n; i++){
        if(vis[i] != 1){
            for(int j=i; j<n; j++){
              vis[j] = 1;
            }
        }// n
    }// n
    // O(n)


    int x; // O(1)
    int arr[n]; // O(n)
    int arr2[n][n]; // O(n^2)

    int y =0; // memory O(1)
    for (int i =0; i < n; i++) {
        cin >> y;
        cout << y;
    }
    for (int i =0; i < n; i++) {
        int y =0; // memory O(n)
        cin >> y;
        cout << y;
    }

    return 0;
}
