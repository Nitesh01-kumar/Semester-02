#include <iostream>
using namespace std;


class Account{
    string accNum;
    string accHolder;
    double balance;

    public:
    Account(){
        balance = 0;
    };
    Account(string num, string name, double amount): accNum(num), accHolder(name), balance(amount){}

    Account operator+(const Account &obj){
        cout << "Before adding amount" << balance << endl;
        Account temp;
        temp.balance = this->balance + obj.balance;
        cout << "After adding amount" << temp.balance << endl;
        return temp;
    }

    Account& operator -=(double amount){
        cout << "Before Tranfering amount" << balance << endl;
        this->balance -= amount;
        cout <<"Amount transfered to Account 1: " << balance << endl;
        return *this;
    }

    Account& operator +=(double amount){

        this->balance += amount;
        cout << "Amount Transfered Successfully to Account: " << balance << endl;
        return *this;
    }

    bool operator>(const Account &obj){

        return this->balance > obj.balance;

    }
    
    void display(){
        cout << "Account number: " << accNum << endl;
        cout << "Account Holder: " << accHolder << endl;
        cout << "Balance Available: " << balance << endl;
    }
};


int main(){
    Account a1("PK78FAYS1000", "Nitesh Kumar", 100000);
    Account a2("PK10UBH2000", "Ashok Kumar" , 200000);
    Account a3;
    a3 = a1+a2;
    a2 -= 20000;
    a1 += 20000;

    if(a1>a2){
        cout <<"\nAccount 1 have greater amount" << endl;

    }
    else{
        cout <<"\nAccount 2 have greater Amount" << endl;
    }
    cout << "\nAccount 1 details: " << endl;
    a1.display();
    
    cout << "\nAccount 2 details: " << endl;
    a2.display();


    
}