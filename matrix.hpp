#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Xvector.hpp"

class Matrix {
protected:

    std::vector<std::vector<double>> matrix;
    XVector Vector;

public:

    Matrix(int size);

    void Print();

    void FillTask13();

    void FillLambdaTask(double Lambda1, double Lambda2, double Lambda3);

    Matrix ForwardGause();

    void GetMaxElement(int& swapTo, int column);

    XVector BackGause();

    void TakeNewVector(XVector Vector);

    XVector GetVector();

    XVector operator* (XVector vec);

};
