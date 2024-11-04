#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}

    void setLeft( Node<T>* someNode ) {
        this->left = someNode;
    }

    void setRight( Node<T>* someNode ) {
        this->right = someNode;
    }

    Node<T>* getLeft() {
        return left;
    }

    Node<T>* getRight() {
        return right;
    }
};


#endif // NODE_H
