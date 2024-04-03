#include <iostream>
#include <thread>
#include <future>

#include "Operation.h"

int main() {
    // Execute all functionalities in a separate std::async thread
    std::future<void> result = std::async([](){
        Operation& op = Operation::getInstance();

        op.createInstances();

        auto engineRefs = op.getEngineReferences();
        std::cout << "Engine References: " << std::endl;
        for (auto& engineRef : engineRefs) {
            std::cout << "Engine Number: " << engineRef.get().m_engine_number << std::endl;
        }

        bool allTorqueAbove120 = op.checkAllTorqueAboveThreshold(120);
        std::cout << "All Torque Above 120: " << std::boolalpha << allTorqueAbove120 << std::endl;

        std::optional<float> avgHorsepower = op.averageHorsepowerAbovePriceThreshold(45000);
        if (avgHorsepower.has_value()) {
            std::cout << "Average Horsepower Above Price Threshold: " << avgHorsepower.value() << std::endl;
        } else {
            std::cout << "No cars found above the price threshold." << std::endl;
        }

        std::optional<EngineType> engineType = op.findEngineTypeByCarRegNum("Car2");
        if (engineType.has_value()) {
            std::cout << "Engine Type for Car2: ";
            switch(engineType.value()) {
                case EngineType::CRDI:
                    std::cout << "CRDI" << std::endl;
                    break;
                case EngineType::MPFI:
                    std::cout << "MPFI" << std::endl;
                    break;
                case EngineType::TURBOCHARGED:
                    std::cout << "TURBOCHARGED" << std::endl;
                    break;
            }
        } else {
            std::cout << "Car not found." << std::endl;
        }

        auto highestTorqueEngine = op.findHighestTorqueEngine();
        if (highestTorqueEngine.has_value()) {
            std::cout << "Highest Torque Engine: " << highestTorqueEngine.value().get().m_engine_number << std::endl;
        } else {
            std::cout << "No cars found." << std::endl;
        }
    });

    result.get(); // Wait for the asynchronous operation to complete

    return 0;
}
