#include "linkedlist/singlylinkedlist.h" 
#include <string>

struct Product {
    int id;
    string name;

    Product() : id(0), name("") {}
    Product(int i, string n) : id(i), name(n) {}

    bool operator==(const Product& other) const {
        return id == other.id;
    }


};

ostream& operator<<(ostream& out, const Product& p) {
    out << "ID: " << p.id << ", Name: " << p.name;
    return out;
}

class ProductManagement {
private:
    MySinglyLinkedList<Product> productList;
public:
    void addProduct(Product p) { productList.insertAtTail(p); }

    void deleteProduct(int pos) {
        if (pos < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        productList.deleteFromPosition(pos);
    }

    void displayProducts() { productList.display(); }

    int searchById(int id) {
        Node<Product>* temp = productList.head;
        int pos = 0;
        while (temp != nullptr) {
            if (temp->data.id == id) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }


};


int main() {
    ProductManagement pm;

    Product p1(101, "Laptop");
    Product p2(102, "Mouse");
    Product p3(103, "Keyboard");
    Product p4(104, "Monitor");

    pm.addProduct(p1);
    pm.addProduct(p2);
    pm.addProduct(p3);
    pm.addProduct(p4);

    cout << "Initial List:" << endl;
    pm.displayProducts();

    cout << "\nEnter the product ID to search and delete: ";
    int idToDelete;
    cin >> idToDelete;

    int pos = pm.searchById(idToDelete);
    if (pos != -1) {
        pm.deleteProduct(pos);
        cout << "Product with ID " << idToDelete << " deleted successfully.\n";
    }
    else cout << "Product with ID " << idToDelete << " not found.\n";

    cout << "\nUpdated List:" << endl;
    pm.displayProducts();
    return 0;
}
