#include <iostream>
using namespace std;

class Staff {
public:
    virtual double processSalary() = 0;
    virtual ~Staff() {}
};

class SalariedEmployee : public Staff {
private:
    double salary;

public:
    SalariedEmployee(double s) {
        salary = s;
    }

    double processSalary() {
        return salary;
    }
};

class CommissionEmployee : public Staff {
private:
    double sales;
    double percentage;

public:
    CommissionEmployee(double s, double p) {
        sales = s;
        percentage = p;
    }

    double processSalary() {
        return sales * percentage;
    }
};

int main() {
    Staff* staffList[2];

    staffList[0] = new SalariedEmployee(5000);
    staffList[1] = new CommissionEmployee(10000, 0.1);

    for (int i = 0; i < 2; i++) {
        cout << "Salary: " << staffList[i]->processSalary() << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete staffList[i];
    }

    return 0;
}