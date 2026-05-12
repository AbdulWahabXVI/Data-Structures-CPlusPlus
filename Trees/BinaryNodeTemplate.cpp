#include<iostream>
#include<algorithm>
using namespace std;
template<typename T>
class BiNode {
private:
    T value;
    BiNode<T>* parentNode;
    BiNode<T>* leftNode;
    BiNode<T>* rightNode;
public:
    BiNode(T v) {
        value = v;
        parentNode = nullptr;
        leftNode = nullptr;
        rightNode = nullptr;
    }
    void setParent(BiNode<T>* parentNode) {
        this->parentNode = parentNode;
    }
    void setLeft(BiNode<T>* leftNode) {
        this->leftNode = leftNode;
        if (leftNode) leftNode->setParent(this);
    }
    void setRight(BiNode<T>* rightNode) {
        this->rightNode = rightNode;
        if (rightNode) rightNode->setParent(this);
    }
    T getValue() const {
        return value;
    }
    BiNode<T>* getParent() {
        return parentNode;
    }
    BiNode<T>* getLeft() {
        return leftNode;
    }
    BiNode<T>* getRight() {
        return rightNode;
    }
    bool isLeaf() const {
        return (leftNode == nullptr) && (rightNode == nullptr);
    }

    int size() {
        int l = (leftNode != nullptr) ? leftNode->size() : 0;
        int r = (rightNode != nullptr) ? rightNode->size() : 0;
        return 1 + l + r;

    }
    int height() {
        if (isLeaf()) { return 0; }
        int l = (leftNode != nullptr) ? leftNode->height() : 0;
        int r = (rightNode != nullptr) ? rightNode->height() : 0;
        return 1 + max(l, r);

    }
    void clear() {
        if (leftNode != nullptr) leftNode->clear();
        if (rightNode != nullptr) rightNode->clear();
        if (parentNode) {
            if (parentNode->getLeft() == this) { 
                parentNode->setLeft(nullptr);
            }
            else if (parentNode->getRight() == this) {
                parentNode->setRight(nullptr);
            }
        }
        delete this;
    }
};
int main() {
    BiNode<string>* A = new BiNode<string>("A");
    BiNode<string>* B = new BiNode<string>("B");
    BiNode<string>* C = new BiNode<string>("C");
    BiNode<string>* D = new BiNode<string>("D");
    BiNode<string>* E = new BiNode<string>("E");
    BiNode<string>* F = new BiNode<string>("F");
    BiNode<string>* G = new BiNode<string>("G");
    BiNode<string>* H = new BiNode<string>("H");
    BiNode<string>* I = new BiNode<string>("I");
    BiNode<string>* J = new BiNode<string>("J");
    A->setLeft(B);
    A->setRight(C);
    B->setLeft(D);
    B->setRight(E);
    C->setLeft(F);
    C->setRight(G);
    G->setLeft(H);
    G->setRight(I);
    I->setRight(J);
    cout << A->size() << endl;
    cout << A->height() << endl;
    B->clear();
    cout << A->size() << endl;
    cout << A->height() << endl;
    return 0;
}
