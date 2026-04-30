#include <iostream>
#include <fstream>
using namespace std;

class Editor {
public:
    void fixTypo() {
        fstream file("draft.txt", ios::in | ios::out);

        char ch;
        long pos;

        while (file.get(ch)) {
            if (ch == 't') {
                pos = file.tellg();

                char e, h;
                file.get(e);
                file.get(h);

                if (e == 'e' && h == 'h') {
                    file.seekp(pos - 1);
                    file << "the";
                    break;
                } else {
                    file.seekg(pos);
                }
            }
        }

        file.close();
    }
};

int main() {
    Editor e;
    e.fixTypo();
    return 0;
}