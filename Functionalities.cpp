#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.emplace("tata", std::make_shared<CarUnit> ("tata", 50000, CarType::HATCHBACK, 200, 230, Cargear::CLASSIC));
    data.emplace("honda", std::make_shared<CarUnit> ("honda", 60000, CarType::SEDAN, 300, 230, Cargear::PRNDL));
    data.emplace("mahinra", std::make_shared<CarUnit> ("mahindra", 70000, CarType::SUV, 200, 230, Cargear::TIPTRONIC));
    data.emplace("hyundai", std::make_shared<CarUnit> ("hyundai", 80000, CarType::SEDAN, 150, 230, Cargear::CLASSIC));
    data.emplace("suzuki", std::make_shared<CarUnit> ("suzuki", 90000, CarType::HATCHBACK, 100, 230, Cargear::CLASSIC));
}

std::optional<bool> hasSameGear(Container &data)
{
    if(data.size() == 0){
        return std::nullopt;
    }

    return std::all_of(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, Carpointer>& temp) {
            return temp.second->mCarGearSystem() == (*data.begin()).second->mCarGearSystem();
        }
    );
}

std::optional<Container> hasMCarType(Container &data, CarType type)
{
    if(data.size() == 0) {
        return std::nullopt;
    }

    Container result;

    for(const std::pair<std::string, Carpointer>& temp : data) {
        if(temp.second->mCarType() == type) {
            result.emplace(temp);
        }
    }

    if(result.size() == 0) {
        return std::nullopt;
    }

    return result;
}

std::optional<float> lowestPrice(Container &data)
{
    if(data.size() == 0) {
        return std::nullopt;
    }

    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const std::pair<std::string, Carpointer>& temp1, const std::pair<std::string, Carpointer>& temp2) {
            return temp1.second->mCarTopSpeed() < temp2.second->mCarTopSpeed();
        }
    );

    return (*itr).second->mCarPrice();
}

std::optional<std::vector<int>> m_car_rpmWithId(Container &data, std::string id)
{
    if(data.size() == 0) {
        return std::nullopt;
    }

    std::vector<int> result;

    for(auto temp : data) {
        if(temp.first == id) {
            result.push_back(temp.second->mCarRPM());
        }
    }

    if(result.size() == 0) {
        return std::nullopt;
    }

    return result;
}

std::optional<int> countAboveThreshold(Container &data, float threshold)
{
    if(data.size() == 0) {
        return std::nullopt;
    }

    return std::count_if(
        data.begin(),
        data.end(),
        [&](const std::pair<std::string, Carpointer>& temp) {
            return temp.second->mCarPrice() > threshold;
        }
    );
}
