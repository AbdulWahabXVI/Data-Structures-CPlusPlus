#include <iostream>
using namespace std;

class Node {
	int element;
	Node* next_node;
public:
	Node(int e = 0, Node* n = nullptr) : element(e), next_node(n) {};
	int retrieve() const {
		return element;
	}
	Node* next() const {
		return next_node;
	}
	friend class List;
};

class List {
	Node* list_head;
public:
	List(Node* n = nullptr) : list_head(n) {}

	bool empty() const {
		if (list_head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	Node* list_tail() {
		if (empty()) return nullptr;
		for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			if (ptr->next_node == nullptr) {
				return ptr;
			}
		}
	}

	void display() {
		for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			cout << ptr->retrieve() << " " << ptr << endl;
		}
		cout << endl;
	}

	void push_front(int n) {
		Node* temp = new Node(n, list_head);
		list_head = temp;
	}

	int pop_front() {
		int val = 0;
		if (empty()) {
			throw std::runtime_error("Empty");
		}
		else {
			Node* temp = list_head;
			list_head = list_head->next_node;
			val = temp->retrieve();
			delete temp;
			temp = nullptr;
		}
		return val;
	}

	void push_end(int n) {
		if (empty()) {
			push_front(n);
		}
		else {
			for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node == nullptr) {
					Node* temp = new Node(n, nullptr);
					ptr->next_node = temp;
					break;
				}
			}
		}
	}

	int pop_end() {
		int val = 0;
		if (empty() || (list_head != nullptr && list_head->next_node == nullptr)) {
			pop_front();
		}
		else {
			for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node->next_node == nullptr) {
					val = ptr->next_node->retrieve();
					delete ptr->next_node;
					ptr->next_node = nullptr;
					break;
				}
			}
		}
		return val;
	}

	void erase(int n) {
		if (empty()) {
			return;
		}
		while (list_head && list_head->retrieve() == n) {
			pop_front();
		}
		for (Node* ptr = list_head; ptr && ptr->next_node;) {
			if (ptr->next_node->retrieve() == n) {
				Node* temp = ptr->next_node;
				ptr->next_node = temp->next_node;
				delete temp;
				temp = nullptr;
			}
			else {
				ptr = ptr->next_node;
			}
		}
	}
	~List() {
		while (!empty()) pop_front();
	}
	friend class Queue;
};

class Queue {
	List l;
public:
	bool empty() const {
		return l.empty();
	}
	int top() const {
		if (!empty()) {
			l.list_head->retrieve();
		}
		else {
			throw std::runtime_error("Empty");
		}
	}
	void push(int n) {
		l.push_end(n);
	}
	int pop() {
		return l.pop_front();
	}

};

int main() {
	Queue q;

	q.push(6);
	q.push(7);
	cout << q.top() << endl;
	cout << q.pop() << endl;
	cout << q.top() << endl;
	cout << q.pop() << endl;
}
