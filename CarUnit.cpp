#include "CarUnit.h"

CarUnit::CarUnit(std::string brand, float price, CarType type, int speed, int rpm, Cargear gear)
    :_m_carBrand{brand}, _m_carPrice{price}, _m_carType{type}, _m_carTopSpeed{speed}, _m_carRPM{rpm}, _m_carGearSystem{gear}
{
}
std::ostream &operator<<(std::ostream &os, const CarUnit &rhs) {
    os << "_m_carBrand: " << rhs._m_carBrand
       << " _m_carPrice: " << rhs._m_carPrice
       << " _m_carType: " << static_cast<int>(rhs._m_carType)
       << " _m_carTopSpeed: " << rhs._m_carTopSpeed
       << " _m_carRPM: " << rhs._m_carRPM
       << " _m_carGearSystem: " << static_cast<int>(rhs._m_carGearSystem);
    return os;
}
