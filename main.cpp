#include <iostream>
#include <cmath>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace caveofprogramming;

int main() {
    int const WIDTH = 1280;
    int const HEIGHT = 720;

    Bitmap bitmap(WIDTH,HEIGHT);

    double min = 9999999;
    double max = -9999999;

    //careful not to exceed the bounds of the array
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]()); //array of ints to store the iterations
    //the whole array is initialized to 0 thanks to the final brackets

    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x <WIDTH; x++){
            // bitmap.setPixel(x,y, 255,0,0); //should show a white pixel in the middle.
            double xFractal = (x - WIDTH/2 - 200) * (2.0/HEIGHT); // (2.0/WIDTH) is scaling, (x-WIDTH/2) is the offset
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT); //having both the same scaling will make it more symmetrical

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            histogram[iterations]++;

            uint8_t color =(uint8_t)(255 * (double)iterations / Mandelbrot::MAX_ITERATIONS);

            color = color*color*color; //will always have a maximum value of 255 because of uint8_t

            bitmap.setPixel(x,y,0,color,0);

            if (color < min) min = color;
            if (color > max) max = color;
        }
    }
    cout << endl;
    int count = 0;
    for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
        cout << histogram[i] << " " << flush;
        count += histogram[i];
    }
    cout << count << "; " << WIDTH*HEIGHT << endl; //count and Height*Width should be the same. (Amount of pixels)
    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}
