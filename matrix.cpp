
#include "matrix.hpp"

Matrix::Matrix(int size){

    std::vector<std::vector<double>> TempMatrix(size, std::vector<double>(size, 0));
    XVector vec(size);
    matrix = TempMatrix;
    Vector = vec;

}

void Matrix::Print(){

    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.at(i).size(); i_n++){
            printf("%20.5f", matrix.at(i).at(i_n));
        }
        printf("%20.5f", Vector.at(i));
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::GetMaxElement(int& swapTo, int column){

    int lastMax = INT32_MIN;

    for(int i = column; i < matrix.size(); i++){
        if(abs(matrix.at(i).at(column)) > lastMax){
            lastMax = matrix.at(column).at(i);
            swapTo = i;
        }
    }
}

Matrix Matrix::ForwardGause(){
    Matrix tempMatrix = *this;

    for(int i = 0; i < tempMatrix.matrix.size(); i++){

        std::vector<double> coefficients(matrix.size() + 1, 0);
        for(int i_n = i + 1; i_n < tempMatrix.matrix.size(); i_n++){
            coefficients.at(i_n - 1) = tempMatrix.matrix.at(i_n).at(i) / tempMatrix.matrix.at(i).at(i);
        }

        for(int i_m = i; i_m < matrix.size(); i_m++){
            for(int i_n = i + 1; i_n < matrix.size(); i_n++){
                tempMatrix.matrix.at(i_n).at(i_m) -= tempMatrix.matrix.at(i).at(i_m) * coefficients.at(i_n - 1);
            }
        }

        for(int i_n  = i + 1; i_n < matrix.size(); i_n++){
            tempMatrix.Vector.at(i_n) -= tempMatrix.Vector.at(i) * coefficients.at(i_n - 1);
        }
        tempMatrix.Vector.at(i) /= tempMatrix.matrix.at(i).at(i);

        for(int i_n = matrix.size() - 1; i_n >= i; i_n--){
            tempMatrix.matrix.at(i).at(i_n) /= tempMatrix.matrix.at(i).at(i);
        }

    }

    return tempMatrix;
}


XVector Matrix::BackGause(){
    XVector tempVector(matrix.size());
    for(int i = tempVector.size() - 1; i >= 0; i--){
        double value = Vector.at(i);
        for(int i_n = tempVector.size() - 1; i_n > i; i_n--){
            value -= matrix.at(i).at(i_n) * tempVector.at(i_n);
            // std::cout << "Value: " << value << std::endl;
        }
        tempVector.at(i) = value / matrix.at(i).at(i);
    }
    return tempVector;
}

void Matrix::TakeNewVector(XVector Vector){
    this->Vector = Vector;
}

XVector Matrix::operator* (XVector vec){
    XVector tempVector(Vector.size());
    for(int i = 0; i < matrix.size(); i++){
        for(int i_n = 0; i_n < matrix.size(); i_n++){
            tempVector.at(i) += matrix.at(i).at(i_n) * vec.at(i_n);
            // std::cout << tempVector.at(i) << std::endl;
        }
        // std::cout << std::endl;
    }

    return tempVector;
}

XVector Matrix::GetVector(){
    return Vector;
}
