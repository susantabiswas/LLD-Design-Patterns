/*
    Interface segregation basically means that the client should not
    be forced to implement things it doesn't need.
*/
#include<iostream>
using namespace std;

// This is a fat class, as Water and Land vechicles cannot fly, but they have to implement the fly() method.
// This is a violation of Interface Segregation Principle.
class Vehicle {
public:
    virtual void drive() = 0;
    virtual void brake() = 0;
    virtual void fly() = 0;
    virtual void honk() = 0;
};

// Solution: Separate the interfaces for Water and Land vehicles.
class VehicleBase {
public:
    virtual void drive() = 0;
    virtual void brake() = 0;
};

// Now the land vehicles dont have to inherit the fly() method.
class LandVehicle: VehicleBase {
public:
    virtual void honk() = 0;
};

class AirVehicle: VehicleBase {
public:
    virtual void fly() = 0;    
};

int main() {
    return 0;
}
