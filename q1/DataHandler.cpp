#include "DataHandler.h"

DataHandler::DataHandler() {
    _data = {1, 2, 3, 4, 5};
}

void DataHandler::FilterData(const std::function<bool(int)>& predicate) {
    std::vector<int> filtered_data;
    for (int num : _data) {
        if (predicate(num)) {
            filtered_data.push_back(num);
        }
    }
    std::cout << "Filtered data: ";
    for (int num : filtered_data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int DataHandler::SumOfEven() {
    int sum = 0;
    for (int num : _data) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}

void DataHandler::operator<<(const std::vector<int>& data) {
    _data = data;
}

void DataHandler::ComputerSquare(const std::vector<int>& data) {
    _result.clear();
    for (int num : data) {
        _result.push_back(num * num);
    }
    _is_computed = true;
    _cv.notify_one();
}

void DataHandler::DisplayResult() {
    std::unique_lock<std::mutex> lock(_mutex);
    _cv.wait(lock, [this] { return _is_computed; });
    std::cout << "Computed squares: ";
    for (int num : _result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void DataHandler::ComputeCube(const std::vector<int>& data) {
    _result.clear();
    for (int num : data) {
        _result.push_back(num * num * num);
    }
    _is_computed = true;
    _cv.notify_one();
}

void DataHandler::DisplayCube() {
    std::unique_lock<std::mutex> lock(_mutex);
    _cv.wait(lock, [this] { return _is_computed; });
    std::cout << "Computed cubes: ";
    for (int num : _result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
