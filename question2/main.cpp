#include "functionalities.h"
#include <iostream>

int main() {
    try {
        std::vector<Vehicle> vehicles;
        CreateObject(vehicles);

        float threshold = 10000.0f;
        std::cout << "Number of vehicles with mileage above " << threshold << ": "
                  << CountInstance(vehicles, threshold) << std::endl;

        float rating_threshold = 4.0f;
        if (AllAboveRating(vehicles, rating_threshold)) {
            std::cout << "All vehicles have a driver rating above " << rating_threshold << std::endl;
        } else {
            std::cout << "Not all vehicles have a driver rating above " << rating_threshold << std::endl;
        }

        std::vector<Vehicle> lmv_vehicles = FindLMV(vehicles);
        std::cout << "Number of LMV vehicles: " << lmv_vehicles.size() << std::endl;

        ComputeDriveSalary(vehicles);

        AddInstance(vehicles, 15000.0f, 70.0f, 35000.0f, "HMV", 2, 3.5f);
        std::cout << "Added new instance." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
}
}