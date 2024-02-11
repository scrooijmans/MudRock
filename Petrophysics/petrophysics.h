#ifndef PETROPHYSICS_H
#define PETROPHYSICS_H
#include <Eigen/Dense>

namespace Utilities
{
    class Petrophysics
    {
    public:
        Petrophysics();
        template<typename Derived>
        static Eigen::Array<typename Derived::Scalar, Eigen::Dynamic, 1> gardner(const Eigen::ArrayBase<Derived>& vp, double alpha = 310.0, double beta = 0.25, bool fps = false ){
            if (fps)
            {
                alpha = 230.0;
            }
            return alpha * vp.pow(beta);
        };


    };

    }

#endif // PETROPHYSICS_H
