#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.h"

template<class T>
Stack<T>::Stack() : top(INITIAL_TOP) , capacity(0) , arr(nullptr) {

}

template<class T>
void Stack<T>::push(T val) {
    if (!arr)
        arr = new int[++capacity];
    else if (isFull())
        expand();
    arr[++top] = val;
}

template<class T>
T Stack<T>::pop() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    return arr[top--];
}

template<class T>
T Stack<T>::peek() { // return top element
    if (isEmpty())
        throw std::out_of_range("Stack is empty");

    return arr[top];
}

template<class T>
int Stack<T>::size() {
    return top + 1;
}

template<class T>
bool Stack<T>::isEmpty() {
    return top == INITIAL_TOP;

}

template<class T>
bool Stack<T>::isFull() {
    return top == capacity - 1;

}

template<class T>
void Stack<T>::expand() {
    T* newArr = new int [capacity << 1];
    //n -> 1 2 3 .. n -> sum(n) -> (n * (n + 1)) / 2 -> O(n^2)
    //Doubling approach: 1 , 2 , 4 , 8 , .. n : 2*n - 1 -> O(n)
    for (int i = 0; i < this->capacity; ++i)
        newArr[i] = arr[i];
    capacity <<= 1;

    swap(this->arr , newArr);

    delete[] newArr;
    newArr = nullptr;
}

template<class T>
void Stack<T>::print() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    for (int i = top ; ~i ; --i)
        std::cout << arr[i] << std::endl;
}

template<class T>
void Stack<T>::clear() {
    if (arr)
        delete[] arr;
    arr = nullptr;
    capacity = 0;
    top = INITIAL_TOP;
}

template<class T>
Stack<T>::~Stack() {
    clear();
}



#endif
