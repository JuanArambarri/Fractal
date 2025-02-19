//
// Created by bauli on 2025/02/19.
//

#ifndef FRACTAL_ZOOMLIST_H
#define FRACTAL_ZOOMLIST_H
#include <vector>
#include <utility>
#include "Zoom.h"

class ZoomList {
private:
    int m_width{0};
    int m_height{0};
    std::vector<Zoom> zooms;
public:
    ZoomList(int width, int height);
    void add(const Zoom& zoom);
    std::pair<double, double> doZoom(int x, int y);
};


#endif //FRACTAL_ZOOMLIST_H
