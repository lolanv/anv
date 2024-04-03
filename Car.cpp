#include "Car.h"

Car::Car(const std::string& reg_num, float price, std::shared_ptr<Engine> engine)
    : m_car_reg_num(reg_num), m_price(price), m_car_engine(engine) {}
