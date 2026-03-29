#include <iostream>
using namespace std;

class Stack{
    int stack_size;
    int array_capacity;
    int *array;
public:
    Stack(int n) : 
    stack_size(0), 
    array_capacity(std::max(1, n)), 
    array(new int[array_capacity]){
        
    }
    ~Stack(){
        delete [] array;
    }
    bool empty(){
        return stack_size == 0;
    }
    int top(){
        if (empty()){
            throw std::runtime_error("List Empty");
        }
        return array[stack_size - 1];
    }
    void push(int n){
        if(stack_size == array_capacity){
            double_capacity();
        }
        array[stack_size] = n;
        stack_size++;
    }
    int pop(){
        if (empty()){
            throw std::runtime_error("List Empty");
        }
        stack_size--;
        return array[stack_size];
    }
    void double_capacity(){
        int *tmp_array = new int[2*array_capacity];
        for(int i = 0; i < array_capacity; i++){
            tmp_array[i] = array[i];
        }
        delete [] array;
        array = tmp_array;
        array_capacity *= 2;
        cout<<"Doubling was done"<<endl;
    }
    void display(){
        for(int i = 0; i < stack_size; i++){
            cout<<array[i]<<endl;
        }
        cout<<endl;
    }
};

int main() {
	Stack s(1);

	s.push(67);
	s.push(68);
	s.display();
    
    s.pop();
    s.display();
}
