//
// Created by bauli on 2025/02/20.
//

#ifndef FRACTAL_RGB_H
#define FRACTAL_RGB_H


struct RGB {
    double r;
    double g;
    double b;
    RGB(double r, double g, double b);
};
RGB operator-(const RGB& first, const RGB& second);

#endif //FRACTAL_RGB_H
