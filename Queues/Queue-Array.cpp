#include <iostream>
using namespace std;

class Queue {
	int queue_size;
	int ifront;
	int iback;
	int array_capacity;
	int* array;
public:
	Queue(int n = 10) : queue_size(0), ifront(0), iback(0), array_capacity(n), array( new int[n]) {}
	bool empty() const {
		return (queue_size == 0);
	}
	int top() const {
		if (!empty()) {
			return array[ifront];
		}
		else {
			throw std::runtime_error("Empty");
		}
	}
	void push(int n) {
		if (queue_size == array_capacity) {
			throw std::runtime_error("Full");
		}
		array[iback] = n;
		iback++;
		if (iback >= array_capacity) {
			iback = 0;
		}
		queue_size++;
	}
	int pop() {
		if (empty()) {
			throw std::runtime_error("Empty");
		}
		int value = array[ifront];
		ifront++;
		if (ifront >= array_capacity) {
			ifront = 0;
		}
		queue_size--;
		return value;
	}
	~Queue() {
		delete[] array;
	}
};

int main() {
	Queue q(10);

	q.push(6);
	q.push(7);
	cout << q.top() << endl;
	cout << q.pop() << endl;
	cout << q.top() << endl;
	cout << q.pop() << endl;
}
