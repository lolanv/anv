#include "Driver.h"
#include <stdexcept>

Driver::Driver(const std::string& license_type, unsigned int experience_years, float rating)
    : _driver_license_type(license_type), _driver_experience_years(experience_years) {
    if (rating < 1 || rating > 15) {
        throw std::invalid_argument("Rating must be between 1 and 15.");
    }
    _driver_rating = rating;
}

std::string Driver::getLicenseType() const {
    return _driver_license_type;
}

unsigned int Driver::getExperienceYears() const {
    return _driver_experience_years;
}

float Driver::getRating() const {
    return _driver_rating;
}
