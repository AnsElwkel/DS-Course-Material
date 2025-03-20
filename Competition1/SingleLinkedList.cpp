//
// Created by anas-elwkel on 3/15/25.
//
#ifndef SINGLELINKEDLIST_CPP
#define SINGLELINKEDLIST_CPP
#include "SingleLinkedList.h"
template<class T>
SingleLinkedList<T>::SingleLinkedList() : head(nullptr), tail(nullptr) {};


///Competition function
/** Here is the logic :-
 * In Undo Function, I care about "What is the last operation done?"
 * So i will choose the stack data structure to solve this
 * The idea is simple,
 *  When perform any linkedlist operation (insertion or deletion) -> push this in stack
 *  And when Undo function call, I take the top of stack and make the reverse of this operation
 *  If the last op is insertion -> delete it (and vice versa)
 *
 *  there is minor change from function call -> make the fromUndo flag true
 *  To avoid push it again in the stack
 */
template<class T>
void SingleLinkedList<T>::undo() {
    if (this->undoStack.empty())
        throw std::out_of_range("Undo stack is empty");

    ///Take the last operation and make reverse of this operation
    ///I'm add the fromUndo flag just instead of duplicate the code :)
    Process lastOperation = undoStack.top();
    undoStack.pop();

    if (lastOperation.operation == Operation::INSERT) {
        if (lastOperation.idx == 0)
            this->delete_front(true);
        else if (lastOperation.idx == length - 1)
            this->delete_back(true);
        else
            this->erase(lastOperation.idx , true);

    }else if (lastOperation.operation == Operation::DELETE) {
        if (lastOperation.idx == 0)
            this->insert_front(lastOperation.data , true);
        else if (lastOperation.idx == length)
            this->insert_end(lastOperation.data , true);
        else
            this->insert(lastOperation.data , lastOperation.idx , true);

    }else {
        throw std::invalid_argument("Wrong operation");
    }
}





//Add new element in the end of linked list
template<class T>
void SingleLinkedList<T>::insert_end(T val , bool fromUndo) {
    //O(1)
    Node *item = new Node(val);
    length++;
    if (!fromUndo)
        undoStack.push(Process(Operation::INSERT, length-1 , val));

    if (!head)
        head = tail = item;
    else {
        tail->next = item;
        tail = tail->next;
        tail->next = nullptr;
    }
}

template<class T>
void SingleLinkedList<T>::insert_front(T val , bool fromUndo) {
    //O(1)
    Node *item = new Node(val), *tmp = head;
    length++;

    if (!fromUndo)
        undoStack.push(Process(Operation::INSERT, 0 , val));

    if (!head)
        head = tail = item;
    else {
        head = item;
        head->next = tmp;
    }
}

template<class T>
void SingleLinkedList<T>::insert(T val, int idx , bool fromUndo) noexcept(false) {
    if (idx > length || idx < 0) throw std::out_of_range("Index is out of range" + to_string(length));
    if (idx == length) return insert_end(val), void();
    if (!idx) return insert_front(val), void();
    Node *item = new Node(val), *prv = get_nth_node(idx), *next = prv->next;
    prv->next = item;
    item->next = next;
    ++length;
    if (!fromUndo)
        undoStack.push(Process(Operation::INSERT, idx , val));
}

template<class T>
void SingleLinkedList<T>::delete_front(bool fromUndo) noexcept(false) {
    if (!head) throw std::out_of_range("Empty list");
    Node *tmp = head;

    if (!fromUndo)
        undoStack.push(Process(Operation::DELETE, 0 , tmp->data));

    head = head->next;
    delete tmp;
    if (!head) tail = nullptr;
    --length;

}

template<class T>
void SingleLinkedList<T>::delete_back(bool fromUndo) {
    if (length <= 1) return delete_front(), void();
    Node *prv = get_nth_back_node(2);

    if (!fromUndo)
        undoStack.push(Process(Operation::DELETE, length-1 , tail->data));


    delete tail;
    tail = prv;
    tail->next = nullptr;
    --length;
}

template<class T>
void SingleLinkedList<T>::erase(int idx , bool fromUndo) noexcept(false) {
    if (idx >= length || idx < 0) throw std::out_of_range("Index out of range from erase");
    if (idx == 0) return delete_front(), void();
    if (idx == length - 1) return delete_back(), void();
    Node *prv = get_nth_node(idx), *tmp = prv->next;

    if (!fromUndo)
        undoStack.push(Process(Operation::DELETE, idx, tmp->data));

    prv->next = tmp->next;
    delete tmp;
    length--;

}


//Printing all data with sequence format
template<class T>
void SingleLinkedList<T>::print() {
    //O(n)
    for (Node *tmp = head; tmp; tmp = tmp->next)
        std::cout << tmp->data << ' ';
    std::cout << std::endl;
}

//Printing all data with Linked format
template<class T>
void SingleLinkedList<T>::print_list_format() {
    //O(n)
    int cnt = 0;
    for (Node *node = head, *prv = nullptr; ; prv = node, node = node->next) {
        if (!node) {
            if (prv)
                std::cout << prv->data << " -> X Tail" << std::endl;
            else
                std::cout << "Empty !" << std::endl;
            break;
        }

        if (!prv)continue;
        std::cout << prv->data << " -> " << node->data;
        if (++cnt == 1) std::cout << " Head";
        std::cout << std::endl;
    }
}

//Return number of nodes in linked list
template<class T>
int SingleLinkedList<T>::size() {
    //O(1)
    return length;
}





//Return value of n-th node in linked list
template<class T>
T SingleLinkedList<T>::get_nth(int n) {
    //O(n)
    if (n < 0 or n > length) throw std::out_of_range("n is out of range!");
    int i = 0;
    for (Node *tmp = head; tmp; ++i, tmp = tmp->next)
        if (i == n - 1) return tmp->data;
    return nullptr;
}

template<class T>
typename SingleLinkedList<T>::Node *SingleLinkedList<T>::get_nth_node(int n) noexcept(false) {
    if (n < 0 or n > length) throw std::out_of_range("n is out of range!");
    int i = 0;
    for (Node *tmp = head; tmp; ++i, tmp = tmp->next)
        if (i == n - 1) return tmp;
    return nullptr;
}

template<class T>
T SingleLinkedList<T>::get_nth_back(int n) {
    if (length < n) throw std::out_of_range("n is out of range!");
    int idx = length - n, i = 0;
    for (Node *node = head; node; node = node->next, ++i)
        if (i == idx) return node->data;
    return nullptr;
}

template<class T>
typename SingleLinkedList<T>::Node *SingleLinkedList<T>::get_nth_back_node(int n) {
    if (length < n)
        return nullptr;
    int idx = length - n, i = 0;
    for (Node *node = head; node; node = node->next, ++i)
        if (i == idx) return node;
    return nullptr;
}

template<class T>
//Return in the index of first node contain val
int SingleLinkedList<T>::search(T val) {
    //O(n)
    int idx = 0;
    for (Node *tmp = head; tmp; tmp = tmp->next, ++idx)
        if (tmp->data == val) return idx;

    return -1; //Not found
}

//A little bit efficient search that each find shift the element to left
template<class T>
int SingleLinkedList<T>::improved_search(T val) {
    //O(n)
    int idx = 0;
    for (Node *tmp = head, *prv = nullptr; tmp; prv = tmp, tmp = tmp->next) {
        if (tmp->data == val) {
            if (!prv) return idx;
            std::swap(prv->data, tmp->data);
            return idx - 1;
        }
        ++idx;
    }

    return -1;
}

template<class T>
bool SingleLinkedList<T>::is_same_list(const SingleLinkedList<T> &other) {
    bool same = true;
    Node *tmp1 = head, *tmp2 = other.head;
    if (!tmp1 || !tmp2 || length != other.length) same = false;
    for (; tmp1 and tmp2 and same; tmp1 = tmp1->next, tmp2 = tmp2->next)
        if (tmp1->data != tmp2->data) same = false;
    return same;
}

template<class T>
void SingleLinkedList<T>::debug() {
    if (!length) {
        assert(!head);
        assert(!tail);
    } else {
        assert(head);
        assert(tail);
        if (length == 1)
            assert(head == tail);
        else
            assert(head != tail);
        assert(!tail->next);
    }
    int len = 0;
    for (Node *node = head; node; node = node->next, ++len)
        assert(len < MAX_SIZE); // Consider infinite cycle
    assert(len == length);
    // assert(len == (int)debug_data.size());
}

template<class T>
std::string SingleLinkedList<T>::debug_to_string() {
    if (length == 0)
        return "";
    std::ostringstream oss;
    for (Node *node = head; node; node = node->next) {
        oss << node->data;
        if (node->next)
            oss << ' ';
    }
    return oss.str();
}

// To avoid memory leak
template<class T>
SingleLinkedList<T>::~SingleLinkedList<T>() {
    //O(n) time , O(1) memory
    while (head) {
        Node *current = head->next;
        std::cout << &head << ' ';
        delete head;
        head = current;
    }
};


void testLinkedList_structure() {
    //To check structure work well or not
    SingleLinkedList<int> lst;
    lst.insert_front(100);

    lst.insert_end(10);
    lst.insert_end(20);
    lst.insert_end(30);
    lst.insert_end(40);

    lst.debug();
    std::string excepcted = "100 10 20 30 40", result = lst.debug_to_string();
    if (excepcted != result) {
        std::cout << "No match:\nExcepcted: " << excepcted << "\nResult: " << result << std::endl;
        assert(false);
    }
    std::cout << "Linked List Format:" << std::endl;
    lst.print_list_format();
    std::cout << "**************" << std::endl;
    std::cout << "No RTE , Testing is Done!" << std::endl;
}
void testUndoStack() {
    SingleLinkedList<int> lst;
    lst.insert_end(10);
    lst.insert_end(20);
    lst.insert_end(20);
    lst.insert_end(40);
    lst.insert_end(50);
    lst.insert(70 , 2);
    lst.delete_front();
    lst.delete_back();
    lst.erase(0);


    std::cout << "List before undo:" << std::endl;
    // lst.print_list_format();
    lst.print();
    lst.undo();
    lst.undo();
    lst.undo();
    lst.undo();
    std::cout << "List after undo:" << std::endl;
    lst.print();
    // lst.print_list_format();
}

#endif