#include "BinaryHeap.h"
#include<vector>
void test(){
    BinaryHeap heap;
    std::vector<int> v = { 2 , 17 , 22 ,10 , 8, 37 , 14 , 19, 7, 6,5 ,12,25,30};
    // std::vector<int> v = { 6 , 4, 2 , 5 , 7, 6 , 8, 10};

    for (auto i : v) // O(nlog(n))
        heap.insert(i);

    while (!heap.isEmpty()) {
        std::cout << heap.top() << ' ' ;
        heap.pop();
    }
    std::cout << std::endl;
}

void test2() {
    BinaryHeap heap(std::vector<int> {2 , 17 , 22 ,10 , 8, 37 , 14 , 19, 7, 6,5 ,12,25,30}); //O(n) with move constructor call

    while (!heap.isEmpty()) {
        std::cout << heap.top() << ' ' ;
        heap.pop();
    }
    std::cout << std::endl;
}

void test3() {
    std::vector<int> v = { 2 , 17 , 22 ,10 , 8, 37 , 14 , 19, 7, 6,5 ,12,25,30};

    BinaryHeap heap(v);

    while (!heap.isEmpty()) {
        std::cout << heap.top() << ' ' ;
        heap.pop();
    }
    std::cout << std::endl;
}