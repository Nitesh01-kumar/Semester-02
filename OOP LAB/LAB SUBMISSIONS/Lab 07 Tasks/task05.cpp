#include <iostream>
using namespace std;

class Character {
public:
    virtual void performAttack() = 0;
    virtual ~Character() {}
};

class Warrior : public Character {
public:
    void performAttack() {
        cout << "Warrior performs Sword Slash!" << endl;
    }
};

class Mage : public Character {
public:
    void performAttack() {
        cout << "Mage casts Fireball!" << endl;
    }
};

class Healer : public Character {
public:
    void performAttack() {
        cout << "Healer performs Healing Strike!" << endl;
    }
};

int main() {
    Character* party[3];

    party[0] = new Warrior();
    party[1] = new Mage();
    party[2] = new Healer();

    for (int i = 0; i < 3; i++) {
        party[i]->performAttack();
    }

    for (int i = 0; i < 3; i++) {
        delete party[i];
    }

    return 0;
}