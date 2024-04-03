#include "Functionalities.h"
#include <algorithm>

std::optional<Container> createInstances() {
    Container container;
    try {
        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<EvCar> car = std::make_shared<EvCar>(
                "Car_" + std::to_string(i + 1), // Car ID
                8,                                // Battery charging time
                Platform::PURE_EV,               // Platform
                4.5f,                             // Chassis length
                5,                                // Seat count
                200                               // Top speed
            );
            container.push_back(car);
        }
        return container;
    } catch (...) {
        return std::nullopt; // Error occurred while creating instances
    }
}

std::optional<std::list<std::shared_ptr<EvCar>>> findFirstNInstances(const Container& container, int n) {
    if (n <= 0 || n > container.size()) {
        return std::nullopt; // Invalid value for N
    }

    std::list<std::shared_ptr<EvCar>> result(container.begin(), container.begin() + n);
    return result;
}

std::optional<int> findTopSpeedByCarId(const Container& container, const std::string& car_id) {
    auto it = std::find_if(container.begin(), container.end(), [&car_id](const std::shared_ptr<EvCar>& car) {
        return car->getCarId() == car_id;
    });

    if (it != container.end()) {
        return (*it)->getTopSpeed();
    } else {
        return std::nullopt; // Car ID not found
    }
}

std::optional<int> countInstancesWithChassisLengthAbove(const Container& container, float threshold) {
    int count = std::count_if(container.begin(), container.end(), [threshold](const std::shared_ptr<EvCar>& car) {
        return car->getChassisLength() > threshold;
    });
    return count;
}

Container filterInstancesByPredicate(const Container& container, std::function<bool(const EvCar&)> predicate) {
    Container result;
    std::copy_if(container.begin(), container.end(), std::back_inserter(result), [&predicate](const std::shared_ptr<EvCar>& car) {
        return predicate(*car);
    });
    return result;
}

bool hasPureEVPlatform(const Container& container) {
    return std::any_of(container.begin(), container.end(), [](const std::shared_ptr<EvCar>& car) {
        return car->getPlatform() == Platform::PURE_EV;
    });
}
