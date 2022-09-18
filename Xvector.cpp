
#include "Xvector.hpp"

XVector::XVector(int size) : std::vector<double>(size){}

void XVector::Print(){
    for(int i = 0; i < size(); i++){
        std::cout << at(i) << " ";
    }
    std::cout << std::endl;
}

XVector XVector::operator-(XVector vec){
    XVector tempvec(size());
    for(int i = 0; i < size(); i++){
        tempvec.at(i) = at(i) - vec.at(i);
    }
    return tempvec;
}

XVector XVector::operator*(double num){
    XVector tmp(size());
    for(int i = 0; i < size(); i++){
        tmp.at(i) = at(i) * num;
    }
    return tmp;
}

double XVector::GetMaxElement(){
    double value = 0.f;
    for(int i = 0 ; i < size(); i++){
        if(std::abs(at(i)) > value){
            value = std::abs(at(i));
        }
    }
    return value;
}

void XVector::ReCountDiscrepancyVector(XVector x){
    at(0) = 1.5 * pow(x.at(0), 3) - pow(x.at(1), 2) - 1;
    at(1) = x.at(0) * pow(x.at(1), 3) - x.at(1) - 4;
}
