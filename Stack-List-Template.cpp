#include <iostream>
using namespace std;

template<typename T>
class Node {
	T element;
	Node<T>* next_node;
public:
	Node(T e = 0, Node<T>* n = nullptr) : element(e), next_node(n) {};
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
	List(Node<T>* n = nullptr) : list_head(n) {}

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
			cout << ptr->retrieve() << endl;
		}
		cout << endl;
	}

	T end() {
		return list_tail()->retrieve();
	}

	void push_front(T n) {
		Node<T>* temp = new Node<T>(n, list_head);
		list_head = temp;
	}

	T pop_front() {
		T val = 0;
		if (empty()) {
			throw std::runtime_error("List Empty");
		}
		else {
			Node<T>* temp = list_head;
			list_head = list_head->next_node;
			val = temp->retrieve();
			delete temp;
			temp = nullptr;
		}
		return val;
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

	T pop_end() {
		T val = 0;
		if (empty() || (list_head != nullptr && list_head->next_node == nullptr)) {
			return pop_front();
		}
		else {
			for (Node<T>* ptr = list_head; ptr != nullptr; ptr = ptr->next_node) {
				if (ptr->next_node->next_node == nullptr) {
					val = ptr->retrieve();
					delete ptr->next_node;
					ptr->next_node = nullptr;
					break;
				}
			}
		}
		return val;
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

template<typename T>
class Stack {
	List<T> l;
public:
	bool empty() {
		return l.empty();
	}
	T top() {
		return l.end();
	}
	void push(T n) {
		l.push_end(n);
	}
	T pop() {
		return l.pop_end();
	}
	void display() {
		l.display();
	}
};

int main() {
	Stack<float> s;

	s.push(67);
	s.push(68);
	s.display();

	s.pop();
	s.display();
}
