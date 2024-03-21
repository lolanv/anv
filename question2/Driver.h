#ifndef DRIVER_H
#define DRIVER_H

#include <string>

class Driver {
private:
    std::string _driver_license_type;
    unsigned int _driver_experience_years;
    float _driver_rating;

public:
    Driver(const std::string& license_type, unsigned int experience_years, float rating);

    std::string getLicenseType() const;
    unsigned int getExperienceYears() const;
    float getRating() const;
};

#endif // DRIVER_H
