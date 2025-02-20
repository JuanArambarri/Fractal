//
// Created by bauli on 2025/02/18.
//
#include <complex>
#include "Mandelbrot.h"

using namespace std;

int Mandelbrot::getIterations(double x, double y) {
    complex<double> z = 0;
    complex<double> c(x, y);

    int iterations = 0;

    while (iterations < MAX_ITERATIONS) {
        z = z * z + c;
        if(norm(z)> 4.0){ //a lot quicker than abs(z).
            break;
        }
//        if (abs(z) > 2) { //abs is the magnitude of a complex number
//            break;
//        }
        iterations++;
    }
    return iterations;
}
