#include <iostream>
using namespace std;

class Plugin {
public:
    virtual void execute() = 0;
    virtual ~Plugin() {}
};

class Antivirus : public Plugin {
public:
    void execute() {
        cout << "Scanning system for threats" << endl;
    }
};

class Updater : public Plugin {
public:
    void execute() {
        cout << "Checking for system updates" << endl;
    }
};

int main() {
    Plugin* plugins[2];

    plugins[0] = new Antivirus();
    plugins[1] = new Updater();

    for (int i = 0; i < 2; i++) {
        plugins[i]->execute();
    }

    for (int i = 0; i < 2; i++) {
        delete plugins[i];
    }

    return 0;
}