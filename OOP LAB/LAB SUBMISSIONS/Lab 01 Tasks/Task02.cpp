#include <iostream>
using namespace std;

struct Book{
	int ID;
	string title;
	string author;
	float price;
};

int main(){
	Book b[3];
	float total=0;
	
	for(int i=0;i<3;i++){
		cout << "Enter Details for Book " << i+1 << ": " << endl;
		
		cout << "ID: " ;
		cin >> b[i].ID;
		
		cin.ignore();

        cout << "Title: ";
        getline(cin, b[i].title);

        cout << "Author: ";
        getline(cin, b[i].author);
		
		cout << "Price: " ;
		cin >> b[i].price;
		
		total = total + b[i].price;
	}
	
	
	
	cout << "\nAll books information: \n" << endl;
	for(int i=0;i<3;i++){
	
		cout << "\nBook"<< i+1 << ": " << endl;
		cout << "ID: " << b[i].ID << endl;
		cout << "Title: " << b[i].title << endl;
		cout << "Author: " << b[i].author << endl;
		cout << "Price: " << b[i].price << endl;
	}
	
	cout <<"\nTotal price of all books: " << total <<endl;
	return 0;
}
