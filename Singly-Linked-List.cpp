#include <iostream>
using namespace std;

class Node {
	int element;
	Node* next_node;
public:
	Node(int e = 0, Node* n = nullptr): element(e), next_node(n) {};
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
	List(Node* n = nullptr): list_head(n) {}
	
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

	void pop_front() {
		if (empty()) {
			return;
		}
		else {
			Node* temp = list_head;
			list_head = list_head->next_node;
			delete temp;
			temp = nullptr;
		}
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

	void pop_end() {
		if (empty() || (list_head != nullptr && list_head->next_node == nullptr)) {
			pop_front();
		}
		else {
			for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node->next_node == nullptr) {
					delete ptr->next_node;
					ptr->next_node = nullptr;
					break;
				}
			}
		}
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
};

int main() {
	List list;

	list.pop_front();
	list.display();

	list.erase(6);
	list.display();

	list.push_end(6);
	list.display();

	list.erase(6);
	list.display();

	list.push_end(6);
	list.display();

	list.push_end(6);
	list.display();

	list.push_end(6);
	list.display();

	list.push_end(6);
	list.display();

	list.push_end(6);
	list.display();

	list.push_end(5);
	list.display();

	list.push_end(6);
	list.display();

	list.erase(6);
	list.display();
}
