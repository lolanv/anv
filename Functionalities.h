#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"CarUnit.h"
#include<unordered_map>
#include<memory>
#include<optional>
#include<algorithm>
#include<numeric>
#include<vector>

using Carpointer = std::shared_ptr<CarUnit>;
using Container = std::unordered_map<std::string, Carpointer>;

void CreateObjects(Container& data);

std::optional<bool> hasSameGear(Container& data);

std::optional<Container> hasMCarType(Container& data, CarType type);

std::optional<float> lowestPrice(Container& data);

std::optional<std::vector<int>> m_car_rpmWithId(Container& data, std::string id);

std::optional<int> countAboveThreshold(Container& data, float threshold);

#endif // FUNCTIONALITIES_H
