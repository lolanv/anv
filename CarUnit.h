#ifndef CARUNIT_H
#define CARUNIT_H

// std::string m_car_brand;
// float m_car_price;
// CarType m_car_type;(SEDAN,SUV,HATCHBACK)
// int m_car_top_speed;
// int m_car_rpm;
// CarGear m_car_gear_system;(PRNDL,TIPTRONIC,CLASSIC)

#include<iostream>
#include"Cartype.h"
#include"Cargear.h"

class CarUnit
{
private:
    std::string _m_carBrand;
    float _m_carPrice;
    CarType _m_carType;
    int _m_carTopSpeed;
    int _m_carRPM;
    Cargear _m_carGearSystem;

public:
    CarUnit()=default;
    CarUnit(const  CarUnit&)=delete; 
    CarUnit(CarUnit&&)=delete; 
    CarUnit& operator= (const  CarUnit &) = delete; 
    CarUnit& operator= (CarUnit &&) = delete;    
    ~CarUnit() =default;

    CarUnit(std::string brand, float price, CarType type, int speed, int rpm, Cargear gear);

    std::string mCarBrand() const { return _m_carBrand; }
    void setMCarBrand(const std::string &m_carBrand) { _m_carBrand = m_carBrand; }

    float mCarPrice() const { return _m_carPrice; }
    void setMCarPrice(float m_carPrice) { _m_carPrice = m_carPrice; }

    CarType mCarType() const { return _m_carType; }
    void setMCarType(const CarType &m_carType) { _m_carType = m_carType; }

    int mCarTopSpeed() const { return _m_carTopSpeed; }
    void setMCarTopSpeed(int m_carTopSpeed) { _m_carTopSpeed = m_carTopSpeed; }

    int mCarRPM() const { return _m_carRPM; }
    void setMCarRPM(int m_carRPM) { _m_carRPM = m_carRPM; }

    Cargear mCarGearSystem() const { return _m_carGearSystem; }
    void setMCarGearSystem(const Cargear &m_carGearSystem) { _m_carGearSystem = m_carGearSystem; }

    friend std::ostream &operator<<(std::ostream &os, const CarUnit &rhs);
};


#endif // CARUNIT_H
