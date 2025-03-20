//
// Created by anas-elwkel on 3/15/25.
//

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <stack>
using namespace std;

template<class T>
class SingleLinkedList {
    struct Node {
        T data;
        Node *next;
        Node(T data) : data(data) , next(nullptr) {}
    }*head , *tail;

    //Operation that can i do it in linkedlist
    enum Operation {
        INSERT,
        DELETE
    };

    //this struct to know the last operation done to save it in stack
    /// I need to know the operation insert or delete
    /// And the index i perform the operation on it and data of this operation
    struct Process {
        Operation operation;
        int idx;
        T data;
        Process(Operation operation, int idx , T data = 0) :
        operation(operation), idx(idx) , data(data) {}
    };

    //Push the operation in this stack when insert_end, insert_front, insert,
    //delete_end, delete_front or erase
    stack<Process> undoStack;

    int length{};
    const int MAX_SIZE = 100001;

public:
    SingleLinkedList();

    //Task Function
    void undo();

    ///To avoid duplications i add the default flag to know the function call from user or undo function ?
    void insert_end(T val , bool fromUndo = false); //operation 0
    void insert_front(T val, bool fromUndo = false); //operation 1
    void insert(T val, int idx , bool fromUndo = false); //operation 2
    void delete_front(bool fromUndo = false); //operation 3
    void delete_back(bool fromUndo = false); //operation 4
    void erase(int idx , bool fromUndo = false); //operation 5





    void print();

    void print_list_format();

    int size();


    SingleLinkedList(const SingleLinkedList &other) = delete;
    SingleLinkedList(SingleLinkedList<T> &&other) = delete;
    SingleLinkedList &operator=(const SingleLinkedList &other) = delete;
    SingleLinkedList &operator=(SingleLinkedList<T> &&other) = delete;



    T get_nth(int n);

    Node *get_nth_node(int n);

    T get_nth_back(int n);

    Node *get_nth_back_node(int n);

    int search(T val);

    int improved_search(T val);

    bool is_same_list(const SingleLinkedList &other);

    void debug();

    std::string debug_to_string();

    ~SingleLinkedList();
};

void testLinkedList_structure();
void testUndoStack();

#include "SingleLinkedList.cpp"

#endif //SINGLELINKEDLIST_H
