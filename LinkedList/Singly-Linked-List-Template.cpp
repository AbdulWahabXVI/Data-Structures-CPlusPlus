#include <iostream>
using namespace std;

template<typename T>
class Node {
	T element;
	Node<T>* next_node;
public:
	Node(T e = 0, Node<T>* n = nullptr): element(e), next_node(n) {};
	T retrieve() const {
		return element;
	}
	Node<T>* next() const {
		return next_node;
	}

	template<typename T>
	friend class List;
};

template<typename T>
class List {
	Node<T>* list_head;
public:
	List(Node<T>* n = nullptr): list_head(n) {}
	
	bool empty() const {
		if (list_head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	Node<T>* list_tail() {
		if (empty()) return nullptr;
		for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			if (ptr->next_node == nullptr) {
				return ptr;
			}
		}
	}

	void display() {
		for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
			cout << ptr->retrieve() << " " << ptr << endl;
		}
		cout << endl;
	}

	void push_front(T n) {
		Node<T>* temp = new Node<T>(n, list_head);
		list_head = temp;
	}

	void pop_front() {
		if (empty()) {
			return;
		}
		else {
			Node<T>* temp = list_head;
			list_head = list_head->next_node;
			delete temp;
			temp = nullptr;
		}
	}

	void push_end(T n) {
		if (empty()) {
			push_front(n);
		}
		else {
			for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node == nullptr) {
					Node<T>* temp = new Node<T>(n, nullptr);
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
			for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node->next_node == nullptr) {
					delete ptr->next_node;
					ptr->next_node = nullptr;
					break;
				}
			}
		}
	}

	void erase(T n) {
		if (empty()) {
			return;
		}
		while (list_head && list_head->retrieve() == n) {
			pop_front();
		}
		for (Node<T>* ptr = list_head; ptr && ptr->next_node;) {
			if (ptr->next_node->retrieve() == n) {
				Node<T>* temp = ptr->next_node;
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
	List<double> list;

	list.pop_front();
	list.display();

	list.erase(6.5);
	list.display();

	list.push_end(6.6);
	list.display();

	list.erase(6);
	list.display();

	list.push_end(6.1);
	list.display();

	list.push_end(6.2);
	list.display();

	list.push_end(6.3);
	list.display();

	list.push_end(6.4);
	list.display();

	list.push_end(6.7);
	list.display();

	list.push_end(5.1);
	list.display();

	list.push_end(6.9);
	list.display();

	list.erase(6.6);
	list.display();
}
