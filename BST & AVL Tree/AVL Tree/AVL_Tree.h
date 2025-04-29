#ifndef AVL_TREE_H
#define AVL_TREE_H
#include "TreeNode.cpp"

/* Adelson-Velsky and Landis Tree :)
Self-balancing binary search tree
insertion , deletion , search in O(logn) time

- The Balance Factor of a node is the height of the left subtree minus the height of the right subtree
- It must be -1 , 0 , 1
- Left subtree height > Right subtree height => Right Rotation
- Right subtree height > Left subtree height => Left Rotation
- If the balance factor of a node is not -1 , 0 , 1 then we have to balance the tree

There are 4 cases to balance the tree:
1. Left-Left Case => Right Rotation

2. Left-Right Case => (convert it two LL then Right Rotation)
                      Left Rotation on left child and Right Rotation on node
3. Right-Right Case => Left Rotation

4. Right-Left Case => (convert it two LL then Right Rotation)
                      Right Rotation on right child then Left Rotation on node


- In each insertion and deletion we have to update the height of the node and re-balance the tree
*/
template <class T>
class AVL_Tree{
private:
    TreeNode<T> *root;

    int ch_height(TreeNode<T> *node);
    int balance_factor(TreeNode<T> *node);
    void update_height(TreeNode<T> *node);
    TreeNode<T> *left_rotation(TreeNode<T> *node);
    TreeNode<T> *right_rotation(TreeNode<T> *node);
    TreeNode<T> *balance(TreeNode<T> *node);
    TreeNode<T> *insert(TreeNode<T> *node, T val);
    void print(TreeNode<T> *node);
    TreeNode<T> * delete_node(TreeNode<T> *node , T val);

public:
    AVL_Tree();
    AVL_Tree(int val);
    void insert(T val);
    void print();
    void delete_node(T val);
    ~AVL_Tree();
};

#include "AVL_Tree.cpp"
#endif // AVL_TREE_H
