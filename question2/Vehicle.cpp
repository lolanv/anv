#include "Vehicle.h"

Vehicle::Vehicle(float mileage, float fuel_capacity, float cost, Driver& driver)
    : _vehicle_mileage(mileage), _vehicle_fuel_capacity(fuel_capacity), _vehicle_cost(cost), _vehicle_driver(driver) {}

float Vehicle::getMileage() const {
    return _vehicle_mileage;
}

float Vehicle::getFuelCapacity() const {
    return _vehicle_fuel_capacity;
}

float Vehicle::getCost() const {
    return _vehicle_cost;
}

const Driver& Vehicle::getDriver() const {
    return _vehicle_driver;
}
