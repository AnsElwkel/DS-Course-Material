#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <bits/stdc++.h>
using namespace std;
/** Minimum Binary Heap
 * Is a complete binary Tree (so we can represent it in array! )
 * Array Representation Style ( special locality and fast access )
 * Get the minimum element in O(1)
 * Insertion and deletion in O(log(n))
 * Floyed Optimization trick : load container of element in heap with O(n) only
 * Another Optimization trick : after apply the floyed trick now we can start the heapify with only non leaf nodes
 * (non leaf nodes in Complete binary tree is floor(n / 2) !
 */

class BinaryHeap {
    int * arr;
    int size , capacity;

public :
    explicit BinaryHeap(int capacity = 1000); //O(n)
    explicit BinaryHeap(const std::vector<int>& vec); //O(n) !
    explicit BinaryHeap(const std::vector<int> && vec); //O(n) !

    int left(int idx); //O(1)

    int right(int idx); //O(1)

    int parent(int idx); //O(1)

    void heapify();

    void heapify_up(int child_idx); //O(log(n))

    void heapify_down(int parent_idx); //O(log(n))

    void insert(int val); //O(log(n))

    int top() const; //O(1)

    void pop(); //O(log(n))

    bool isEmpty() const; //O(1)

    ~BinaryHeap(); //O(n)
};

#endif //BINARYHEAP_H
