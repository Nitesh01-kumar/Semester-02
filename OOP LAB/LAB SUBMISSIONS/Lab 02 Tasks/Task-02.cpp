#include <iostream>
#include <string>
using namespace std;

class BankAcc {
private:
    int AccNum;
    string holderName;
    float currentBalance;

public:

    BankAcc(int acc, string name, float balance) {
        AccNum = acc;
        holderName = name;
        if (balance < 0) {
            currentBalance = 0;
            cout << "Initial balance cannot be negative. Setting balance to 0." << endl;
        } else {
            currentBalance = balance;
        }
    }

    void deposit(float amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive!" << endl;
        } else {
            currentBalance += amount;
            cout << "Amount Deposited: " << amount << endl;
        }
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
        } else if (amount > currentBalance) {
            cout << "Insufficient balance! Cannot withdraw " << amount << endl;
        } else {
            currentBalance -= amount;
            cout << "Amount Withdrawn: " << amount << endl;
        }
    }

    void current_balance() {
        cout << "Current Balance = " << currentBalance << endl;
    }

    void display() {
       
        cout << "Account Number = " << AccNum << endl;
        cout << "Holder Name = " << holderName << endl;
        cout << "Current Balance = " << currentBalance << endl;
    }
};

int main() {
  
    int acc;
    string name;
    float balance;

    cout << "Enter Account Number: ";
    cin >> acc;
    cin.ignore(); 
    cout << "Enter Holder Name: ";
    getline(cin, name);
    cout << "Enter Initial Balance: ";
    cin >> balance;

    BankAcc account(acc, name, balance);

 
    account.display();

    account.deposit(500);  
    account.current_balance();

    account.withdraw(200);  
    account.current_balance();

    account.withdraw(1000); 
    account.deposit(-50);   

    cout << "\n--- Final Account Status ---" << endl;
    account.display();

    return 0;
}
