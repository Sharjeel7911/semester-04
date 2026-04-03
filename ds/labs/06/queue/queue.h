#pragma once
#include <iostream>
using namespace std;

template <class T>
class Queue {
protected:
    T* qu;
    int currSize;
    int maxSize;
public:
    Queue(int);
    virtual ~Queue();
    int getCurrSize();
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual T peek() = 0;
    virtual void enqueue(T) = 0;
    virtual T dequeue() = 0;
    virtual void display() = 0;
};

template <class T>
Queue<T>::Queue(int size) {
    qu = new T[size];
    currSize = 0;
    maxSize = size;
}

template <class T>
Queue<T>::~Queue() {
    delete[] qu;
}

template <typename T>
int Queue<T>::getCurrSize() { return currSize; }