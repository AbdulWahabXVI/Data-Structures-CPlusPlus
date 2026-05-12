#include <iostream>
using namespace std;

class Node {
	int element;
	Node* next_node;
	Node* prev_node;
public:
	Node(int e = 0, Node* n = nullptr, Node* p = nullptr) : element(e), next_node(n), prev_node(p) {};
	int retrieve() const {
		return element;
	}
	Node* next() const {
		return next_node;
	}
	Node* prev() const {
		return prev_node;
	}
	friend class List;
};

class List {
	Node* list_head;
public:
	List(Node* n = nullptr) : list_head(n) {}

	bool empty() {
		return list_head == nullptr;
	}

	void push_front(int n) {
		Node* temp = new Node(n, list_head, nullptr);
		if (!empty()) {
			list_head->prev_node = temp;
		}
		list_head = temp;
	}

	void pop_front() {
		if (empty()) {
			return;
		}
		Node* temp = list_head;
		list_head = list_head->next_node;
		delete temp;
		temp = nullptr;
		if (!empty()) {
			list_head->prev_node = nullptr;
		}
	}

	void push_back(int n) {
		if (empty()) {
			push_front(n);
		}
		else {
			for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node == nullptr) {
					Node* temp = new Node(n, nullptr, ptr);
					ptr->next_node = temp;
					break;
				}
			}
		}
	}

	void pop_back() {
		if (empty()) {
			return;
		}
		for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			if (ptr->next_node == nullptr) {
				if (ptr->prev_node != nullptr) {
					ptr->prev_node->next_node = nullptr;
				}
				else {
					list_head = nullptr;
				}
				ptr->prev_node = nullptr;
				delete ptr;
				ptr = nullptr;
				break;
			}
		}
	}

	void erase(int n) {
		if (empty()) {
			return;
		}
		for (Node* ptr = list_head; ptr != nullptr;) {
			if (ptr->retrieve() == n) {
				Node* temp = ptr;
				if (ptr->prev_node) {
					ptr->prev_node->next_node = ptr->next_node;
				}
				else {
					list_head = ptr->next_node;
				}
				if (ptr->next_node) {
					ptr->next_node->prev_node = ptr->prev_node;
				}
				ptr = ptr->next_node;
				temp->prev_node = nullptr;
				temp->next_node = nullptr;
				delete temp;
				temp = nullptr;
			}
			else {
				ptr = ptr->next_node;
			}
		}
	}

	int count() {
		int count = 0;
		for (Node* ptr = list_head; ptr; ptr = ptr->next_node) {
			count++;
		}
		return count;
	}

	void insert(int n, int p) {
		if (p <= 0) {
			push_front(n);
			return;
		}
		else if (p >= count()) {
			push_back(n);
			return;
		}
		Node* ptr = list_head;
		int i = 0;
		while (i < p && ptr) {
			ptr = ptr->next_node;
			i++;
		}
		Node* temp = new Node(n, ptr, ptr->prev_node);
		if (ptr->prev_node) {
			ptr->prev_node->next_node = temp;
		}
		ptr->prev_node = temp;
	}

	void display() {
		for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			cout << ptr->retrieve() << endl;
		}
		cout << endl;
	}

	friend class Node;
};

int main() {
	List list;
	list.push_front(1);
	list.display();

	list.insert(5, 0);
	list.display();

	list.insert(5, 2);
	list.display();
}
