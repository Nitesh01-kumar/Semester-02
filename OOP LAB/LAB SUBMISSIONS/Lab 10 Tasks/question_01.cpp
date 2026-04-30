#include <iostream>
#include <fstream>
using namespace std;


class Attendee {
private:
    string name;
    string email;

public:
    void getData() {
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your email: ";
        getline(cin, email);
    }

    void saveToFile() {
        ofstream file;

        file.open("signup.txt", ios::app);

        if (file.is_open()) {
            file << "Name: " << name << ", Email: " << email << endl;
            file.close();
            cout << "Registration saved successfully!\n";
        } else {
            cout << "Error opening file!\n";
        }
    }
};

int main() {
    Attendee person;

    person.getData();

    person.saveToFile();

    return 0;
}