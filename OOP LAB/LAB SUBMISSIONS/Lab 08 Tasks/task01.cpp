#include <iostream>
using namespace std;


class Device{
    protected:
    string id;
    string type;
    double powerRating;
    bool status;

    public:
    
    Device(string i, string t, double p): id(i), type(t), powerRating(p){}

    virtual void turnOn(){
        status = true;
    }

    virtual void turnOff(){
        status = false;
    }

    virtual double calculatePowerUsage(int hours){
        return 0;
    }
};

class Lights : public Device{

    public:
    Lights(string i, string t, double p): Device(i, t, p){}

    void turnOn(){
        status =  true;
        cout << "LED Light [ID: " << id << "] turned ON.\n";

    }
    
    virtual void turnOff(){
        status = false;
    }

    double calculatePowerUsage(int hours){
        return powerRating*hours;
    }
    

};

class Fans: public Device{

    public:
    double speedFactor;

    Fans(string i, string t, double p, double s) : Device(i, t, p) , speedFactor(s){}

    double calculatePowerUsage(int hours){
        return powerRating*hours*speedFactor;
    }

    void turnOn(){
        status =  true;
        cout << "Ceiling Fan [ID: " << id << "] turned ON at Speed " << speedFactor << ".\n";
    }
    
    virtual void turnOff(){
        status = false;
    }
};

class AirConditioner : public Device{
    public:
    int currentTemp, desiredTemp;

   AirConditioner(string i, string t, double p, int c, int d ) : Device(i, t, p) , desiredTemp(d), currentTemp(c){}

    double calculatePowerUsage(int hours){
        return powerRating*hours*(1-(currentTemp-desiredTemp)/100);
    }

    void turnOn(){
        status =  true;
        cout << "Split AC [ID: " << id << "] turned ON. Cooling to " << desiredTemp << "°C.\n";
    }
    
    virtual void turnOff(){
        status = false;
    }

};


class SecuritySystem : public Device{
    string logs = "Intrusion Detected";

    public:
    SecuritySystem(string i, string t, double p): Device(i, t, p){}

    void turnOn(){
        status =  true;
        cout << "Home Alarm [ID: " << id << "] activated.\n";
    }
    
    virtual void turnOff(){
        status = false;
    }

    double calculatePowerUsage(int hours){
        return powerRating*hours;
    }

    friend void SecurityLogs(SecuritySystem S);

    friend class MaintainanceTool;

};

void SecurityLogs(SecuritySystem S){
    cout << "Have access to see Security logs: " << S.logs << endl;
}


class MaintainanceTool{

    public:

    void resetSecurity(){
        cout << "Security reset alert" << endl;
    }
};


class UserMAnagement{
    string userID;
    string userRole;
    int AccessLevel;

    public:

    UserMAnagement(string id, string r, int level) {
        userID = id;
        userRole = r;
        AccessLevel= level;
    }


    void accessSecurityLogs(SecuritySystem &s) {
        if (AccessLevel > 1) {
            cout << "User: " << userID << " - ";
            ::SecurityLogs(s);
        } else {
            cout << "Access Denied!\n";
        }
    }
};


int main(){
    UserMAnagement u1("A10", "Regular", 1);
    UserMAnagement u2("A102", "Maintainance staff", 10);



    Lights lightl("L001", "LED Light", 10);

    Fans fan1("F001", "Ceiling Fan", 75, 3);

    AirConditioner ac1("AC001", "Split AC", 1500, 25, 10);

    SecuritySystem secSys1("S001", "Home Alarm", 100);

    

    lightl.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();


    cout << lightl.calculatePowerUsage(5) << endl; 
    cout << fan1.calculatePowerUsage(3) << endl;
    cout << ac1.calculatePowerUsage(6) << endl; 
    cout << secSys1.calculatePowerUsage(24) << endl;

}