#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include <iostream>
using namespace std;

class securityDevice {
public:
    virtual void authenticate() = 0;
};

class BiometricScanner : public securityDevice {
private:
    int attempts;

public:
    BiometricScanner();
    void authenticate();
};

#endif