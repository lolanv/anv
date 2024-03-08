#include "DataHandler.h"

int main() {
    DataHandler handler;
    std::vector<int> data = {1, 2, 3, 4, 5};
    handler << data;
    handler.FilterData([](int num) { return num % 4 == 0; });
    std::cout << "Sum of even numbers: " << handler.SumOfEven() << std::endl;

    std::thread t1(&DataHandler::ComputerSquare, &handler, data);
    std::thread t2(&DataHandler::DisplayResult, &handler);
    t1.join();
    t2.join();

    std::thread t3(&DataHandler::ComputeCube, &handler, data);
    std::thread t4(&DataHandler::DisplayCube, &handler);
    t3.join();
    t4.join();

    return 0;
}