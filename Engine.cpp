#include "Engine.h"

Engine::Engine(const std::string& engine_number, int torque, int horsepower, EngineType type)
    : m_engine_number(engine_number), m_engine_torque(torque), m_horsepower(horsepower), m_engine_type(type) {}
