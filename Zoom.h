//
// Created by bauli on 2025/02/19.
//

#ifndef FRACTAL_ZOOM_H
#define FRACTAL_ZOOM_H

struct Zoom{
    ///coordinates of place to zoom and scale
    int x{0};
    int y{0};
    double scale{0.0};
    Zoom(int x, int y, double scale): x(x), y(y), scale(scale){};
};

#endif //FRACTAL_ZOOM_H
