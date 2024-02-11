
#include <Eigen/Dense>
#include "petrophysics.h"
#include <iostream>

int main()
{
    // Create dynamic array of doubles
    Eigen::ArrayXd vp(4);
    vp << 1500.0, 2000.0, 3500.0, 3000.0;


    auto rho = Utilities::Petrophysics::gardner(vp);
    std::cout << "densities:" << rho<< std::endl;
    return 0;

}
