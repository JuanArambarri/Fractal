#include <iostream>
#include <cmath>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"

using namespace std;
using namespace caveofprogramming;

int main() {
    int const WIDTH = 1280;
    int const HEIGHT = 720;

    Bitmap bitmap(WIDTH,HEIGHT);

    double min = 9999999;
    double max = -9999999;

    //careful not to exceed the bounds of the array
    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]()); //array of ints to store the iterations
    unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});
    //the whole array is initialized to 0 thanks to the final brackets

    ///this loop only sets our iterations
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x <WIDTH; x++){
            // bitmap.setPixel(x,y, 255,0,0); //should show a white pixel in the middle.
            double xFractal = (x - WIDTH/2 - 200) * (2.0/HEIGHT); // (2.0/WIDTH) is scaling, (x-WIDTH/2) is the offset
            double yFractal = (y - HEIGHT/2) * (2.0/HEIGHT); //having both the same scaling will make it more symmetrical

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            fractal[y*WIDTH+x] = iterations; // Pixel left to right and then next row y*WIDTH (0,0 *width... 1,0... 2,0)

            if (iterations != Mandelbrot::MAX_ITERATIONS){
                histogram[iterations]++;
            }
        }
    }
    int total = 0;
    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
        total += histogram[i];
    }
    /// this loop sets our colors
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x <WIDTH; x++){

            uint8_t red (0);
            uint8_t green(0);
            uint8_t blue(0);

            int iterations = fractal[y * WIDTH + x];

            //can read about Mandelbrot colouring
            if (iterations !=Mandelbrot::MAX_ITERATIONS){
                double hue = 0.0;
                for (int i = 0; i <= iterations; i++){
                    hue += ((double)histogram[i]) / total;
                }
                red = pow(255, hue);
                green = pow(255, hue);
                blue = pow(255, hue);
            }
            bitmap.setPixel(x,y,red,green,blue);
        }

    }
    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}
