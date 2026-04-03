#include "queue.h"

template <class T>
class MyPriorityQueue : public Queue<T> {
public:
    MyPriorityQueue(int);
    bool isFull();
    bool isEmpty();
    T peek();
    void enqueue(T);
    T dequeue();
    void display();
};

// constructor
template <class T>
MyPriorityQueue<T>::MyPriorityQueue(int size) : Queue<T>(size) {}

// checks if queue is full
template <typename T>
bool MyPriorityQueue<T>::isFull() { return Queue<T>::currSize == Queue<T>::maxSize; }

// checks if queue is empty
template <typename T>
bool MyPriorityQueue<T>::isEmpty() { return Queue<T>::currSize == 0; }

// returns element at front
template <typename T>
T MyPriorityQueue<T>::peek() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return T();
    }
    return Queue<T>::qu[0];
}

// add a value [piority is min element]
template <typename T>
void MyPriorityQueue<T>::enqueue(T val) {
    try {
        if (isFull()) throw runtime_error("Queue is full\n");
        int i = Queue<T>::currSize - 1;
        while (i >= 0 && Queue<T>::qu[i] > val) {  // Queue<T>::qu[i] < val [for max priority in queue]
            Queue<T>::qu[i + 1] = Queue<T>::qu[i];
            i--;
        }
        Queue<T>::qu[i + 1] = val;
        Queue<T>::currSize++;
    } catch (const exception& ptr) { cout << ptr.what(); }
}

// remove a value from front
template <typename T>
T MyPriorityQueue<T>::dequeue() {
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
void MyPriorityQueue<T>::display() {
    cout << "Current Size: " << Queue<T>::currSize << endl;
    cout << "Max Size: " << Queue<T>::maxSize << endl;
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    for (int i = 0; i < Queue<T>::currSize; i++) {
        cout << i << ". ";
        cout << Queue<T>::qu[i] << endl;
    }
}