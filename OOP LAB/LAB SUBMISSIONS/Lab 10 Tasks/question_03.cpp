#include <iostream>
#include <fstream>
using namespace std;

class Backup {
public:
    void addLog() {
        string message;
        cout << "Enter log message: ";
        getline(cin, message);

        ofstream file("backup_log.txt", ios::app);
        file << message << endl;

        cout << "Current file size: " << file.tellp() << " bytes" << endl;

        file.close();
    }
};

int main() {
    Backup b;
    b.addLog();
    return 0;
}