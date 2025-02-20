//
// Created by bauli on 2025/02/20.
//

#ifndef FRACTAL_FRACTALCREATOR_H
#define FRACTAL_FRACTALCREATOR_H

#include <string>
#include <cstdint>
#include <vector>
#include <cassert>
#include <memory>
#include <iostream>
#include <math.h>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"
using namespace std;

class FractalCreator {
private:
    int m_width;
    int m_height;
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
    int m_total { 0 };

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange {false};

private:
    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void writeBitmap(string name);


public:
    FractalCreator(int width, int height);
    void addRange(double rangeEnd, const RGB& rgb);
    void addZoom(const Zoom& zoom);
    virtual ~FractalCreator();
    void run(string name);
    void calculateRangeTotals();
    int getRange(int iterations) const;
};

#endif //FRACTAL_FRACTALCREATOR_H
