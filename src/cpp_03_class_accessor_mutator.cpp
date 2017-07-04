#include <iostream>
using namespace std;

/**
 * Illustrate simple accessor/mutator functions
 *
 * Keeping class variables private ensures proper encapsulation.
 * Should access variables only through accessor/mutator functions, so
 * that the underlying storage is unknown to outside world
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        int getWidth(void) { return width; };
        int getHeight(void) { return height; };
        void setWidth(int w) { width = w; };
        void setHeight(int h) { height = h; };
};

int main() 
{
    Rectangle rect;

    /* Access the rectangles accessors/mutators */
    rect.setWidth(5);
    rect.setHeight(7);
    cout << "Rect width = " << rect.getWidth() << endl;
    cout << "Rect height = " << rect.getHeight() << endl;

    /* Update the rectangle */
    rect.setWidth(2);
    rect.setHeight(3);
    cout << "Rect width = " << rect.getWidth() << endl;
    cout << "Rect height = " << rect.getHeight() << endl;

    return 0;
}
