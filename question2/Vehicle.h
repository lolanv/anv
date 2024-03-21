#ifndef VEHICLE_H
#define VEHICLE_H

#include <functional>
#include "Driver.h"

class Vehicle {
private:
    float _vehicle_mileage;
    float _vehicle_fuel_capacity;
    float _vehicle_cost;
    std::reference_wrapper<Driver> _vehicle_driver;

public:
    Vehicle(float mileage, float fuel_capacity, float cost, Driver& driver);

    float getMileage() const;
    float getFuelCapacity() const;
    float getCost() const;
    const Driver& getDriver() const;
};

#endif // VEHICLE_H
