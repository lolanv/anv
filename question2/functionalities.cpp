#include "functionalities.h"
#include <iostream>

void CreateObject(std::vector<Vehicle>& vehicles) {
    Driver driver1("LMV", 5, 4.5f);
    vehicles.push_back(Vehicle(10000.0f, 60.0f, 25000.0f, driver1));

    Driver driver2("HMV", 7, 3.8f);
    vehicles.push_back(Vehicle(8000.0f, 80.0f, 30000.0f, driver2));

    Driver driver3("BOTH", 3, 4.2f);
    vehicles.push_back(Vehicle(12000.0f, 50.0f, 20000.0f, driver3));
}

int CountInstance(const std::vector<Vehicle>& vehicles, float threshold) {
    int count = 0;
    for (const auto& vehicle : vehicles) {
        if (vehicle.getMileage() > threshold) {
            count++;
        }
    }
    return count;
}

bool AllAboveRating(const std::vector<Vehicle>& vehicles, float rating_threshold) {
    for (const auto& vehicle : vehicles) {
        if (vehicle.getDriver().getRating() < rating_threshold) {
            return false;
        }
    }
    return true;
}

std::vector<Vehicle> FindLMV(const std::vector<Vehicle>& vehicles) {
    std::vector<Vehicle> lmv_vehicles;
    for (const auto& vehicle : vehicles) {
        if (vehicle.getDriver().getLicenseType() == "LMV") {
            lmv_vehicles.push_back(vehicle);
        }
    }
    return lmv_vehicles;
}

void ComputeDriveSalary(const std::vector<Vehicle>& vehicles) {
    for (const auto& vehicle : vehicles) {
        float salary;
        if (vehicle.getDriver().getRating() > 4.0f) {
            salary = 4 * vehicle.getDriver().getExperienceYears();
        } else {
            salary = 3 * vehicle.getDriver().getExperienceYears();
        }
        std::cout << "Driver salary for vehicle with mileage " << vehicle.getMileage() << ": $" << salary << std::endl;
    }
}

void AddInstance(std::vector<Vehicle>& vehicles, float mileage, float fuel_capacity, float cost,
                 const std::string& license_type, unsigned int experience_years, float rating) {
    Driver driver(license_type, experience_years, rating);
    vehicles.push_back(Vehicle(mileage, fuel_capacity, cost, driver));
}
