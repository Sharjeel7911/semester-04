#include "library.h"

int main() {

    Book<string> book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book<string> book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper<string> newspaper1("Washington Post", "2024-10-13", "ZEdition");
    Newspaper<string> newspaper2("The Times", "2024-10-12", "AEdition");

    Library<Book<string>, Newspaper<string>> library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book<string>* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    } else {
        cout << "\nBook not found.\n";
    }

    Newspaper<string>* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    } else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}