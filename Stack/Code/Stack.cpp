#ifndef STACK_H
#define STACK_H
//Array-based

template<class T>
class Stack {
#define INITIAL_TOP (-1)
    int top , capacity;
    T* arr;
public:
    Stack(); //O(n)
    Stack(const Stack<T> &other) = delete;
    Stack(Stack<T> &&other) = delete;
    Stack<T> &operator=(const Stack<T> &other) = delete;
    Stack<T> &operator=(Stack<T> &&other) = delete;

    //Main Operations
    void push(T val); //O(1)
    T pop(); //O(1)

    //Other Operations
    T peek(); //O(1)
    int size(); //O(1)
    bool isEmpty(); //O(1)
    bool isFull(); //O(1)
    void clear(); //O(n)
    void expand(); //O(n)
    void print(); //O(n)

    ~Stack(); //O(n)
};


#include "Stack.cpp"
#endif //STACK_H
