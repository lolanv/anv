#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "EvCar.h"
#include <list>
#include <memory>
#include <vector>
#include <optional>
#include <functional>

using Container = std::vector<std::shared_ptr<EvCar>>;

std::optional<Container> createInstances();
std::optional<std::list<std::shared_ptr<EvCar>>> findFirstNInstances(const Container& container, int n);
std::optional<int> findTopSpeedByCarId(const Container& container, const std::string& car_id);
std::optional<int> countInstancesWithChassisLengthAbove(const Container& container, float threshold);
Container filterInstancesByPredicate(const Container& container, std::function<bool(const EvCar&)> predicate);
bool hasPureEVPlatform(const Container& container);

#endif // FUNCTIONALITIES_H
