#include<iostream>
#include<algorithm>
using namespace std;
template <class T>
class BSNode{
public:
    T value;
    BSNode<T>* leftNode;
    BSNode<T>* rightNode;
    BSNode(T n) : value(n), leftNode(nullptr), rightNode(nullptr) {}
    void setValue(T n) {
        value = n;
    }
    void setLeft(BSNode* n) {
        leftNode = n;
    }
    void setRight(BSNode* n) {
        rightNode = n;
    }
    T getValue() const{
        return value;
    }
    BSNode* getLeft(){
        return leftNode;
    }
    BSNode* getRight(){
        return rightNode;
    }
    bool is_leaf(){
        return (getLeft() == nullptr && getRight() == nullptr);
    }
    int size(){
        int l = getLeft() ? getLeft()->size() : 0;
        int r = getRight() ? getRight()->size() : 0;
        return 1 + l + r;
    }
    int height(){
        int l = getLeft() ? getLeft()->height() : -1;
        int r = getRight() ? getRight()->height() : -1;
        return 1 + max(l, r);
    }
    T front(){
        return (getLeft() ? getLeft()->front() : getValue());
    }

    T end(){
        return (getRight() ? getRight()->end() : getValue());
    }
    bool find(T n){
        if (n == getValue()){
            return true;
        }
        if (n < getValue() && getLeft()){
            return getLeft()->find(n);
        }
        if (n > getValue() && getRight()) {
            return getRight()->find(n);
        }
        return false;
    }
};

template <class T>
class BSTree
{
public:
    BSNode<T>* rootNode;
    BSTree(){
        rootNode = nullptr;
    }
    ~BSTree(){
        clear();
    }
    BSNode* getRoot(){
        return rootNode;
    }
    bool empty(){
        return (rootNode == nullptr);
    }
    int size(){
        return (rootNode != nullptr) ? rootNode->size() : 0;
    }
    int height(){
        return (rootNode != nullptr) ? rootNode->height() : -1;
    }
    bool find(T n) {
        return rootNode ? rootNode->find(n) : false;
    }
    T front(){
        if (rootNode == nullptr) {
            throw std::runtime_error("Empty");
        }
        return rootNode->front();
    }
    T back(){
        if (rootNode == nullptr) {
            throw std::runtime_error("Empty");
        }
        return rootNode->end();
    }

    bool insert(T n) {
        if (find(n)) return false;
        rootNode = insertRecurse(rootNode, n);
        return true;
    }

    bool erase(T n) {
        if (!find(n)) return false;
        rootNode = eraseRecurse(rootNode, n);
        return true;
    }

    void clear() {
        clearRecurse(rootNode);
        rootNode = nullptr;
    }

    BSNode<T>* insertRecurse(BSNode<T>* node, T n) {
        if (!node) return new BSNode<T>(n);
        if (n < node->value) {
            node->leftNode = insertRecurse(node->leftNode, n);
        }
        else if (n > node->value) {
            node->rightNode = insertRecurse(node->rightNode, n);
        }
        return node;
    }

    BSNode<T>* eraseRecurse(BSNode<T>* node, T n) {
        if (!node) return nullptr;
        if (n < node->value) {
            node->leftNode = eraseRecurse(node->leftNode, n);
        }
        else if (n > node->value) {
            node->rightNode = eraseRecurse(node->rightNode, n);
        }
        else {
            if (!node->leftNode && !node->rightNode) {
                delete node;
                return nullptr;
            }
            if (!node->leftNode) {
                BSNode<T>* temp = node->rightNode;
                delete node;
                return temp;
            }
            if (!node->rightNode) {
                BSNode<T>* temp = node->leftNode;
                delete node;
                return temp;
            }
            T replace = node->rightNode->front();
            node->value = replace;
            node->rightNode = eraseRecurse(node->rightNode, replace);
        }
        return node;
    }

    void clearRecurse(BSNode<T>* node) {
        if (!node) return;
        clearRecurse(node->leftNode);
        clearRecurse(node->rightNode);
        delete node;
    }
};
