#include "linkedlist/singlylinkedlist.h"

struct Coordinate {
    int x;
    int y;

    Coordinate() : x(0), y(0) {}
    Coordinate(int xx, int yy) : x(xx), y(yy) {}

    bool operator==(const Coordinate& other) const {
        return x == other.x && y == other.y;
    }

    friend ostream& operator<<(ostream& out, const Coordinate& c) {
        out << "(" << c.x << "," << c.y << ")";
        return out;
    }
};

class Snake {
private:
    MySinglyLinkedList<Coordinate> body;

public:
    Snake(int startX, int startY) {
        body.insertAtTail(Coordinate(startX, startY));
    }

    void move(int newX, int newY, bool grow = false) {
        Coordinate newHead(newX, newY);
        body.insertAtHead(newHead);

        if (!grow) {
            body.deleteFromTail();
        }
    }

    bool collisionCheck() {
        if (body.isEmpty() || body.head->next == nullptr) return false;
        Coordinate headPos = body.head->data;
        Node<Coordinate>* temp = body.head->next;
        while (temp != nullptr) {
            if (temp->data == headPos) return true;
            temp = temp->next;
        }
        return false;
    }

    void printSnake() {
        Node<Coordinate>* temp = body.head;
        cout << "Snake: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Snake snake(5, 5);
    snake.printSnake();

    cout << "\nMove right (6,5)" << endl;
    snake.move(6, 5);
    snake.printSnake();

    cout << "\nMove down (6,6) and grow (eat food)" << endl;
    snake.move(6, 6, true);
    snake.printSnake();

    cout << "\nMove left (5,6)" << endl;
    snake.move(5, 6);
    snake.printSnake();

    return 0;
}
