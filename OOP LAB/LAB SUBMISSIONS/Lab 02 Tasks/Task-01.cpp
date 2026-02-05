#include <iostream>
#include <string>
using namespace std;

class Book{
    string title;
    string author;
    int code;
    string status;
    
    public:
    Book(string t, string a, int c, string s){
        title = t;
        author = a;
        code = c;
        status = s;
    }

    void Display(){
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << code << endl;
        cout << "status: " << status << endl;

    }

    int check(){
        if(status == "Available"){
            return 1;
        }
        else {
            return 0;
        }
    }

    void borrowBook(){
        if(check()== 1){
            cout << "Book Borrowed Successfully" << endl;
            status = "Borrowed";
        }
        else{
            cout << "Book is already borrowed" << endl;
        }
    }

    void returnBook(){
        if(status == "Borrowed"){
            status = "Available";
            cout << "Book returned successfully" << endl;
        }
        else{
            cout << "This book was not borrowed" << endl;
        }
    }

    int getcode(){
        return code;
    }
};

int main(){
    int choice;
    Book b[3] = {
    Book("OOP", "Hilton", 10, "Available"),
    Book("MVC", "Livis", 20, "Borrowed"),
    Book("DLD", "Mark-Zukrberg", 30, "Available") };

    do{
        cout << "Library Menu: \n" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. Borrow Book by ISBN" << endl;
        cout << "3. Return Book by ISBN" << endl;
        cout << "4. Search Book by ISBN" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1){
            for(int i=0;i<3;i++){
                b[i].Display();
            }
        }
               else if (choice == 2) {
            // Borrow book by ISBN
            int isbn;
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            bool found = false;
            for (int i = 0; i < 3; i++) {
                if (b[i].getcode() == isbn) {
                    b[i].borrowBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!" << endl;
            }
        } 
        else if (choice == 3) {
            int isbn;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            bool found = false;
            for (int i = 0; i < 3; i++) {
                if (b[i].getcode() == isbn) {
                    b[i].returnBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!" << endl;
            }
        } 
        else if (choice == 4) {
            // Search book by ISBN
            int isbn;
            cout << "Enter ISBN to search: ";
            cin >> isbn;
            bool found = false;
            for (int i = 0; i < 3; i++) {
                if (b[i].getcode() == isbn) {
                    b[i].Display();
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!" << endl;
            }
        } 
        else if (choice == 5) {
            cout << "Exiting..." << endl;
        } 
        else {
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}