#ifndef EV_CAR_H
#define EV_CAR_H

#include <string>
#include <ostream>

enum class Platform {
    PURE_EV,
    IC_BASED
};

class EvCar {
public:
    EvCar(std::string car_id, int battery_charging_time, Platform platform, float chassos_length, int seat_count, int top_speed);

    std::string getCarId() const {
        return m_car_id;
    }
    int getTopSpeed() const{
        return m_top_speed;
    }
    float getChassisLength() const{
        return m_chassis_length;
    }
    Platform getPlatform() const{
        return m_platform;
    }

    int seatCount() const { return m_seat_count; }
    void setSeatCount(int seat_count) { m_seat_count = seat_count; }

    friend std::ostream &operator<<(std::ostream &os, const EvCar &rhs);

private:
    std::string m_car_id;
    int m_battery_charging_time;
    Platform m_platform;
    float m_chassis_length;
    int m_seat_count;
    int m_top_speed;
};

#endif // EV_CAR_H
