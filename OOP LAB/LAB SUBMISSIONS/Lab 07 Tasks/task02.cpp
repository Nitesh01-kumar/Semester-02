#include <iostream>
using namespace std;

class Staff {
public:
    virtual double calculateSalary() = 0;
    virtual ~Staff() {}
};

class Contractor : public Staff {
private:
    double hours;
    double rate;

public:
    Contractor(double h, double r) {
        hours = h;
        rate = r;
    }

    double calculateSalary() {
        return hours * rate;
    }
};

class FullTimeEmployee : public Staff {
private:
    double baseSalary;
    double bonus;

public:
    FullTimeEmployee(double b, double bo) {
        baseSalary = b;
        bonus = bo;
    }

    double calculateSalary() {
        return baseSalary + bonus;
    }
};

int main() {
    Staff* staffList[2];

    staffList[0] = new Contractor(40, 20);
    staffList[1] = new FullTimeEmployee(3000, 500);

    for (int i = 0; i < 2; i++) {
        cout << "Salary: " << staffList[i]->calculateSalary() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete staffList[i];
    }

    return 0;
}