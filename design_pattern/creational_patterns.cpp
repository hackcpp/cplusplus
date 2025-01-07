#include <iostream>

class Transport {
public:
virtual void deliver() = 0;
}; 

class Trunk: public Transport {
public:
virtual void deliver() override {
    std::cout << "Trunk" << std::endl;
}
};

class Airport: public Transport {
virtual void deliver() override {
    std::cout << "Airport" << std::endl;
}
};

class Transportfactory {
public:
virtual Transport* create() = 0;
};

class Trunkfactory: public Transportfactory {
    public: 
    Transport* create() override {return new Trunk();}
};

class Airportfactory: public Transportfactory {
    public: 
    Transport* create() override {return new Airport();}
};

// class Deliver {
// public:
//     void deliver() {
//         auto t = mfactory->create();
//         t->deliver();
//     }
//     void setFactory(Transportfactory* f) {mfactory = f;}
// private:
//     Transportfactory* mfactory = nullptr;
// };

int main() {
    int i;
    std::cin >> i;
    Transport* t = nullptr;
    Transportfactory* f = nullptr;
    if (i == 0) {
        f = new Trunkfactory();
    }
    else {
        f = new Airportfactory();
    }
    t = f->create();
    t->deliver();
}