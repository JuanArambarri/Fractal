//
// Created by bauli on 2025/02/18.
//

#ifndef FRACTAL_MANDELBROT_H
#define FRACTAL_MANDELBROT_H


class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 3500; //more pixels, better image.
public:
    Mandelbrot() = default;
    virtual ~Mandelbrot() = default;

    static int getIterations(double x, double y);
};


#endif //FRACTAL_MANDELBROT_H
