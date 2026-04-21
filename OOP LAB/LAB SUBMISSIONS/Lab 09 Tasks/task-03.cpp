#include <iostream>
using namespace std;

class Package {
protected:
    double weight;

public:
    Package(double w) {
        weight = w;
    }

    virtual void calculateCost() = 0;
};

class LocalPackage : public Package {
public:
    LocalPackage(double w) : Package(w) {}

    void calculateCost() {
        double cost = weight * 5;
        if (weight > 20) {
            cost += 15;
        }
        cout << "Local Package Cost: $" << cost << endl;
    }
};

class InternationalPackage : public Package {
public:
    InternationalPackage(double w) : Package(w) {}

    void calculateCost() {
        double cost = weight * 15 + 25;
        cout << "International Package Cost: $" << cost << endl;
    }
};

int main() {
    LocalPackage lp(25);
    lp.calculateCost();

    InternationalPackage ip(10);
    ip.calculateCost();

    return 0;
}