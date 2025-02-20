#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"


using namespace std;

int main() {

    FractalCreator fractalCreator(800, 600);

    fractalCreator.addRange(0.0,RGB(0,0,0));//set to black
    /// until 0.3 does red (300 iterations based on the 1000 set in Mandelbrot class)
    fractalCreator.addRange(0.1,RGB(255, 182, 193));
    fractalCreator.addRange(0.3,RGB(230, 230, 250));
    fractalCreator.addRange(0.45,RGB(189, 252, 201));
    fractalCreator.addRange(0.55,RGB(255, 182, 193));
    fractalCreator.addRange(0.77,RGB(230, 230, 250));
    fractalCreator.addRange(0.88,RGB(189, 252, 201));
    fractalCreator.addRange(1.0,RGB(255, 218, 185));


    fractalCreator.addZoom(Zoom(295, 202, 0.1));
    fractalCreator.addZoom(Zoom(312, 304, 0.1));
    fractalCreator.addZoom(Zoom(123,300,.3));

    fractalCreator.run("test.bmp");

    cout << "Finished." << endl;
    return 0;
}
