#ifndef AVL_TREE_CPP
#define AVL_TREE_CPP
#include "AVL_Tree.h"

template <class T>
AVL_Tree<T>::AVL_Tree() : root(nullptr) {}

template <class T>
AVL_Tree<T>::AVL_Tree(int val) : root(new TreeNode<T>(val)) {}


template <class T>
int AVL_Tree<T>::ch_height(TreeNode<T> *node) {
    return node ? node->height : -1;
}

template <class T>
int AVL_Tree<T>::balance_factor(TreeNode<T> *node) {
    return node ? ch_height(node->left) - ch_height(node->right) : 0;
}

template <class T>
void AVL_Tree<T>::update_height(TreeNode<T> *node) {
    if (node)
        node->height = 1 + std::max(ch_height(node->left), ch_height(node->right));
}

template <class T>
TreeNode<T> *AVL_Tree<T>::left_rotation(TreeNode<T> *node) {
    TreeNode<T> *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    update_height(node);
    update_height(temp);
    return temp;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::right_rotation(TreeNode<T> *node) {
    TreeNode<T> *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    update_height(node);
    update_height(temp);
    return temp;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::balance(TreeNode<T> *node) {
    if(balance_factor(node) == 2){ // balance the LL and LR case
        if(balance_factor(node->left) == -1)
            node->left = left_rotation(node->left);
        node = right_rotation(node);
    }else if(balance_factor(node) == -2){ //balance the RR and RL case
        if(balance_factor(node->right) == 1)
            node->right = right_rotation(node->right);
        node = left_rotation(node);
    }

    return node;
}

template <class T>
TreeNode<T> *AVL_Tree<T>::insert(TreeNode<T> *node, T data) {
    if(!node)
        node = new TreeNode<T>(data);
    else if(data < node->data)
        node->left = insert(node->left , data);
    else
        node->right = insert(node->right , data);

    update_height(node);
    return balance(node);
}

template <class T>
void AVL_Tree<T>::print(TreeNode<T> *node){
    if(!node) return;
    print(node->left);
    cout<< node->data << ' ';
    print(node->right);
}

template <class T>
void AVL_Tree<T>::insert(T data) {
    if(!root) {
        root = new TreeNode<T>(data);
        return;
    }
    root = insert(root, data);
}

template<class T>
void AVL_Tree<T>::print(){
    if(!root) return ;
    print(root);
    cout << '\n';
}

template <class T>
TreeNode<T> *AVL_Tree<T>::delete_node(TreeNode<T> *node ,T val){
    /*
        delete and rebalance the tree
    */


    if(!node) return nullptr;

    if(val < node->data){
        node->left = delete_node(node->left , val);
    }else if(val > node->data){
        node->right = delete_node(node->right , val);
    }else{// reach the node
        if(!node->left && !node->right){
            delete node;
            node = nullptr;
        }else if(!node->right){
            node->data = node->left->data;
            delete node->left;
        }else if(!node->left){
            node->data = node->right->data;
            delete node->right;
        }else{ // two childern
            TreeNode<T> *temp =node->right;
            while(temp && temp->left) // get the successor
                temp = temp->left;
            node->data = temp->data;
            node->right = delete_node(node->right , temp->data); // go to remove the successor
        }
    }

    if(node){
        update_height(node);
        node = balance(node);
    }

    return node;
}

template <class T>
void AVL_Tree<T>::delete_node(T val){
    root = delete_node(root , val);
}

template <class T>
AVL_Tree<T>::~AVL_Tree() {
    delete root;
    root = nullptr;
}

#endif // AVL TREE CPP
