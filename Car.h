#ifndef CAR_H
#define CAR_H

#include <string>
#include <memory>
#include <functional>

#include "Engine.h"

class Car {
public:
    std::string m_car_reg_num;
    float m_price;
    std::shared_ptr<Engine> m_car_engine;

    Car(const std::string& reg_num, float price, std::shared_ptr<Engine> engine);
};

#endif // CAR_H
