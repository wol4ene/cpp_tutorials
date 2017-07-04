#include <iostream>
using namespace std;

/**
 * Constructors allow a class to be initialized
 * Get called automatically when object gets created
 *
 * Constructurs are named the same as the class.
 */

class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle(int x, int y) { cout << "In ctor " << endl; width = x; height = y; };
        int area(void) { return width * height; };
};

int main() 
{
    /* Create two rectangle objects */
    Rectangle rectA(5,6), rectB(3,9);

    cout << "rectA.area = " << rectA.area() << endl;
    cout << "rectB.area = " << rectB.area() << endl;

    return 0;
}
