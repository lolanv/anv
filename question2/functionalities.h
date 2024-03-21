#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Vehicle.h"
#include <vector>

void CreateObject(std::vector<Vehicle>& vehicles);
int CountInstance(const std::vector<Vehicle>& vehicles, float threshold);
bool AllAboveRating(const std::vector<Vehicle>& vehicles, float rating_threshold);
std::vector<Vehicle> FindLMV(const std::vector<Vehicle>& vehicles);
void ComputeDriveSalary(const std::vector<Vehicle>& vehicles);
void AddInstance(std::vector<Vehicle>& vehicles, float mileage, float fuel_capacity, float cost,
                 const std::string& license_type, unsigned int experience_years, float rating);

#endif // FUNCTIONALITIES_H
