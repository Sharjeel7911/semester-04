#include <iostream>
#include <stdexcept>
using namespace std;

inline void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[1;1H";
#endif
}

inline void pauseScreen() {
    cout << "Press Enter to continue..." << endl;
    cin.get();
}

template <class T>
class MyStack {
private:
    T* st;
    int topPtr;
    int maxSize;

public:
    MyStack(int);
    ~MyStack();
    bool isFull();
    bool isEmpty();
    void push(T);
    T pop();
    T top();
    int size();
    void display();
};

// constructor
template <class T>
MyStack<T>::MyStack(int size) : topPtr(0), maxSize(size) {
    st = new T[maxSize];
}

// destructor
template <class T>
MyStack<T>::~MyStack() {
    delete[] st;
}

// check if stack is full
template <class T>
bool MyStack<T>::isFull() {
    return topPtr == maxSize;
}

// check if stack is empty
template <class T>
bool MyStack<T>::isEmpty() {
    return topPtr == 0;
}

// get top element
template <class T>
T MyStack<T>::top() {
    if (isEmpty()) {
        cout << "No ongoing call.\n";
        return T();
    }
    return st[topPtr - 1];
}

// push element
template <class T>
void MyStack<T>::push(T val) {
    try {
        if (isFull()) throw runtime_error("Cannot add new call\n");
        st[topPtr++] = val;
        cout << "New call added: " << val << endl;
    } catch (const exception& ptr) {
        cout << ptr.what();
    }
}

// pop element
template <class T>
T MyStack<T>::pop() {
    try {
        if (isEmpty()) throw runtime_error("No ongoing call to end.\n");
        T val = st[--topPtr];
        cout << "Ended call with: " << val << endl;
        return val;
    } catch (const exception& ptr) {
        cout << ptr.what();
    }
    return T();
}

// current size of stack
template <class T>
int MyStack<T>::size() {
    return topPtr;
}

// display stack from top to bottom
template <class T>
void MyStack<T>::display() {
    if (isEmpty()) {
        cout << "No ongoing calls.\n";
        return;
    }

    cout << "Calls in stack\n";
    for (int i = topPtr - 1; i >= 0; i--) {
        cout << (topPtr - i) << ". " << st[i] << endl;
    }
}

//---------------------------------------------------------------------------

int main() {
    int maxCalls;
    cout << "Enter maximum number of calls the phone can handle: ";
    cin >> maxCalls;
    cin.ignore();

    MyStack<string> callStack(maxCalls);

    int choice;
    string caller;

    do {
        clearScreen();
        cout << "\n==== Mobile Call Stack ====\n";
        cout << "1. New Call (Push)\n";
        cout << "2. End Current Call (Pop)\n";
        cout << "3. Check Current Call (Top)\n";
        cout << "4. Display All Calls\n";
        cout << "5. Check if Call Stack is Empty\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter caller name: ";
            getline(cin, caller);
            callStack.push(caller);
            pauseScreen();
            break;
        case 2:
            caller = callStack.pop();
            pauseScreen();
            break;
        case 3:
            caller = callStack.top();
            if (!caller.empty()) {
                cout << "Current ongoing call: " << caller << endl;
            }
            pauseScreen();
            break;
        case 4:
            callStack.display();
            pauseScreen();
            break;
        case 5:
            if (callStack.isEmpty()) {
                cout << "No ongoing calls.\n";
            }
            else {
                cout << "There are ongoing calls.\n";
            }
            pauseScreen();
            break;
        case 0:
            cout << "Exiting program.\n";
            pauseScreen();
            break;
        default:
            cout << "Invalid choice! Try again.\n";
            pauseScreen();
        }
    }
    while (choice != 0);

    return 0;
}