#include <complex>
#include "../include/mandelbrot.h"

namespace happikin
{   
    mandelbrot::mandelbrot() {

    }
    mandelbrot::~mandelbrot() {

    }
    int mandelbrot::getIterations(double x, double y) {
        std::complex<double> z{0};
        std::complex<double> c(x, y);
        int iterations{0};
        while(iterations < MAX_ITERATIONS) {
            z*=z; z+=c;
            if(abs(z) > 2) break;
            iterations++;
        }
        return iterations;
    }
} // namespace happikin
