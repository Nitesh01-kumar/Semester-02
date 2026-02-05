#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(string n, int id, double salary, double hours) {
    name = n;
    empID = id;
    baseSalary = salary;
    hoursWorked = hours;
}

string Employee::getName() { return name; }
int Employee::getEmpID() { return empID; }
double Employee::getBaseSalary() { return baseSalary; }
double Employee::getHoursWorked() { return hoursWorked; }

double Employee::calculateRegularPay() {
    double regularHours = (hoursWorked > 40) ? 40 : hoursWorked;
    return (baseSalary / 40) * regularHours;
}

double Employee::calculateOvertimePay() {
    if (hoursWorked > 40) {
        double overtimeHours = hoursWorked - 40;
        double hourlyRate = baseSalary / 40;
        return overtimeHours * hourlyRate * 1.5;
    } else {
        return 0;
    }
}

double Employee::calculateTotalSalary() {
    return calculateRegularPay() + calculateOvertimePay();
}

void Employee::displayEmployeeInfo() {
    cout << "----------------------------" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << empID << endl;
    cout << "Base Salary: $" << baseSalary << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Regular Pay: $" << calculateRegularPay() << endl;
    cout << "Overtime Pay: $" << calculateOvertimePay() << endl;
    cout << "Total Salary: $" << calculateTotalSalary() << endl;
    cout << "----------------------------" << endl;
}
