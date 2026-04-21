#include <iostream>
using namespace std;

class Payment {
protected:
    double amount;

public:
    Payment(double a) {
        amount = a;
    }

    virtual void processPayment() = 0;
};

class CreditCard : public Payment {
public:
    CreditCard(double a) : Payment(a) {}

    void processPayment() {
        double total = amount + (amount * 0.02);
        cout << "Processing Credit Card payment of $" << total << endl;
    }
};

class PayPal : public Payment {
public:
    PayPal(double a) : Payment(a) {}

    void processPayment() {
        double total = amount;
        if (amount > 500) {
            total -= 10;
        }
        cout << "Processing PayPal payment of $" << total << endl;
    }
};

int main() {
    CreditCard c(500);
    c.processPayment();

    PayPal p(600);
    p.processPayment();

    return 0;
}
