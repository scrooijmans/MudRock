#include <iostream>
#include <mudrock.h>
#include <armadillo>
#include <Eigen/Dense>
#include <boost/lexical_cast.hpp> // Include the lexical_cast header

int main(){
    // Initialize Armadillo's random number generator
    arma::arma_rng::set_seed_random();


    // Sample Boost code using lexical_cast
    try {
        std::string strNum = "123";
        int num = boost::lexical_cast<int>(strNum);
        std::cout << "Converted string to int: " << num << std::endl;

        // Convert back from int to string
        strNum = boost::lexical_cast<std::string>(num);
        std::cout << "Converted back to string: " << strNum << std::endl;
    } catch(const boost::bad_lexical_cast& e) {
        std::cerr << "Error converting string: " << e.what() << std::endl;
    }

    Eigen::MatrixXd mat(2,2);
    mat(0,0) = 3;
    mat(1,0) = 2.5;
    mat(0,1) = -1;
    mat(1,1) = mat(0,0) + mat(1,0);
    std::cout << mat << std::endl;

    std::cout << "test asa" << std::endl;
    bool status = true;
    return (status) ? 0: -1;
}
