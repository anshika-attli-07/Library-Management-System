#include <iostream>
#include <string>
using namespace std;

// Maximum number of books
const int MAX_BOOKS = 100;


// Book Class
class Book {

public:

    // Book details
    string bookName;
    int bookID;
    bool issued;

};


// Library Class
class Library {

private:

    Book books[MAX_BOOKS];
    int bookCount = 0;


public:

    // Add a Book
    void addBook() {

        if (bookCount >= MAX_BOOKS) {
            cout << "\nLibrary is full!\n";
            return;
        }

        cout << "\nEnter Book ID: ";
        cin >> books[bookCount].bookID;

        cin.ignore();

        cout << "Enter Book Name: ";
        getline(cin, books[bookCount].bookName);

        books[bookCount].issued = false;

        bookCount++;

        cout << "Book added successfully!\n";
    }


    // Display Books
    void displayBooks() {

        if (bookCount == 0) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n----- LIBRARY BOOKS -----\n";

        for (int i = 0; i < bookCount; i++) {

            cout << "\nBook ID: " << books[i].bookID;
            cout << "\nBook Name: " << books[i].bookName;

            if (books[i].issued == true) {
                cout << "\nStatus: Issued\n";
            }
            else {
                cout << "\nStatus: Available\n";
            }
        }
    }


    // Search a Book
    void searchBook() {

        int id;
        bool found = false;

        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {

            if (books[i].bookID == id) {

                cout << "\nBook Found!";
                cout << "\nBook Name: " << books[i].bookName;

                if (books[i].issued == true) {
                    cout << "\nStatus: Issued\n";
                }
                else {
                    cout << "\nStatus: Available\n";
                }

                found = true;
                break;
            }
        }

        if (found == false) {
            cout << "\nBook not found.\n";
        }
    }


    // Issue a Book
    void issueBook() {

        int id;
        bool found = false;

        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {

            if (books[i].bookID == id) {

                found = true;

                if (books[i].issued == true) {
                    cout << "\nBook is already issued.\n";
                }
                else {
                    books[i].issued = true;
                    cout << "\nBook issued successfully.\n";
                }

                break;
            }
        }

        if (found == false) {
            cout << "\nBook not found.\n";
        }
    }


    // Return a Book
    void returnBook() {

        int id;
        bool found = false;

        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {

            if (books[i].bookID == id) {

                found = true;

                if (books[i].issued == false) {
                    cout << "\nBook is already available.\n";
                }
                else {
                    books[i].issued = false;
                    cout << "\nBook returned successfully.\n";
                }

                break;
            }
        }

        if (found == false) {
            cout << "\nBook not found.\n";
        }
    }

};



int main() {

    Library library;

    int choice;

    do {

        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====\n";

        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                library.addBook();
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                library.searchBook();
                break;

            case 4:
                library.issueBook();
                break;

            case 5:
                library.returnBook();
                break;

            case 6:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
