#ifndef OPERATION_H
#define OPERATION_H

#include <vector>
#include <functional>
#include <memory>
#include <future>
#include <optional>

#include "Car.h"

class Operation {
public:
    static Operation& getInstance();

    void createInstances();
    std::vector<std::reference_wrapper<Engine>> getEngineReferences();
    bool checkAllTorqueAboveThreshold(int threshold);
    std::optional<float> averageHorsepowerAbovePriceThreshold(float threshold);
    std::optional<EngineType> findEngineTypeByCarRegNum(const std::string& reg_num);
    std::optional<std::reference_wrapper<Engine>> findHighestTorqueEngine();

private:
    std::vector<std::shared_ptr<Car>> m_carInstances;

    Operation() = default;
    Operation(const Operation&) = delete;
    Operation& operator=(const Operation&) = delete;
};

#endif // OPERATION_H
