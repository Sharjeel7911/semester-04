#include "stack.h"

template <class T>
class MyStack : public Stack<T> {
public:
    MyStack(int);
    bool isFull();
    bool isEmpty();
    void push(T);
    T pop();
    T top();
    void display();
};

// constructor
template <class T>
MyStack<T>::MyStack(int size) : Stack<T>(size) {}

// checks if stack is full
template <typename T>
bool MyStack<T>::isFull() { return Stack<T>::topPtr == Stack<T>::size; }

// checks if stack is empty
template <typename T>
bool MyStack<T>::isEmpty() { return Stack<T>::topPtr == 0; }

// return top element
template <typename T>
T MyStack<T>::top() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return T();
    }
    return Stack<T>::st[Stack<T>::topPtr - 1];
}

// insert a value
template <typename T>
void MyStack<T>::push(T val) {
    try {
        if (isFull()) throw runtime_error("Stack overflow\n");
        Stack<T>::st[Stack<T>::topPtr++] = val;
    } catch (const exception& ptr) { cout << ptr.what(); }
}

// remove a value
template <typename T>
T MyStack<T>::pop() {
    try {
        if (isEmpty()) throw runtime_error("Stack underflow\n");
        return Stack<T>::st[--Stack<T>::topPtr];
    } catch (const exception& ptr) { cout << ptr.what(); }
    return T();
}

// display the stack content
template <typename T>
void MyStack<T>::display() {
    cout << "Current Size: " << Stack<T>::topPtr << endl;
    cout << "Max Size: " << Stack<T>::size << endl;
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }

    for (int i = 0; i < Stack<T>::topPtr; i++) {
        cout << i << ". ";
        cout << Stack<T>::st[i] << endl;
    }
}