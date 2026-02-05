#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
    Employee emp1("Alice", 101, 4000, 45);  
    Employee emp2("Bob", 102, 3500, 38);    

    emp1.displayEmployeeInfo();
    emp2.displayEmployeeInfo();

    
    if (emp1.calculateTotalSalary() > emp2.calculateTotalSalary()) {
        cout << emp1.getName() << " has higher total salary." << endl;
    } else if (emp1.calculateTotalSalary() < emp2.calculateTotalSalary()) {
        cout << emp2.getName() << " has higher total salary." << endl;
    } else {
        cout << "Both employees have equal total salary." << endl;
    }

    return 0;
}
