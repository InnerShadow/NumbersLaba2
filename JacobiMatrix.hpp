#pragma once

#include "matrix.hpp"

class JacobiMatrix : public Matrix {
protected:

    double (*equation1)(double x, double y);
    double (*equation2)(double x, double y);

public:

    JacobiMatrix(int size, double (*equation1)(double x, double y), double (*equation2)(double x, double y));

    void RecountJacobiMatrix(XVector x, double M);

};
