#include <iostream>
using namespace std;

template <class T>
class Stack {
protected:
    T* st;
    int topPtr;
    int size;
public:
    Stack(int);
    virtual ~Stack();
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T) = 0;
    virtual T pop() = 0;
    virtual T top() = 0;
    virtual void display() = 0;
};

template <class T>
Stack<T>::Stack(int size) {
    st = new T[size];
    topPtr = 0;
    this->size = size;
}

template <class T>
Stack<T>::~Stack() {
    delete[] st;
}