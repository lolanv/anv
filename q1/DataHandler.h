#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class DataHandler {
private:
    std::vector<int> _data;
    std::vector<int> _result;
    std::mutex _mutex;
    std::condition_variable _cv;
    bool _is_computed = false;

public:
    DataHandler();

    void FilterData(const std::function<bool(int)>& predicate);

    int SumOfEven();

    void operator<<(const std::vector<int>& data);

    void ComputerSquare(const std::vector<int>& data);

    void DisplayResult();

    void ComputeCube(const std::vector<int>& data);

    void DisplayCube();
};

#endif // DATAHANDLER_H
