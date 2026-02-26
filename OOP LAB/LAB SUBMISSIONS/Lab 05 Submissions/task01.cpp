#include <iostream>
using namespace std;


class Order {
    public:
    int id;
    string customer;
    string resturant;
    string foodItem;

    Order(int id, string customer, string resturant, string foofItem){
        this->id=id;
        this->customer=customer;
        this->resturant=resturant;
        this->foodItem=foodItem;

    }

    void display(){
        cout << "Order " << id << ": " << foodItem << " for " << customer << " from " << resturant;
    }


};


class Resturant{

    public:
    string name;
    Order* order;

    Resturant(string name, Order* order){
        this->name = name;
        this->order = order;
    }

    void display(){
        order->display();
        cout << name << " making: " << order->foodItem << endl;
    }
};

class Customer{
    string name;
    Resturant* resturant;

    public:
    Customer(string name, Resturant* Resturant){
        this->name=name;
        this->resturant= resturant;
    }

    void display(){
        resturant->display();
        cout << name << " placed a order at " << resturant->name << endl;
    }
};


int main(){
    Order o1(101, "nitesh", "Pizza Heaven" , "Pizza");
    Resturant r1("Pizza Heaven", &o1);
    Customer c1("Nitesh", &r1);

    c1.display();
    return 0;
}