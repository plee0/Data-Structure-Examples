#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}

    // setters to set the right and left nodes
    void setLeft( Node<T>* someNode ) {
        this->left = someNode;
    }

    void setRight( Node<T>* someNode ) {
        this->right = someNode;
    }

    // getters to return the left and right nodes, if available
    Node<T>* getLeft() {
        return left;
    }

    Node<T>* getRight() {
        return right;
    }
    
    // getters to return the integer data of each story
    int getEventNumber() {
        return data.eventNumber;
    }
    
    int getLeftEvent() {
        return data.leftEventNumber;
    }

    int getRightEvent() {
        return data.rightEventNumber;
    }

};


#endif // NODE_H
