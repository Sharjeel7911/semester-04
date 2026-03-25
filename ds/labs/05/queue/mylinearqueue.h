#include "queue.h"

template <class T>
class MyLinearQueue : public Queue<T> {
public:
    MyLinearQueue(int);
    bool isFull();
    bool isEmpty();
    T peek();
    void enqueue(T);
    T dequeue();
    void display();
};

// constructor
template <class T>
MyLinearQueue<T>::MyLinearQueue(int size) : Queue<T>(size) {}

// checks if queue is full
template <typename T>
bool MyLinearQueue<T>::isFull() { return Queue<T>::currSize == Queue<T>::maxSize; }

// checks if queue is empty
template <typename T>
bool MyLinearQueue<T>::isEmpty() { return Queue<T>::currSize == 0; }

// returns element at front
template <typename T>
T MyLinearQueue<T>::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return T();
    }
    return Queue<T>::qu[0];
}

// add a value 
template <typename T>
void MyLinearQueue<T>::enqueue(T val) {
    try {
        if (isFull()) throw runtime_error("Queue is full\n");
        Queue<T>::qu[Queue<T>::currSize++] = val;
    } catch (const exception& ptr) { cout << ptr.what(); }
}

// remove a value from front
template <typename T>
T MyLinearQueue<T>::dequeue() {
    try {
        if (isEmpty()) throw runtime_error("Queue is empty\n");
        T removedVal = Queue<T>::qu[0];
        for (int i = 0; i < Queue<T>::currSize - 1; i++) {
            Queue<T>::qu[i] = Queue<T>::qu[i + 1];
        }
        Queue<T>::currSize--;
        return removedVal;
    } catch (const exception& ptr) { cout << ptr.what(); }
    return T();
}

// display the content
template <typename T>
void MyLinearQueue<T>::display() {
    cout << "Current Size: " << Queue<T>::currSize << endl;
    cout << "Max Size: " << Queue<T>::maxSize << endl;
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << endl;
    for (int i = 0; i < Queue<T>::currSize; i++) {
        cout << i << ". ";
        cout << Queue<T>::qu[i] << endl;
    }
}