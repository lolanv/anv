#include "Functionalities.h"
#include "EvCar.h"
// #include"EvCar.cpp"
#include <iostream>

int main() {
    // 1. Create at least 5 instances in a container managed by shared pointers
    std::optional<Container> instances = createInstances();
    if (!instances) {
        std::cerr << "Error creating instances.\n";
        return 1;
    }

    // 2. Find and return the first N instances from the container
    int n = 3; // Example value for N
    std::optional<std::list<std::shared_ptr<EvCar>>> firstN = findFirstNInstances(*instances, n);
    if (!firstN) {
        std::cerr << "Error finding first N instances.\n";
        return 1;
    }
    std::cout << "First " << n << " instances:\n";
    for (const auto& car : *firstN) {
        std::cout << car->getCarId() << std::endl;
    }

    // 3. Find and return the top speed of an instance by car ID
    std::string carId = "Car_3"; // Example car ID
    std::optional<int> topSpeed = findTopSpeedByCarId(*instances, carId);
    if (!topSpeed) {
        std::cerr << "Error finding top speed for car ID " << carId << ".\n";
        return 1;
    }
    std::cout << "Top speed of car " << carId << ": " << *topSpeed << " km/h\n";

    // 4. Count instances with chassis length above a threshold
    float threshold = 4.0f; // Example threshold value
    std::optional<int> countAboveThreshold = countInstancesWithChassisLengthAbove(*instances, threshold);
    if (!countAboveThreshold) {
        std::cerr << "Error counting instances with chassis length above " << threshold << ".\n";
        return 1;
    }
    std::cout << "Number of instances with chassis length above " << threshold << ": " << *countAboveThreshold << std::endl;

    // 5. Filter instances by a predicate
    Container filteredInstances = filterInstancesByPredicate(*instances, [](const EvCar& car) {
        return car.getPlatform() == Platform::PURE_EV && car.seatCount() >= 5;
    });
    std::cout << "Filtered instances with PURE_EV platform and seat count >= 5:\n";
    for (const auto& car : filteredInstances) {
        std::cout << car->getCarId() << std::endl;
    }

    // 6. Check if at least one instance has PURE_EV platform
    bool hasPureEV = hasPureEVPlatform(*instances);
    std::cout << "At least one instance has PURE_EV platform: " << std::boolalpha << hasPureEV << std::endl;

    return 0;
}
