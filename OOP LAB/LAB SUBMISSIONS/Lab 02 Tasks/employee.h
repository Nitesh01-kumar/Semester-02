#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    string name;
    int empID;
    double baseSalary;
    double hoursWorked;

public:
    
    Employee(string n, int id, double salary, double hours);


    string getName();
    int getEmpID();
    double getBaseSalary();
    double getHoursWorked();


    double calculateRegularPay();    
    double calculateOvertimePay();   
    double calculateTotalSalary();   


    void displayEmployeeInfo();
};

#endif
