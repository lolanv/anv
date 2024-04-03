#include"Functionalities.h"

int main() {
    Container data;

    CreateObjects(data);

    std::optional<bool> ans1 = hasSameGear(data);

    std::optional<Container> ans2 = hasMCarType(data, CarType::HATCHBACK);

    std::optional<float> ans3 = lowestPrice(data);

    std::optional<std::vector<int>> ans4 = m_car_rpmWithId(data, "tata");

    std::optional<int> ans5 = countAboveThreshold(data, 60000);

    if(ans1.has_value()) {
        std::cout<<"has same Gear -- "<<ans1.value()<<"\n";
    } else {
        std::cout<<"no data or no result";
    }

    if(ans2.has_value()) {
        std::cout<<"has M CarType -- "<<"\n";
    } else {
        std::cout<<"no data or no result";
    }

    if(ans3.has_value()) {
        std::cout<<"lowest price -- "<<ans3.value()<<"\n";
    } else {
        std::cout<<"no data or no result";
    }

    if(ans4.has_value()) {
        std::cout<<"m_car_rpmWithId"<<"\n";
    } else {
        std::cout<<"no data or no result";
    }

    if(ans5.has_value()) {
        std::cout<<"countAboveThreshold --"<<ans5.value()<<"\n";
    } else {
        std::cout<<"no data or no result";
    }
}
