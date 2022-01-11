#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color) {
    for (float t = 0.; t < 1.; t += 0.01) {
        int x = x0 * (1. - t) + x1 * t;
        int y = y0 * (1. - t) + y1 * t;
        image.set(x, y, color);
    }
}

int main(int argc, char** argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    
    line(20, 13, 40, 80, image, red);
    line(80, 40, 13, 20, image, red);
    line(13, 20, 80, 40, image, white);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output4.tga");
    return 0;
}
// It turns out that one line is good, the second one is with holes, 
//and there¡¯s no third line at all. Note that the first and the third lines (in the code) draw the same line in 
// different colors, and in different directions (with the source and target points flipped). 
// We have already seen the white one, it is drawn well. I was hoping to change the color of the white line to red, 
// but could not do it. It¡¯s a test for symmetry: the result of drawing a line segment should not depend on the order 
// of points: the (a,b) line segment should be exactly the same as the (b,a) line segment.