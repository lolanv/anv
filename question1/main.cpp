#include <iostream>
#include <functional>
#include "functionalities.h"

int main() {
    try {
        int R, C;
        std::cout << "Enter the number of rows and columns: ";
        std::cin >> R >> C;
        int** data = new int*[R];
        for (int i = 0; i < R; ++i) {
            data[i] = new int[C];
        }
        std::cout << "Enter " << R * C << " integers:\n";
        Create(R, C, data);

        // Function 1: Display Row Sum
        std::cout << "Row Sums:\n";
        Adaptor(R, C, data, DisplayRowSum);

        // Function 2: Display Highest Value
        std::cout << "Highest Value: ";
        Adaptor(R, C, data, DisplayHighestValue);

        // Function 3: Display Square of Last Value
        std::cout << "Square of Last Value: ";
        Adaptor(R, C, data, DisplaySquareOfLastValue);


        // Function 4: Display Max in Each Column
        std::cout << "Max in Each Column:\n";
        Adaptor(R, C, data, DisplayMaxInEachColumn);

        // Clean up
        for (int i = 0; i < R; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
    catch (Exception& e) {
        e.what();
    }

    return 0;
}
