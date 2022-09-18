
#include "JacobiMatrix.hpp"

JacobiMatrix::JacobiMatrix(int size, double (*equation1)(double , double ), double (*equation2)(double , double )) : Matrix(size){
    this->equation1 = equation1;
    this->equation2 = equation2;
}

void JacobiMatrix::RecountJacobiMatrix(XVector x, double M){
    matrix.at(0).at(0) = (equation1(x.at(0) + M * x.at(0), x.at(1)) - equation1(x.at(0), x.at(1))) / (M * x.at(0));
    matrix.at(0).at(1) = (equation1(x.at(0), x.at(1) + M * x.at(1)) - equation1(x.at(0), x.at(1))) / (M * x.at(1));
    matrix.at(1).at(0) = (equation2(x.at(0) + M * x.at(0), x.at(1)) - equation2(x.at(0), x.at(1))) / (M * x.at(0));
    matrix.at(1).at(1) = (equation2(x.at(0), x.at(1) + M * x.at(1)) - equation2(x.at(0), x.at(1))) / (M * x.at(1)); 
}
