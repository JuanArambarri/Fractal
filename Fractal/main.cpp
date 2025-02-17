#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {
    int const WIDTH = 1280;
    int const HEIGHT = 720;
    Bitmap bitmap(WIDTH,HEIGHT);

    for(int y = 0; y< HEIGHT; y++){
        for(int x = 0; x<WIDTH; x++){
            bitmap.setPixel(x,y, 255,0,0); //should show a white pixel in the middle.
        }
    }

    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}
