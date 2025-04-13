#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP
#include "BinaryTree.h"
/*  /////////////////////////_CONSTRUCTORS_/////////////////////////*/
template<class T>
BinaryTree<T>::BinaryTree(T val) : data(val) , left(nullptr), right(nullptr) {
}


template<class T>
BinaryTree<T>::BinaryTree(const std::string& postfix) {
    std::stack<BinaryTree<T>*> st;
    for(int i = 0 ; i < (int) postfix.size() ; ++i){
        BinaryTree<T>* node = new BinaryTree<T>(postfix[i]);
        if(!isdigit(postfix[i])) {
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
        }
        st.push(node);
    }

    BinaryTree<T>* root = st.top();
    this->data = root->data;
    this->left = root->left;
    this->right = root->right;
}

/*  /////////////////////////_TRAVERSAL_TYPES_ /////////////////////////*/
template<class T>
void BinaryTree<T>::print_inorder_expression() { // Expression trees
    if(left) {
        if(!left->is_leaf())
            std::cout << "(";
        left->print_inorder_expression();
        if(!left->is_leaf())
            std::cout << ")";
    }
    std::cout << data << ' ';
    if(right) {
        if(!right->is_leaf())
            std::cout << "(";
        right->print_inorder_expression();
        if(!right->is_leaf())
            std::cout << ")";
    }
}


template<class T>
void BinaryTree<T>::print_postorder() {
    if (left)
        left->print_postorder();
    if (right)
        right->print_postorder();
    std::cout << data << ' ';
}

template<class T>
void BinaryTree<T>::print_inorder() {
    if (left)
        left->print_inorder();
    std::cout << data << ' ';
    if (right)
        right->print_inorder();
}

template<class T>
void BinaryTree<T>::print_preorder() {
    std::cout << data << ' ';
    if (left)
        left->print_preorder();
    if (right)
        right->print_preorder();
}

template<class T>
void BinaryTree<T>::print_by_levels() {
    std::queue<BinaryTree<T>* > q;
    q.push(this);
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        std::cout << "Level: "  << level << '\n';
        while(size--) {
            auto current = q.front();
            q.pop();
            std::cout << current->data << ' ';
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
        ++level;
        std::cout << '\n';
    }
}

template<class T>
void BinaryTree<T>::print_by_levels_spiral() { // good idea
    std::deque<BinaryTree<T>* > q;
    q.push_front(this);
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        std::cout << "Level: "  << level << '\n';
        while(size--) {
            if(level % 2 == 0) {
                auto current = q.front();
                q.pop_front();
                std::cout << current->data << ' ';
                if(current->left)
                    q.push_back(current->left);
                if(current->right)
                    q.push_back(current->right);
            }else {
                auto current = q.back();
                q.pop_back();
                std::cout << current->data << ' ';
                if(current->right)
                    q.push_front(current->right);
                if(current->left)
                    q.push_front(current->left);
            }
        }
        ++level;
        std::cout << '\n';
    }
}

template<class T>
void BinaryTree<T>::clear() {
    if(left) {
        delete left;
        left = nullptr;
    }

    if(right) {
        delete right;
        right = nullptr;
    }
}

template<class T>
void BinaryTree<T>::add(const std::vector<T> &path_val, const std::vector<char> &path_dir) {
    if (path_val.size() != path_dir.size())
        throw std::invalid_argument("Path size mismatch");

    BinaryTree *cur = this;
    for (int i = 0; i < path_val.size(); i++) {
        if (path_dir[i] == 'L') {
            if (!cur->left)
                cur->left = new BinaryTree<T>(path_val[i]);
            else if (cur->left->data != path_val[i])
                throw std::invalid_argument("Wrong path value");
            cur = cur->left;
        } else {
            if (!cur->right)
                cur->right = new BinaryTree<T>(path_val[i]);
            else if (cur->right->data != path_val[i])
                throw std::invalid_argument("Wrong path value");
            cur = cur->right;
        }
    }
}

template<class T>
long long BinaryTree<T>::max() const { //WITH NUMS ONLY
    long long ret = data;
    if(left)
        ret = std::max(ret , left->max());
    if(right)
        ret = std::max(ret , right->max());
    return ret;
}

template<class T>
int BinaryTree<T>::height() const {
    int ret = 0;
    if(left)
        ret = 1 + left->height();
    if(right)
        ret = std::max(ret , 1 + right->height());

    return ret;
}

template<class T>
bool BinaryTree<T>::find(T val) const {
    int ret = data == val;
    if(!ret and left)
        ret = left->find(val);
    if(!ret and right)
        ret = right->find(val);
    return ret;
}

template<class T>
long long BinaryTree<T>::count_nodes() const {
    long long ret = 1;
    if(left)
        ret += left->count_nodes();
    if(right)
        ret += right->count_nodes();
    return ret;
}

template<class T>
bool BinaryTree<T>::is_leaf() const {
    return (left == nullptr && right == nullptr);
}

template<class T>
int BinaryTree<T>::count_leaves() const {
    int ret = is_leaf() ;
    if(left)
        ret += left->count_leaves();
    if(right)
        ret += right->count_leaves();
    return ret;
}

template<class T>
bool BinaryTree<T>::is_perfect_tree_rec(int h) const { // check this logic
    if(h == -1)
        h = height();
    //invalid case
    if(!left and right or !right and left)
        return false;
    //base case
    if(is_leaf()) // leaves level should be on all of them on the last level at h == 0
        return h == 0;

    return left->is_perfect_tree_rec(h - 1) && right->is_perfect_tree_rec(h - 1);
}

template<class T>
bool BinaryTree<T>::is_perfect_tree_formula() const {
    long long count = count_nodes();
    int _height = height();
    return count == (1LL << (_height+1)) - 1;
}

//Important approach in this function
template<class T>
void BinaryTree<T>::print_inorder_iterative() {
    std::stack<std::pair< BinaryTree<T>* , bool > > nodes; // bool to tell me if current node is expanded or not
    nodes.push({this , false});

    while(!nodes.empty()) {
        BinaryTree<T>* cur = nodes.top().first;
        bool is_done = nodes.top().second;
        nodes.pop();

        if(is_done)
            std::cout << cur->data << ' ';
        else {
            //stack -> FILO , so we reverse operations
            if(cur->right)
                nodes.push(std::make_pair(cur->right, false));
            nodes.push(std::make_pair(cur , true)) ; // Expanded
            if(cur->left)
                nodes.push(std::make_pair(cur->left, false));
        }
    }

    std::cout << '\n';
}

template<class T>
void BinaryTree<T>::traverse_tree_boundary() {
    std::cout << data << ' ';

    if(left)
        left->traverse_tree_boundary();
    else if(right)
        right->traverse_tree_boundary();
}

template<class T>
std::pair<int,int> BinaryTree<T>::tree_diameter() const {
    if(!left and !right) return {0 , 0};
    std::pair<int,int> ret , left_diam , right_diam;
    ret = left_diam = right_diam = {0 , 0};
    if(left)
        left_diam = left->tree_diameter() , ret.first += 1 + left_diam.second;
    if(right)
        right_diam = right->tree_diameter() , ret.first += 1 + right_diam.second;
    ret.first = std::max(ret.first , std::max(left_diam.first , right_diam.first));
    ret.second = 1 + std::max(left_diam.second, right_diam.second);
    return ret;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    // if(left) {
    //     std::cout << "~BinaryTree::~BinaryTree()" << left->data << ' '  << &this->left << std::endl;
    //     delete left;
    // }
    // if(right) {
    //     std::cout << "~BinaryTree::~BinaryTree()" << right->data << ' '  << &this->right << std::endl;
    //     delete right;
    // }
    clear();
}


#endif
