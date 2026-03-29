#include<iostream>
using namespace std;

class Node {
    int element;
    Node* next;
public:
    Node(int e, Node* n = nullptr) : element(e), next(n) {}
    int retrieve() { return element; }
    friend class List;
};

class List {
    Node* head;
public:
    List() : head(nullptr) {}

    bool empty() {
        return head == nullptr;
    }
    Node* tail() {
        if (empty()) return nullptr;
        Node* ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        return ptr;
    }

    int size() {
        int count = 0;
        if (empty()) return count;
        Node* ptr = head;
        do {
            count++;
            ptr = ptr->next;
        } while (ptr != head);
        return count;
    }
    int count(int n) {
        int count = 0;
        if (empty()) return count;
        Node* ptr = head;
        do {
            if (ptr->retrieve() == n) {
                count++;
            }
            ptr = ptr->next;
        } while (ptr != head);
        return count;
    }
    int front() {
        if (empty()) throw std::runtime_error("Empty");
        return head->retrieve();
    }
    int end() {
        if (empty()) throw std::runtime_error("Empty");
        return tail()->retrieve();
    }

    void push_front(int n) {
        Node* temp = new Node(n);
        if (empty()) {
            head = temp;
            head->next = head;
        }
        else {
            temp->next = head;
            tail()->next = temp;
            head = temp;
        }
    }
    void push_end(int n) {
        if (empty()) {
            push_front(n);
            return;
        }
        Node* temp = new Node(n, head);
        tail()->next = temp;
    }
    int pop_front() {
        if (empty()) throw std::runtime_error("Empty");
        Node* temp = head;
        int val = temp->retrieve();
        if (head->next == head) {
            head = nullptr;
        }
        else {
            tail()->next = head->next;
            head = head->next;
        }
        delete temp;
        temp = nullptr;
        return val;
    }
    int pop_end() {
        if (empty()) throw std::runtime_error("Empty");
        int val = 0;
        if (head->next == head) {
            val = head->retrieve();
            delete head;
            head = nullptr;
        }
        else {
            Node* ptr = head;
            while (ptr->next->next != head) {
                ptr = ptr->next;
            }
            Node* temp = ptr->next;
            ptr->next = head;
            val = temp->retrieve();
            delete temp;
            temp = nullptr;
        }
        return val;
    }
    void erase(int n) {
        if (empty()) return;

        while (!empty() && head->retrieve() == n) {
            pop_front();
        }

        if (empty()) return;

        Node* ptr = head;
        while (ptr->next != head) {
            if (ptr->next->retrieve() == n) {
                Node* temp = ptr->next;
                ptr->next = temp->next;
                delete temp;
                temp = nullptr;
            }
            else {
                ptr = ptr->next;
            }
        }
    }

    void display() {
        if (empty()) {
            cout << "head -> (empty) -> head" << endl;
            return;
        }
        Node* ptr = head;
        cout << "head ->";
        do {
            cout << ptr->retrieve() << " -> ";
            ptr = ptr->next;
        } while (ptr != head);
        cout << "head" << endl;
    }

    ~List() {
        while (!empty()) pop_front();
    }
};

int main() {
    for (int j = 0; j < 10; j++) {
        List l;
        for (int i = 10; i > 0; i--) {
            l.push_end(i);
        }
        l.display();
        cout << endl;
    }
}
