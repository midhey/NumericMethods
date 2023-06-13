#include <iostream>
#include <cmath>
#include "iter.h"

double F(double X) {
    return X*pow(2,X)-1;
}

void iteration() {
    double X1, X2, E;
    std::cout << "¬ведите точность: ";
    std::cin >> E;


    X1 = 1;
    X2 = F(X1);

    while (std::abs(X2 - X1) > E) {
        X1 = X2;
        X2 = F(X1);
    }

    std::cout << "«начение корн€ с точностью " << E << " равно " << X2 << std::endl;
}