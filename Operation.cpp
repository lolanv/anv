#include "Operation.h"

#include <algorithm>
#include <numeric>

Operation& Operation::getInstance() {
    static Operation instance;
    return instance;
}

void Operation::createInstances() {
    for (int i = 0; i < 5; ++i) {
        // Creating Engine instances
        std::shared_ptr<Engine> engine = std::make_shared<Engine>("Engine" + std::to_string(i), 150, 200, EngineType::CRDI);
        // Creating Car instances and storing them
        m_carInstances.push_back(std::make_shared<Car>("Car" + std::to_string(i), 50000 + i * 1000, engine));
    }
}

std::vector<std::reference_wrapper<Engine>> Operation::getEngineReferences() {
    std::vector<std::reference_wrapper<Engine>> engineRefs;
    std::transform(m_carInstances.begin(), m_carInstances.end(), std::back_inserter(engineRefs),
                   [](const std::shared_ptr<Car>& car) { return std::ref(*(car->m_car_engine)); });
    return engineRefs;
}

bool Operation::checkAllTorqueAboveThreshold(int threshold) {
    return std::all_of(m_carInstances.begin(), m_carInstances.end(),
                       [threshold](const std::shared_ptr<Car>& car) { return car->m_car_engine->m_engine_torque > threshold; });
}

std::optional<float> Operation::averageHorsepowerAbovePriceThreshold(float threshold) {
    std::vector<float> horsepowers;
    for (const auto& car : m_carInstances) {
        if (car->m_price > threshold) {
            horsepowers.push_back(car->m_car_engine->m_horsepower);
        }
    }
    if (horsepowers.empty()) {
        return std::nullopt;
    }
    float average = std::accumulate(horsepowers.begin(), horsepowers.end(), 0.0f) / horsepowers.size();
    return average;
}

std::optional<EngineType> Operation::findEngineTypeByCarRegNum(const std::string& reg_num) {
    auto carIt = std::find_if(m_carInstances.begin(), m_carInstances.end(),
                               [&reg_num](const std::shared_ptr<Car>& car) { return car->m_car_reg_num == reg_num; });
    if (carIt != m_carInstances.end()) {
        return (*carIt)->m_car_engine->m_engine_type;
    }
    return std::nullopt;
}

std::optional<std::reference_wrapper<Engine>> Operation::findHighestTorqueEngine() {
    auto maxTorqueCarIt = std::max_element(m_carInstances.begin(), m_carInstances.end(),
                                           [](const std::shared_ptr<Car>& car1, const std::shared_ptr<Car>& car2) {
                                               return car1->m_car_engine->m_engine_torque < car2->m_car_engine->m_engine_torque;
                                           });
    if (maxTorqueCarIt != m_carInstances.end()) {
        return std::ref(*((*maxTorqueCarIt)->m_car_engine));
    }
    return std::nullopt;
}
