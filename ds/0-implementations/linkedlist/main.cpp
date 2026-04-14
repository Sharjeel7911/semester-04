#include "mylinkedlist.h"

int main() {
    MyLinkedList<int>* ll = new MyLinkedList<int>;

    ll->insertAtPosition(5, 0);
    ll->insertAtPosition(4, 1);
    ll->insertAtPosition(6, 0);
    ll->insertAtPosition(9, 1);
    ll->insertAtPosition(11, 0);
    ll->insertAtPosition(111, 5);
    ll->insertAtPosition(99, 8);



    cout << endl << endl << endl;

    ll->display();
    return 0;
}