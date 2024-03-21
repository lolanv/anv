#include "functionalities.h"

void Create(int R, int C, int** arr) {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            std::cin >> arr[i][j];
        }
    }
}

void Adaptor(int R, int C, int** arr, Fntype func) {
    func(R, C, arr);
}

void DisplayRowSum(int R, int C, int** arr) {
    if(sizeof(arr) == 0) {
        throw Exception("empty\n");
    }
    for (int i = 0; i < R; ++i) {
        int sum = 0;
        for (int j = 0; j < C; ++j) {
            sum += arr[i][j];
        }
        std::cout << sum << std::endl;
    }
}

void DisplayHighestValue(int R, int C, int** arr) {
    if(sizeof(arr) == 0) {
        throw Exception("empty\n");
    }
    int max = arr[0][0];
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
    }
    std::cout << max << std::endl;
}

Fntype DisplaySquareOfLastValue = [](int R, int C, int** arr) {
    if(sizeof(arr) == 0) {
        throw Exception("empty\n");
    }
    std::cout << arr[R - 1][C - 1] * arr[R - 1][C - 1] << std::endl;
};

Fntype DisplayMaxInEachColumn = [](int R, int C, int** arr) {
    if(sizeof(arr) == 0) {
        throw Exception("empty\n");
    }
    for (int j = 0; j < C; ++j) {
        int max = arr[0][j];
        for (int i = 1; i < R; ++i) {
            if (arr[i][j] > max)
                max = arr[i][j];
        }
        std::cout << max << std::endl;
    }
};
