//
// Created by bauli on 2025/02/17.
//

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>
using namespace std;


    class Bitmap {
    private:
        int m_width{0};
        int m_height{0};
        unique_ptr<uint8_t[]> m_pPixels{nullptr};


    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(string filename);
        virtual ~Bitmap();
    };


#endif /* BITMAP_H_ */