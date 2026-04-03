#include "queue.h"

template <class T>
class MyCircularQueue : public Queue<T> {
private:
    int front;
    int rear;
public:
    MyCircularQueue(int);
    bool isFull();
    bool isEmpty();
    T peek();
    void enqueue(T);
    T dequeue();
    void display();
    // currSize = rear - front; 
};

// constructor
template <class T>
MyCircularQueue<T>::MyCircularQueue(int size) : Queue<T>(size), front(0), rear(0) {}

// checks if queue is full
template <typename T>
bool MyCircularQueue<T>::isFull() { return Queue<T>::currSize == Queue<T>::maxSize; }

// checks if queue is empty
template <typename T>
bool MyCircularQueue<T>::isEmpty() { return Queue<T>::currSize == 0; }

// returns element at front
template <typename T>
T MyCircularQueue<T>::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return T();
    }
    return Queue<T>::qu[front];
}

// add a value 
template <typename T>
void MyCircularQueue<T>::enqueue(T val) {
    try {
        if (isFull()) throw runtime_error("Queue is full\n");
        Queue<T>::qu[rear] = val;
        rear = (rear + 1) % Queue<T>::maxSize;
        Queue<T>::currSize++;
    } catch (const exception& ptr) { cout << ptr.what(); }
}

// remove a value from front
template <typename T>
T MyCircularQueue<T>::dequeue() {
    try {
        if (isEmpty()) throw runtime_error("Queue is empty\n");
        T removedVal = Queue<T>::qu[front];
        front = (front + 1) % Queue<T>::maxSize;
        Queue<T>::currSize--;
        return removedVal;
    } catch (const exception& ptr) { cout << ptr.what(); }
    return T();
}

// display the content
template <typename T>
void MyCircularQueue<T>::display() {
    cout << "Current Size: " << Queue<T>::currSize << endl;
    cout << "Max Size: " << Queue<T>::maxSize << endl;
    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;

    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    for (int i = 0; i < Queue<T>::currSize; i++) {
        int index = (front + i) % Queue<T>::maxSize;
        cout << index << ". ";
        cout << Queue<T>::qu[index] << endl;
    }
}