#include <iostream>
#include <cmath>

#include "matrix.hpp"
#include "Xvector.hpp"
#include "JacobiMatrix.hpp"

#define EPSILON1 10e-9
#define EPSILON2 10e-9
#define KNIT  100

// Task 9

double equation1(double x, double y){
    return 1.5 * pow(x, 3) - pow(y, 2) - 1;
}

double equation2(double x, double y){
    return x * pow(y, 3) - y - 4;
}

double CountDelta1(XVector x){
	if (std::abs(equation1(x.at(0), x.at(1))) > std::abs(equation2(x.at(0), x.at(1)))){
		return std::abs(equation1(x.at(0), x.at(1)));
    } else {
		return std::abs(equation2(x.at(0), x.at(1)));
    }
}

double CountDelta2(XVector x, XVector prev){
    double max = 0;

    for (int i = 0; i < x.size(); i++){
        if (std::abs(prev.at(i)) < 1){
            if (abs(prev.at(i) - x.at(i)) > max){
                max = std::abs(prev.at(i) - x.at(i));
            }
        } else {
            if (std::abs((prev.at(i) - x.at(i)) / prev.at(i)) > max){
                max = std::abs((prev.at(i) - x.at(i)) / prev.at(i));
            }
        }
    }

    return max;
}

void DoTaskInPropertyOfM(double M){
    JacobiMatrix Jacobi(2, equation1, equation2);

    XVector Solution(2);
    Solution.at(0) = 1;
    Solution.at(1) = 1;

    double delta1 = 1;
    double delta2 = 1;
    int counter = 0;
    XVector Discrepancy(2);  //F

    printf("%25s%25s%25s", "counter", "delta1", "delta2\n");
    while(delta1 > EPSILON1 || delta2 > EPSILON2){
        Discrepancy.ReCountDiscrepancyVector(Solution);
        Jacobi.RecountJacobiMatrix(Solution, M);

        Jacobi.TakeNewVector(Discrepancy * -1);

        XVector deltax = Jacobi.ForwardGause().BackGause();

        XVector tmp(Solution.size());
        for(int i = 0; i < Solution.size(); i++){
            tmp.at(i) = Solution.at(i) + deltax.at(i);
        }

        delta1 = CountDelta1(Solution);
        delta2 = CountDelta2(Solution, tmp);
        
        Solution = tmp;

        counter++;
        printf("%25d%25.15f%25.15f\n", counter, delta1, delta2);

        if(counter >= KNIT){
            std::cout << "IER = 2\n";
            return;
        }
        
        // Solution.Print();

    }

    std::cout << "Solution: ";
    Solution.Print();

    std::cout << "Discrepancy first equation: " << std::abs(equation1(Solution.at(0), Solution.at(1))) << "\n";
    std::cout << "Discrepancy second equation: " << std::abs(equation2(Solution.at(0), Solution.at(1))) << "\n";

}

int main(void){
    printf("%45s\n", "M == 0.1");
    DoTaskInPropertyOfM(0.1);
    printf("\n%45s\n", "M == 0.05");
    DoTaskInPropertyOfM(0.05);
    printf("\n%45s\n", "M == 0.01");
    DoTaskInPropertyOfM(0.01);
    return 0;
}
