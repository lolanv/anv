#ifndef ENGINE_H
#define ENGINE_H

#include <string>

enum class EngineType {
    CRDI,
    MPFI,
    TURBOCHARGED
};

class Engine {
public:
    std::string m_engine_number;
    int m_engine_torque;
    int m_horsepower;
    EngineType m_engine_type;

    Engine(const std::string& engine_number, int torque, int horsepower, EngineType type);
};

#endif // ENGINE_H
