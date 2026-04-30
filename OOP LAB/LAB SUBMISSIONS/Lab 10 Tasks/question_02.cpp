#include <iostream>
#include <fstream>
#include <cctype>  
using namespace std;

class SecurityTool {
private:
    int uppercaseCount;

public:
    SecurityTool() {
        uppercaseCount = 0;
    }

    void analyzeFile() {
        ifstream file("secret.txt");

        if (!file) {
            cout << "Error: Cannot open file!\n";
            return;
        }

        char ch;

        while (file.get(ch)) {
            if (isupper(ch)) {
                uppercaseCount++;
            }
        }

        file.close();
        
    }

    void displayResult() {
        cout << "Number of hidden signals (uppercase letters): "
             << uppercaseCount << endl;
    }
};

int main() {
    SecurityTool tool;

    tool.analyzeFile();
    tool.displayResult();

    return 0;
}