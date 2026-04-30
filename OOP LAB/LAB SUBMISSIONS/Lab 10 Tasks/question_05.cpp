#include <iostream>
#include <fstream>
using namespace std;

class Analyzer {
public:
    void generateReport() {
        ifstream file("article.txt");

        int charCount = 0;
        int wordCount = 0;
        int lineCount = 0;
        int punctuationCount = 0;

        char ch;
        bool inWord = false;

        while (file.get(ch)) {
            charCount++;

            if (ch == '\n') {
                lineCount++;
            }

            if (ch == '.' || ch == ',' || ch == '!' || ch == '?' ||
                ch == ';' || ch == ':' || ch == '\'' || ch == '"') {
                punctuationCount++;
            }

            if (ch == ' ' || ch == '\n' || ch == '\t') {
                inWord = false;
            } else {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            }
        }

        file.close();

        ofstream report("report.txt");

        report << "ARTICLE ANALYSIS REPORT\n";
        report << "------------------------\n";
        report << "Total Characters: " << charCount << "\n";
        report << "Total Words: " << wordCount << "\n";
        report << "Total Lines: " << lineCount << "\n";
        report << "Punctuation Marks: " << punctuationCount << "\n";

        report.close();

        cout << "Report generated successfully.\n";
    }
};

int main() {
    Analyzer a;
    a.generateReport();
    return 0;
}