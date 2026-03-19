#include <iostream>
using namespace std;

class Bank{
public:
    virtual void interest(){
        cout << "Base Function" << endl;
    }
};

class SavingAccount : public Bank{
    public:
    
    void interest() override{
        cout << "Saving Account Interset Rate = 5%" << endl;
    }

};

class currentAccount: public Bank{
    public:
    void interest() override{
        cout << "Current account interest rate = 2%" << endl;
    }
};

int main(){
    Bank *b;
    SavingAccount sAcc;

    b = &sAcc;
    b->interest();

}