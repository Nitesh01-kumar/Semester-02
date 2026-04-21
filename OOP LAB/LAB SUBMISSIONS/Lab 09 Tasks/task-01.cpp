#include <iostream>
using namespace std;

class CoffeeMachine {
    int waterlevel;
    int coffeebeans;
public:
    CoffeeMachine(int a, int c) {
        waterlevel = a;    
        coffeebeans = c; 
    }
    void makecoffe(){
        if(waterlevel < 100){
            cout << "Insufficient water level" << endl;
        }
        else {
            cout << "Coffee is ready!" << endl;
            waterlevel -= 100;
        }
    }

};

int main() {
    CoffeeMachine cm(150, 50);
    cm.makecoffe();
    return 0;
}