//
// Created by bauli on 2025/02/19.
//

#include "ZoomList.h"
ZoomList::ZoomList(int width, int height): m_height(height), m_width(width) {

}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);
}
std::pair<double,double> ZoomList::doZoom(int x, int y){
    return std::pair<double, double>(0,0);
}