#include "BinaryHeap.h"
BinaryHeap::BinaryHeap(int capacity) : capacity(capacity), size(0) , arr(new int[capacity]) {}

BinaryHeap::BinaryHeap(const std::vector<int> &vec) : BinaryHeap() {
    for (; size < (int) vec.size(); size++)
        arr[size] = vec[size];

    heapify();
}

BinaryHeap::BinaryHeap(const std::vector<int> &&vec) : BinaryHeap() {
    for (; size < (int) vec.size(); size++)
        arr[size] = vec[size];

    heapify();
}

void BinaryHeap::heapify() { // ~ O(n) , reverse thinking and optimized
    for (int i = size / 2 - 1; ~i ; i--) // start with non leaf nodes
        heapify_down(i);
}


int BinaryHeap::left(int idx){
    int pos = idx * 2 + 1;
    return pos >= size ? -1 : pos;
}

int BinaryHeap::right(int idx){
  int pos = idx * 2 + 2;
  return pos >= size ? -1 : pos;
}

int BinaryHeap::parent(int idx){
    return idx == 0 ? -1 : (idx - 1) / 2;
}

void BinaryHeap::heapify_up(int child_idx){
    int parent_idx = this->parent(child_idx);

    if(child_idx < 0 || arr[parent_idx] <= arr[child_idx])
       return ;

    swap(arr[parent_idx], arr[child_idx]);
    heapify_up(parent_idx);
}

void BinaryHeap::insert(int val) {
    if (size + 1 >= capacity)
        throw std::overflow_error("BinaryHeap::capacity");
    arr[size++] = val;
    heapify_up(size-1);
}

int BinaryHeap::top() const {
    return arr[0];
}

bool BinaryHeap::isEmpty() const {
    return size == 0;
}

void BinaryHeap::pop() {
    if (isEmpty())
        throw std::underflow_error("BinaryHeap is empty");
    arr[0] = arr[--size];
    arr[size] = 0;
    heapify_down(0);
}

void BinaryHeap::heapify_down(int parent_idx) {
    int child_idx = left(parent_idx) , right_child_idx = right(parent_idx);
    if (child_idx == -1) return;

    if (~right_child_idx && arr[right_child_idx] < arr[child_idx])
        child_idx = right_child_idx;

    if (arr[child_idx] < arr[parent_idx]) {
        swap(arr[child_idx], arr[parent_idx]);
        heapify_down(child_idx);
    }
}

BinaryHeap::~BinaryHeap(){
    delete[] arr;
    arr = nullptr;
}

