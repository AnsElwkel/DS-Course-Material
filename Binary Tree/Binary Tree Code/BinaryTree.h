#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <queue>
#include <deque>


template<typename T>
class BinaryTree {
public:
    BinaryTree(T val);
    BinaryTree(const std::string& postfix); //Expression trees

    bool is_just_num();

    void clear();

    // three methods below are a depth first traversal
    void print_postorder(); //O(n) where n is num of node .... O(2^levels)

    void print_inorder(); //O(n) where n is num of node .... O(2^levels)

    void print_preorder(); //O(n) where n is num of node .... O(2^levels)

    void print_inorder_expression();

    // Breadth traversal
    void print_by_levels();

    //problem on leetcode :)
    void print_by_levels_spiral();

    void add(const std::vector<T> &path_val, const std::vector<char> &path_dir);

    long long max() const; //O(n) where n is num of node .... O(2^levels)

    int height() const; //O(n) where n is num of node .... O(2^levels)

    bool find(T val) const; //O(n) where n is num of node .... O(2^levels)

    long long count_nodes() const; //O(n) where n is num of node .... O(2^levels)

    bool is_leaf() const; //O(1)

    int count_leaves() const; //O(n) where n is num of node .... O(2^levels)

    bool is_perfect_tree_rec(int h = -1) const; //O(n) where n is num of node .... O(2^levels)

    bool is_perfect_tree_formula() const; //O(n) where n is num of node .... O(2^levels)

    void print_inorder_iterative() ;

    void traverse_tree_boundary() ;

    //problem on leetcode
    std::pair<int,int> tree_diameter() const;

    int tree_diameter_2() const;

    ~BinaryTree();

    private :
        T data{};
    BinaryTree *left, *right;
};

#include "BinaryTree.cpp"

#endif //BINARYTREE_H
