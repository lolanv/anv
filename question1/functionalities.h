#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include <functional>
#include"Exception.h"

using Fntype = std::function<void(int, int, int**)>;

// Function to fill data in the 2D array
void Create(int R, int C, int** arr);

// Adaptor function
void Adaptor(int R, int C, int** arr, Fntype func);

// Functions to be passed to Adaptor
void DisplayRowSum(int R, int C, int** arr);
void DisplayHighestValue(int R, int C, int** arr);
extern Fntype DisplaySquareOfLastValue;
extern Fntype DisplayMaxInEachColumn;

#endif // FUNCTIONALITIES_H
