#pragma once

#include <vector>
#include <cmath>
#include <iostream>

class XVector : public std::vector<double>{

public:

    XVector(int size);

    XVector() : std::vector<double>(){}
    void Print();

    XVector operator-(XVector vec);

    double GetMaxElement();

    XVector operator+(XVector vec);

    void ReCountDiscrepancyVector(XVector x);

    XVector operator*(double num);

    double CountDelta1();

    double CountDelta2(XVector x);

};
